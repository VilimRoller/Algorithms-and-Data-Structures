#pragma once
#include "SearchAlgorithm.h"

class JumpSearch final :
	public SearchAlgorithm {

public:
	JumpSearch() {
		SetAlgorithmName("Jump Search");
		SetAlgorithmComplexity("O(sqrtN)");
	}

	template<class container_iterator, class container_value>
	const container_iterator FindValue(const container_iterator begin_it, const container_iterator end_it,
		const container_value& search_value, int jump_size = 2) const noexcept {
		CorrectJumpSizeIfNecessary(begin_it, end_it, jump_size);

		if (jump_size == 0)
			return end_it;

		for (auto selected_it = begin_it; selected_it <= end_it - jump_size; selected_it += jump_size) 
			if (*selected_it == search_value)
				return selected_it;
			else if (*selected_it > search_value)
				return DescendingLinearFindValue(selected_it, end_it, search_value, jump_size);
		
		auto last_jump_it = end_it - jump_size;
		return AscendingLinearFindValue(last_jump_it, end_it, search_value, jump_size);
	}

private:
	template<class container_iterator>
	void CorrectJumpSizeIfNecessary(const container_iterator begin_it, const container_iterator end_it,
		int& jump_size) const noexcept {
		auto num_of_elements = end_it - begin_it;
		if (jump_size > num_of_elements)
			jump_size = num_of_elements;
	}

	template<class container_iterator, class container_value>
	const container_iterator DescendingLinearFindValue(const container_iterator selected_it, const container_iterator end_it,
		const container_value& search_value, const int jump_size) const noexcept {
		for (int i = 1; i < jump_size; ++i)
			if (*(selected_it - i) == search_value)
				return selected_it - i;
		return end_it;
	}

	template<class container_iterator, class container_value>
	const container_iterator AscendingLinearFindValue(const container_iterator selected_it, const container_iterator end_it,
		const container_value& search_value, const int jump_size) const noexcept {
		for (int i = 1; i < jump_size; ++i)
			if (*(selected_it + i) == search_value)
				return selected_it + i;
		return end_it;
	}

};