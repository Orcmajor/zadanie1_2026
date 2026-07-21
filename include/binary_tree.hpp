#pragma once

template <typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree();

    void push(const T& value);
    void pop(const T& value);
    bool search(const T& value) const;
    bool empty() const;

private:
    TreeNode<T>* root;
    TreeNode<T>* insert(TreeNode<T>* node, const T& value);
    TreeNode<T>* remove(TreeNode<T>* node, const T& value);
    bool find(TreeNode<T>* node, const T& value) const;
    void destroy(TreeNode<T>* node);
};
