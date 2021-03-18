#pragma once
#include <array>
#include <iostream>

constexpr const int number_of_array_elems = 99;

template<class data_type>
class BigObject {

public:
	//TODO add default move constructors

	BigObject() {
		data = static_cast<data_type>(0);
	}

	BigObject(data_type input_data) {
		data = input_data;
		unused_data_.fill(input_data);
	}

	friend std::ostream& operator<<(std::ostream& os, const BigObject& object) {
		os << object.data;
		return os;
	}

	friend bool operator> (const BigObject& left, const BigObject& right) {
		return left.data > right.data;
	}

	friend bool operator>= (const BigObject& left, const BigObject& right) {
		return left.data >= right.data;
	}

	friend bool operator< (const BigObject& left, const BigObject& right) {
		return left.data < right.data;
	}

	friend bool operator<= (const BigObject& left, const BigObject& right) {
		return left.data <= right.data;
	}

	friend bool operator== (const BigObject& left, const BigObject& right) {
		return left.data == right.data;
	}

	friend bool operator!= (const BigObject& left, const BigObject& right) {
		return left.data != right.data;
	}

	data_type data;
private:
	std::array<data_type, number_of_array_elems> unused_data_;
};