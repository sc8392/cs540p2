
#ifndef _NODE_H__
#define _NODE_H__

#include <string>


class Node {
  
 public:
  Node();
  Node(int dataIn, Node* leftIn, Node*rightIn);
  Node *getLeft();
  Node *getRight();
  void setLeft(Node* leftIn);
  void setRight(Node* rightIn);
  int getData();
  void setData(int dataIn);
  ~Node();

  int data;
  Node* left;
  Node* right;
    
    
};


#endif // NODE_H__
