#ifndef CPP2_S21_CONTAINERS_1_SRC_AVLTREE_TREENODE_AVL_TREE_NODE_H_
#define CPP2_S21_CONTAINERS_1_SRC_AVLTREE_TREENODE_AVL_TREE_NODE_H_
#include <type_traits>

namespace s21 {

template <typename Value, bool returnPair>

class AVLTreeNode {
 public:
  using value_type = Value;

 private:
  value_type data_;
  AVLTreeNode<Value, returnPair> *parent_;
  AVLTreeNode<Value, returnPair> *left_;
  AVLTreeNode<Value, returnPair> *right_;

 public:
  AVLTreeNode<Value, returnPair>()
      : data_(value_type()),
        parent_(nullptr),
        left_(nullptr),
        right_(nullptr) {}
  AVLTreeNode<Value, returnPair>(const value_type &val)
      : data_(val), parent_(nullptr), left_(nullptr), right_(nullptr) {}
  AVLTreeNode<Value, returnPair>(const AVLTreeNode<Value, returnPair> &other)
      : data_(other.data_), parent_(nullptr), left_(nullptr), right_(nullptr) {}
  AVLTreeNode<Value, returnPair> *getParent() const { return parent_; }
  void setParent(AVLTreeNode<Value, returnPair> *parentNode) {
    parent_ = parentNode;
  }
  AVLTreeNode<Value, returnPair> *getLeftChild() const { return left_; }
  void setLeftChild(AVLTreeNode<Value, returnPair> *leftNode) {
    left_ = leftNode;
  }
  AVLTreeNode<Value, returnPair> *getRightChild() const { return right_; }
  void setRightChild(AVLTreeNode<Value, returnPair> *rightNode) {
    right_ = rightNode;
  }
  value_type &getValue() { return data_; }
  void setValue(const value_type &val) {
    if constexpr (returnPair) {
      data_.second = val.second;
    } else {
      data_ = val;
    }
  }
};
}  // namespace s21
#endif  //  CPP2_S21_CONTAINERS_1_SRC_AVLTREE_TREENODE_AVL_TREE_NODE_H_