#pragma once
#include "Algorithms/Algorithm.h"


class QuickSort final : 
	public Algorithm {

public:
	QuickSort() {
		SetAlgorithmInfo("Quick Sort", "O(n*logn)", "O(n)");
	}

	template <class container_type>
	void SortContainer(container_type& container, const SortingType sorting_type = SortingType::Ascending) const noexcept {
		if (sorting_type == SortingType::Ascending)
			SortContainer(container.begin(), container.end());
		else
			SortContainer(container.rbegin(), container.rend());
	}

	template <class container_it>
	void SortContainer(const container_it begin_it, const container_it end_it) const noexcept {
		if (CheckIfEndOfRecursion(begin_it, end_it))
			return;

		PutPivotAtEndOfContainer(begin_it, end_it);
		auto pivot_it = GetPivotAfterSortAround(begin_it, end_it);

		SortContainer(begin_it, pivot_it);
		SortContainer(pivot_it , end_it);
	}

private: 
	template <class container_it>
	container_it GetPivotAfterSortAround(const container_it begin_it, const container_it end_it) const noexcept {
		auto sortable_container = Container<container_it>(begin_it, end_it - 1 );
		auto left_it = begin_it;
		auto right_it = sortable_container.end_it - 1;

		while (right_it >= left_it) 
			if (!SwapFirstLeftAndRight(left_it, right_it, sortable_container))
				break;

		return GetPivotReturnedToRightPlace(left_it, end_it - 1);
	}
	
	template <class container_it>
	bool SwapFirstLeftAndRight(container_it& left_it, container_it& right_it, 
								const Container<container_it>& container) const noexcept {
		bool find_left = SetFirstLargerFromLeft(left_it, right_it, container.end_it);
		bool find_right = SetFirstSmallerFromRight(left_it, right_it, container);

		if (!find_left || !find_right)
			return false;

		std::iter_swap(left_it, right_it);
		return true;
	}

	template <class container_it>
	bool CheckIfEndOfRecursion(const container_it begin_it, const container_it end_it) const noexcept {
		auto num_of_elements = GetNumberOfContainerElements(begin_it, end_it);
		if (num_of_elements < 2)
			return true;

		if (num_of_elements == 2)
			return SortTwoElements(begin_it, end_it);

		return false;
	}

	template <class container_it>
	bool SortTwoElements(const container_it begin_it, const container_it end_it) const noexcept {
		if (*begin_it > *(end_it - 1))
			std::iter_swap(begin_it, end_it - 1);
		return true;
	}

	template <class container_it>
	void PutPivotAtEndOfContainer(const container_it begin_it, const container_it end_it) const noexcept {
		auto pivot_it = GetPivotIterator(begin_it, end_it);
		auto last_element_it = end_it - 1;

		std::iter_swap(pivot_it, last_element_it);
	}

	template <class container_it>
	container_it GetPivotReturnedToRightPlace(const container_it first_bigger_element_it, const container_it last_element_it) const noexcept {
		std::iter_swap(first_bigger_element_it, last_element_it);
		return first_bigger_element_it;
	}

	template <class container_it>
	auto GetNumberOfContainerElements(container_it begin_it, container_it end_it) const noexcept {
		return end_it - begin_it;
	}

	template <class container_it>
	container_it GetPivotIterator(const container_it begin_it, const container_it end_it) const noexcept {
		auto num_of_elements = GetNumberOfContainerElements(begin_it, end_it);
		return begin_it + (num_of_elements / 2);
	}

	template <class container_it>
	bool SetFirstLargerFromLeft(container_it& left_it, container_it& right_it, container_it last_element_it) const noexcept {
		for (; left_it < last_element_it && IsRightIterBigger(left_it, right_it); ++left_it)
			if (*left_it > *last_element_it)
				return true;
		return false;
	}

	template <class container_it>
	bool SetFirstSmallerFromRight(container_it& left_it, container_it& right_it,
								const Container<container_it> container) const noexcept {
		for (; right_it > container.begin_it && IsRightIterBigger(left_it, right_it); --right_it)
			if (*right_it < *container.end_it)
				return true;
		return false;
	}

	template <class container_it>
	bool IsRightIterBigger(container_it left_it, container_it right_it) const noexcept {
		return left_it <= right_it;
	}

};