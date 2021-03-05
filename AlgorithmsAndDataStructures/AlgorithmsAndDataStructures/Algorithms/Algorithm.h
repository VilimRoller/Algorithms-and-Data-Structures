#pragma once
#include <string>
#include "AlgorithmInfo.h"

class Algorithm {

public:

	Algorithm() {}

	void SetAlgorithmInfo(const std::string& name, const std::string& time_complexity, const std::string& space_complexity) {
		algorithm_info_ = AlgorithmInfo{ name, time_complexity, space_complexity };
	}

	[[nodiscard]] const AlgorithmInfo& GetAlgorithmInfo() const noexcept {
		return algorithm_info_;
	}

	void PrintAlgorithmInfo() const noexcept {
		algorithm_info_.PrintAlgoInfo();
	}

private:
	AlgorithmInfo algorithm_info_;
};