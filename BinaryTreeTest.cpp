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

TEST(tree, destructorNull){};
TEST(tree, destructorSingleEle){};
TEST(tree, destructorTwoEles){};
TEST(tree, destructorMultipleEles){};
TEST(tree, inorderNull){};
TEST(tree, inorderSingle){};
TEST(tree, inorderTwoNodes){};
TEST(tree, inorderThreeNodes){};
TEST(tree, inorderFourNodes){};
TEST(tree, inorderManyNodes){};
TEST(tree, postorderNull){};
TEST(tree, postorderSingle){};
TEST(tree, postorderTwoNodes){};
TEST(tree, postorderThreeNodes){};
TEST(tree, postorderFourNodes){};
TEST(tree, postorderManyNodes){};
TEST(tree, LCA44){};
TEST(tree, LCA77){};
TEST(tree, LCA73){};
TEST(tree, LCA78){};
TEST(tree, LCA86){};
TEST(tree, LCA32){};
