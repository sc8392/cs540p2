#ifndef BINARY_SEARCH_TREE__
#define BINARY_SEARCH_TREE__

#include <iostream>
#include "TreeNode.h"

class BinarySearchTree{
 public:
  BinarySearchTree();
  ~BinarySearchTree();
  bool bstSearch(int item);
  void insert(int item);
  void insertRec(int item, TreeNode* rootin);
  void traverseInOrder();
  void traverseInOrderRec(TreeNode* rootin);
  void traverseDescendingOrder();
  void traverseDescendingOrderRec(TreeNode* rootin);
  void deleteTree(TreeNode* rootin);
       
 
 private:
  TreeNode* root;
};

#endif // BINARY_SEARCH_TREE__
