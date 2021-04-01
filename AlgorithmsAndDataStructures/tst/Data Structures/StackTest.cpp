#include "gtest/gtest.h"
#include "Data Structures/Stack.h"

class StackTest : public ::testing::Test {
protected:
	void SetUp() override {
	}

	void TearDown() override {}
};

TEST_F(StackTest, InitializingStack) {
	Stack<int> test_stack;

	EXPECT_EQ(test_stack.size(), 0);
}

TEST_F(StackTest, PushElement) {
	Stack<int> test_stack;

	test_stack.push(1);
	EXPECT_EQ(test_stack.size(), 1);

	test_stack.push(2);
	EXPECT_EQ(test_stack.size(), 2);

	test_stack.push(3);
	EXPECT_EQ(test_stack.size(), 3);

	test_stack.push(4);
	EXPECT_EQ(test_stack.size(), 4);
}

TEST_F(StackTest, PopElement) {
	Stack<int> test_stack;

	test_stack.push(1);
	test_stack.push(2);
	test_stack.push(3);
	test_stack.push(4);

	EXPECT_EQ(test_stack.size(), 4);
	EXPECT_EQ(test_stack.pop(), 4);

	EXPECT_EQ(test_stack.size(), 3);
	EXPECT_EQ(test_stack.pop(), 3);

	EXPECT_EQ(test_stack.size(), 2);
	EXPECT_EQ(test_stack.pop(), 2);

	EXPECT_EQ(test_stack.size(), 1);
	EXPECT_EQ(test_stack.pop(), 1);

	EXPECT_EQ(test_stack.size(), 0);
}


