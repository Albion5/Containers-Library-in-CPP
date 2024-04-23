#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_QUEUE_S21_QUEUE_H_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_QUEUE_S21_QUEUE_H_

#include <iostream>

#include "../deque/deque.h"

namespace s21 {
template <class T>
class queue : public deque<T> {
 public:
  using Base = deque<T>;
  using typename Base::const_reference;
  using typename Base::reference;
  using typename Base::size_type;
  using typename Base::value_type;

  queue() = default;
  queue(std::initializer_list<value_type> const &items) : Base(items) {}
  queue(const queue &other) : Base(other) {}
  queue(queue &&other) : Base(std::move(other)) {}
  ~queue() {}

  const_reference front() const { return Base::front(); }
  const_reference back() const { return Base::back(); }
  bool empty() const { return Base::empty(); }
  size_type size() const { return Base::size(); }
  void push(const_reference value) { Base::push_back(value); }
  void pop() { Base::pop_front(); }

  void swap(queue &other) { Base::swap(other); }

  template <class... Args>
  void insert_many_back(Args &&...args) {
    Base::insert_many_back(std::forward<Args>(args)...);
  }

  queue &operator=(const queue &other) {
    Base::operator=(other);
    return *this;
  }
  queue &operator=(queue &&other) noexcept {
    Base::operator=(std::move(other));
    return *this;
  }
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_QUEUE_S21_QUEUE_H_