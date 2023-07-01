#pragma once
#include "SearchAlgorithm.h"

class InterpolationSearch final :
	public SearchAlgorithm {

public:
	InterpolationSearch() {
		SetAlgorithmName("Interpolation Search");
		SetAlgorithmComplexity("O(N)");
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

		auto interpolation_it = GetInterpolatedIterator(begin_it, end_it, search_value);
		auto interpolation_val = *interpolation_it;

		if (AreLessThanTwoElementsLeft(begin_it, end_it))
			return interpolation_it;

		if (IsValueFound(interpolation_it, end_it, search_value))
			return interpolation_it;

		return SearchPartOfContainer(begin_it, end_it, interpolation_it, search_value);
	}

	template<class container_iterator, class container_value>
	const container_iterator GetInterpolatedIterator(const container_iterator begin_it, const container_iterator end_it,
		const container_value& search_value) const noexcept {
		auto val = GetDistanceFromBeginIterator(begin_it, end_it, search_value);
		return begin_it + GetDistanceFromBeginIterator(begin_it, end_it, search_value);
	}

	template<class container_iterator, class container_value>
	const int GetDistanceFromBeginIterator(const container_iterator begin_it, const container_iterator end_it,
		const container_value& search_value) const noexcept {
		long deviation_from_lowest = static_cast<long>(search_value) - static_cast<long>(*begin_it);
		long num_of_elements = static_cast<long>(end_it - begin_it);
		long value_range = static_cast<long>(*(end_it - 1)) - static_cast<long>(*begin_it);
		if (value_range == long(0) || deviation_from_lowest == long(0))
			return 0;
		return (((num_of_elements * deviation_from_lowest) - long(1)) / value_range);
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
	const container_iterator SearchPartOfContainer(const container_iterator begin_it, const container_iterator end_it,
		const container_iterator interpolation_it, const container_value& search_value) const noexcept {
		if (search_value < *interpolation_it)
			return GetValueIterator(begin_it, interpolation_it, search_value);
		else
			return GetValueIterator(interpolation_it + 1, end_it, search_value);
	}
};
