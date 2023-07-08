#include "gtest/gtest.h"
#include "../../src/DataStructures/LinkedListNode.h"

class LinkedListNodeTest : public ::testing::Test {
protected:
	void SetUp() override {
	}

	void TearDown() override {}
};

TEST_F(LinkedListNodeTest, CreateNewNode) {
    int value = 10;
    auto newNode = LinkedListNode<int>::createNewNode(value);

    EXPECT_EQ(newNode->data, value);
    EXPECT_EQ(newNode->next, nullptr);
}

TEST_F(LinkedListNodeTest, Insert) {
    auto testNode = LinkedListNode<int>::createNewNode(1);
    testNode->insert(3);
    testNode->insert(2);
    
    EXPECT_EQ(testNode->data, 1);
    EXPECT_EQ(testNode->next->data, 2);
    EXPECT_EQ(testNode->next->next->data, 3);
    EXPECT_EQ(testNode->next->next->next, nullptr);
}

TEST_F(LinkedListNodeTest, InsertAtEnd) {
    auto testNode = LinkedListNode<int>::createNewNode(1);
    testNode->insertAtEnd(2);
    testNode->insertAtEnd(3);

    EXPECT_EQ(testNode->data, 1);
    EXPECT_EQ(testNode->next->data, 2);
    EXPECT_EQ(testNode->next->next->data, 3);
    EXPECT_EQ(testNode->next->next->next, nullptr);
}

TEST_F(LinkedListNodeTest, ReverseList) {
    auto testNode = LinkedListNode<int>::createNewNode(1);
    testNode->insertAtEnd(2)->insertAtEnd(3)->insertAtEnd(4);

    auto reversed = LinkedListNode<int>::reverseList(testNode);

    EXPECT_EQ(reversed->data, 4);
    EXPECT_EQ(reversed->next->data, 3);
    EXPECT_EQ(reversed->next->next->data, 2);
    EXPECT_EQ(reversed->next->next->next->data, 1);
    EXPECT_EQ(reversed->next->next->next->next, nullptr);
}

TEST_F(LinkedListNodeTest, HasCycle) {
    auto testNode = LinkedListNode<int>::createNewNode(1);
    testNode->insertAtEnd(2)->insertAtEnd(3)->insertAtEnd(4);

    EXPECT_FALSE(testNode->hasCycle());
}

TEST_F(LinkedListNodeTest, HasNotCycle) {
    auto testNode = LinkedListNode<int>::createNewNode(1);
    auto lastNode = testNode->insertAtEnd(2)->insertAtEnd(3)->insertAtEnd(4);
    lastNode->next = testNode;

    EXPECT_TRUE(testNode->hasCycle());
}

TEST_F(LinkedListNodeTest, Iterator) {
    auto testNode = LinkedListNode<int>::createNewNode(1);
    testNode->insertAtEnd(2)->insertAtEnd(3)->insertAtEnd(4);

    int sum = 0;
    for (const auto& node : *testNode) {
        sum += node;
    }

    EXPECT_EQ(sum, 10);
}
