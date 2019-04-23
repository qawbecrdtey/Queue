#ifndef QUEUE_QUEUE_HPP
#define QUEUE_QUEUE_HPP

#include <cstdio>
#include <cstdlib>
#include <exception>
#include <memory>
#include <iostream>

template <typename T>
class Queue {
    struct Node {
        T data;
        Node *next;
    };
    Node *head;
    Node *tail;
    std::size_t _size;

public:
    Queue() : _size(0), head(new Node()), tail(new Node()) {
        head->next = nullptr;
        tail->next = head;
    }

    ~Queue() {
        clear();
        delete head;
        delete tail;
    }

    [[deprecated]]
    T const &back() const {
        return tail->next->data;
    }
    [[deprecated]]
    T back() {
        return tail->next->data;
    }

    void clear() {
        while(tail->next != head) {
            auto it = head;
            head = head->next;
            delete it;
        }
        _size = 0;
    }

    constexpr bool empty() { return _size > 0; }

    void push(T const &element) {
        auto node = new Node();
        node->data = element;
        node->next = nullptr;
        tail->next->next = node;
        tail->next = node;
    }
    void push(T &&element) noexcept {
        auto node = new Node();
        node->data = std::move(element);
        node->next = nullptr;
        tail->next->next = node;
        tail->next = node;
    }

    void pop() {
        auto it = head;
        head = head->next;
        delete it;
    }

    constexpr std::size_t size() const {
        return _size;
    }

    void swap(Queue &queue) {
        std::swap(head, queue.head);
        std::swap(tail, queue.tail);
        std::swap(_size, queue._size);
    }

    T const &front() const {
        return head->next->data;
    }
    T front() {
        return head->next->data;
    }
};


#endif