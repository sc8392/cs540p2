#include "BST.h"
#include <iostream>


/*
 *initializes the root to nullptr
 */
template<class Key, class Value>
BST<Key, Value>::BST(){
  root = nullptr;
}

/*
 * destructor
 */
template<class Key, class Value>
BST<Key, Value>::~BST(){
  deleteTree(root);
}

/*
 * searches for an item in the tree
 */
template<class Key, class Value>
Node<Key, Value>* BST<Key, Value>::bstSearch(Key k){
  Node<Key, Value> *temp;
  temp = root;
  if(k == root->getKey()){
    return temp;
  }
  while(temp->getLeft() != nullptr && temp->getRight() !=nullptr){
    if(temp == nullptr){
      return nullptr;
    }
    if(k == temp->getKey()){
      return temp;
    } else if(k < temp->getKey()){
      temp = temp->getLeft();
    } else {
      temp = temp->getRight();
    }
  }
  return nullptr;
}

/*
 * inserts data in the proper location in the tree
 */
template<class Key, class Value>
void BST<Key, Value>::insert(std::pair<Key, Value>* item){
  if(root == nullptr){
    root = new Node<Key, Value>();
    root->setData(item);
  } else {
    insertRec(item,root);
  }
}

/*
 * insterts a value into the BST while keeping it a BST
 */
template<class Key, class Value>
void 
BST<Key, Value>::insertRec(std::pair<Key, Value>* item, Node<Key, Value>* rootin){
  if(rootin->getKey() == item->first){
    if(item == rootin->getPair()){
      return;
    }
    delete item;//items different but has the same key
    return;
  } if(rootin->getKey() > item->first){

    if(rootin->getLeft() == nullptr){
      Node<Key, Value>* pred;
      Node<Key, Value>* succ;
      Node<Key, Value> *current;

      rootin->setLeft(new Node<Key, Value>());
      current = rootin->getLeft();
      
      current->setData(item);
      current->setParent(rootin);

      succ = this->findSuccessor(current);
      pred = this->findPredecessor(current);
      current->setSuccessor(succ);
      current->setPredecessor(pred);
      if(pred != nullptr){
	pred->setSuccessor(current);
      }
      if(succ != nullptr){
	succ->setPredecessor(current);
      }      
    } else {
      insertRec(item, rootin->getLeft());
    }

  } else if(rootin->getKey() < item->first){

    if(rootin->getRight() == nullptr){
      Node<Key, Value>* pred;
      Node<Key, Value>* succ;
      Node<Key, Value> *current;

      rootin->setRight(new Node<Key, Value>());
      current = rootin->getRight();

      current->setData(item);
      current->setParent(rootin);
   
      succ = this->findSuccessor(current);
      pred = this->findPredecessor(current);
      current->setSuccessor(succ);
      current->setPredecessor(pred);

      if(pred != nullptr){
	pred->setSuccessor(current);
      }
      if(succ != nullptr){
	succ->setPredecessor(current);
      }     

    } else {
      insertRec(item, rootin->getRight());
    }
  } 
}

template<class Key, class Value>
void BST<Key, Value>::deleteValue(Key k){
  if(root == nullptr){
    return;
  }
  deleteRec(k, root);
}

/*
 * deletes the value fixed the tree so that it is still a binary tree
 */
template<class Key, class Value>
void BST<Key, Value>::deleteRec(Key k, Node<Key, Value>* rootin){
  
  if(rootin == nullptr) return;
  
  if(rootin->getKey() == k){

    if((rootin->getLeft() != nullptr) && (rootin->getRight() != nullptr)){
      //swaps data with successor
      std::pair<Key, Value> *temp;
      
      //swaps the data
      temp =rootin->getPair();
      rootin->setData(rootin->getSuccessor()->getPair());
      rootin->getSuccessor()->setData(temp);
      
      this->deleteRec(k, rootin->getSuccessor());

    } else if (rootin->getRight() != nullptr){
      //right child is the new parent
      Node<Key,Value> *parent;
      
      //sets pointers, successor, predecessor, parent, children
      parent = rootin->getParent();
      if(parent != nullptr){
	if(parent->getLeft() == rootin){
	  parent->setLeft(rootin->getRight());
	  parent->getLeft()->setParent(parent);
	} else {
	  parent->setRight(rootin->getRight());
	  parent->getRight()->setParent(parent);
	}
	//parent->setSuccessor(parent->getSuccessor());
      } else { //it's a the root
	root = rootin->getRight();
	root->setParent(nullptr);
      }
      
      if(rootin->getSuccessor() != nullptr){
	rootin->getSuccessor()->setPredecessor(rootin->getPredecessor());
      }
      if(rootin->getPredecessor() != nullptr){
	rootin->getPredecessor()->setSuccessor(rootin->getSuccessor());
      }

      delete rootin;

    } else if (rootin->getLeft() != nullptr){
      //left child is the new parent
      Node<Key,Value> *parent;
      
      //sets pointers, successor, predecessor, parent, children
      parent = rootin->getParent();
      if(parent != nullptr){
	if(parent->getLeft() == rootin){
	  parent->setLeft(rootin->getLeft());
	  parent->getLeft()->setParent(parent);
	} else {
	  parent->setRight(rootin->getLeft());
	  parent->getRight()->setParent(parent);
	}
	//parent->setPredecessor(rootin->getPredecessor());
      } else {//it's the root
	root = rootin->getLeft();
	root->setParent(nullptr);
      }
      
      if(rootin->getSuccessor() != nullptr){
	rootin->getSuccessor()->setPredecessor(rootin->getPredecessor());
      }
      if(rootin->getPredecessor() != nullptr){
	rootin->getPredecessor()->setSuccessor(rootin->getSuccessor());
      }

      delete rootin;

      
    } else {//is leaf
      Node<Key,Value> *tempNode;
      Node<Key,Value> *parent;
      
      if(rootin == root){
	root = nullptr;
	delete rootin;
	return;
      }

      //set the predecessors and successors of the node
      tempNode = rootin->getSuccessor();
      if(tempNode != nullptr){
	tempNode->setPredecessor(rootin->getPredecessor()); 
	//	tempNode->setSuccessor(this->findSuccessor(tempNode));
      }
      if(rootin->getPredecessor() != nullptr){
	rootin->getPredecessor()->setSuccessor(tempNode);
      }

      parent = rootin->getParent();
      //removes the parent's refence to this node
      if(parent->getLeft() == rootin){ //left leaf
	parent->setLeft(nullptr);
      } else { //right leaf
	parent->setRight(nullptr); 
      }
      delete rootin;
    }

  } else if (rootin->getKey() < k){
    deleteRec(k, rootin->getRight());
    
  } else if (rootin->getKey() > k){
    deleteRec(k, rootin->getLeft());
  
  } 
  return;
  
}



/*
 * recursively deletes all nodes in the tree
 */
template<class Key, class Value>
void BST<Key, Value>::deleteTree(Node<Key, Value>* rootin){

  if(rootin == nullptr) return;

  if(rootin->getLeft() != nullptr){
    deleteTree(rootin->getLeft());
  } 
  
  if(rootin->getRight() != nullptr){
    deleteTree(rootin->getRight());
  }
  delete rootin;
}

/*
 * find the predecessor of the given node
 */
template<class Key, class Value>
Node<Key, Value>* BST<Key, Value>::findPredecessor(Node<Key, Value> *n){
  Node<Key, Value> *temp;
  
  if(n->getLeft() != nullptr){
    temp = n->getLeft();
    while(temp != nullptr){
      temp = temp->getRight();
    }
  } else {
    temp = n->getParent();
    while((temp != nullptr) && (temp->getLeft() == n)){
      n = n->getParent();
      temp = temp->getParent();
    }
    
  }
  
  return temp;
}

/*
 * finds the successor of the given node
 */
template<class Key, class Value>
Node<Key, Value>* BST<Key, Value>::findSuccessor(Node<Key, Value> *n){
  Node<Key, Value> *temp;
  
  if(n->getRight() != nullptr){
    temp = n->getRight();
    while(temp != nullptr){
      temp = temp->getLeft();
    }
  } else {
    temp = n->getParent();
    while((temp != nullptr) && (temp->getRight() == n)){
      n = n->getParent();
      temp = temp->getParent();
    }
  }
  
  return temp;
}




/*
 * prints out the data inorder
 */
template<class Key, class Value>
void BST<Key, Value>::traverseInOrder(){
  traverseInOrderRec(root);
  std::cout << std::endl;
}

/*
 * prints out the data inorder
 */
template<class Key, class Value>
void BST<Key, Value>::traverseInOrderRec(Node<Key, Value>* rootin){
  if(rootin ==  NULL){
    return;
  }
  traverseInOrderRec(rootin->getLeft());
  std::cout << "(" << rootin->getKey() << "," << rootin->getValue() << ") ";
  traverseInOrderRec(rootin->getRight());
}

/*
 * print out the data inorder by traversing using successor then reverse
 */
template<class Key, class Value>
void BST<Key, Value>::traverseInOrderSuc(){
  Node<Key, Value> *temp;
 
  temp = root;
  
  if(temp == nullptr) return;
 
  while(temp->getLeft() != nullptr){
    temp = temp->getLeft();
  }
  while(temp != nullptr){
    std::cout << "(" << temp->getKey() << "," << temp->getValue() << ") ";
    temp = temp->getSuccessor();
  }
  std::cout << std::endl;
 
  temp = root;
  while(temp->getRight() != nullptr){
    temp = temp->getRight();
  }
  while(temp != nullptr){
    std::cout << "(" << temp->getKey() << "," << temp->getValue() << ") ";
    temp = temp->getPredecessor();
  }
  std::cout << std::endl;
}
