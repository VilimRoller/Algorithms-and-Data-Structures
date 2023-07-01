#pragma once
#include "../Algorithms/AlgorithmInfo.h"
#include "../Algorithms/SortAlgorithms/SortAlgorithm.h"
#include "../Algorithms/SortAlgorithms/SelectionSort.h"
#include "../Algorithms/SortAlgorithms/BubbleSort.h"
#include "../Algorithms/SortAlgorithms/InsertionSort.h"
#include "../Algorithms/SortAlgorithms/MergeSort.h"
#include "../Algorithms/SortAlgorithms/QuickSort.h"
#include "../Algorithms/SortAlgorithms/HeapSort.h"
#include "../Algorithms/SortAlgorithms/ShellSort.h"
#include "Benchmark.h"
#include "Timer.h"
#include "RandomNumberGenerator.h"

#include <vector>
#include <iostream>
#include <cstdint>
#include <iomanip>
#include <fstream>
#include <string>
#include <utility>
#include <cstring>
#include <memory>


constexpr const int num_of_random_element_vectors = 10;

template<class sorting_data>
class SortAlgorithmsBenchmark {

public:
	SortAlgorithmsBenchmark() = default;

	void StartBenchmark(const DistributionType distribution_type, const int num_of_vector_sizes, 
						const int vector_step_size, const std::string& file_name_suffix) noexcept {
		
		SetDistributionType(distribution_type);
		InitializeRandomElementVectorSizes(num_of_vector_sizes, vector_step_size);
		SetOutputFileNameSuffix(file_name_suffix);
		SetOutputFileName();
		GenerateRandomDataVectors(distribution_type);
		OpenOutputFile();
		MeasureSortingTimesForAllSorts();
		WriteOutputToFile();
		CloseOutputFile();
		ResetAllData();
	}
	
private:

	void SetOutputFileName() noexcept {
		output_file_name_ = name_of_used_distribution_ + " distribution benchmark results" + output_file_name_suffix_ + ".txt";
	}

	void SetOutputFileNameSuffix(const std::string& name_suffix) noexcept {
		output_file_name_suffix_ = name_suffix;
	}

	void SetDistributionType(const DistributionType distribution_type) noexcept {
		distribution_type_ = distribution_type;
		name_of_used_distribution_ = GetNameOfUsedDistribution(distribution_type);
	}

	void InitializeRandomElementVectorSizes(const int num_of_vector_sizes, const int vector_size_step) {
		for (int num_of_elements = vector_size_step; num_of_elements <= num_of_vector_sizes * vector_size_step; num_of_elements += vector_size_step)
			random_element_vector_sizes_.emplace_back(static_cast<std::size_t>(num_of_elements));
	}

	void GenerateRandomDataVectors(const DistributionType distribution_type_) noexcept {
		for (const auto& vector_size : random_element_vector_sizes_) 
			random_data_element_vectors_.emplace_back(generator_.GetGeneratedValues(distribution_type_, vector_size));
	}

	void MeasureSortingTimesForAllSorts() noexcept {
		for (const auto& sorter : all_sorts_)
			MeasureSortExecutionTimeForAllVectorSizes(sorter);
	}

	void MeasureSortExecutionTimeForAllVectorSizes(const std::shared_ptr<SortAlgorithm> sorter) noexcept {
		std::vector<long double> sorting_times;

		for (auto& random_data_element_vector : random_data_element_vectors_)
			FlushCacheAndMeasureSortExecutionTime(random_data_element_vector, sorting_times, sorter);

		all_sorting_times_.emplace_back(sorting_times);
	}

	template<class random_data_vector>
	void FlushCacheAndMeasureSortExecutionTime(random_data_vector& random_data_element_vector, std::vector<long double>& sorting_times,
		const std::shared_ptr<SortAlgorithm> sorter) noexcept {
		Benchmark::FlushCache();
		MeasureSortExecutionTime(random_data_element_vector, sorting_times, sorter);
	}

	template<class random_data_vector>
	void MeasureSortExecutionTime(random_data_vector random_data_element_vector, std::vector<long double>& sorting_times,
					const std::shared_ptr<SortAlgorithm> sorter) noexcept {
		
		benchmark_timer_.Start();
		sorter->SortVector(random_data_element_vector.begin(), random_data_element_vector.end());
		benchmark_timer_.Stop();

		sorting_times.emplace_back(benchmark_timer_.GetMeasuredTimeInMicroseconds());
	}

	void OpenOutputFile() noexcept {
		results_file_.open(output_file_name_);
		is_file_open_ = true;
	}

	void WriteOutputToFile() noexcept {
		if (!is_file_open_)
			OpenOutputFile();

		int sort_counter = 0;
		WriteNameOfUsedDistributionToFile();
		WriteNumberOfVectorsElementsToFile();

		for (const auto& sorter : all_sorts_) 
			WriteSortAlgorithmDataToFile(sorter, sort_counter);
	}

	void WriteNameOfUsedDistributionToFile() noexcept {
		results_file_ << "Distribution used: " << name_of_used_distribution_ << "\n";
	}

	void WriteNumberOfVectorsElementsToFile() noexcept {
		results_file_ << "Number of vector elements: ";
		for (const auto element : random_element_vector_sizes_)
			results_file_ << element << " ";

		results_file_ << "\n";
	}

	void WriteSortAlgorithmDataToFile(const std::shared_ptr<SortAlgorithm> sorter, int& sort_counter) noexcept {
		WriteAlgorithmInfoToFile(sorter->GetAlgorithmInfo());
		WriteSortingTimeToFile(all_sorting_times_[sort_counter]);

		++sort_counter;
	}

	void WriteAlgorithmInfoToFile(const AlgorithmInfo& algo_info) noexcept {
		results_file_ << line_separator;
		results_file_ << "Algorithm name: " << algo_info.GetName() << "\n";
		results_file_ << "Time complexity (best case): " << algo_info.GetBestTimeComplexity() << "\n";
		results_file_ << "Time complexity (average case): " << algo_info.GetAverageTimeComplexity() << "\n";
		results_file_ << "Time complexity (worst case): " << algo_info.GetWorstTimeComplexity() << "\n";
		results_file_ << "Auxiliary space complexity: " << algo_info.GetSpaceComplexity() << "\n";
		results_file_ << line_separator;
	}

	void WriteSortingTimeToFile(const std::vector<long double>& sorting_times) noexcept {
		results_file_ << "Sorting times[us]: ";

		for (const auto& sorting_time : sorting_times) 
			results_file_ << std::fixed << std::setprecision(1) << sorting_time << " ";

		results_file_ << "\n";
	}

	void CloseOutputFile() noexcept {
		results_file_.close();
		is_file_open_ = false;
	}

	std::string GetNameOfUsedDistribution(DistributionType distribution_type) noexcept {
		switch (distribution_type) {
		case DistributionType::Uniform:
			return "Uniform";
		case DistributionType::Binomial:
			return "Binomial";
		case DistributionType::NegativeBinomial:
			return "Negative Binomial";
		case DistributionType::Geometric:
			return "Geometric";
		case DistributionType::Poisson:
			return "Poisson";
		case DistributionType::Exponential:
			return "Exponential";
		case DistributionType::Gamma:
			return "Gamma";
		case DistributionType::Weibull:
			return "Weibull";
		case DistributionType::ExtremeValue:
			return "ExtremeValue";
		case DistributionType::Normal:
			return "Normal";
		case DistributionType::LogNormal:
			return "LogNormal";
		case DistributionType::ChiSquared:
			return "ChiSquared";
		case DistributionType::Cauchy:
			return "Cauchy";
		case DistributionType::Fischer_f:
			return "Fischer_f";
		case DistributionType::Student_t:
			return "Student_t";
		case DistributionType::NO_DISTRIBUTION:
			return "NO_DISTRIBUTION";
		default:
			return "";
		}
	}

	void ResetAllData() noexcept {
		name_of_used_distribution_.clear();
		output_file_name_.clear();
		random_element_vector_sizes_.clear();
		random_data_element_vectors_.clear();
		all_sorting_times_.clear();
	}

	RandomNumberGenerator<sorting_data> generator_;
	Timer benchmark_timer_;

	DistributionType distribution_type_ = DistributionType::NO_DISTRIBUTION;
	std::string name_of_used_distribution_;
	std::string output_file_name_;
	std::string output_file_name_suffix_;

	std::vector<std::size_t> random_element_vector_sizes_;

	std::vector<std::vector<sorting_data>> random_data_element_vectors_;
	std::vector<std::vector<long double>> all_sorting_times_;

	const std::vector<std::shared_ptr<SortAlgorithm>> all_sorts_{ 
		std::make_shared<BubbleSort>(),
		std::make_shared<HeapSort>(),
		std::make_shared<InsertionSort>(),
		std::make_shared<MergeSort>(),
		std::make_shared<QuickSort>(),
		std::make_shared<SelectionSort>(),
		std::make_shared<ShellSort>()};

	std::ofstream results_file_;
	bool is_file_open_ = false;

	static inline const std::string line_separator = "\n|-------------------------------------------------------------------------------------------|\n";

};
