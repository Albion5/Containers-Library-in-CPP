#ifndef CPP2_S21_CONTAINERS_1_CONTAINERS_SRC_SET_S21_SET_H_
#define CPP2_S21_CONTAINERS_1_CONTAINERS_SRC_SET_S21_SET_H_

#include "../AVLTree/AVLTree.h"

namespace s21 {
template <typename Key>
class set : public AVL<Key, Key, false> {
 public:
  using Base = AVL<Key, Key, false>;
  using typename Base::const_iterator;
  using typename Base::const_reference;
  using typename Base::iterator;
  using typename Base::key_type;
  using typename Base::reference;
  using typename Base::size_type;
  using typename Base::value_type;

  set() = default;
  set(std::initializer_list<value_type> const& items) : Base(items) {}
  set(const set& other) : Base(other) {}
  set(set&& other) : Base(std::move(other)) {}
  ~set() {}
  set& operator=(set&& other) {
    Base::operator=(std::move(other));
    return *this;
  }

  set& operator=(const set& other) {
    if (this != &other) {
      Base::operator=(other);
    }
    return *this;
  }

  iterator begin() const { return Base::begin(); }
  iterator end() const { return Base::end(); }
  const_iterator cbegin() const { return Base::cbegin(); }
  const_iterator cend() const { return Base::cend(); }

  bool empty() const { return Base::empty(); }
  size_type size() const { return Base::size(); }
  size_type max_size() const { Base::max_size(); }

  void clear() { Base::clear(); }
  std::pair<iterator, bool> insert(const value_type& value) {
    return Base::insert(value);
  }
  void erase(iterator pos) { Base::erase(pos); }
  void swap(set& other) { Base::swap(other); }
  void merge(set& other) { Base::merge(other); }
  iterator find(const Key& key) const { return Base::find(key); }
  bool contains(const Key& key) const { return Base::contains(key); }

  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args&&... args) {
    return Base::insert_many(std::forward<Args>(args)...);
  }

  void printTree() const { Base::printTree(); }
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_CONTAINERS_SRC_SET_S21_SET_H_