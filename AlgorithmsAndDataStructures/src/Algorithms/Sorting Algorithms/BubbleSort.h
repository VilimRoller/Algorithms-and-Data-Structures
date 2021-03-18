#pragma once

#include <string>
#include <iterator>
#include <algorithm>
#include "SortingAlgorithm.h"


class BubbleSort final : 
	public SortingAlgorithm {

public:
	BubbleSort() {
		SetAlgorithmInfo("Bubble Sort", "O(N)", "O(N^2)", "O(N^2)", "O(1)");
	}

	~BubbleSort() = default;

	void SortVector(const vector_iterator_int begin_it, const vector_iterator_int end_it) override {
		SortContainer(begin_it, end_it);
	}

	void SortVector(const vector_iterator_big_obj begin_it, const vector_iterator_big_obj end_it) override {
		SortContainer(begin_it, end_it);
	}

	template <class container_type>
	void SortContainer(container_type& container, const SortingType sorting_type = SortingType::Ascending) const noexcept {
		if (sorting_type == SortingType::Ascending)
			SortContainer(container.begin(), container.end());
		else
			SortContainer(container.rbegin(), container.rend());
	}

	template <class container_iterator>
	void SortContainer(const container_iterator begin_it, const container_iterator end_it) const noexcept {
		for (int i = 0; i < end_it - begin_it; ++i)
			if (IterateThroughContainer(begin_it, end_it))
				break;
	}

private:

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