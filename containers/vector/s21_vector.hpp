#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_VECTOR_S21_VECTOR_HPP
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_VECTOR_S21_VECTOR_HPP

#include <initializer_list>
#include <iostream>
#include <utility>

namespace s21 {
template <typename T>
class Vector {
  // === Private attributes ===
 private:
  size_t m_size;
  size_t m_capacity;
  T *arr;

 public:
  // === Vector Member type ===
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = T *;
  using const_iterator = const T *;
  using size_type = size_t;

 public:
  // === Vector Member functions ===
  Vector();
  explicit Vector(size_type n);
  Vector(std::initializer_list<value_type> const &items);
  Vector(const Vector &v);
  Vector(Vector &&v);
  ~Vector();
  Vector &operator=(Vector &&v) noexcept;
  Vector &operator=(const Vector &v) noexcept;
  // === Vector Element access ===
  reference at(size_type pos);
  reference operator[](size_type pos);
  const_reference operator[](size_type pos) const;
  const_reference front() const;
  const_reference back() const;
  T *data();
  // === Vector Iterators ===
  iterator begin() const;
  iterator end() const;
  const_iterator cbegin() const;
  const_iterator cend() const;
  // === Vector Capacity ===
  bool empty() const;
  size_type size() const;
  size_type max_size() const;
  void reserve(size_type size);
  size_type capacity() const;
  void shrink_to_fit();
  // === Vector Modifiers ===
  void clear();
  iterator insert(iterator pos, const_reference value);
  void erase(iterator pos);
  void push_back(const_reference value);
  void pop_back();
  void swap(Vector &other);
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args &&...args);
  template <typename... Args>
  void insert_many_back(Args &&...args);
};

template <typename T>
Vector<T>::Vector() : m_size(0U), m_capacity(0U), arr(nullptr) {}

template <typename T>
Vector<T>::Vector(size_t n)
    : m_size(n), m_capacity(n), arr(n ? new T[n] : nullptr) {
  for (size_t i = 0; i != n; i++) {
    arr[i] = value_type();
  }
}

template <typename T>
Vector<T>::Vector(std::initializer_list<T> const &items) {
  arr = new T[items.size()];
  int i = 0;
  for (auto it = items.begin(); it != items.end(); it++) {
    arr[i] = *it;
    i++;
  }
  m_size = items.size();
  m_capacity = items.size();
}

template <typename T>
Vector<T>::Vector(const Vector &v)
    : m_size(v.m_size), m_capacity(v.m_capacity), arr(new T[v.m_capacity]) {
  std::copy(v.arr, v.arr + v.m_size, arr);
}

template <typename T>
Vector<T>::Vector(Vector &&v)
    : m_size(v.m_size), m_capacity(v.m_capacity), arr(v.arr) {
  v.arr = nullptr;
  v.m_size = 0;
  v.m_capacity = 0;
}

template <typename T>
Vector<T>::~Vector() {
  delete[] arr;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector &&v) noexcept {
  if (this != &v) {
    this->swap(v);
    delete[] v.arr;
    v.m_size = 0;
    v.m_capacity = 0;
    v.arr = nullptr;
  }

  return *this;
}
template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &v) noexcept {
  if (this != &v) {  // Check for self-assignment
    // Delete the existing memory
    delete[] arr;

    // Copy the size and capacity
    m_size = v.m_size;
    m_capacity = v.m_capacity;

    // Allocate new memory
    arr = new T[m_capacity];

    // Copy the elements
    std::copy(v.arr, v.arr + v.m_size, arr);
  }
  return *this;
}
// === Vector Element access ===
template <typename T>
T &Vector<T>::at(size_type i) {
  if (i >= m_size) {
    throw std::out_of_range("Index out of range!");
  }
  return arr[i];
}

template <typename T>
T &Vector<T>::operator[](size_type pos) {
  if (pos >= m_size) {
    throw std::out_of_range("Index out of range!");
  }
  return arr[pos];
}
template <typename T>
const T &Vector<T>::operator[](size_type pos) const {
  if (pos >= m_size) {
    throw std::out_of_range("Index out of range!");
  }
  return arr[pos];
}

template <typename T>
const T &Vector<T>::front() const {
  return arr[0];
}

template <typename T>
const T &Vector<T>::back() const {
  return arr[m_size - 1];
}

template <typename T>
T *Vector<T>::data() {
  return arr;
}

// === Vector Iterators ===
template <typename T>
T *Vector<T>::begin() const {
  return iterator(arr);
}

template <typename T>
T *Vector<T>::end() const {
  return iterator(arr + m_size);
}

template <typename T>
const T *Vector<T>::cbegin() const {
  return const_iterator(arr);
}

template <typename T>
const T *Vector<T>::cend() const {
  return const_iterator(arr + m_size);
}

// === Vector Capacity ===
template <typename T>
bool Vector<T>::empty() const {
  return m_size == 0;
}

template <typename T>
size_t Vector<T>::size() const {
  return m_size;
}

template <typename T>
size_t Vector<T>::max_size() const {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type);
}

template <typename T>
void Vector<T>::reserve(size_type size) {
  if (size <= m_capacity) {
    return;
  }

  if (size > max_size()) {
    throw std::out_of_range("ReserveError: Too large size for a new capacity");
  }

  iterator new_data = new value_type[size];
  std::copy(arr, arr + m_size, new_data);
  delete[] arr;
  arr = new_data;
  m_capacity = size;
}

template <typename T>
size_t Vector<T>::capacity() const {
  return m_capacity;
}

template <typename T>
void Vector<T>::shrink_to_fit() {
  if (m_size < m_capacity) {
    iterator new_data = new value_type[m_size];
    std::copy(arr, arr + m_size, new_data);
    delete[] arr;
    arr = new_data;
    m_capacity = m_size;
  }
}

// === Vector Modifiers ===
template <typename T>
void Vector<T>::clear() {
  delete[] arr;
  arr = nullptr;
  m_size = 0;
}

template <typename T>
T *Vector<T>::insert(iterator pos, const_reference value) {
  Vector<value_type> tmp(m_size + 1);
  size_type j = 0, position = pos - this->begin();
  for (size_type i = 0; i < tmp.m_size; ++i) {
    if (i == position) {
      tmp.arr[i] = value;
    } else {
      tmp.arr[i] = arr[j++];
    }
  }
  *this = std::move(tmp);
  return arr + position;
}

template <typename T>
void Vector<T>::erase(iterator pos) {
  Vector<value_type> tmp(m_size - 1);
  size_type j = 0, position = pos - this->begin();
  for (size_type i = 0; i < m_size; ++i) {
    if (i != position) {
      tmp.arr[j++] = arr[i];
    }
  }
  *this = std::move(tmp);
}

template <typename T>
void Vector<T>::push_back(const_reference value) {
  if (m_capacity > m_size) {
    arr[m_size] = value;
    m_size += 1;
  } else {
    Vector<value_type> tmp(m_size + 1);
    for (size_type i = 0; i < m_size; ++i) {
      tmp.arr[i] = arr[i];
    }
    tmp[m_size] = value;
    *this = std::move(tmp);
  }
}

template <typename T>
void Vector<T>::pop_back() {
  m_size -= 1;
}

template <typename T>
void Vector<T>::swap(Vector &other) {
  value_type *tmp_arr = arr;
  size_type tmp_size = m_size;
  size_type tmp_capacity = m_capacity;
  arr = other.arr;
  m_size = other.m_size;
  m_capacity = other.m_capacity;
  other.arr = tmp_arr;
  other.m_size = tmp_size;
  other.m_capacity = tmp_capacity;
}

template <typename T>
template <typename... Args>
typename Vector<T>::iterator Vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  size_type index = pos - arr;
  size_type n = sizeof...(args);
  if (m_size + n > m_capacity) {
    reserve((m_size + n) * 2);
  }
  if (index < m_size) {
    std::move_backward(arr + index, arr + m_size, arr + m_size + n);
  }
  auto inserter = [this, &index](auto &&arg) {
    new (arr + index) T(std::forward<decltype(arg)>(arg));
    ++index;
  };
  (inserter(std::forward<Args>(args)), ...);

  m_size += n;
  return arr + index - n;
}

template <typename T>
template <typename... Args>
void Vector<T>::insert_many_back(Args &&...args) {
  size_t n = sizeof...(args);
  if (m_size + n > m_capacity) {
    reserve((m_size + n) * 2);
  }
  auto inserter = [this](auto &&arg) {
    new (arr + m_size) T(std::forward<decltype(arg)>(arg));
    ++m_size;
  };
  (inserter(std::forward<Args>(args)), ...);
}

}  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_VECTOR_S21_VECTOR_HPP