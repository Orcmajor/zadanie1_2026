#include <gtest/gtest.h>
#include "heap.hpp"

class HeapTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(HeapTest, PushTopTest) {
    Heap<int> h;
    h.push(10);
    h.push(30);
    h.push(20);
    h.push(5);

    EXPECT_EQ(h.top(), 30);
    EXPECT_EQ(h.size(), 4);
}

TEST_F(HeapTest, PopTest) {
    Heap<int> h;
    h.push(10);
    h.push(30);
    h.push(20);
    h.push(5);

    EXPECT_EQ(h.top(), 30);
    h.pop();
    EXPECT_EQ(h.top(), 20);
    h.pop();
    EXPECT_EQ(h.top(), 10);
    h.pop();
    EXPECT_EQ(h.top(), 5);
}

TEST_F(HeapTest, EmptyTest) {
    Heap<int> h;
    EXPECT_TRUE(h.empty());

    h.push(42);
    EXPECT_FALSE(h.empty());

    h.pop();
    EXPECT_TRUE(h.empty());
}

TEST_F(HeapTest, NegativeNumbersTest) {
    Heap<int> h;
    h.push(-5);
    h.push(-10);
    h.push(-3);
    h.push(-1);

    EXPECT_EQ(h.top(), -1);
    h.pop();
    EXPECT_EQ(h.top(), -3);
}

TEST_F(HeapTest, LargeHeapTest) {
    Heap<int> h;
    for (int i = 0; i < 1000; ++i) {
        h.push(i);
    }

    EXPECT_EQ(h.size(), 1000);
    EXPECT_EQ(h.top(), 999);

    h.pop();
    EXPECT_EQ(h.top(), 998);
}

TEST_F(HeapTest, StringTest) {
    Heap<std::string> h;
    h.push("apple");
    h.push("zebra");
    h.push("banana");

    EXPECT_EQ(h.top(), "zebra");
}
