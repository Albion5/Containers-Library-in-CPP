#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_DEQUE_DEQUE_H_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_DEQUE_DEQUE_H_

#include <iostream>

#include "Iterators/deque_iterator.h"
#include "dequeNode/deque_node.h"
namespace s21 {

template <class T>
class deque {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = std::size_t;
  using iterator = dequeIterator<value_type>;

  deque() : head_(nullptr), tail_(nullptr), size_(0) {}
  ~deque() { clear(); }
  deque(std::initializer_list<value_type> const &items)
      : head_(nullptr), tail_(nullptr), size_(0) {
    for (const auto &item : items) {
      push_back(item);
    }
  }

  deque(const deque &other) {
    auto ends = copyDeque(other.head_);
    head_ = ends.first;
    tail_ = ends.second;
    size_ = other.size_;
  }

  deque(deque &&other) {
    // Move the contents of 'other' to 'this'
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;

    // Leave 'other' in a valid, but unspecified state
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
  }

  void push_front(const_reference data) {
    dequeNode<value_type> *newNode = new dequeNode<value_type>(data);
    if (empty()) {
      head_ = newNode;
      tail_ = newNode;
    } else {
      newNode->setNext(head_);
      head_->setPrev(newNode);
      head_ = newNode;
    }
    size_++;
  }

  void pop_front() {
    if (empty()) {
      throw std::out_of_range("deque::pop_front(): deque is empty");
    }
    if (head_ == tail_) {
      delete head_;
      head_ = nullptr;
      tail_ = nullptr;
    } else {
      dequeNode<value_type> *nextNode = head_->getNext();
      delete head_;
      head_ = nextNode;
      head_->setPrev(nullptr);
    }
    size_--;
  }

  void push_back(const_reference data) {
    dequeNode<value_type> *newNode = new dequeNode<value_type>(data);
    if (empty()) {
      head_ = newNode;
      tail_ = newNode;
    } else {
      tail_->setNext(newNode);
      newNode->setPrev(tail_);
      tail_ = newNode;
    }
    size_++;
  }

  void pop_back() {
    if (empty()) {
      throw std::out_of_range("deque::pop_back(): deque is empty");
    }
    if (head_ == tail_) {
      delete tail_;
      head_ = nullptr;
      tail_ = nullptr;
    } else {
      dequeNode<value_type> *prevNode = tail_->getPrev();
      delete tail_;
      tail_ = prevNode;
      tail_->setNext(nullptr);
    }
    size_--;
  }

  const_reference front() const {
    if (empty()) {
      throw std::out_of_range("deque::front(): deque is empty");
    }
    return head_->getValue();
  }

  const_reference back() const {
    if (empty()) {
      throw std::out_of_range("deque::back(): deque is empty");
    }
    return tail_->getValue();
  }

  bool empty() const { return size_ == 0; }
  size_type size() const { return size_; };

  void swap(deque &other) {
    std::swap(head_, other.head_);
    std::swap(tail_, other.tail_);
    std::swap(size_, other.size_);
  }

  void clear() {
    while (!empty()) {
      pop_front();
    }
    head_ = nullptr;
    tail_ = nullptr;
    size_ = 0;
  }

  deque &operator=(const deque &other) {
    if (this != &other) {
      clear();
      auto ends = copyDeque(other.head_);
      head_ = ends.first;
      tail_ = ends.second;
      size_ = other.size_;
    }
    return *this;
  }

  deque &operator=(deque &&other) {
    clear();  // Clear the current contents
    // Move the contents of 'other' to 'this'
    head_ = other.head_;
    tail_ = other.tail_;
    size_ = other.size_;

    // Leave 'other' in a valid, but unspecified state
    other.head_ = nullptr;
    other.tail_ = nullptr;
    other.size_ = 0;
    return *this;
  }

  std::pair<dequeNode<value_type> *, dequeNode<value_type> *> copyDeque(
      dequeNode<value_type> *curNode) {
    dequeNode<value_type> *newHead = nullptr;
    dequeNode<value_type> *newTail = nullptr;
    while (curNode != nullptr) {
      dequeNode<value_type> *copyNode = new dequeNode<value_type>(*curNode);
      if (newHead == nullptr) {
        newHead = copyNode;
      } else {
        newTail->setNext(copyNode);
        copyNode->setPrev(newTail);
      }
      newTail = copyNode;
      curNode = curNode->getNext();
    }
    return std::make_pair(newHead, newTail);
  }

  template <class... Args>
  void insert_many_back(Args &&...args) {
    for (const auto &arg : {args...}) {
      push_back(arg);
    }
  }

  iterator begin() const { return iterator(head_, &head_, &tail_); }

  iterator end() const { return iterator(nullptr, &head_, &tail_); }

  void printDeque() const {
    std::cout << "Deque elements: ";
    for (iterator it = begin(); it != end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }

 private:
  dequeNode<value_type> *head_;
  dequeNode<value_type> *tail_;
  size_type size_;
};
}  // namespace s21

#endif  // CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_DEQUE_DEQUE_H_