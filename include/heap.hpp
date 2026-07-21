#pragma once
#include <vector>

template <typename T>
class Heap {
public:
    Heap() = default;
    ~Heap() = default;

    void push(const T& value);
    void pop();
    T& top();
    const T& top() const;
    bool empty() const;
    size_t size() const;

private:
    std::vector<T> data;
    void heapifyUp(size_t index);
    void heapifyDown(size_t index);
};
