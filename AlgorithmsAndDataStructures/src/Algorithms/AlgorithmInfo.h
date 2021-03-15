#pragma once
#include <string>
#include <iostream>


class AlgorithmInfo {

public:

	AlgorithmInfo() = default;

	AlgorithmInfo(	const std::string& algo_name, const std::string& algo_time_best, const std::string& algo_time_avg,
					const std::string& algo_time_worst, const std::string& algo_space_complex) {
		SetName(algo_name);
		SetBestTimeComplexity(algo_time_best);
		SetAverageTimeComplexity(algo_time_avg);
		SetWorstTimeComplexity(algo_time_worst);
		SetSpaceComplexity(algo_space_complex);
	}

	void SetName(const std::string& algo_name) noexcept {
		name_ = algo_name;
	}

	void SetBestTimeComplexity(const std::string& algo_time_complex) noexcept {
		time_complexity_best_ = algo_time_complex;
	}

	void SetAverageTimeComplexity(const std::string& algo_time_complex) noexcept {
		time_complexity_average_ = algo_time_complex;
	}

	void SetWorstTimeComplexity(const std::string& algo_time_complex) noexcept {
		time_complexity_worst_ = algo_time_complex;
	}

	void SetSpaceComplexity(const std::string& algo_space_complex) noexcept {
		space_complexity_ = algo_space_complex;
	}

	[[nodiscard]] const std::string& GetName() const noexcept {
		return name_;
	}

	[[nodiscard]] const std::string& GetBestTimeComplexity() const noexcept {
		return time_complexity_best_;
	}

	[[nodiscard]] const std::string& GetAverageTimeComplexity() const noexcept {
		return time_complexity_average_;
	}

	[[nodiscard]] const std::string& GetWorstTimeComplexity() const noexcept {
		return time_complexity_worst_;
	}

	[[nodiscard]] const std::string& GetSpaceComplexity() const noexcept {
		return space_complexity_;
	}

	void PrintAlgoInfo() const noexcept {
		PrintLine();
		PrintName();
		PrintTimeComplexity();
		PrintSpaceComplexity();
		PrintLine();
	}

	void PrintName() const noexcept {
		std::cout << "Algorithm name: " << name_ << std::endl;
	}

	void PrintTimeComplexity() const noexcept {
		PrintBestTimeComplexity();
		PrintAverageTimeComplexity();
		PrintWorstTimeComplexity();
	}

	void PrintBestTimeComplexity() const noexcept {
		std::cout << "Algorithm best case time complexity: " << time_complexity_best_ << std::endl;
	}

	void PrintAverageTimeComplexity() const noexcept {
		std::cout << "Algorithm average case time complexity: " << time_complexity_average_ << std::endl;
	}

	void PrintWorstTimeComplexity() const noexcept {
		std::cout << "Algorithm worst case time complexity: " << time_complexity_worst_ << std::endl;
	}

	void PrintSpaceComplexity() const noexcept {
		std::cout << "Algorithm auxiliary space complexity: " << space_complexity_ << std::endl;
	}

	void PrintLine() const noexcept {
		std::cout << "-----------------------------------------------------------------------" << std::endl;
	}

private:
	std::string name_;
	std::string time_complexity_best_;
	std::string time_complexity_average_;
	std::string time_complexity_worst_;
	std::string space_complexity_;
};