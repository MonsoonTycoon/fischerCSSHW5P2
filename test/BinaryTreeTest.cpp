#include "BinaryTree.h"
#include "gtest/gtest.h"


TEST(tree, demo) {
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(5));

    BinaryTree<int> tree(root);

    ASSERT_EQ(tree.height(),3);
}

TEST(tree, destructorMultipleEles){
//Testing destructor:
    // running valgrind on the program and ensuring there are no memory leaks is one way to test the destructor is working.
    // an idea is to try and print or access the memory that is supposedly deleted, but ive been told (by a friend) this is not possible in C++.
    // calling delete on an object that should already be deleted, and gauging the computer's response is another idea
    // while completing this homework I have many problems with the destructor being called upon local scope terminating
    // when local scope terminated the destructor was called on some objects which forced me to understand in much
    //more detail how memory is allocated. writing a new constructor, and having a program that compiles
    //with no memory leaks is a strong test but not a test that is written with any sort of boolean return to the user.
    
};
TEST(tree, inorderNull){
    TreeNode<int>* root = nullptr;

    BinaryTree<int> tree(root);
    EXPECT_NO_FATAL_FAILURE( tree.traverseInOrder() );
};
TEST(tree, inorderSingle){
    TreeNode<int>* root = new TreeNode<int>(3);

    BinaryTree<int> tree(root);
    std::vector<int> testTree = tree.traverseInOrder();
    std::vector<int> testAns = { 3 };
    EXPECT_EQ( testTree, testAns );
};
TEST(tree, inorderTwoNodes){
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));

    BinaryTree<int> tree(root);
    tree.traverseInOrder();
    std::vector<int> testTree = tree.traverseInOrder();
    std::vector<int> testAns = { 1, 3 };
    EXPECT_EQ( testTree, testAns );
};
TEST(tree, inorderThreeNodes){
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    BinaryTree<int> tree(root);
    std::vector<int> testTree = tree.traverseInOrder();
    std::vector<int> testAns = { 1, 3, 5 };
    EXPECT_EQ( testTree, testAns );
};
TEST(tree, inorderFourNodes){
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft( new TreeNode<int> (2));

    BinaryTree<int> tree(root);
    std::vector<int> testTree = tree.traverseInOrder();
    std::vector<int> testAns = { 2, 1, 3, 5 };
    EXPECT_EQ( testTree, testAns );
};
TEST(tree, inorderManyNodes){
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(6));

    BinaryTree<int> tree(root);
    std::vector<int> testTree = tree.traverseInOrder();
    std::vector<int> testAns = { 2, 1, 7, 3, 6, 5};
    EXPECT_EQ( testTree, testAns);
};
TEST(tree, postorderNull){
    TreeNode<int>* root = nullptr;

    BinaryTree<int> tree(root);
    EXPECT_NO_FATAL_FAILURE( tree.traversePostOrder() );
};
TEST(tree, postorderSingle){
    TreeNode<int>* root = new TreeNode<int>(3);

    BinaryTree<int> tree(root);
    std::vector<int> testTree = tree.traversePostOrder();
    std::vector<int> testAns = { 3 };
    EXPECT_EQ( testTree, testAns);
};
TEST(tree, postorderTwoNodes){
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));

    BinaryTree<int> tree(root);
    std::vector<int> testTree = tree.traversePostOrder();
    std::vector<int> testAns = { 1, 3};
    EXPECT_EQ( testTree, testAns);
};
TEST(tree, postorderThreeNodes){
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    BinaryTree<int> tree(root);
    std::vector<int> testTree = tree.traversePostOrder();
    std::vector<int> testAns = { 1, 5, 3};
    EXPECT_EQ( testTree, testAns);
};
TEST(tree, postorderFourNodes){
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft( new TreeNode<int> (2));

    BinaryTree<int> tree(root);
    std::vector<int> testTree = tree.traversePostOrder();
    std::vector<int> testAns = { 2, 1, 5, 3};
    EXPECT_EQ( testTree, testAns);
};
TEST(tree, postorderManyNodes){
    TreeNode<int>* root = new TreeNode<int>(3);
    root->setLeft(new TreeNode<int>(1));
    root->setRight(new TreeNode<int>(5));

    root->getLeft()->setLeft(new TreeNode<int>(2));
    root->getLeft()->setRight(new TreeNode<int>(7));

    root->getRight()->setLeft(new TreeNode<int>(6));

    BinaryTree<int> tree(root);
    std::vector<int> testTree = tree.traversePostOrder();
    std::vector<int> testAns = { 2, 7, 1, 6, 5, 3};
    EXPECT_EQ( testTree, testAns);
};
BinaryTree<int> LCATree (){
    TreeNode<int>* root = new TreeNode<int>(4);
    root->setLeft(new TreeNode<int>(8));
    root->setRight(new TreeNode<int>(6));

    root->getLeft()->setLeft(new TreeNode<int>(7));
    root->getLeft()->setRight(new TreeNode<int>(3));

    root->getRight()->setLeft(new TreeNode<int>(2));
    root->getRight()->setRight(new TreeNode<int>(9));
//that right theres yor problm
//    BinaryTree<int> tree(root);
    return root;
}

TEST(tree, LCA44){
    BinaryTree<int> testTree = LCATree();
    EXPECT_EQ( testTree.LCA ( 4, 4), 4);
};
TEST(tree, LCA77){
    BinaryTree<int> testTree = LCATree();
    EXPECT_EQ( testTree.LCA ( 7, 7), 7);
};
TEST(tree, LCA73){
    BinaryTree<int> testTree = LCATree();
    EXPECT_EQ( testTree.LCA ( 7, 3), 8);
};
TEST(tree, LCA78){
    BinaryTree<int> testTree = LCATree();
    EXPECT_EQ( testTree.LCA ( 7, 8), 8);
};
TEST(tree, LCA86){
    BinaryTree<int> testTree = LCATree();
    EXPECT_EQ( testTree.LCA ( 8, 6), 4);
};
TEST(tree, LCA32){
    BinaryTree<int> testTree = LCATree();
    EXPECT_EQ( testTree.LCA ( 3, 2), 4);
};
