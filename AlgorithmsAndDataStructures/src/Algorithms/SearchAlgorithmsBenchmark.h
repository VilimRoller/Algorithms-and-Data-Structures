#pragma once
#include "SearchAlgorithmIncludes.h"
#include "Timer.h"
#include "RandomNumberGenerator.h"
#include "Algorithms/Sorting Algorithms/QuickSort.h"
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <utility>
#include <cstring>
#include "Benchmark.h"

inline const std::string output_file_name = "Search Algorithms Benchmark.txt";

template<class data_type>
class SearchAlgorithmsBenchmark {
public:
	SearchAlgorithmsBenchmark() = default;

	void StartBenchmark(const int num_of_vector_sizes, const int vector_size_step) {
		OpenOutputFile();
		WriteVectorSizeDataToFile(num_of_vector_sizes, vector_size_step);
		MeasureSearchTimesForAllVectorSizes(num_of_vector_sizes, vector_size_step);
		WriteMeasuredDataToFile();
		CloseOutputFile();
	}

private:
	void OpenOutputFile() noexcept {
		results_file_.open(output_file_name);
		is_file_open_ = true;
	}

	void WriteVectorSizeDataToFile(const int num_of_vector_sizes, const int vector_size_step) noexcept {
		results_file_ << "Distribution used: Uniform\n";
		results_file_ << "Number of vector elements: ";
		for (int i = vector_size_step; i <= num_of_vector_sizes * vector_size_step; i += vector_size_step)
			results_file_ << i << " ";
		results_file_ << "\n\n";
		WriteLineSeparator();
	}

	std::vector<data_type> GetSortedVector(const int number_of_elements) noexcept {
		auto sorted_vector = random_generator_.GetGeneratedValues(DistributionType::Uniform, number_of_elements);
		quick_sorter_.SortContainer(sorted_vector.begin(), sorted_vector.end());
		return std::move(sorted_vector);
	}

	void MeasureSearchTimesForAllVectorSizes(const int num_of_vector_sizes, const int vector_step_size) noexcept {
		for (int vec_size = vector_step_size; vec_size <= vector_step_size * num_of_vector_sizes; vec_size += vector_step_size)
			MeasureSearchTime(vec_size);
	}

	void MeasureSearchTime(const int vec_size) noexcept {
		Benchmark::FlushCache();
		auto sorted_vector = GetSortedVector(vec_size);
		
		linear_search_time_.emplace_back(GetMeasuredAverageLinearSearchTime(sorted_vector));
		binary_search_time_.emplace_back(GetMeasuredAverageBinarySearchTime(sorted_vector));
		jump_search_time_.emplace_back(GetMeasuredAverageJumpSearchTime(sorted_vector));
		interpolation_search_time_.emplace_back(GetMeasuredAverageInterpolationSearchTime(sorted_vector));
	}

	long double GetMeasuredAverageLinearSearchTime(const std::vector<data_type>& sorted_vector) noexcept {
		timer_.Start();
		for (const auto element : sorted_vector)
			linear_searcher_.FindValue(sorted_vector.begin(), sorted_vector.end(), element);
		timer_.Stop();
		return (timer_.GetMeasuredTimeInMicroseconds() / static_cast<long double>(sorted_vector.size()));
	}

	long double GetMeasuredAverageBinarySearchTime(const std::vector<data_type>& sorted_vector) noexcept {
		timer_.Start();
		for (const auto element : sorted_vector)
			binary_searcher_.FindValue(sorted_vector.begin(), sorted_vector.end(), element);
		timer_.Stop();
		return (timer_.GetMeasuredTimeInMicroseconds() / static_cast<long double>(sorted_vector.size()));
	}

	long double GetMeasuredAverageJumpSearchTime(const std::vector<data_type>& sorted_vector) noexcept {
		timer_.Start();
		for (const auto element : sorted_vector)
			jump_searcher_.FindValue(sorted_vector.begin(), sorted_vector.end(), element, static_cast<int>(static_cast<int>(std::sqrt(sorted_vector.size()))));
		timer_.Stop();
		return (timer_.GetMeasuredTimeInMicroseconds() / static_cast<long double>(sorted_vector.size()));
	}

	long double GetMeasuredAverageInterpolationSearchTime(const std::vector<data_type>& sorted_vector) noexcept {
		timer_.Start();
		for (const auto element : sorted_vector)
			interpolation_searcher_.FindValue(sorted_vector.begin(), sorted_vector.end(), element);
		timer_.Stop();
		return (timer_.GetMeasuredTimeInMicroseconds() / static_cast<long double>(sorted_vector.size()));
	}

	void WriteMeasuredDataToFile() noexcept {
		WriteLinearSearchTimeData();
		WriteBinarySearchTimeData();
		WriteJumpSearchTimeData();
		WriteInterpolationSearchTimeData();
	}

	void WriteLinearSearchTimeData() noexcept {
		WriteAlgoInfo(linear_searcher_);
		for (const auto time : linear_search_time_)
			results_file_ << time << " ";
		results_file_ << std::fixed << std::setprecision(3) << "\n";
		WriteLineSeparator();
	}
	void WriteBinarySearchTimeData() noexcept {
		WriteAlgoInfo(binary_searcher_);
		for (const auto time : binary_search_time_)
			results_file_ << std::fixed << std::setprecision(3) << time << " ";
		results_file_ << "\n";
		WriteLineSeparator();
	}
	void WriteJumpSearchTimeData() noexcept {
		WriteAlgoInfo(jump_searcher_);
		for (const auto time : jump_search_time_)
			results_file_ << time << " ";
		results_file_ << std::fixed << std::setprecision(3) << "\n";
		WriteLineSeparator();
	}

	void WriteInterpolationSearchTimeData() {
		WriteAlgoInfo(interpolation_searcher_);
		for (const auto time : interpolation_search_time_)
			results_file_ << time << " ";
		results_file_ << std::fixed << std::setprecision(3) << "\n";
		WriteLineSeparator();
	}

	template<class search_algorithm>
	void WriteAlgoInfo(const search_algorithm& search_algo) noexcept {
		results_file_ << "Algorithm name:" << search_algo.GetAlgorithmName() << "\n";
		results_file_ << "Algorithm complexity: " << search_algo.GetAlgorithmComplexity() << "\n";
		Write4EmptyLines();
		WriteLineSeparator();
		results_file_ << "Sorting times[us]: ";
	}

	void Write4EmptyLines() noexcept {
		results_file_ << "\n\n\n\n";
	}

	void WriteLineSeparator() noexcept {
		results_file_ << line_separator << "\n";
	}

	void CloseOutputFile() noexcept {
		results_file_.close();
		is_file_open_ = false;
	}

	std::vector<long double> linear_search_time_;
	std::vector<long double> binary_search_time_;
	std::vector<long double> jump_search_time_;
	std::vector<long double> interpolation_search_time_;

	RandomNumberGenerator<data_type> random_generator_;
	Timer timer_;
	QuickSort quick_sorter_;
	std::ofstream results_file_;
	bool is_file_open_ = false;
	
	LinearSearch linear_searcher_;
	BinarySearch binary_searcher_;
	JumpSearch jump_searcher_;
	InterpolationSearch interpolation_searcher_;

	static inline const std::string line_separator = "\n|-------------------------------------------------------------------------------------------|\n";

};