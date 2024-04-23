#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_DEQUE_ITERATORS_DEQUE_ITERATOR_H_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_DEQUE_ITERATORS_DEQUE_ITERATOR_H_

#include "../dequeNode/deque_node.h"

namespace s21 {

template <typename Value>
class dequeIterator {
  friend class dequeNode<Value>;

 public:
  using value_type = Value;
  dequeIterator()
      : curNode_(nullptr),
        dequeHead_(nullptr),
        dequeTail_(nullptr),
        isEnd_(true){};
  dequeIterator(dequeNode<Value> *const *head)
      : curNode_(nullptr), dequeHead_(head), dequeTail_(head), isEnd_(true) {}
  dequeIterator(dequeNode<Value> *curNode, dequeNode<Value> *const *head,
                dequeNode<Value> *const *tail)
      : curNode_(curNode), dequeHead_(head), dequeTail_(tail), isEnd_(false) {
    if (curNode == nullptr) isEnd_ = true;
  }

  dequeIterator(const dequeIterator &other) = default;
  dequeIterator &operator=(const dequeIterator &other) = default;

  dequeIterator operator++() {
    auto next = getNext(curNode_);
    curNode_ = next;
    if (next == nullptr) {
      isEnd_ = true;
    }
    return *this;
  }

  dequeIterator operator++(int) {
    auto curState = *this;
    auto next = getNext(curNode_);
    curNode_ = next;
    if (next == nullptr) {
      isEnd_ = true;
    }
    return curState;
  }

  dequeIterator operator--() {
    if (isEnd_) {
      curNode_ = getLastNode();
      isEnd_ = false;
    } else {
      curNode_ = getPrev(curNode_);
    }
    return *this;
  }

  dequeIterator operator--(int) {
    auto curState = *this;
    if (isEnd_) {
      curNode_ = getLastNode();
      isEnd_ = false;
    } else {
      curNode_ = getPrev(curNode_);
    }
    return curState;
  }
  dequeNode<Value> *getCurrent() const { return curNode_; }
  void setCurrent(dequeNode<Value> *newNode) { curNode_ = newNode; }
  value_type *operator->() const { return &curNode_->getValue(); }

  value_type &operator*() const { return curNode_->getValue(); }

  bool operator==(const dequeIterator &other) const {
    return other.dequeHead_ == dequeHead_ && other.dequeTail_ == dequeTail_ &&
           other.curNode_ == curNode_ && other.isEnd_ == isEnd_;
  }

  bool operator!=(const dequeIterator &other) const {
    return !(other == *this);
  }

  dequeNode<value_type> *getLastNode() {
    if (dequeTail_) return *dequeTail_;
    return nullptr;
  }

  dequeNode<value_type> *getFirstNode() {
    if (dequeHead_) return *dequeHead_;
    return nullptr;
  }

  static dequeNode<value_type> *getNext(dequeNode<value_type> *curNode) {
    if (curNode != nullptr) {
      curNode = curNode->getNext();
    }
    return curNode;
  }

  static dequeNode<value_type> *getPrev(dequeNode<value_type> *curNode) {
    if (curNode != nullptr) {
      curNode = curNode->getPrev();
    }
    return curNode;
  }

 private:
  dequeNode<Value> *curNode_;
  dequeNode<Value> *const *dequeHead_;
  dequeNode<Value> *const *dequeTail_;
  bool isEnd_;
};

};  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_DEQUE_ITERATORS_DEQUE_ITERATOR_H_