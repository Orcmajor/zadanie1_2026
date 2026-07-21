#include <gtest/gtest.h>
#include "binary_tree.hpp"

class BinaryTreeTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(BinaryTreeTest, PushSearchTest) {
    BinaryTree<int> tree;
    tree.push(50);
    tree.push(30);
    tree.push(70);
    tree.push(20);
    tree.push(40);
    tree.push(60);
    tree.push(80);

    EXPECT_TRUE(tree.search(50));
    EXPECT_TRUE(tree.search(20));
    EXPECT_TRUE(tree.search(80));
    EXPECT_FALSE(tree.search(100));
    EXPECT_FALSE(tree.search(0));
}

TEST_F(BinaryTreeTest, PopLeafTest) {
    BinaryTree<int> tree;
    tree.push(50);
    tree.push(30);
    tree.push(70);

    tree.pop(30);
    EXPECT_FALSE(tree.search(30));
    EXPECT_TRUE(tree.search(50));
    EXPECT_TRUE(tree.search(70));
}

TEST_F(BinaryTreeTest, PopOneChildTest) {
    BinaryTree<int> tree;
    tree.push(50);
    tree.push(30);
    tree.push(20);

    tree.pop(30);
    EXPECT_FALSE(tree.search(30));
    EXPECT_TRUE(tree.search(20));
    EXPECT_TRUE(tree.search(50));
}

TEST_F(BinaryTreeTest, PopTwoChildrenTest) {
    BinaryTree<int> tree;
    tree.push(50);
    tree.push(30);
    tree.push(70);
    tree.push(20);
    tree.push(40);
    tree.push(60);
    tree.push(80);

    tree.pop(50);
    EXPECT_FALSE(tree.search(50));
    EXPECT_TRUE(tree.search(30));
    EXPECT_TRUE(tree.search(70));
    EXPECT_TRUE(tree.search(20));
    EXPECT_TRUE(tree.search(40));
    EXPECT_TRUE(tree.search(60));
    EXPECT_TRUE(tree.search(80));
}

TEST_F(BinaryTreeTest, EmptyTest) {
    BinaryTree<int> tree;
    EXPECT_TRUE(tree.empty());

    tree.push(10);
    EXPECT_FALSE(tree.empty());
}

TEST_F(BinaryTreeTest, StringTest) {
    BinaryTree<std::string> tree;
    tree.push("cat");
    tree.push("apple");
    tree.push("zebra");

    EXPECT_TRUE(tree.search("cat"));
    EXPECT_TRUE(tree.search("apple"));
    EXPECT_TRUE(tree.search("zebra"));
    EXPECT_FALSE(tree.search("dog"));

    tree.pop("apple");
    EXPECT_FALSE(tree.search("apple"));
}
