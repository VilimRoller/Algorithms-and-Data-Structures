#pragma once
#include <memory>
#include <utility>
#include <cstring>
#include <iterator>
#include <cstddef>
#include <cassert>

template <class data_type>
class Vector {

public:
	Vector() = default;
	~Vector() = default;

	Vector(const Vector& other) = default;
	Vector(Vector&& other) = default;

	Vector& operator=(const Vector& other) = default;
	Vector& operator=(Vector&& other) = default;

	/*--------------------------------------------------------------------------------------------------*/
	/*										STANDARD UTILITIES											*/
	/*--------------------------------------------------------------------------------------------------*/

	void emplace_back(const data_type& element) noexcept {
		++size_;
		CheckCapacity();
		object_handle_[size_ - 1] = element;
	}

	const data_type pop_back() {
		--size_;
		return object_handle_[size_];
	}

	void reserve(const std::size_t num_of_elements) noexcept {
		if (num_of_elements > size_)
			reserveCapacity(num_of_elements);
	}

	void reserveCapacity(const std::size_t num_of_elements) noexcept {
		capacity_ = num_of_elements;
		ReallocateMemoryToCapacitySize();
	}

	void clear() noexcept {
		size_ = 0;
		capacity_ = 0;
		ReallocateMemoryToCapacitySize();
	}

	[[nodiscard]] const bool isEmpty() const noexcept {
		return size() == std::size_t(0);
	}

	[[nodiscard]] const std::size_t size() const noexcept {
		return size_;
	}
	[[nodiscard]] const std::size_t capacity() const noexcept {
		return capacity_;
	}

	data_type& operator[](const int index) {
		assert(index < size_ && "Index out of range");
		return object_handle_[index];
	}

private:

	void CheckCapacity() noexcept {
		if (size_ > capacity_)
			IncreaseCapacitySize();
	}

	void IncreaseCapacitySize() noexcept {
		if (capacity_ == 0)
			++capacity_;
		else
			capacity_ *= 2;

		ReallocateMemoryToCapacitySize();
	}

	void ReallocateMemoryToCapacitySize() noexcept {
		std::unique_ptr<data_type[]> object_handle_tmp = std::make_unique<data_type[]>(capacity_);
		MoveElementsToNewLocation(object_handle_tmp);
		object_handle_ = std::move(object_handle_tmp);
	}

	void MoveElementsToNewLocation(std::unique_ptr<data_type[]>& destination) noexcept {
		if (size_ > std::size_t{ 1 })
			for (std::size_t i{ 0 }; i < size_ - std::size_t{ 1 }; ++i)
				destination[i] = std::move(object_handle_[i]);
	}

	std::unique_ptr<data_type[]> object_handle_;
	std::size_t capacity_ = 0;
	std::size_t size_ = 0;

public:

	/*--------------------------------------------------------------------------------------------------*/
	/*										CONTAINER ITERATORS											*/
	/*--------------------------------------------------------------------------------------------------*/

	struct Iterator {

	private:
		data_type* iterator_ptr;

	public:
		Iterator(data_type* ptr = nullptr) : iterator_ptr{ ptr } {}
		~Iterator() = default;
		Iterator(const Iterator& other) = default;

		/*---------------------------------BASIC OPERATORS----------------------------------------*/

		data_type* GetPtr() const noexcept {
			return iterator_ptr;
		}

		data_type& operator*() const noexcept {
			return *iterator_ptr;
		}

		data_type* operator->() const noexcept {
			return iterator_ptr;
		}

		friend bool operator== (const Iterator& left, const Iterator& right) noexcept {
			return left.iterator_ptr == right.iterator_ptr;
		}

		friend bool operator != (const Iterator& left, const Iterator& right) noexcept {
			return left.iterator_ptr != right.iterator_ptr;
		}

		friend bool operator> (const Iterator& left, const Iterator& right) noexcept {
			return left.iterator_ptr > right.iterator_ptr;
		}

		friend bool operator>= (const Iterator& left, const Iterator& right) noexcept {
			return left.iterator_ptr >= right.iterator_ptr;
		}

		friend bool operator< (const Iterator& left, const Iterator& right) noexcept {
			return left.iterator_ptr < right.iterator_ptr;
		}

		friend bool operator<= (const Iterator& left, const Iterator& right) noexcept {
			return left.iterator_ptr <= right.iterator_ptr;
		}

		/*---------------------------------ARITHMETIC OPERATORS----------------------------------------*/

		Iterator& operator+=(const std::ptrdiff_t& distance) noexcept {
			iterator_ptr += distance;
			return *this;
		}

		Iterator& operator-=(const std::ptrdiff_t& distance) noexcept {
			iterator_ptr -= distance;
			return *this;
		}

		Iterator& operator++() noexcept {
			++iterator_ptr;
			return *this;
		}

		Iterator operator++(int) {
			Iterator it_tmp = *this;
			++(*this);
			return it_tmp;
		}

		Iterator& operator--() noexcept {
			--iterator_ptr;
			return *this;
		}

		Iterator operator--(int) {
			Iterator it_tmp = *this;
			--(*this);
			return it_tmp;
		}

		Iterator operator+(const std::ptrdiff_t& distance) const noexcept {
			auto tmp_it = *this;
			tmp_it += distance;
			return tmp_it;
		}

		Iterator operator-(const std::ptrdiff_t& distance) const noexcept {
			auto tmp_it = *this;
			tmp_it -= distance;
			return tmp_it;
		}

		std::ptrdiff_t operator-(const Iterator& other) noexcept {
			return std::distance(other.GetPtr(), this->GetPtr());
		}
	};

	struct ReverseIterator {

	private:
		data_type* iterator_ptr;

	public:
	ReverseIterator(data_type* ptr = nullptr) : iterator_ptr{ ptr } {}
	~ReverseIterator() = default;
	ReverseIterator(const ReverseIterator& other) = default;

	/*---------------------------------BASIC OPERATORS----------------------------------------*/

	data_type* GetPtr() const noexcept {
		return iterator_ptr;
	}

	data_type& operator*() const noexcept {
		return *iterator_ptr;
	}

	data_type* operator->() const noexcept {
		return iterator_ptr;
	}

	friend bool operator== (const ReverseIterator& left, const ReverseIterator& right) noexcept {
		return right.iterator_ptr == left.iterator_ptr;
	}

	friend bool operator != (const ReverseIterator& left, const ReverseIterator& right) noexcept {
		return right.iterator_ptr != left.iterator_ptr;
	}

	friend bool operator> (const ReverseIterator& left, const ReverseIterator& right) noexcept {
		return right.iterator_ptr > left.iterator_ptr;
	}

	friend bool operator>= (const ReverseIterator& left, const ReverseIterator& right) noexcept {
		return right.iterator_ptr >= left.iterator_ptr;
	}

	friend bool operator< (const ReverseIterator& left, const ReverseIterator& right) noexcept {
		return right.iterator_ptr < left.iterator_ptr;
	}

	friend bool operator<= (const ReverseIterator& left, const ReverseIterator& right) noexcept {
		return right.iterator_ptr <= left.iterator_ptr;
	}

	/*---------------------------------ARITHMETIC OPERATORS----------------------------------------*/

	ReverseIterator& operator+=(const std::ptrdiff_t& distance) noexcept {
		iterator_ptr -= distance;
		return *this;
	}

	ReverseIterator& operator-=(const std::ptrdiff_t& distance) noexcept {
		iterator_ptr += distance;
		return *this;
	}

	ReverseIterator& operator++() noexcept {
		--iterator_ptr;
		return *this;
	}

	ReverseIterator operator++(int) {
		ReverseIterator it_tmp = *this;
		--(*this);
		return it_tmp;
	}

	ReverseIterator& operator--() noexcept {
		++iterator_ptr;
		return *this;
	}

	ReverseIterator operator--(int) {
		ReverseIterator it_tmp = *this;
		++(*this);
		return it_tmp;
	}

	ReverseIterator operator+(const std::ptrdiff_t& distance) const noexcept {
		auto tmp_it = *this;
		tmp_it += distance;
		return tmp_it;
	}

	ReverseIterator operator-(const std::ptrdiff_t& distance) const noexcept {
		auto tmp_it = *this;
		tmp_it -= distance;
		return tmp_it;
	}

	std::ptrdiff_t operator-(const ReverseIterator& other) noexcept {
		return std::distance(this->GetPtr(), other.GetPtr());
	}
};

	Iterator begin() {
		return Iterator(&object_handle_[0]);
	}

	Iterator end() {
		return Iterator(&object_handle_[size_]);
	}

	ReverseIterator rbegin() {
		return ReverseIterator(&object_handle_[size_-1]);
	}

	ReverseIterator rend() {
		return ReverseIterator(&object_handle_[-1]);
	}
};
