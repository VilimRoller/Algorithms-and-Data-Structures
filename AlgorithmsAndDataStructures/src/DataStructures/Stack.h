#pragma once
#include "Vector.h"
#include <cassert>

template <class data_type>
class Stack {

public:
	Stack() = default;
	~Stack() = default;

	Stack(const Stack& other) = default;
	Stack(Stack&& other) = default;

	Stack& operator=(const Stack& other) = default;
	Stack& operator=(Stack&& other) = default;

	void push(const data_type& element) noexcept {
		elements_.emplace_back(element);
		++size_;
	}

	const data_type pop() noexcept {
		assert(!is_empty() && "Empty stack should not be popped");
		--size_;
		return elements_[size_];
	}

	const std::size_t size() noexcept {
		return size_;
	}

	bool is_empty() noexcept {
		return size_ == std::size_t(0);
	}

private:
	std::size_t size_{ 0 };
	Vector<data_type> elements_;
};
