#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_MAP_S21_MAP_H_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_MAP_S21_MAP_H_

#include "../AVLTree/AVLTree.h"

namespace s21 {
template <typename Key, typename T>
class map : public AVL<Key, T> {
 public:
  using Base = AVL<Key, T>;
  using typename Base::key_type;
  using mapped_type = T;
  using typename Base::const_iterator;
  using typename Base::const_reference;
  using typename Base::iterator;
  using typename Base::reference;
  using typename Base::size_type;
  using typename Base::value_type;

  map() = default;
  map(std::initializer_list<value_type> const& items) : Base(items) {}
  map(const map& other) : Base(other) {}
  map(map&& other) : Base(std::move(other)) {}
  ~map() = default;
  map& operator=(map&& other) {
    Base::operator=(std::move(other));
    return *this;
  }

  map& operator=(const map& other) {
    if (this != &other) {
      Base::operator=(other);
    }
    return *this;
  }

  T& at(const Key& key) {
    typename map<Key, T>::iterator it = Base::find(key);
    if (it == end()) {
      throw std::out_of_range("Key not found");
    }
    return it->second;
  }

  T& operator[](const Key& key) {
    try {
      return at(key);
    } catch (const std::out_of_range&) {
      iterator it = insert(key, T()).first;
      return it->second;
    }
  };

  bool empty() const { return Base::empty(); }
  size_type size() const { return Base::size(); }
  size_type max_size() const { return Base::max_size(); }

  iterator begin() const { return Base::begin(); }
  iterator end() const { return Base::end(); }
  const_iterator cbegin() const { return Base::cbegin(); }
  const_iterator cend() const { return Base::cend(); };

  void clear() { Base::clear(); }
  std::pair<iterator, bool> insert(const value_type& value) {
    return Base::insert(value);
  }

  std::pair<iterator, bool> insert(const Key& key, const T& obj) {
    value_type keyValue = std::make_pair(key, obj);
    return Base::insert(keyValue);
  }

  std::pair<iterator, bool> insert_or_assign(const Key& key, const T& obj) {
    return Base::insert_or_assign(std::make_pair(key, obj));
  }

  void erase(iterator pos) { Base::erase(pos); }
  void swap(map& other) { Base::swap(other); }
  void merge(map& other) { Base::merge(other); }

  bool contains(const Key& key) const { return Base::contains(key); }
  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    return Base::insert_many(std::forward<Args>(args)...);
  }

  void printTree() const { Base::printTree(); }
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_MAP_S21_MAP_H_
