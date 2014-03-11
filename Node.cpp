#include <utility>
#include "Node.h"


// initializes the data and the left and right nodes
template <class Key, class Value>
Node<Key, Value>::Node(): data(nullptr),parent(nullptr), right(nullptr), 
	      successor(nullptr), predecessor(nullptr), left(nullptr){
}

// returns the left node
template <class Key, class Value>
Node<Key, Value>* Node<Key, Value>::getLeft() {
  return left;
}

// returns the right node
template <class Key, class Value>
Node<Key, Value>* Node<Key, Value>::getRight() {
  return right;
}


// changes what left is pointing to
template <class Key, class Value>
void Node<Key, Value>::setLeft(Node* leftIn) {
  left = leftIn;
}

// changes what right is pointing to
template <class Key, class Value>
void Node<Key, Value>::setRight(Node* rightIn) {
  right = rightIn;
}

// returns the key of the pair in node
template <class Key, class Value>
Key& Node<Key, Value>::getKey() {
  return data->first;
}

template <class Key, class Value>
Value& Node<Key,Value>::getValue(){
  return data->second;
}

template <class Key, class Value>
std::pair<Key, Value>* Node<Key, Value>::getPair(){
  return data;
}

// changes the data in the current node
template <class Key, class Value>
void Node<Key, Value>::setData(std::pair<Key, Value> *dataIn) {
  data = dataIn; 
}

// deletes the data
template <class Key, class Value>
Node<Key, Value>::~Node() {
  delete data;
}

template <class Key, class Value>
Node<Key, Value>* Node<Key, Value>::getSuccessor(){
  return successor;
}

template <class Key, class Value>
Node<Key, Value>* Node<Key, Value>::getPredecessor(){
  return predecessor;
}

template <class Key, class Value>
Node<Key, Value>* Node<Key, Value>::getParent(){
  return parent;
}

template <class Key, class Value>
void Node<Key, Value>::setSuccessor(Node *successorIn){
  successor = successorIn;
}

template <class Key, class Value>
void Node<Key, Value>::setPredecessor(Node *predecessorIn){
  predecessor = predecessorIn;
}

template <class Key, class Value>
void Node<Key, Value>::setParent(Node *parentIn){
  parent = parentIn;
}
