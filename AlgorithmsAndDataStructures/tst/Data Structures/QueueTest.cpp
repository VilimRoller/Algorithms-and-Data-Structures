#include "gtest/gtest.h"
#include "Data Structures/Queue.h"

class QueueTest : public ::testing::Test {
protected:
	void SetUp() override {
	}

	void TearDown() override {}
};

TEST_F(QueueTest, InitializingQueue) {
	Queue<int> test_queue;

	EXPECT_EQ(test_queue.size(), 0);
}

TEST_F(QueueTest, PushElement) {
	Queue<int> test_queue;

	test_queue.push(1);
	EXPECT_EQ(test_queue.size(), 1);

	test_queue.push(2);
	EXPECT_EQ(test_queue.size(), 2);

	test_queue.push(3);
	EXPECT_EQ(test_queue.size(), 3);
}

TEST_F(QueueTest, PopElement) {
	Queue<int> test_queue;
	test_queue.push(1);
	test_queue.push(2);
	test_queue.push(3);

	EXPECT_EQ(test_queue.size(), 3);
	EXPECT_EQ(test_queue.pop(), 1);

	EXPECT_EQ(test_queue.size(), 2);
	EXPECT_EQ(test_queue.pop(), 2);

	EXPECT_EQ(test_queue.size(), 1);
	EXPECT_EQ(test_queue.pop(), 3);

	EXPECT_EQ(test_queue.size(), 0);
}

TEST_F(QueueTest, IsQueueEmpty) {
	Queue<int> test_queue;

	EXPECT_TRUE(test_queue.is_empty());
	test_queue.push(1);
	EXPECT_FALSE(test_queue.is_empty());
	test_queue.pop();
	EXPECT_TRUE(test_queue.is_empty());
}