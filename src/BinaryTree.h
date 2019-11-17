#pragma once

#include "Tree.h"
#include "TreeNode.h"
#include <vector>
#include "LinkedStack.h"
#include <iostream>
#include <stack>

using namespace std;
//design elements taken from
//https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
//https://www.geeksforgeeks.org/iterative-preorder-traversal/
//https://www.techiedelight.com/postorder-tree-traversal-iterative-recursive/
//in-class examples, and the book

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

            //process right side of tree
            curr = curr->right;
        }
        return result;
    }

    std::vector<T> traversePreOrder() override {}

    std::vector<T> traversePostOrder() override {
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

        return result;
    }

    virtual ~BinaryTree() {
        //first idea...this deleted the tree in pre-order when called locally, but
        //when the tree was returned through a function, gave a seg fault error
        //I'm guessing because it deletes the root but loses reference to it's children
       // if (root) delete root;
        //this idea does a preorder iterative traversal and saves the memory reference in a vector
        //then the stack is deleted
        std::vector<T> toDelete = preorderDelete( root );
        toDelete.clear(); //remove elements
        toDelete.shrink_to_fit(); // free memory
        //this is extremely ineffectient but I think it meets the HW specifications
    }
    std::vector<T> preorderDelete ( TreeNode<T> * curr){
        std::vector<int> result;

        if (root == nullptr) return result;

        stack<TreeNode<T> *> nodeStack;
        nodeStack.push(root);

        while (!nodeStack.empty()) {

            TreeNode<T> *node = nodeStack.top();
            result.push_back(node->val);
   //         printf("%d ", node->val);
            nodeStack.pop();

            // Push right and left children of the popped node to stack
            if (node->right)
                nodeStack.push(node->right);
            if (node->left)
                nodeStack.push(node->left);
        }
        return result;
    }

    T LCA(T node1, T node2) {
        if (node1 == node2) {
            return node1;
        }
        TreeNode<T>* ans = LCARecursive(node1, node2, root);
        return ans -> val;
    }

    TreeNode<T>* LCARecursive(T node1, T node2, TreeNode<T> *curr) {
        if (curr == nullptr) return nullptr;
        if (curr->val == node1 || curr->val == node2)
            return curr;

        TreeNode<T> *left_lca = LCARecursive(node1, node2, curr->left);
        TreeNode<T> *right_lca = LCARecursive(node1, node2, curr->right);

        if (left_lca && right_lca) return curr;

        return (left_lca != nullptr) ? left_lca : right_lca;
    }

    bool add(const T &)
    override {
        // not implemented yet
    }

    bool remove(const T &)
    override {
        // not implemented yet
    }

    int height()
    override {
        return height(root);
    }

};
