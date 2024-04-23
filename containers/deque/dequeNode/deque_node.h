#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_DEQUE_DEQUE_NODE_H_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_DEQUE_DEQUE_NODE_H_

namespace s21 {

template <typename Value>
class dequeNode {
 public:
  using value_type = Value;

 public:
  dequeNode<Value>() : data_(value_type()), next_(nullptr), prev_(nullptr) {}
  dequeNode<Value>(const value_type &val)
      : data_(val), next_(nullptr), prev_(nullptr) {}
  dequeNode<Value>(const value_type &val, dequeNode<Value> *next,
                   dequeNode<Value> *prev)
      : data_(val), next_(next), prev_(prev) {}
  dequeNode<Value>(const dequeNode<Value> &other)
      : data_(other.data_), next_(other.next_), prev_(other.prev_) {}
  dequeNode<Value> *getPrev() const { return prev_; }
  void setPrev(dequeNode<Value> *prevNode) { prev_ = prevNode; }
  dequeNode<Value> *getNext() const { return next_; }
  void setNext(dequeNode<Value> *nextNode) { next_ = nextNode; }
  value_type &getValue() { return data_; }
  void setValue(const value_type &val) { data_ = val; }

 private:
  value_type data_;
  dequeNode<Value> *next_;
  dequeNode<Value> *prev_;
};
}  // namespace s21
#endif  //  CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_DEQUE_DEQUE_NODE_H_