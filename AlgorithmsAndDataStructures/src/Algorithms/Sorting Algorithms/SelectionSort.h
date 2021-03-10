#pragma once

#include <string>
#include <iterator>
#include <algorithm>
#include "Algorithms/Algorithm.h"

class SelectionSort final : 
	public Algorithm {

public:
	SelectionSort() {
		SetAlgorithmInfo("Selection Sort", "O(n^2)", "O(1)");
	}

	template <class container_type>
	void SortContainer(container_type& container, const SortingType sorting_type = SortingType::Ascending) const noexcept {
		if (sorting_type == SortingType::Ascending)
			SortContainer(container.begin(), container.end());
		else
			SortContainer(container.rbegin(), container.rend());
	}

	template <class container_iterator>
	void SortContainer(container_iterator begin_it, container_iterator end_it) const noexcept {
		for (; begin_it != end_it; ++begin_it)
			PutMinValueToBegin(begin_it, end_it);
	}

private: 

	template <class container_iterator>
	void PutMinValueToBegin(container_iterator begin_it, container_iterator end_it) const noexcept {
		container_iterator min_element = std::min_element(begin_it, end_it);

		if (min_element != begin_it)
			std::iter_swap(min_element, begin_it);
	}

};