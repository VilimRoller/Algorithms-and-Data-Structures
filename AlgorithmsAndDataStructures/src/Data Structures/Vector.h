#pragma once
#include <memory>
#include <utility>
#include <cstring>

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
	}

	void reserve(const std::size_t num_of_elements) {
		if (num_of_elements > size_)
			capacity_ = num_of_elements;
	}
	void erase();

	[[nodiscard]] const std::size_t size() const noexcept {
		return size_;
	}
	[[nodiscard]] const std::size_t capacity() const noexcept {
		return capacity_;
	}

	data_type& operator[](int index) {
		return object_handle_[index];
	}




/*--------------------------------------------------------------------------------------------------*/
/*											OPERATORS												*/
/*--------------------------------------------------------------------------------------------------*/

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
		
		for (std::size_t i{ 0 }; i < size_ - 1; ++i) 
			object_handle_tmp[i] = std::move(object_handle_[i]);
		
		object_handle_ = std::move(object_handle_tmp);
	}
	
	std::unique_ptr<data_type[]> object_handle_;
	std::size_t capacity_ = 0;
	std::size_t size_ = 0;
};