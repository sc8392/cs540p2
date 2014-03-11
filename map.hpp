#ifndef __MAP_HPP__
#define __MAP_HPP__

#include "BST.h"
#include <utility>
#include <initializer_list>


namespace cs540{
  
  template <class Key, class Value>
  class Map{
    
  public:
    BST<Key, Value> *bst;
    
    class Iterator{
    public:
      Iterator(const Iterator& it);
      Iterator& operator=(const Iterator& it);
      Iterator(Iterator&& it);
      Iterator& operator=(Iterator&& it);
      ~Iterator();
      Iterator& operator++();
      Iterator operator++(int i);
      Iterator& operator--();
      Iterator operator--(int i);
      std::pair<const Key, Value>& operator*() const;      
    };
      

    class ConstIterator{
    public:
      ConstIterator(const ConstIterator& it);
      ConstIterator& operator=(const ConstIterator& it);
      ConstIterator(ConstIterator&& it);
      ConstIterator& operator=(ConstIterator&& it);
      ~ConstIterator();
      ConstIterator& operator++();
      ConstIterator operator++(int i);
      ConstIterator& operator--();
      ConstIterator operator--(int i);
      std::pair<const Key, Value>& operator*() const;      
    };
    
    
    
    class ReverseIterator{
    public:
      ReverseIterator(const ReverseIterator& it);
      ReverseIterator& operator=(const ReverseIterator& it);
      ReverseIterator(ReverseIterator&& it);
      ReverseIterator& operator=(ReverseIterator&& it);
      ~ReverseIterator();
      ReverseIterator& operator++();
      ReverseIterator operator++(int i);
      ReverseIterator& operator--();
      ReverseIterator operator--(int i);
      std::pair<const Key, Value>& operator*() const;      
    };


    Map();
    Map(const Map<Key, Value>& m);
    Map& operator=(const Map<Key, Value>& m);
    Map(Map<Key, Value>&& m);
    Map(std::initializer_list<std::pair<const Key, Value> > list);
    ~Map();
    
    Map::Iterator insert(const std::pair<const Key, Value>& pair);
    Map::Iterator insert(std::pair<const Key, Value>&& pair);
    void erase(Map::Iterator it);
    void remove(const Key& k);
    void clear();

    Map::Iterator find(const Key& k);
    Map::ConstIterator find(const Key& k) const;
    Value& at(const Key &);
    const Value& at(const Key &) const;
    Value& operator[](const Key&);

    std::size_t size() const;
    bool empty() const;
    bool operator==(const Map<Key, Value>&) const;
    bool operator!=(const Map<Key, Value>&) const;
    
    Map::Iterator begin();
    Map::Iterator end();
    Map::ConstIterator begin() const;
    Map::ConstIterator end() const;
    Map::ReverseIterator rbegin();
    Map::ReverseIterator rend();
    
    
    friend bool operator==(const Iterator &it1, const Iterator &it2){}
    friend bool operator!=(const Iterator &it1, const Iterator &it2){}
    
    friend bool operator==(const ConstIterator &it1, const ConstIterator &it2){}
    friend bool operator!=(const ConstIterator &it1, const ConstIterator &it2){}
      
    friend bool operator==(const ReverseIterator &it1, const ReverseIterator &it2){}
    friend bool operator!=(const ReverseIterator &it1, const ReverseIterator &it2){}

    friend bool operator==(const ConstIterator &cit, const Iterator &it){}
    friend bool operator==(const Iterator&, const ConstIterator&){}
    friend bool operator!=(const ConstIterator &cit, const Iterator &it){}
    friend bool operator!=(const Iterator&, const ConstIterator&){}
    
  private:

  };

#include "map.cpp"
  
}
#endif //__MAP_HPP__
