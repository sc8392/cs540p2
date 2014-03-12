#include "map.hpp"
#include <stdexcept>


//default constructor
template<class Key, class Value>
Map<Key, Value>::Map(){
  bst = new BST<Key,Value>();
}

//copy constructor
template<class Key, class Value>
Map<Key, Value>::Map(const Map<Key, Value>& m){
  BST<Key, Value> copy = m.bst;
  
  if(map == this) return;

  if(bst != nullptr) delete bst;
  bst = new BST<Key,Value>();
  
  recCopy(*((m.bst)->root));

}

//creates a new node with the given node's data
template<class Key, class Value>
void Map<Key,Value>::recCopy(Node<Key,Value> &n){
  if(n==nullptr) return;

  recCopy(*(n.getLeft()));
  bst.insert(new std::pair<Key, Value>(n.getKey(), n.getValue()));
  recCopy(*(n.getRight()));
  
}

//copy assignment ?
template<class Key, class Value>
Map<Key, Value>::Map& operator=(const Map<Key, Value>& m){
  BST<Key, Value> copy = m.bst;
  
  if(map == this) return;

  if(bst != nullptr) delete bst;
  bst = new BST<Key,Value>();

  recCopy(*((m.bst)->root));

  return *this;
}

//move constructor
template<class Key, class Value>
Map(Map<Key, Value>&& m){
 
  bst = m.bst;
  m.bst = nullptr;
}

//move assignment
template<class Key, class Value>
Map& operator=(Map<Key, Value> &&m){
  if(m == this) return this;

  if(bst != nullptr) delete bst;
  bst = new BST<Key,Value>();
  bst = m.bst;
  m.bst = nullptr;
  return *this;
}

//inserts everything in the initializer list into the bst
template<class Key, class Value>
Map(std::initializer_list<std::pair<const Key, Value> > list){
  for(auto i = begin(list); list.end(list); ++i){
    bst->insert(*i);
  }
}

//deletes bst
template<class Key, class Value>
~Map(){
  delete bst;
}


template<class Key, class Value>
Map::Iterator insert(const std::pair<const Key, Value>& pair){
}

template<class Key, class Value>
Map::Iterator insert(std::pair<const Key, Value>&& pair){
}

template<class Key, class Value>
void erase(Map::Iterator it){
}

//removes the element with key k
template<class Key, class Value>
void remove(const Key& k){
  bst.deleteValue(k);
}

//deletes the bst and makes a new one
template<class Key, class Value>
void Map<Key, Value>::clear(){
  delete bst;
  bst = new BST<Key, Value>();
}

template<class Key, class Value>
Map::Iterator find(const Key& k){
}

template<class Key, class Value>
Map::ConstIterator find(const Key& k) const{
}

//returns the value of the given key, throws exception if not found
template<class Key, class Value>
Value& Map<Key,Value>::at(const Key &k){
  Node<Key,Value> temp;
  temp = bst.bstsearch(k);
  if(temp == nullptr){
    throw std::out_of_range("key not found");
  }
  return temp.getValue();
}

//returns a const reference to value with the key
template<class Key, class Value>
const Value& Map<Key,Value>::at(const Key &k) const{
  Node<Key,Value> temp;
  const Value val;
  temp = bst.bstsearch(k);
  if(temp == nullptr){
    throw std::out_of_range("key not found");
  }
  return val;
}

//returns a reference to the value with the given key
template<class Key, class Value>
Value& operator[](const Key&k){
  Node<Key,Value> temp;
  temp = bst.bstsearch(k);
  if(temp == nullptr){
    return Value();
  }
  return temp.getValue();
}

//returns current size of the map
template<class Key, class Value>
std::size_t size() const{
  return bst->size;
}

//returns true if empty, false if not
template<class Key, class Value>
bool empty() const{
  if(bst->size == 0) return true;
  return false;
}

template<class Key, class Value>
bool operator==(const Map<Key, Value>&m) const{
}

template<class Key, class Value>
bool operator!=(const Map<Key, Value>&m) const{
}

template<class Key, class Value>
    
Map::Iterator begin(){
}

template<class Key, class Value>
Map::Iterator end(){
}

template<class Key, class Value>
Map::ConstIterator begin() const{
}

template<class Key, class Value>
Map::ConstIterator end() const{
}

template<class Key, class Value>
Map::ReverseIterator rbegin(){
}

template<class Key, class Value>
Map::ReverseIterator rend(){
}

