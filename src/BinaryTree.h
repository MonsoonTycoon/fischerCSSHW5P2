#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"
#include <iostream>
#include <stack>

using namespace std;

template<class T>
class BinaryTree : public Tree<T> {
private:
    TreeNode<T> *root;

    int height(TreeNode<T> *root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + std::max(height(root->left), height(root->right));
    }

public:
    BinaryTree() : root(nullptr) {};

    BinaryTree(std::vector<T> &array) {
        // not implemented yet
    }

    BinaryTree(TreeNode<T> *root) : root(root) {
    }

    bool contains(T val) override {
        // not implemented yet
        return false;
    }

    std::vector<T> traverseInOrder() override {
        std::vector<int> result;

        if (root == nullptr) return result;

        std::stack<TreeNode<T> *> nodeStack;
        TreeNode<T> *curr = root;

        while (curr != nullptr || !nodeStack.empty()) {
            //process left side of tree
            while (curr != nullptr) {
                nodeStack.push(curr);
                curr = curr->left;
            }

            curr = nodeStack.top();
            result.push_back(curr->val);
            nodeStack.pop();
            cout << curr->val << " ";
            //process right side of tree
            curr = curr->right;

        }
        return result;
    }

    std::vector<T> traversePreOrder() override {
        std::vector<int> result;

        if (root == nullptr) return result;

        stack<TreeNode<T> *> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {

            TreeNode<T> *node = nodeStack.top();
            result.push_back(node->val);
            printf("%d ", node->val);
            nodeStack.pop();

            // Push right and left children of the popped node to stack
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return result;
    }

    std::vector<T> traversePostOrder() override {
        // Iterative function to perform post-order traversal of the tree
        // create an empty stack and push root node
        std::vector<T> result;
        if (root == nullptr) return result;

        stack<TreeNode<T> *> nodeStack;
        nodeStack.push(root);

        // run till stack is not empty
        while (!nodeStack.empty()) {

            TreeNode<T> *curr = nodeStack.top();
            nodeStack.pop();
            result.insert(result.begin(), curr->val);

            // push left and right child of popped node to the stack
            if (curr->left)
                nodeStack.push(curr->left);

            if (curr->right)
                nodeStack.push(curr->right);
        }

      //  while (!result.empty()) {
      //      result.front() << " ";
   //         result.erase(result.begin());
       // }
        return result;
    }

    virtual ~BinaryTree() {
        // homework
    }

    T LCA(T node1, T node2) {
        // Base case
        if (root == nullptr) return -1;

        if (root->val == node1 || root->val == node2)
            return root->val;

        // Look for keys in left and right subtrees
        TreeNode<T> *left_lca = LCA( node1->left, node2);
        TreeNode<T> *right_lca = LCA( node1, node2->right);

        // If both of the above calls return Non-NULL, then one key
        // is present in once subtree and other is present in other,
        // So this node is the LCA
        if (left_lca && right_lca) return root;

        // Otherwise check if left subtree or right subtree is LCA
        return (left_lca != nullptr) ? left_lca : right_lca;
    }

    bool add(const T &) override {
        // not implemented yet
    }

    bool remove(const T &) override {
        // not implemented yet
    }

    int height() override {
        return height(root);
    }

};
