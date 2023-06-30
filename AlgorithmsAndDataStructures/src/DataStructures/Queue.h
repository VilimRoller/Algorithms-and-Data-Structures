#pragma once
#include "Vector.h"
#include <cassert>

template <class data_type>
class Queue {

public:
	Queue() = default;
	~Queue() = default;

	Queue(const Queue& other) = default;
	Queue(Queue&& other) = default;

	Queue& operator=(const Queue& other) = default;
	Queue& operator=(Queue&& other) = default;

	void push(const data_type& element) noexcept {
		++size_;
		elements_.emplace_back(element);
	}

	data_type pop() noexcept {
		assert(!is_empty() && "Empty queue should not be popped");
		auto return_value = elements_[0];
		ShiftElementsToLeft();
		--size_;
		return return_value;
	}

	void ShiftElementsToLeft() noexcept {
		for (std::size_t i{ 0 }; i < size_ - std::size_t{ 1 }; ++i)
			elements_[i] = std::move(elements_[i+1]);
	}

	std::size_t size() const noexcept {
		return size_;
	}

	bool is_empty() const noexcept {
		return size_ == std::size_t(0);
	}

private:
	std::size_t front_{ 0 };
	std::size_t size_{ 0 };
	Vector<data_type> elements_;
};
