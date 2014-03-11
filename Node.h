#ifndef NODE_H__
#define NODE_H__

#include <utility>

template <class Key, class Value>
class Node {
  
 public:
  Node();
  Node<Key, Value>* getLeft();
  Node<Key, Value>* getRight();
  void setLeft(Node<Key, Value>* leftIn);
  void setRight(Node<Key, Value>* rightIn);
  Key& getKey();
  Value& getValue();
  std::pair<Key, Value>* getPair();
  void setData(std::pair<Key, Value> *data);
  Node<Key, Value>* getSuccessor();
  Node<Key, Value>* getPredecessor();
  Node<Key, Value>* getParent();
  void setSuccessor(Node<Key, Value>*sucessorIn);
  void setPredecessor(Node<Key, Value>*predecessorIn);
  void setParent(Node<Key, Value>*parentIn);
  ~Node();

 private:
  std::pair<Key, Value> *data;
  Node<Key, Value> *parent;
  Node<Key, Value> *right;
  Node<Key, Value> *successor;
  Node<Key, Value> *predecessor;
  Node<Key, Value> *left;
    
    
};

#include "Node.cpp"

#endif // NODE_H__
