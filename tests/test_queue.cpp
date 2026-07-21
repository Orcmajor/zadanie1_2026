#include <gtest/gtest.h>
#include "queue.hpp"

class QueueTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(QueueTest, PushPopTest) {
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);

    EXPECT_EQ(q.front(), 10);
    EXPECT_EQ(q.size(), 3);

    q.pop();
    EXPECT_EQ(q.front(), 20);
    EXPECT_EQ(q.size(), 2);

    q.pop();
    EXPECT_EQ(q.front(), 30);
    EXPECT_EQ(q.size(), 1);
}

TEST_F(QueueTest, EmptyTest) {
    Queue<int> q;
    EXPECT_TRUE(q.empty());

    q.push(5);
    EXPECT_FALSE(q.empty());

    q.pop();
    EXPECT_TRUE(q.empty());
}

TEST_F(QueueTest, DifferentTypesTest) {
    Queue<std::string> q;
    q.push("first");
    q.push("second");

    EXPECT_EQ(q.front(), "first");
    q.pop();
    EXPECT_EQ(q.front(), "second");
}

TEST_F(QueueTest, SizeTest) {
    Queue<double> q;
    EXPECT_EQ(q.size(), 0);

    for (int i = 0; i < 100; ++i) {
        q.push(i * 1.5);
    }
    EXPECT_EQ(q.size(), 100);
}

TEST_F(QueueTest, FIFOTest) {
    Queue<int> q;
    for (int i = 0; i < 10; ++i) {
        q.push(i);
    }

    for (int i = 0; i < 10; ++i) {
        EXPECT_EQ(q.front(), i);
        q.pop();
    }
}
