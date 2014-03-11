#ifndef BST_H__
#define BST_H__

#include <utility>
#include <iostream>
#include "Node.h"

template<class Key, class Value>
class BST{
 public:
  BST();
  ~BST();
  BST(const BST<Key, Value> &bst);
  Node<Key, Value>* bstSearch(Key k);
  void insert(std::pair<Key, Value>* item);
  void insertRec(std::pair<Key, Value> *item, Node<Key, Value>* rootin);
  void deleteValue(Key k);
  void deleteRec(Key k, Node<Key, Value>* rootin);
  void deleteTree(Node<Key, Value>* rootin);
  Node<Key, Value>* findPredecessor(Node<Key, Value> *n); 
  Node<Key, Value>* findSuccessor(Node<Key, Value> *n);
  
  void traverseInOrder();
  void traverseInOrderRec(Node<Key, Value>* rootin);

  void traverseInOrderSuc();

 private:
  Node<Key, Value>* root;
  
};

#include "BST.cpp"

#endif // BST__
