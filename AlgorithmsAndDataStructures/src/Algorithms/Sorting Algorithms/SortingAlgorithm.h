#pragma once
#include <string>
#include <iterator>
#include <algorithm>
#include <utility>
#include <vector>
#include "../AlgorithmInfo.h"
#include "../BigObject.h"

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

using vector_iterator_int = std::vector<int>::iterator;
using vector_iterator_big_obj = std::vector<BigObject<long long>>::iterator;

class SortingAlgorithm {

public:
	SortingAlgorithm() = default;

	virtual void SortVector(const vector_iterator_int begin_it, const vector_iterator_int end_it) = 0;
	virtual void SortVector(const vector_iterator_big_obj begin_it, const vector_iterator_big_obj end_it) = 0;

	void SetAlgorithmInfo(const std::string& name, const std::string& best_time_complexity,
		const std::string& avg_time_complexity, const std::string& worst_time_complexity, const std::string& space_complexity) {
		algorithm_info_ = AlgorithmInfo{ name, best_time_complexity, avg_time_complexity, worst_time_complexity, space_complexity };
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