#pragma once
#include "SearchAlgorithm.h"

class LinearSearch final : 
	public SearchAlgorithm {

public:
	LinearSearch() {
		SetAlgorithmName("Linear Search");
		SetAlgorithmComplexity("O(N)");
	}

	template<class container_iterator, class container_value>
	const container_iterator FindValue(const container_iterator begin_it, const container_iterator end_it,
		const container_value& search_value) const noexcept {
		for (auto select_it = begin_it; select_it != end_it; ++select_it)
			if (*select_it == search_value)
				return select_it;
		return end_it;
	}

};