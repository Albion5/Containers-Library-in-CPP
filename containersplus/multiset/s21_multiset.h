#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERSPLUS_MULTISET_S21_MULTISET_H_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERSPLUS_MULTISET_S21_MULTISET_H_

#include "../../containers/AVLTree/AVLTree.h"

namespace s21 {
template <typename Key>
class multiset : public AVL<Key, Key, false, false> {
 public:
  using Base = AVL<Key, Key, false, false>;
  using key_type = Key;
  using value_type = key_type;
  using reference = value_type&;
  using const_reference = const value_type&;
  using typename Base::const_iterator;
  using typename Base::iterator;
  using typename Base::size_type;

  multiset() = default;
  multiset(std::initializer_list<value_type> const& items) : Base(items) {}
  multiset(const multiset& other) : Base(other) {}
  multiset(multiset&& other) : Base(std::move(other)) {}
  ~multiset() {}
  multiset& operator=(multiset&& other) {
    Base::operator=(std::move(other));
    return *this;
  }
  multiset& operator=(const multiset& other) {
    Base::operator=(other);
    return *this;
  }

  bool empty() const { return Base::empty(); }
  size_type size() const { return Base::size(); }
  size_type max_size() const { return Base::max_size(); }

  iterator begin() const { return Base::begin(); }
  iterator end() const { return Base::end(); }
  const_iterator cbegin() const { return Base::cbegin(); }
  const_iterator cend() const { return Base::cend(); }

  void clear() { Base::clear(); }
  std::pair<iterator, bool> insert(const value_type& value) {
    return Base::insert(value);
  }

  void erase(iterator pos) { Base::erase(pos); }
  void swap(multiset& other) { Base::swap(other); }
  void merge(multiset& other) { Base::merge(other); }

  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    return Base::insert_many(std::forward<Args>(args)...);
  }

  size_type count(const Key& key) const { return Base::count(key); }
  iterator find(const Key& key) const { return Base::find(key); }
  bool contains(const Key& key) const { return Base::contains(key); }
  std::pair<iterator, iterator> equal_range(const Key& key) {
    return Base::equal_range(key);
  }
  iterator lower_bound(const Key& key) const { return Base::lower_bound(key); }
  iterator upper_bound(const Key& key) const { return Base::upper_bound(key); }
  void printTree() const { Base::printTree(); }
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_CONTAINERSPLUS_MULTISET_S21_MULTISET_H_