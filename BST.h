#ifndef BST_H__
#define BST_H__

#include <cstdio>
#include <utility>
#include <iostream>
#include "Node.h"

template<class Key, class Value>
class BST{
 public:
  BST();
  ~BST();
  Node<Key, Value>* bstSearch(Key k);
  Node<Key, Value>* insert(std::pair<Key, Value>* item);
  Node<Key, Value>* insertRec(std::pair<Key, Value> *item, Node<Key, Value>* rootin);
  int deleteValue(Key k);
  int deleteRec(Key k, Node<Key, Value>* rootin);
  void deleteTree(Node<Key, Value>* rootin);
  Node<Key, Value>* findPredecessor(Node<Key, Value> *n); 
  Node<Key, Value>* findSuccessor(Node<Key, Value> *n);
  
  void traverseInOrder();
  void traverseInOrderRec(Node<Key, Value>* rootin);

  void traverseInOrderSuc();

  Node<Key, Value>* root;
  std::size_t size;

 private:

 
  
};

#include "BST.cpp"

#endif // BST__
