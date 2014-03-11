#include "map.hpp"


//default constructor
template<class Key, class Value>
Map(){
  bst = new BST<Key,Value>();
}

//copy constructor
template<class Key, class Value>
Map(const Map<Key, Value>& m){
  BST<Key, Value> copy = m.bst;
  
  if(map == this) return;
  
  //bst = new BST<Key,Value>();
  
  
}

template<class Key, class Value>
Map& operator=(const Map<Key, Value>& m){
}

template<class Key, class Value>
Map(Map<Key, Value>&& m){
}

template<class Key, class Value>
Map(std::initializer_list<std::pair<const Key, Value> > list){
}

template<class Key, class Value>
~Map(){
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

template<class Key, class Value>
void remove(const Key& k){
}

template<class Key, class Value>
void clear(){
}

template<class Key, class Value>

Map::Iterator find(const Key& k){
}

template<class Key, class Value>
Map::ConstIterator find(const Key& k) const{
}

template<class Key, class Value>
Value& at(const Key &){
}

template<class Key, class Value>
const Value& at(const Key &) const{
}

template<class Key, class Value>
Value& operator[](const Key&){
}

template<class Key, class Value>

std::size_t size() const{
}

template<class Key, class Value>
bool empty() const{
}

template<class Key, class Value>
bool operator==(const Map<Key, Value>&) const{
}

template<class Key, class Value>
bool operator!=(const Map<Key, Value>&) const{
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

