#include "Node.h"


// initializes the data and the left and right nodes
Node::Node() {
  data = NULL;
  left = NULL;
  right = NULL;
  
}

// explicit value contructor
// initializes the data, left and right to the given data, left and right
Node::Node(int dataIn, Node* leftIn, Node* rightIn) {
  data = dataIn;
  left = leftIn;
  right = rightIn;
}

// returns the left node
Node* Node::getLeft() {
  return left;
}

// returns the right node
Node* Node::getRight() {
  return right;
}


// changes what left is pointing to
void Node::setLeft(Node* leftIn) {
  left = leftIn;
}

// changes what right is pointing to
void Node::setRight(Node* rightIn) {
  right = rightIn;
}

// returns the data in the node
int Node::getData() {
  return data;
}

// changes the data in the current node
void Node::setData(int dataIn) {
  data = dataIn; 
}

// deletes the data
Node::~Node() {
   
}
