#include <utility>
#include <initializer_list>

#ifndef __MAP_HPP__
#define __MAP_HPP__

namespace cs540{
  
  template <class Value>
  template <class Key>
  class Map{
    
  public:
    Map();
    Map(const Map& m);
    Map& operator=(const Map& m);
    Map(Map&& m);
    Map(std::initializer_list
	<std::pair<const Key, Value> > list);
    Map::Iterator insert(const std::pair<const Key, Value>&&);
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
    bool operator==(const Map&) const;
    bool operator!=(const Map&) const;
    Map::Iterator begin();
    Map::Iterator end();
    Map::ConstIterator begin();
    Map::ConstIterator end();
    

    class Iterator{
    public:
      Iterator(const Iterator& it);
      Iterator& operator=(const Iterator& it);
      Iterator(Iterator&& it);
      Iterator& operator=(Iterator&& it);
      ~Iterator();
      Iterator& operator++();
      Iterator operatpr++(int i);
      Iterator& operator--();
      Iterator operatpr--(int i);
      std::pair<const Key, Value>& operator*() const;      
    };
      
    
    

    ~Map();
    
    
    
  private:
  };
  
}
#endif //__MAP_HPP__
