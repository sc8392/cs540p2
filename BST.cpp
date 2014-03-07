#include <iostream>
#include "BST.h"


/*
 *initializes the root to NULL
 */
BST::BST(){
  root = NULL;
}

/*
 * destructor
 */
BST::~BST(){
  deleteTree(root);
}

/*
 * searches for an item in the tree
 */
bool BST::bstSearch(int item){
  Node* temp;
  temp = root;
  if(item == root->data){
    return true;
  }
  while(temp->left != NULL && temp->right !=NULL){
    if(temp == NULL){
      return false;
    }
    if(item == temp->data){
      return true;
    } else if(item < temp->data){
      temp = temp->left;
    } else {
      temp = temp->right;
    }
  }
  return false;
}

/*
 * inserts data in the proper location in the tree
 */
void BST::insert(int item){
  if(root == NULL){
    root = new Node();
    root-> data = item;
  } else {
    insertRec(item,root);
  }
}

/*
 *
 */
void BST::insertRec(int item, Node* rootin){
  if(rootin->data == item){
    return;
  } else if(rootin->data > item){
    if(rootin->left == NULL){
      rootin->left = new Node();
      rootin->left->data = item;
    } else {
      insertRec(item, rootin->left);
    }
  } else if(rootin->data < item){
     if(rootin->right == NULL){
      rootin->right = new Node();
      rootin->right->data = item;
    } else {
      insertRec(item, rootin->right);
    }
  } 
}

/*
 * prints out the data inorder
 */
void BST::traverseInOrder(){
  traverseInOrderRec(root);
}

/*
 * prints out the data inorder
 */
void BST::traverseInOrderRec(Node* rootin){
  if(rootin ==  NULL){
    return;
  }
  traverseInOrderRec(rootin->left);
  std::cout << rootin->data << std::endl;
  traverseInOrderRec( rootin->right);
}

/*
 * prints out the data in descending  order
 */
void BST::traverseDescendingOrder(){
  traverseDescendingOrderRec(root);
}

/*
 * prints out the data in descending order
 */
void BST::traverseDescendingOrderRec(Node* rootin){
  if(rootin ==  NULL){
    return;
  }
  traverseDescendingOrderRec(rootin->right);
  std::cout << rootin->data << std::endl;
  traverseDescendingOrderRec( rootin->left);
}

/*
 * recursively deletes all nodes in the tree
 */
void BST::deleteTree(Node* rootin){
  if(rootin->left != NULL){
    deleteTree(rootin->left);
  } 
  if(rootin->right != NULL){
    deleteTree(rootin->right);
  }
  delete rootin;
}
