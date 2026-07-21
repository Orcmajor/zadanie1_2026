#pragma once
#include <vector>

template <typename T>
class Queue {
public:
    Queue() = default;
    ~Queue() = default;

    void push(const T& value);
    void pop();
    T& front();
    const T& front() const;
    bool empty() const;
    size_t size() const;

private:
    std::vector<T> data;
};
