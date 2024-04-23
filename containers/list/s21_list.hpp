#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_S21_LIST_HPP_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_S21_LIST_HPP_

#include <initializer_list>
#include <iostream>
#include <utility>

#include "iterators/const_list_iterator.hpp"
#include "iterators/list_iterator.hpp"

namespace s21 {
template <typename T>
class List {
 private:
  List_Node_<T> *tail_;
  List_Node_<T> *head_;
  List_Node_<T> *_sentinel;
  size_t size_;

 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using iterator = List_iterator<T>;
  using const_iterator = Const_list_iterator<T>;
  using size_type = size_t;

 public:
  List() : size_(0) {
    _sentinel = new List_Node_<T>();
    _sentinel->ptr_next_ = _sentinel;
    _sentinel->ptr_prev_ = _sentinel;
    head_ = _sentinel;
    tail_ = _sentinel;
  }

  List(size_t n) : List() {
    while (n-- > 0) push_back(T());
  }

  List(std::initializer_list<T> const &items) : List() {
    for (value_type i : items) push_back(i);
  }

  List(const List &other) : List() {
    for (List_Node_<T> *curr = other.head_; curr != other._sentinel;
         curr = curr->ptr_next_) {
      this->push_back(curr->value_);
    }
    this->size_ = other.size_;
  }

  List(List &&other) noexcept
      : tail_(other.tail_),
        head_(other.head_),
        _sentinel(other._sentinel),
        size_(other.size_)

  {
    other.size_ = 0;
    other._sentinel = nullptr;
    other.head_ = nullptr;
    other.tail_ = nullptr;
  }

  ~List() {
    clear();
    delete _sentinel;
  }

  List &operator=(List &&other) noexcept {
    if (this != &other) {
      clear();
      delete _sentinel;

      size_ = other.size_;
      _sentinel = other._sentinel;
      head_ = other.head_;
      tail_ = other.tail_;

      other.size_ = 0;
      other._sentinel = nullptr;
      other.head_ = nullptr;
      other.tail_ = nullptr;
    }
    return *this;
  }

  List &operator=(const List &other) {
    if (this != &other) {
      clear();

      for (List_Node_<T> *current = other._sentinel->ptr_next_;
           current != other._sentinel; current = current->ptr_next_) {
        push_back(current->value_);
      }
    }
    return *this;
  }

  const T &front() const {
    if (this->_sentinel->ptr_next_ == this->_sentinel) {
      throw std::out_of_range("List is empty");
    }
    return this->_sentinel->ptr_next_->value_;
  }

  const T &back() const {
    if (this->_sentinel->ptr_prev_ == this->_sentinel) {
      throw std::out_of_range("List is empty");
    }
    return this->_sentinel->ptr_prev_->value_;
  }

  iterator begin() const { return iterator(_sentinel->ptr_next_); }
  iterator end() const { return iterator(_sentinel); }
  const_iterator cbegin() const { return const_iterator(_sentinel->ptr_next_); }
  const_iterator cend() const { return const_iterator(_sentinel); }
  bool empty() const { return size_ == 0; }

  size_t size() const { return this->size_; }

  size_t max_size() const { return std::numeric_limits<T>::max(); }

  void clear() {
    if (_sentinel != nullptr) {
      List_Node_<T> *current = _sentinel->ptr_next_;
      while (current != _sentinel) {
        List_Node_<T> *temp = current;
        current = current->ptr_next_;
        delete temp;
      }
      _sentinel->ptr_next_ = _sentinel;
      _sentinel->ptr_prev_ = _sentinel;
      head_ = _sentinel;
      tail_ = _sentinel;
      size_ = 0;
    }
  }

  iterator insert(iterator pos, const_reference value) {
    if (empty() || pos == end()) {
      push_back(value);
      return iterator(tail_);
    }
    if (pos == begin()) {
      push_front(value);
      return iterator(head_);
    }
    List_Node_<T> *newNode = new List_Node_<T>(value);
    List_Node_<T> *current = pos.get_node();

    newNode->ptr_next_ = current;
    newNode->ptr_prev_ = current->ptr_prev_;
    if (current->ptr_prev_ != nullptr) current->ptr_prev_->ptr_next_ = newNode;
    current->ptr_prev_ = newNode;

    size_++;

    return iterator(newNode);
  }

  const_iterator insert(const_iterator pos, const_reference value) {
    if (empty() || pos == cend()) {
      push_back(value);
      return const_iterator(tail_);
    }
    if (pos == cbegin()) {
      push_front(value);
      return const_iterator(head_);
    }
    List_Node_<T> *newNode = new List_Node_<T>(value);
    List_Node_<T> *current = pos.get_node();

    newNode->ptr_next_ = current;
    newNode->ptr_prev_ = current->ptr_prev_;
    if (current->ptr_prev_ != nullptr) current->ptr_prev_->ptr_next_ = newNode;
    current->ptr_prev_ = newNode;

    size_++;

    return const_iterator(newNode);
  }

  void erase(iterator pos) {
    List_Node_<T> *node = pos.get_node();

    node->ptr_prev_->ptr_next_ = node->ptr_next_;
    node->ptr_next_->ptr_prev_ = node->ptr_prev_;

    delete node;
    size_--;
  }

  void push_back(const T &value) {
    List_Node_<T> *newNode =
        new List_Node_<T>(value, _sentinel->ptr_prev_, _sentinel);
    _sentinel->ptr_prev_->ptr_next_ = newNode;
    _sentinel->ptr_prev_ = newNode;
    size_++;
  }

  void push_front(const T &value) {
    List_Node_<T> *newNode =
        new List_Node_<T>(value, _sentinel, _sentinel->ptr_next_);
    _sentinel->ptr_next_->ptr_prev_ = newNode;
    _sentinel->ptr_next_ = newNode;
    size_++;
  }

  void pop_back() {
    if (size_ == 0) {
      return;
    }
    List_Node_<T> *nodeToRemove = _sentinel->ptr_prev_;

    _sentinel->ptr_prev_ = nodeToRemove->ptr_prev_;
    nodeToRemove->ptr_prev_->ptr_next_ = _sentinel;

    delete nodeToRemove;
    size_--;
  }

  void pop_front() {
    if (size_ == 0) {
      return;
    }
    List_Node_<T> *nodeToRemove = _sentinel->ptr_next_;

    _sentinel->ptr_next_ = nodeToRemove->ptr_next_;
    nodeToRemove->ptr_next_->ptr_prev_ = _sentinel;

    delete nodeToRemove;
    size_--;
  }

  void swap(List &other) {
    List temp;

    while (this->size() > 0) {
      auto value = this->front();
      this->pop_front();
      temp.push_back(value);
    }

    while (other.size() > 0) {
      auto value = other.front();
      other.pop_front();
      this->push_back(value);
    }

    while (temp.size() > 0) {
      auto value = temp.front();
      temp.pop_front();
      other.push_back(value);
    }
  }

  template <typename Compare = std::less<T>>
  void merge(List &other, Compare comp = Compare()) {
    if (this == &other || other.empty()) return;

    iterator it_this = this->begin();
    iterator it_other = other.begin();

    while (it_this != this->end() && it_other != other.end()) {
      if (comp(*it_other, *it_this)) {
        // Перемещаем узел из other перед it_this
        List_Node_<T> *node_to_move = it_other.get_node();
        ++it_other;  // Сначала сдвигаем итератор, потому что нода будет
                     // вырезана

        // Вырезаем node_to_move из other
        node_to_move->ptr_prev_->ptr_next_ = node_to_move->ptr_next_;
        node_to_move->ptr_next_->ptr_prev_ = node_to_move->ptr_prev_;
        other.size_--;

        // Вставляем node_to_move перед it_this
        node_to_move->ptr_next_ = it_this.get_node();
        node_to_move->ptr_prev_ = it_this.get_node()->ptr_prev_;
        it_this.get_node()->ptr_prev_->ptr_next_ = node_to_move;
        it_this.get_node()->ptr_prev_ = node_to_move;

        if (it_this == this->begin()) {
          this->_sentinel->ptr_next_ =
              node_to_move;  // Обновляем голову, если вставляем в начало
        }

        this->size_++;
      } else {
        ++it_this;
      }
    }

    // Если в other остались элементы, перемещаем оставшуюся часть в конец this
    if (it_other != other.end()) {
      this->_sentinel->ptr_prev_->ptr_next_ = it_other.get_node();
      it_other.get_node()->ptr_prev_ = this->_sentinel->ptr_prev_;

      this->_sentinel->ptr_prev_ = other._sentinel->ptr_prev_;
      other._sentinel->ptr_prev_->ptr_next_ = this->_sentinel;

      this->size_ += other.size_;
      other._sentinel->ptr_next_ = other._sentinel;
      other._sentinel->ptr_prev_ = other._sentinel;
      other.size_ = 0;
    }
  }

  void splice(const_iterator pos, List &other) {
    if (this == &other) {
      throw std::invalid_argument("Cannot splice a list with itself");
    }

    if (other.empty()) {
      return;
    }

    for (auto it = other.cbegin(); it != other.cend(); ++it) {
      insert(pos, *it);  // Вставляем копию элемента.
    }

    other.clear();
  }

  void reverse() {
    if (size_ <= 1) {
      return;
    }

    List_Node_<T> *current = _sentinel->ptr_next_;
    List_Node_<T> *temp = nullptr;

    do {
      temp = current->ptr_next_;
      current->ptr_next_ = current->ptr_prev_;
      current->ptr_prev_ = temp;

      current = temp;
    } while (current != _sentinel);

    temp = _sentinel->ptr_next_;
    _sentinel->ptr_next_ = _sentinel->ptr_prev_;
    _sentinel->ptr_prev_ = temp;
  }

  void unique() {
    if (size_ <= 1) {
      return;
    }

    List_Node_<T> *current = _sentinel->ptr_next_;

    while (current != _sentinel && current->ptr_next_ != _sentinel) {
      if (current->value_ == current->ptr_next_->value_) {
        List_Node_<T> *duplicate = current->ptr_next_;
        current->ptr_next_ = duplicate->ptr_next_;

        if (duplicate->ptr_next_ != _sentinel) {
          duplicate->ptr_next_->ptr_prev_ = current;
        }

        delete duplicate;
        size_--;
      } else {
        current = current->ptr_next_;
      }
    }
  }

  void sort() {
    if (size_ <= 1) {
      return;
    }

    bool swapped = true;
    while (swapped) {
      swapped = false;
      List_Node_<T> *current = _sentinel->ptr_next_;

      while (current->ptr_next_ != _sentinel) {
        if (current->value_ > current->ptr_next_->value_) {
          std::swap(current->value_, current->ptr_next_->value_);
          swapped = true;
        }

        current = current->ptr_next_;
      }
    }
  }

  template <typename... Args>
  iterator insert_many(iterator pos, Args &&...args) {
    (..., insert(pos, std::forward<Args>(args)));
    return pos;
  }

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (push_back(std::forward<Args>(args)), ...);
  }

  void insert_helper([[maybe_unused]] List<T> &list) {}

  template <typename Arg, typename... Args>
  void insert_helper(List<T> &list, Arg &&arg, Args &&...args) {
    insert_helper(list, std::forward<Args>(args)...);
    list.push_front(std::forward<Arg>(arg));
  }

  template <typename... Args>
  void insert_many_front(Args &&...args) {
    insert_helper(*this, std::forward<Args>(args)...);
  }

  void print() const {
    for (auto it = this->begin(); it != this->end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }
};
}  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_S21_LIST_HPP_