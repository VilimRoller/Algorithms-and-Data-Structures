#pragma once
#include "SortAlgorithm.h"

class ShellSort final :
	public SortAlgorithm {

public:
	ShellSort() {
		SetAlgorithmInfo("Shell Sort", "O(N*logN)", "O(N*logN)", "O(N^2)", "O(1)");
	}

	~ShellSort() = default;

	void SortVector(vector_iterator_int begin_it, vector_iterator_int end_it) override {
		SortContainer(begin_it, end_it);
	}

	void SortVector(vector_iterator_big_obj begin_it, vector_iterator_big_obj end_it) override {
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
	void SortContainer(container_iterator begin_it, container_iterator end_it) const noexcept {
		auto container = Container<container_iterator>(begin_it, end_it);
		int gap = GetInitialGap(container);

		for (; gap > 0; gap /= 2)
			IterateThroughElementsDistancedByGap(container, gap);
	}
private:
	template <class container_iterator>
	const int GetInitialGap(const Container<container_iterator>& container) const noexcept {
		return (container.end_it - container.begin_it) / 2;
	}

	template <class container_iterator>
	void IterateThroughElementsDistancedByGap(const Container<container_iterator>& container, const int gap) const noexcept {
		for (auto it = container.begin_it; it < container.end_it - gap; ++it)
			MakeIterSwaps(it, gap, container.begin_it);
	}

	template <class container_iterator>
	void MakeIterSwaps(container_iterator iterator, int gap, container_iterator begin_it) const noexcept {
		auto it = iterator;
		for (; it >= begin_it + gap; it -= gap)
			if (!SwapIfLeftGreater(it, it + gap))
				break;
		
		SwapIfLeftGreater(it, it + gap);
	}

	template <class container_iterator>
	bool SwapIfLeftGreater(container_iterator left_it, container_iterator right_it) const noexcept {
		bool is_swap_successful = true;
		if (*left_it > *right_it)
			std::iter_swap(left_it, right_it);
		else
			is_swap_successful = false;

		return is_swap_successful;
	}

};
