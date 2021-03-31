#pragma once
#include "SearchAlgorithm.h"

class BinarySearch final : 
	public SearchAlgorithm {

public:
	BinarySearch() {
		SetAlgorithmName("Binary Search");
		SetAlgorithmComplexity("O(logN)");
	}

	template<class container_iterator, class container_value>
	const container_iterator FindValue(const container_iterator begin_it, const container_iterator end_it,
		const container_value& search_value) const noexcept {

		auto result_it = GetValueIterator(begin_it, end_it, search_value);

		if (IsValueFound(result_it, end_it, search_value))
			return result_it;
		else
			return end_it;
	}

private:
	template<class container_iterator, class container_value>
	const container_iterator GetValueIterator(const container_iterator begin_it, const container_iterator end_it,
		const container_value& search_value) const noexcept {

		auto median_it = GetMedianIterator(begin_it, end_it);
		if (AreLessThanTwoElementsLeft(begin_it, end_it))
			return median_it;

		if (IsValueFound(median_it, end_it, search_value))
			return median_it;

		return SearchHalfOfContainer(begin_it, end_it, median_it, search_value);
	}

	template<class container_iterator>
	const container_iterator GetMedianIterator(const container_iterator begin_it, const container_iterator end_it) const noexcept {
		return begin_it + (end_it - begin_it) / 2;
	}

	template<class container_iterator>
	bool AreLessThanTwoElementsLeft(const container_iterator begin_it, const container_iterator end_it) const noexcept {
		return end_it - begin_it < 2;
	}

	template<class container_iterator, class container_value>
	bool IsValueFound(const container_iterator search_it, const container_iterator end_it,
		const container_value& search_value) const noexcept {
		if (search_it == end_it)
			return false;

		return *search_it == search_value;
	}

	template<class container_iterator, class container_value>
	const container_iterator SearchHalfOfContainer(const container_iterator begin_it, const container_iterator end_it,
		const container_iterator median_it, const container_value& search_value) const noexcept {
		if (*median_it > search_value)
			return GetValueIterator(begin_it, median_it, search_value);
		else
			return GetValueIterator(median_it, end_it, search_value);
	}

};
