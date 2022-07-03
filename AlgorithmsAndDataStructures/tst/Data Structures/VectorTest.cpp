#include "gtest/gtest.h"
#include "Data Structures/Vector.h"

class VectorTest : public ::testing::Test {
protected:
	void SetUp() override {
	}

	void TearDown() override {}
};

TEST_F(VectorTest, Initialization) {
	Vector<int> vec_test_int;

	EXPECT_EQ(vec_test_int.size(), std::size_t(0));
	EXPECT_EQ(vec_test_int.capacity(), std::size_t(0));
}

TEST_F(VectorTest, EmplaceBack) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);

	EXPECT_EQ(vec_test_int.size(), std::size_t(2));
	EXPECT_EQ(vec_test_int.capacity(), std::size_t(2));
}

TEST_F(VectorTest, PopBack) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);

	EXPECT_EQ(vec_test_int.pop_back(), 2);
	EXPECT_EQ(vec_test_int.pop_back(), 1);

	EXPECT_EQ(vec_test_int.size(), std::size_t(0));
}

TEST_F(VectorTest, AccessData) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);

	EXPECT_EQ(vec_test_int[0], 1);
	EXPECT_EQ(vec_test_int[1], 2);
}

TEST_F(VectorTest, ReserveMemory) {
	Vector<int> vec_test_int;

	vec_test_int.reserve(50);

	for (int i = 0; i < 10; ++i)
		vec_test_int.emplace_back(i);

	EXPECT_EQ(vec_test_int.size(), 10);
	EXPECT_EQ(vec_test_int.capacity(), 50);
}

TEST_F(VectorTest, ReserveLessThanNumberOfElements) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	vec_test_int.reserve(1);

	EXPECT_NE(vec_test_int.capacity(), 1);
}

TEST_F(VectorTest, IncreasingCapacitySize) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	EXPECT_EQ(vec_test_int.capacity(), std::size_t(1));

	vec_test_int.emplace_back(2);
	EXPECT_EQ(vec_test_int.capacity(), std::size_t(2));

	vec_test_int.emplace_back(3);
	EXPECT_EQ(vec_test_int.capacity(), std::size_t(4));
}

TEST_F(VectorTest, ClearVector) {
	Vector<int> vec_test_int;

	vec_test_int.reserve(50);
	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	vec_test_int.clear();

	EXPECT_EQ(vec_test_int.size(), 0);
	EXPECT_EQ(vec_test_int.capacity(), 0);
}

TEST_F(VectorTest, AddingElementsAfterClearing) {
	Vector<int> vec_test_int;

	vec_test_int.reserve(50);
	for (int i = 0; i < 10; ++i)
		vec_test_int.emplace_back(i);

	vec_test_int.clear();

	for (int i = 0; i < 10; ++i)
		vec_test_int.emplace_back(i);

	EXPECT_EQ(vec_test_int.size(), 10);
	EXPECT_EQ(vec_test_int.capacity(), 16);
	EXPECT_EQ(vec_test_int[5], 5);
}

TEST_F(VectorTest, AddingBigNumberOfElements) {
	Vector<int> vec_test_int;

	for (std::size_t i(0); i < 10000; ++i)
		vec_test_int.emplace_back(i);

	EXPECT_EQ(vec_test_int.size(), std::size_t(10000));
}

TEST_F(VectorTest, DereferencingIterator) {
	Vector<int> vec_test_int;

	for (std::size_t i(0); i < 100; ++i)
		vec_test_int.emplace_back(i);

	EXPECT_EQ(*vec_test_int.begin(), 0);
}

TEST_F(VectorTest, DereferencingReverseIterator) {
	Vector<int> vec_test_int;

	for (std::size_t i(0); i < 100; ++i)
		vec_test_int.emplace_back(i);

	EXPECT_EQ(*vec_test_int.rbegin(), 99);
}

TEST_F(VectorTest, SubstractingIterators) {
	Vector<int> vec_test_int;

	for (std::size_t i(0); i < 100; ++i)
		vec_test_int.emplace_back(i);

	EXPECT_EQ(vec_test_int.end() - vec_test_int.begin(), 100);
}

TEST_F(VectorTest, SubstractingReverseIterators) {
	Vector<int> vec_test_int;

	for (std::size_t i(0); i < 100; ++i)
		vec_test_int.emplace_back(i);

	EXPECT_EQ(vec_test_int.rend() - vec_test_int.rbegin(), 100);
}

TEST_F(VectorTest, IncrementingIterator) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto it = vec_test_int.begin();

	EXPECT_EQ(*it, 1);
	++it;
	EXPECT_EQ(*it, 2);
	++it;
	EXPECT_EQ(*it, 3);
}

TEST_F(VectorTest, IncrementingReverseIterator) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto reverse_it = vec_test_int.rbegin();

	EXPECT_EQ(*reverse_it, 3);
	++reverse_it;
	EXPECT_EQ(*reverse_it, 2);
	++reverse_it;
	EXPECT_EQ(*reverse_it, 1);
}

TEST_F(VectorTest, DecrementingIterator) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto it = vec_test_int.end();
	--it;
	EXPECT_EQ(*it, 3);
	--it;
	EXPECT_EQ(*it, 2);
	--it;
	EXPECT_EQ(*it, 1);
}

TEST_F(VectorTest, DecrementingReverseIterator) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto reverse_it = vec_test_int.rend();

	--reverse_it;
	EXPECT_EQ(*reverse_it, 1);
	--reverse_it;
	EXPECT_EQ(*reverse_it, 2);
	--reverse_it;
	EXPECT_EQ(*reverse_it, 3);
}

TEST_F(VectorTest, AddingIntegerToIterator) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto it = vec_test_int.begin();
	auto it1 = it + 2;
	it += 1;

	EXPECT_EQ(*it, 2);
	EXPECT_EQ(*it1, 3);
}

TEST_F(VectorTest, AddingIntegerToReverseIterator) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto reverse_it = vec_test_int.rbegin();
	auto reverse_it1 = reverse_it + 2;
	reverse_it += 1;

	EXPECT_EQ(*reverse_it, 2);
	EXPECT_EQ(*reverse_it1, 1);
}

TEST_F(VectorTest, IteratorBooleanOperatorEqual) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto it1 = vec_test_int.begin() + 2;
	auto it2 = vec_test_int.begin() + 2;
	auto it3 = vec_test_int.begin() + 3;

	EXPECT_TRUE(it1 == it2);
	EXPECT_FALSE(it2 == it3);
}

TEST_F(VectorTest, ReverseIteratorBooleanOperatorEqual) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto reverse_it1 = vec_test_int.rbegin() + 2;
	auto reverse_it2 = vec_test_int.rbegin() + 2;
	auto reverse_it3 = vec_test_int.rbegin() + 3;

	EXPECT_TRUE(reverse_it1 == reverse_it2);
	EXPECT_FALSE(reverse_it1 == reverse_it3);
}

TEST_F(VectorTest, IteratorBooleanOperatorNotEqual) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto it1 = vec_test_int.begin() + 1;
	auto it2 = vec_test_int.begin() + 2;
	auto it3 = vec_test_int.begin() + 2;

	EXPECT_TRUE(it1 != it2);
	EXPECT_FALSE(it2 != it3);
}

TEST_F(VectorTest, ReverseIteratorBooleanOperatorNotEqual) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto reverse_it1 = vec_test_int.rbegin() + 1;
	auto reverse_it2 = vec_test_int.rbegin() + 2;
	auto reverse_it3 = vec_test_int.rbegin() + 2;

	EXPECT_TRUE(reverse_it1 != reverse_it2);
	EXPECT_FALSE(reverse_it3 != reverse_it2);
}

TEST_F(VectorTest, IteratorBooleanOperatorGreater) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto it1 = vec_test_int.begin() + 1;
	auto it2 = vec_test_int.begin() + 2;

	EXPECT_TRUE(it2 > it1);
	EXPECT_FALSE(it1 > it2);
}

TEST_F(VectorTest, ReverseIteratorBooleanOperatorGreater) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto reverse_it1 = vec_test_int.rbegin() + 1;
	auto reverse_it2 = vec_test_int.rbegin() + 2;

	EXPECT_TRUE(reverse_it2 > reverse_it1);
	EXPECT_FALSE(reverse_it1 > reverse_it2);
}

TEST_F(VectorTest, IteratorBooleanOperatorGreaterOrEqual) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto it1 = vec_test_int.begin() + 1;
	auto it2 = vec_test_int.begin() + 2;
	auto it3 = vec_test_int.begin() + 2;

	EXPECT_TRUE(it2 >= it1);
	EXPECT_TRUE(it3 >= it2);
	EXPECT_FALSE(it1 >= it2);
}

TEST_F(VectorTest, ReverseIteratorBooleanOperatorGreaterOrEqual) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto reverse_it1 = vec_test_int.rbegin() + 1;
	auto reverse_it2 = vec_test_int.rbegin() + 2;
	auto reverse_it3 = vec_test_int.rbegin() + 2;

	EXPECT_TRUE(reverse_it2 >= reverse_it1);
	EXPECT_TRUE(reverse_it3 >= reverse_it2);
	EXPECT_FALSE(reverse_it1 >= reverse_it2);
}

TEST_F(VectorTest, IteratorBooleanOperatorLesser) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto it1 = vec_test_int.begin() + 1;
	auto it2 = vec_test_int.begin() + 2;

	EXPECT_TRUE(it1 < it2);
	EXPECT_FALSE(it2 < it1);
}

TEST_F(VectorTest, ReverseIteratorBooleanOperatorLesser) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto reverse_it1 = vec_test_int.rbegin() + 1;
	auto reverse_it2 = vec_test_int.rbegin() + 2;

	EXPECT_TRUE(reverse_it1 < reverse_it2);
	EXPECT_FALSE(reverse_it2 < reverse_it1);
}

TEST_F(VectorTest, IteratorBooleanOperatorLesserOrEqual) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto it1 = vec_test_int.begin() + 1;
	auto it2 = vec_test_int.begin() + 2;
	auto it3 = vec_test_int.begin() + 2;

	EXPECT_TRUE(it1 <= it2);
	EXPECT_TRUE(it2 <= it3);
	EXPECT_FALSE(it2 <= it1);
}

TEST_F(VectorTest, ReverseIteratorBooleanOperatorLesserOrEqual) {
	Vector<int> vec_test_int;

	vec_test_int.emplace_back(1);
	vec_test_int.emplace_back(2);
	vec_test_int.emplace_back(3);

	auto reverse_it1 = vec_test_int.rbegin() + 1;
	auto reverse_it2 = vec_test_int.rbegin() + 2;
	auto reverse_it3 = vec_test_int.rbegin() + 2;

	EXPECT_TRUE(reverse_it1 <= reverse_it2);
	EXPECT_TRUE(reverse_it2 <= reverse_it3);
	EXPECT_FALSE(reverse_it2 <= reverse_it1);
}