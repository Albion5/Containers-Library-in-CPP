#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_ITERATORS_CONST_LIST_ITERATOR_HPP_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_ITERATORS_CONST_LIST_ITERATOR_HPP_

#include "../ListNode/list_node.hpp"

namespace s21 {

template <typename T>
class Const_list_iterator {
 public:
  using pointer = List_Node_<T> *;  // Константный указатель на узел списка

  // Конструкторы и операторы
  Const_list_iterator() : node_(nullptr) {}
  explicit Const_list_iterator(pointer node) : node_(node) {}
  Const_list_iterator(const Const_list_iterator &other) = default;
  Const_list_iterator &operator=(const Const_list_iterator &other) = default;
  ~Const_list_iterator() = default;

  // Операторы инкремента и декремента
  Const_list_iterator &operator++() {
    if (node_ != nullptr) node_ = node_->ptr_next_;
    return *this;
  }

  Const_list_iterator &operator--() {
    if (node_ != nullptr) node_ = node_->ptr_prev_;
    return *this;
  }

  const T &operator*() const { return node_->value_; }
  const T *operator->() const { return &(node_->value_); }

  friend bool operator==(const Const_list_iterator &lhs,
                         const Const_list_iterator &rhs) {
    return lhs.node_ == rhs.node_;
  }
  friend bool operator!=(const Const_list_iterator &lhs,
                         const Const_list_iterator &rhs) {
    return !(lhs == rhs);
  }

  List_Node_<T> *get_node() const { return node_; }

 private:
  pointer node_;  // Текущий узел
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_CONSTAINERS_LIST_ITERATORS_CONST_LIST_ITERATOR_HPP_
