#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERSPLUS_ARRAY_S21_ARRAY_HPP_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERSPLUS_ARRAY_S21_ARRAY_HPP_

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <utility>

namespace s21 {

template <typename T, size_t N>
class Array {
 public:
  // Member type
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

  // Functions
  Array() = default;
  Array(std::initializer_list<value_type> const &items) {
    if (items.size() != N) {
      throw std::invalid_argument(
          "Initializer list size doesn't match array size");
    }
    std::copy(items.begin(), items.end(), data_);
  }
  Array(const Array &a) { std::copy(a.data_, a.data_ + N, data_); }
  Array(Array &&a) noexcept { std::move(a.data_, a.data_ + N, data_); }
  ~Array() = default;
  Array &operator=(Array &&a) noexcept {
    std::move(a.data_, a.data_ + N, data_);
    return *this;
  }
  Array &operator=(const Array<T, N> &a) {
    std::copy(a.data_, a.data_ + N, data_);

    return *this;
  }

  // Element access
  reference at(size_type pos) {
    if (pos >= N) {
      throw std::out_of_range("pos out of range");
    }
    return data_[pos];
  }

  reference operator[](size_type pos) {
    if (pos >= N) {
      throw std::out_of_range("Index out of range");
    }
    return data_[pos];
  }

  const_reference operator[](size_type pos) const {
    if (pos >= N) {
      throw std::out_of_range("Index out of range");
    }
    return data_[pos];
  }
  const_reference front() const noexcept { return data_[0]; }
  const_reference back() const noexcept { return data_[N - 1]; }
  iterator data() { return begin(); }

  // Iterators
  iterator begin() { return data_; }
  iterator end() { return data_ + N; }

  // Capacity
  bool empty() const { return N == 0; }
  size_type size() const { return N; }
  size_type max_size() const { return N; }

  // Modifiers
  void swap(Array &other) { std::swap_ranges(begin(), end(), other.begin()); }
  void fill(const_reference value) { std::fill(begin(), end(), value); }

 private:
  value_type data_[N] = {};
};

}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_CONTAINERSPLUS_ARRAY_S21_ARRAY_HPP_