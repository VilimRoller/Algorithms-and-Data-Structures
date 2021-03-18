#pragma once
#include "SortingAlgorithm.h"


class HeapSort final :
	public SortingAlgorithm {

public:
	HeapSort() {
		SetAlgorithmInfo("Heap Sort", "O(N*logN)", "O(N*logN)", "O(N*logN)", "O(1)");
	}

	~HeapSort() = default;

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
	void SortContainer(const container_it begin_it, const container_it end_it) const noexcept {
		auto heap_end_it = end_it;

		while (heap_end_it > begin_it)
			HeapifyAndPopLargest(begin_it, heap_end_it);
	}

	template <class container_it>
	void HeapifyAndPopLargest(const container_it begin_it, container_it& heap_end_it) const noexcept {
		std::make_heap(begin_it, heap_end_it);
		std::pop_heap(begin_it, heap_end_it);
		--heap_end_it;
	}

};