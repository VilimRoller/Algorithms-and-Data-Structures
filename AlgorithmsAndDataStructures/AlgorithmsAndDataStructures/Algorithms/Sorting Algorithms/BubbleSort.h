#pragma once

#include <string>
#include <iterator>
#include <algorithm>
#include "Algorithms/Algorithm.h"


class BubbleSort final : public Algorithm {

public:
	BubbleSort() {
		SetAlgorithmInfo("Bubble Sort", "O(n^2)", "O(1)");
	}

	template <class container_iterator>
	void SortContainer(const container_iterator begin_it, const container_iterator end_it) const noexcept {

		for (int i = 0; i < end_it - begin_it; ++i)
			if (IterateThroughContainer(begin_it, end_it))
				break;
	}

	template <class container_iterator>
	bool IterateThroughContainer(const container_iterator begin_it, const container_iterator end_it) const noexcept {
		bool is_sorted = true;
		auto left_it = begin_it;
		auto right_it = begin_it + 1;

		for (int j = 0; j < end_it - begin_it - 1; ++j)
			if (SwapItersIfLeftGreater(left_it, right_it))
				is_sorted = false;

		return is_sorted;
	}

	template <class container_iterator>
	bool SwapItersIfLeftGreater(container_iterator& left_it, container_iterator& right_it) const noexcept {
		bool is_swap_necessary = *left_it > *right_it;

		if (is_swap_necessary)
			std::iter_swap(left_it, right_it);

		IncrementIterators(left_it, right_it);
		return is_swap_necessary;
	}
	template <class container_iterator>
	void IncrementIterators(container_iterator& left_it, container_iterator& right_it) const noexcept {
		++left_it;
		++right_it;
	}

};