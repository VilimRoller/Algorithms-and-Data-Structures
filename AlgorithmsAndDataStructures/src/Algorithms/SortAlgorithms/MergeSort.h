#pragma once
#include "SortAlgorithm.h"

class MergeSort final : 
	public SortAlgorithm {

public:

	MergeSort() {
		SetAlgorithmInfo("Merge Sort", "O(N*logN)", "O(N*logN)", "O(N*logN)", "O(N)");
	}

	~MergeSort() = default;

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

	template <class container_it>
	Container<container_it> SortContainer(container_it begin_it, container_it end_it) const noexcept {
		auto num_of_elements = GetNumberOfContainerElements(begin_it, end_it);
		auto middle_it = GetMedianIterator(begin_it, num_of_elements);

		if (num_of_elements == 1)
			return Container<container_it>(begin_it, end_it);

		auto left_sorted_container = SortContainer(begin_it, middle_it);
		auto right_sorted_container = SortContainer(middle_it, end_it);

		auto sorted_merged_container = GetSortedMergedContainer(left_sorted_container, right_sorted_container);
		return sorted_merged_container;
	}

private:
	template <class container_it>
	Container<container_it> GetSortedMergedContainer(Container<container_it>& left_container,
													 Container<container_it>& right_container) const noexcept {
		for (auto selected_val_it = right_container.begin_it; selected_val_it != right_container.end_it; ++selected_val_it)
			InsertIterator(left_container, selected_val_it);
		
		return Container<container_it>(left_container.begin_it, right_container.end_it);
	}

	template <class container_it>
	void InsertIterator(Container<container_it>& container, container_it inserting_element_it) const noexcept {
		auto inserting_element_tmp = std::move(*inserting_element_it);
		bool insert_at_begin = true;
		ExtendContainer(container);

		auto insert_position_it = GetInsertPosition(container, inserting_element_tmp, insert_at_begin);
		InsertIntoContainer(insert_position_it, container, inserting_element_tmp, insert_at_begin);
	}

	template <class container_it, class container_value>
	container_it GetInsertPosition(Container<container_it>& container, const container_value& insert_val, 
										bool& insert_at_begin) const noexcept {

		auto selected_element_it = GetLeftAdjacentIterator(GetLastElementIter(container));

		for (; selected_element_it > container.begin_it; --selected_element_it)
			if (!ShiftToRightIfGreater(selected_element_it, insert_val, insert_at_begin)) 
				break;

		return selected_element_it;
	}

	template <class container_it, class container_value>
	void InsertIntoContainer(container_it insert_position_it, Container<container_it>& container,
							container_value& insert_val, const bool insert_at_begin) const noexcept {
		if (insert_at_begin)
			InsertAtBegin(container, insert_val);
		else
			InsertElement(GetRightAdjacentIterator(insert_position_it), insert_val);
	}

	template <class container_it>
	void ShiftElementToRight(container_it element_it) const noexcept {
		auto right_element_it = GetRightAdjacentIterator(element_it);
		*right_element_it = std::move(*element_it);
	}

	template <class container_it, class container_element> 
	const bool ShiftToRightIfGreater(container_it compared_value_it, const container_element& elem, 
									bool& insert_at_begin) const noexcept {
		insert_at_begin = elem < *compared_value_it;
		if (elem > *compared_value_it)
			return false;

		ShiftElementToRight(compared_value_it);
		return true;
	}

	template <class container_it, class container_element>
	void ShiftToRightAndInsert(container_it insert_position_it, container_element& inserting_element) const noexcept {
		ShiftElementToRight(insert_position_it);
		InsertElement(insert_position_it, inserting_element);
	}

	template <class container_it, class container_element>
	void InsertElement(container_it insert_position_it, container_element& inserting_element) const noexcept {
		*insert_position_it = std::move(inserting_element);
	}

	template <class container_it, class container_element>
	void InsertAtBegin(Container<container_it>& container, container_element& inserting_element) const noexcept {
		if (*container.begin_it > inserting_element)
			ShiftToRightAndInsert(container.begin_it, inserting_element);
		else 
			InsertElement(container.begin_it + 1, inserting_element);
	}

	template <class container_it>
	auto GetNumberOfContainerElements(container_it begin_it, container_it end_it) const noexcept {
		return end_it - begin_it;
	}

	template <class container_it>
	container_it GetMedianIterator(container_it begin_it, int num_of_elements) const noexcept {
		return begin_it + (num_of_elements / 2);
	}

	template <class container_it>
	void ExtendContainer(Container<container_it>& container) const noexcept {
		++container.end_it;
	}

	template <class container_it>
	container_it GetLastElementIter(const Container<container_it>& container) const noexcept {
		return container.end_it - 1;
	}

	template <class container_it>
	container_it GetRightAdjacentIterator(container_it iterator) const noexcept {
		return iterator + 1;
	}

	template <class container_it>
	container_it GetLeftAdjacentIterator(container_it iterator) const noexcept {
		return iterator - 1;
	}

};
