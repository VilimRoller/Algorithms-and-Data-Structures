#pragma once

#include <memory>
#include <utility>

template <class data_type>
class LinkedListNode {
using NodePtr = std::shared_ptr<LinkedListNode<data_type>>;

public:
	LinkedListNode() = default;
    LinkedListNode(const data_type& inputData) : data{inputData} {}
	~LinkedListNode() = default;
	LinkedListNode(const LinkedListNode& other) = default;
	LinkedListNode(LinkedListNode&& other) = default;

    [[nodiscard]] static NodePtr createNewNode(const data_type& inputData) noexcept {
        return std::make_shared<LinkedListNode<data_type>>(inputData);
    }

    static NodePtr getLastNode(NodePtr head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        while (head->next != nullptr) {
            head = head->next;
        }

        return head;
    }

    [[maybe_unused]] static NodePtr reverseList(NodePtr head) noexcept {
        if (head == nullptr || head->next == nullptr || head->hasCycle()) {
            return head;
        }

        NodePtr previous;
        auto current = head;
        auto next = head->next;

        while (current != nullptr) {
            next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        return previous;
    }

    [[nodiscard]] bool hasCycle() const noexcept {
        if (next == nullptr || next->next == nullptr) {
            return false;
        }

        auto slow = next;
        auto fast = slow->next;

        while ((fast != nullptr) and (fast->next != nullptr)) {
            if (slow == fast) {
                return true;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow == fast;
    }

    [[maybe_unused]] NodePtr insert(NodePtr&& node) noexcept {
        auto next_node = next;
        next = node;
        node->next = next_node;

        return next;
    }

    [[maybe_unused]] NodePtr insert(const data_type& value) noexcept {
        return insert(createNewNode(value));
    }

     [[maybe_unused]] NodePtr insertAtEnd(NodePtr&& node) noexcept {
        if (next == nullptr) {
            return insert(std::move(node));
        }
        return getLastNode(next)->insert(std::move(node));
    }

     [[maybe_unused]] NodePtr insertAtEnd(const data_type& value) noexcept {
        return insertAtEnd(createNewNode(value));
    }


    //Iterator

    struct Iterator {
    private: 
        LinkedListNode<data_type>* iterator_ptr;

    public:
        explicit Iterator(LinkedListNode<data_type>* ptr = nullptr) : iterator_ptr{ ptr } {}
        ~Iterator() = default;
        Iterator(const Iterator& other) = default;

        data_type& operator*() const {
            return iterator_ptr->data;
        }

        data_type* operator->() const {
            return &(iterator_ptr->data);
        }

        Iterator& operator++() {
            if (iterator_ptr != nullptr) {
                iterator_ptr = iterator_ptr->next.get();
            }
            return *this;
        }

        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        friend bool operator==(const Iterator& left, const Iterator& right) {
            return left.iterator_ptr == right.iterator_ptr;
        }

        friend bool operator!=(const Iterator& left, const Iterator& right) {
            return !(left == right);
        }
    };

    Iterator begin() {
        return Iterator(this);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    data_type data;
    NodePtr next;
};
