#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_ITERATORS_LIST_ITERATOR_HPP_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_ITERATORS_LIST_ITERATOR_HPP_

#include "../ListNode/list_node.hpp"

namespace s21 {

template <typename T>
class List_iterator {
 private:
  using ptr = List_Node_<T> *;  // Указатель на узел списка

 public:
  using iterator_category = std::bidirectional_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = T *;
  using reference = T &;

  // Конструкторы
  List_iterator() : node_(nullptr) {}
  explicit List_iterator(ptr node) : node_(node) {}
  List_iterator(const List_iterator &other) = default;
  List_iterator &operator=(const List_iterator &other) = default;
  ~List_iterator() = default;

  // Операторы
  // Префиксный инкремент
  List_iterator &operator++() {
    if (node_ != nullptr) node_ = node_->ptr_next_;
    return *this;
  }

  // Префиксный декремент
  List_iterator &operator--() {
    if (node_ != nullptr) node_ = node_->ptr_prev_;
    return *this;
  }

  // Разыменование
  T &operator*() const { return node_->value_; }
  T *operator->() const { return &(node_->value_); }

  // Операторы сравнения
  friend bool operator==(const List_iterator &lhs, const List_iterator &rhs) {
    return lhs.node_ == rhs.node_;
  }
  friend bool operator!=(const List_iterator &lhs, const List_iterator &rhs) {
    return !(lhs == rhs);
  }

  List_Node_<T> *get_node() const { return node_; }

 private:
  ptr node_;  // Текущий узел
};

}  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_ITERATORS_LIST_ITERATOR_HPP_
