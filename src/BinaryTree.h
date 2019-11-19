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
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode<T> *> nodeStack;
        TreeNode<T> *curr = root;
        while ( curr || !nodeStack.empty()) {
            while ( curr ) {
                nodeStack.push(curr);
                curr = curr->left;
            }
            curr = nodeStack.top();
            result.push_back(curr->val);
            nodeStack.pop();
            curr = curr->right;
        }
        return result;
    }

    std::vector<T> traversePreOrder() override {}

    std::vector<T> traversePostOrder() override {
        std::vector<T> result;
        if (root == nullptr) return result;
        std::stack<TreeNode<T> *> nodeStack;
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            TreeNode<T> *curr = nodeStack.top();
            nodeStack.pop();
            //ends up last
            result.insert(result.begin(), curr->val);
            // push left then right child to stack
            if (curr->left)
                nodeStack.push(curr->left);
            if (curr->right)
                nodeStack.push(curr->right);
        }
        return result;
    }

    virtual ~BinaryTree() {
//        destroy ( root );
        //this is post order, but for now its as close as i can get. calls the node destructor.
//        delete root;
        //first try...this deleted the tree in pre-order when called locally, but
        //when the tree was returned through a function, gave a seg fault error
        //I'm guessing because it deletes the root but loses reference to it's children
        // if (root) delete root;
  //     preorderDelete ( root );
        //this idea might do a preorder iterative traversal and saves the memory reference in a vector
        //then the stack is deleted
        //std::vector<T>* toDelete = preorderDelete(root);
        //toDelete->clear(); //remove elements
        //toDelete->shrink_to_fit(); // free memory
        //this is extremely ineffectient but I think it meets the HW specifications

        destroyPost ( root );
    }
    void destroyPost ( TreeNode<T> *& curr){
        if ( curr ){
            destroyPost ( curr-> left );
            destroyPost ( curr->right );
            delete curr;
        }
    }
    /*
    void destroy ( TreeNode<T> *& curr){
    if ( curr ) {
        stack<TreeNode<T> *> holdThis;
        holdThis.push ( curr );
        while ( !holdThis.empty()){
            TreeNode<T> *ptr = holdThis.top();
            delete curr;
            if ( ptr-> right ){ holdThis.push ( ptr-> right); }
            if ( ptr -> left ){ holdThis.push ( ptr->left ); }
        }
    }
    }


    void preorderDelete(TreeNode<T> *curr) {
        if (curr) {
            stack<TreeNode<T> *> nodeStack;
            TreeNode<T> *ptr = curr;
            nodeStack.push(curr);
            while (!nodeStack.empty()) {
                TreeNode<T> *node = nodeStack.top();
                //       delete node;
                //  result->push_back(node->val);
                //         printf("%d ", node->val);
                nodeStack.pop();
                if (node->right)
                    nodeStack.push(node->right);
                if (node->left)
                    nodeStack.push(node->left);
            }
        }
    }
    */
    T LCA(T node1, T node2) {
        if (node1 == node2) {
            return node1;
        }
        TreeNode<T> *ans = LCARecursive(node1, node2, root);
        return ans->val;
    }

    TreeNode<T> *LCARecursive(T node1, T node2, TreeNode<T> *curr) {
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
