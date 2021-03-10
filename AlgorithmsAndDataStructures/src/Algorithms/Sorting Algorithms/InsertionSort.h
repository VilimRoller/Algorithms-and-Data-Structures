#pragma once

#include <string>
#include <iterator>
#include <algorithm>
#include "Algorithms/Algorithm.h"


class InsertionSort final : 
	public Algorithm {

public:
	InsertionSort() {
		SetAlgorithmInfo("Insertion Sort", "O(n^2)", "O(1)");
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

		for (auto selected_element_it = begin_it + 1; selected_element_it != end_it; ++selected_element_it)
			SortElement(selected_element_it, begin_it, end_it);
	}

private:

	template <class container_iterator>
	void SortElement(const container_iterator selected_element_it, 
					 const container_iterator begin_it, const container_iterator end_it) const noexcept {
		auto insert_position_it = GetPositionToInsert(selected_element_it, begin_it, end_it);

		if (selected_element_it != insert_position_it)
			InsertElementIntoContainer(insert_position_it, selected_element_it, begin_it, end_it);
	}

	template <class container_iterator>
	container_iterator GetPositionToInsert(	const container_iterator selected_element_it, 
											const container_iterator begin_it, const container_iterator end_it) const noexcept {
		auto compared_element_it = begin_it;
		while (!IsPositionToInsertFound(selected_element_it, compared_element_it, begin_it))
			++compared_element_it;

		return compared_element_it;
	}

	template <class container_iterator>
	bool IsPositionToInsertFound(const container_iterator selected_element_it, const container_iterator compared_element_it,
								 const container_iterator begin_it) const noexcept {
		return (*compared_element_it > *selected_element_it) || (compared_element_it == selected_element_it);
	}

	template <class container_iterator>
	void InsertElementIntoContainer(container_iterator insert_position_it, container_iterator value_to_insert_it,
									const container_iterator begin_it, const container_iterator end_it) const noexcept {

		auto value_to_insert_tmp = std::move(*value_to_insert_it);

		for (; value_to_insert_it != insert_position_it; --value_to_insert_it) 
			*value_to_insert_it = std::move(*(value_to_insert_it - 1));

		*insert_position_it = std::move(value_to_insert_tmp);
	}
};