#pragma once
#include <string>
#include <iostream>


class AlgorithmInfo {

public:

	AlgorithmInfo() = default;

	AlgorithmInfo(const std::string& algo_name, const std::string& algo_time_complex, const std::string& algo_space_complex) {
		SetName(algo_name);
		SetTimeComplexity(algo_time_complex);
		SetSpaceComplexity(algo_space_complex);
	}

	void SetName(const std::string& algo_name) noexcept {
		name_ = algo_name;
	}

	void SetTimeComplexity(const std::string& algo_time_complex) noexcept {
		time_complexity_ = algo_time_complex;
	}

	void SetSpaceComplexity(const std::string& algo_space_complex) noexcept {
		space_complexity_ = algo_space_complex;
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
		std::cout << "Algorithm time complexity: " << time_complexity_ << std::endl;
	}

	void PrintSpaceComplexity() const noexcept {
		std::cout << "Algorithm space complexity: " << space_complexity_ << std::endl;
	}

	void PrintLine() const noexcept {
		std::cout << "-----------------------------------------------------------------------" << std::endl;
	}

private:
	std::string name_;
	std::string time_complexity_;
	std::string space_complexity_;
};