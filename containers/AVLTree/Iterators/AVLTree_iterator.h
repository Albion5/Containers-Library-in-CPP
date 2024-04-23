#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_AVLTREE_ITERATORS_AVLTREE_ITERATOR_H_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_AVLTREE_ITERATORS_AVLTREE_ITERATOR_H_

#include "../AVLTreeNode/AVLTree_tree_node.h"

namespace s21 {

template <typename Value, bool returnPair>
class AVLTreeIterator {
  friend class AVLTreeNode<Value, returnPair>;

 public:
  using value_type = Value;

  using Node = AVLTreeNode<Value, returnPair>;
  AVLTreeIterator() : curNode_(nullptr), treeRoot_(nullptr), isEnd_(true){};
  AVLTreeIterator(Node *const *root)
      : curNode_(nullptr), treeRoot_(root), isEnd_(true) {}
  AVLTreeIterator(Node *curNode, Node *const *root)
      : curNode_(curNode), treeRoot_(root), isEnd_(false) {
    if (curNode == nullptr) isEnd_ = true;
  }

  AVLTreeIterator(const AVLTreeIterator &other) = default;
  AVLTreeIterator &operator=(const AVLTreeIterator &other) = default;

  AVLTreeIterator operator++() {
    auto next = getNext(curNode_);
    curNode_ = next;
    if (next == nullptr) {
      isEnd_ = true;
    }
    return *this;
  }

  AVLTreeIterator operator++(int) {
    auto curState = *this;
    auto next = getNext(curNode_);
    curNode_ = next;
    if (next == nullptr) {
      isEnd_ = true;
    }
    return curState;
  }

  AVLTreeIterator operator--() {
    if (isEnd_) {
      curNode_ = getMaxNodeRecursive(*treeRoot_);
      isEnd_ = false;
    } else {
      curNode_ = getPrev(curNode_);
    }
    return *this;
  }

  AVLTreeIterator operator--(int) {
    auto curState = *this;
    if (isEnd_) {
      curNode_ = getMaxNodeRecursive(*treeRoot_);
      isEnd_ = false;
    } else {
      curNode_ = getPrev(curNode_);
    }
    return curState;
  }

  Node *getCurrent() const { return curNode_; }
  value_type *operator->() const { return &(curNode_->getValue()); }
  value_type &operator*() const { return curNode_->getValue(); }

  bool operator==(const AVLTreeIterator &other) const {
    return other.treeRoot_ == treeRoot_ && other.curNode_ == curNode_ &&
           other.isEnd_ == isEnd_;
  }

  bool operator!=(const AVLTreeIterator &other) const {
    return !(other == *this);
  }

  static Node *getMinNodeRecursive(Node *curNode) {
    if (curNode == nullptr || curNode->getLeftChild() == nullptr)
      return curNode;
    return getMinNodeRecursive(curNode->getLeftChild());
  }

  static Node *getMaxNodeRecursive(Node *curNode) {
    if (curNode == nullptr || curNode->getRightChild() == nullptr)
      return curNode;
    return getMaxNodeRecursive(curNode->getRightChild());
  }

  static Node *getNext(Node *curNode) {
    if (curNode != nullptr) {
      if (curNode->getRightChild() != nullptr) {
        curNode = getMinNodeRecursive(curNode->getRightChild());
      } else {
        Node *nodeParent = curNode->getParent();
        while (nodeParent && (curNode == nodeParent->getRightChild())) {
          curNode = nodeParent;
          nodeParent = nodeParent->getParent();
        }
        curNode = nodeParent;
      }
    }
    return curNode;
  }

  static Node *getPrev(Node *curNode) {
    if (curNode != nullptr) {
      if (curNode->getLeftChild() != nullptr) {
        curNode = getMaxNodeRecursive(curNode->getLeftChild());
      } else {
        Node *nodeParent = curNode->getParent();
        while (nodeParent && (curNode == nodeParent->getLeftChild())) {
          curNode = nodeParent;
          nodeParent = nodeParent->getParent();
        }
        curNode = nodeParent;
      }
    }
    return curNode;
  }

 private:
  Node *curNode_;
  Node *const *treeRoot_;
  bool isEnd_;
};

};  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_AVLTREE_ITERATORS_AVLTREE_ITERATOR_H_