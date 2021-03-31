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

	EXPECT_EQ(vec_test_int.size(), 0);
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

TEST_F(VectorTest, AddingBigNumberOfElements) {
	Vector<int> vec_test_int;

	for (std::size_t i(0); i < 10000; ++i)
		vec_test_int.emplace_back(i);

	EXPECT_EQ(vec_test_int.size(), std::size_t(10000));
}