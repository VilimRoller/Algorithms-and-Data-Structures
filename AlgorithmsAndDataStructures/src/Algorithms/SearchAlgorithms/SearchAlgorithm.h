#pragma once
#include <string>

class SearchAlgorithm {
public:

	const std::string& GetAlgorithmName() const noexcept {
		return algorithm_name_;
	}

	const std::string& GetAlgorithmComplexity() const noexcept {
		return algorithm_complexity_;
	}

	void SetAlgorithmName(const std::string& name) noexcept {
		algorithm_name_ = name;
	}

	void SetAlgorithmComplexity(const std::string& complexity) noexcept {
		algorithm_complexity_ = complexity;
	}

private:
	std::string algorithm_name_;
	std::string algorithm_complexity_;
};
