#pragma once
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>
#include "AlgorithmInfo.h"

template <class container_it>
struct Container {
	Container(container_it begin, container_it end) : begin_it{ begin }, end_it{ end } {}
	container_it begin_it;
	container_it end_it;
};

enum class SortingType {
	Ascending,
	Descending
};

class Algorithm {

public:
	Algorithm() = default;

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