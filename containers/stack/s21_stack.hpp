#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_STACK_S21_STACK_HPP_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_STACK_S21_STACK_HPP_

#include <initializer_list>
#include <iostream>
#include <utility>

#include "../list/s21_list.hpp"

namespace s21 {
template <typename T>
class Stack {
 public:
  using value_type = T;
  using reference = value_type &;
  using const_reference = const value_type &;
  using size_type = size_t;

 private:
  List<value_type> data_;

 public:
  // Member functions
  Stack() { data_.clear(); }

  Stack(std::initializer_list<value_type> const &items) {
    data_.clear();
    for (const auto &i : items) {
      push(i);
    }
  }

  Stack(const Stack &s) { operator=(s); }

  Stack(Stack &&s) { operator=(std::move(s)); }

  ~Stack() { data_.clear(); }

  Stack &operator=(Stack &&s) {
    this->data_ = std::move(s.data_);
    return *this;
  }

  Stack &operator=(const Stack &s) {
    this->data_ = s.data_;
    return *this;
  }

  // Element access
  const_reference top() const { return data_.front(); }

  // Capacity
  bool empty() const { return data_.empty(); }
  size_type size() const { return data_.size(); }

  // Modifiers
  void push(const_reference value) { data_.push_front(value); }
  void pop() { data_.pop_front(); }
  void swap(Stack &other) { data_.swap(other.data_); }
  template <typename... Args>
  void insert_many_front(Args &&...args) {
    data_.insert_many_front(std::forward<Args>(args)...);
  }
};
}  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_STACK_S21_STACK_HPP_