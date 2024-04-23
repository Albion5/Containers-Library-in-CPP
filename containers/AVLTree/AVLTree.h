#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_AVLTREE_AVLTREE_H
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_AVLTREE_AVLTREE_H
#include <algorithm>  // For std::swap
#include <initializer_list>
#include <limits>
#include <type_traits>  // For std::conditional

#include "AVLTreeNode/AVLTree_tree_node.h"
#include "Iterators/AVLTree_const_iterator.h"
#include "Iterators/AVLTree_iterator.h"
namespace s21 {

template <typename Key, typename T, bool returnPair = true,
          bool uniqueKeys = true>
class AVL {
 public:
  using value_type =
      std::conditional_t<returnPair, std::pair<const Key, T>, Key>;
  using key_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using pointer = value_type *;
  using const_pointer = const value_type *;
  using iterator =
      std::conditional_t<returnPair, AVLTreeIterator<value_type, returnPair>,
                         ConstAVLTreeIterator<value_type, returnPair>>;
  using const_iterator = ConstAVLTreeIterator<value_type, returnPair>;
  using size_type = std::size_t;
  using Node = AVLTreeNode<value_type, returnPair>;

  AVL() : root_(nullptr), size_(0) {}
  AVL(std::initializer_list<value_type> const &items)
      : root_(nullptr), size_(0) {
    for (const auto &item : items) {
      insert(item);
    }
  }

  ~AVL() { clear(); }

  AVL(const AVL<Key, T, returnPair, uniqueKeys> &other) {
    if (this != &other) {
      root_ = copyTree(other.root_);
      size_ = other.size_;
    }
  }

  AVL(AVL<Key, T, returnPair, uniqueKeys> &&other) {
    root_ = other.root_;
    size_ = other.size_;

    // Leave 'other' in a valid, but unspecified state
    other.root_ = nullptr;
    other.size_ = 0;
  }

  iterator begin() const { return iterator(getMinNode(), &root_); }

  iterator end() const { return iterator(&root_); }

  const_iterator cbegin() const { return const_iterator(getMinNode(), &root_); }
  const_iterator cend() const { return const_iterator(&root_); }
  size_type max_size() const {
    return std::numeric_limits<size_type>::max() / sizeof(Node);
  }

  size_type size() const { return size_; }
  bool empty() const { return size_ == 0; }
  void erase(iterator pos) {
    if (pos.getCurrent() == nullptr) {
      return;
    }
    deleteNode(getKey(pos.getCurrent()));
  }

  void inOrderTraversal() const { inOrderTraversalRecursive(root_); }

  void merge(AVL<Key, T, returnPair, uniqueKeys> &other) {
    if (this == &other) {
      return;
    }
    mergeRecursive(other.root_);
    other.clear();
  }

  void swap(AVL<Key, T, returnPair, uniqueKeys> &other) {
    std::swap(root_, other.root_);
    std::swap(size_, other.size_);
  }

  void deleteNode(key_type oldKey) {
    root_ = deleteNodeRecursive(root_, oldKey);
  }

  void clear() {
    clearRecursive(root_);
    root_ = nullptr;
    size_ = 0;
  }

  AVL<Key, T, returnPair, uniqueKeys> &operator=(
      const AVL<Key, T, returnPair, uniqueKeys> &other) {
    if (this != &other) {
      clear();  // Clear the current contents
      root_ = copyTree(other.root_);
      size_ = other.size_;
    }
    return *this;
  }

  AVL<Key, T, returnPair, uniqueKeys> &operator=(
      AVL<Key, T, returnPair, uniqueKeys> &&other) {
    clear();  // Clear the current contents

    // Move the contents of 'other' to 'this'
    root_ = other.root_;
    size_ = other.size_;

    // Leave 'other' in a valid, but unspecified state
    other.root_ = nullptr;
    other.size_ = 0;
    return *this;
  }

  iterator find(const key_type &key) const {
    Node *result = findNode(key);
    return iterator(result, &root_);
  }

  bool contains(const key_type &key) const { return findNode(key) != nullptr; }

  void printTree() const { printTreeRecursive(root_, 0); }

  template <class... Args>
  std::vector<std::pair<iterator, bool>> insert_many(Args &&...args) {
    std::vector<std::pair<iterator, bool>> vec;
    for (const auto &arg : {args...}) {
      vec.push_back(insert(arg));
    }
    return vec;
  }

  std::pair<iterator, bool> insert(const value_type &value) {
    auto result = insertValue(nullptr, root_, value);
    root_ = result.first;
    key_type newKey = getKeyFromValue(value);
    if constexpr (uniqueKeys) {
      return {find(newKey), result.second};
    } else {
      return {findLast(newKey), result.second};
    }
  }

  std::pair<iterator, bool> insert_or_assign(const value_type &value) {
    auto result = insert(value);
    key_type newKey = getKeyFromValue(value);
    auto searchNode = findNode(newKey);
    if (!result.second) {
      searchNode->setValue(value);
    }
    return {iterator(searchNode, &root_), result.second};
  }

  Node *getRoot() const { return root_; };

  size_type count(const key_type &key) const {
    size_t n = 0;
    auto lb = lower_bound(key);
    auto ub = upper_bound(key);
    for (auto it = lb; it != ub; ++it) {
      n++;
    }
    return n;
  }

  std::pair<iterator, iterator> equal_range(const key_type &key) const {
    return std::make_pair(lower_bound(key), upper_bound(key));
  }

  iterator lower_bound(const Key &key) const {
    return lower_bound_recursive(root_, nullptr, key);
  }

  iterator upper_bound(const Key &key) const {
    return upper_bound_recursive(root_, nullptr, key);
  }

 private:
  iterator upper_bound_recursive(Node *curNode, Node *searchNode,
                                 const Key &key) const {
    if (curNode == nullptr) {
      return (searchNode == nullptr ? end() : iterator(searchNode, &root_));
    }

    if (getKey(curNode) > key) {
      searchNode = curNode;
      return upper_bound_recursive(curNode->getLeftChild(), searchNode, key);
    } else {
      return upper_bound_recursive(curNode->getRightChild(), searchNode, key);
    }
  }

  iterator lower_bound_recursive(Node *curNode, Node *searchNode,
                                 const Key &key) const {
    if (curNode == nullptr) {
      return (searchNode == nullptr ? end() : iterator(searchNode, &root_));
    }

    if (getKey(curNode) >= key) {
      searchNode = curNode;
      return lower_bound_recursive(curNode->getLeftChild(), searchNode, key);
    } else {
      return lower_bound_recursive(curNode->getRightChild(), searchNode, key);
    }
  }

  Node *getMaxNode() const { return iterator::getMaxNodeRecursive(root_); }

  Node *getMinNode() const { return iterator::getMinNodeRecursive(root_); }

  std::pair<Node *, bool> insertValue(Node *parent, Node *curNode,
                                      value_type newValue) {
    if (curNode == nullptr) {
      curNode = new Node(newValue);
      curNode->setParent(parent);
      size_++;
      return {curNode, true};
    }
    bool insertSuccess;
    key_type newKey = getKeyFromValue(newValue);
    if (newKey < getKey(curNode)) {
      auto result = insertValue(curNode, curNode->getLeftChild(), newValue);
      curNode->setLeftChild(result.first);
      insertSuccess = result.second;
    } else if (newKey > getKey(curNode)) {
      auto result = insertValue(curNode, curNode->getRightChild(), newValue);
      curNode->setRightChild(result.first);
      insertSuccess = result.second;
    } else {
      if constexpr (uniqueKeys) {
        insertSuccess = false;
      } else {
        auto result = insertValue(curNode, curNode->getRightChild(), newValue);
        curNode->setRightChild(result.first);
        insertSuccess = result.second;
      }
    }
    curNode = balanceAfterInsert(curNode);
    return {curNode, insertSuccess};
  }

  void printTreeRecursive(Node *curNode, int space) const {
    if (curNode == nullptr) return;
    space = space + 5;
    printTreeRecursive(curNode->getRightChild(), space);
    std::cout << std::endl;
    for (int i = 5; i < space; i++) {
      std::cout << " ";
    }
    std::cout << "{" << getKey(curNode) << "}"
              << "\n";
    printTreeRecursive(curNode->getLeftChild(), space);
  }

  Node *searchRecursive(Node *curNode, key_type searchKey) const {
    if (curNode == nullptr or getKey(curNode) == searchKey) {
      return curNode;
    } else if (searchKey < getKey(curNode)) {
      return searchRecursive(curNode->getLeftChild(), searchKey);
    } else {
      return searchRecursive(curNode->getRightChild(), searchKey);
    }
  }

  Node *findNode(const key_type &key) const {
    return searchRecursive(root_, key);
  }

  Node *findLastNode(const key_type &key) const {
    auto er = equal_range(key);
    auto lb = er.first;
    Node *res = nullptr;
    auto ub = er.second;
    if (lb != end()) {
      ub--;
      res = ub.getCurrent();
    }
    return res;
  }

  iterator findLast(const key_type &key) const {
    Node *result = findLastNode(key);
    return iterator(result, &root_);
  }

  Node *copyTree(Node *curNode) {
    if (curNode == nullptr) {
      return nullptr;
    }
    Node *newNode = new Node(*curNode);
    newNode->setLeftChild(copyTree(curNode->getLeftChild()));
    if (newNode->getLeftChild() != nullptr) {
      newNode->getLeftChild()->setParent(newNode);
    }
    newNode->setRightChild(copyTree(curNode->getRightChild()));
    if (newNode->getRightChild() != nullptr) {
      newNode->getRightChild()->setParent(newNode);
    }
    return newNode;
  }

  int getBalanceFactor(Node *curNode) const {
    if (curNode == nullptr) return -1;
    return (getHeight(curNode->getLeftChild()) -
            getHeight(curNode->getRightChild()));
  }

  int getHeight(Node *curNode) const {
    if (curNode == nullptr)
      return -1;
    else {
      int leftHeight = getHeight(curNode->getLeftChild());
      int rightHeight = getHeight(curNode->getRightChild());
      if (leftHeight > rightHeight)
        return (leftHeight + 1);
      else
        return (rightHeight + 1);
    }
  }

  void clearRecursive(Node *curNode) {
    if (curNode != nullptr) {
      clearRecursive(curNode->getLeftChild());
      clearRecursive(curNode->getRightChild());
      delete curNode;
    }
  }

  Node *deleteNodeRecursive(Node *curNode, key_type oldKey) {
    if (curNode == nullptr) return nullptr;
    key_type curKey = getKey(curNode);
    if (oldKey < curKey) {
      curNode->setLeftChild(
          deleteNodeRecursive(curNode->getLeftChild(), oldKey));
    } else if (oldKey > curKey) {
      curNode->setRightChild(
          deleteNodeRecursive(curNode->getRightChild(), oldKey));
    } else {
      if (curNode->getLeftChild() == nullptr) {  // right child or no child
        Node *temp = curNode->getRightChild();
        if (temp != nullptr) temp->setParent(curNode->getParent());
        delete curNode;
        size_--;
        return temp;
      } else if (curNode->getRightChild() == nullptr) {  // left child
        Node *temp = curNode->getLeftChild();
        if (temp != nullptr) temp->setParent(curNode->getParent());
        delete curNode;
        size_--;
        return temp;
      } else {  // two children
        Node *temp = iterator::getMinNodeRecursive(curNode->getRightChild());
        curNode->setValue(temp->getValue());
        curNode->setRightChild(
            deleteNodeRecursive(curNode->getRightChild(), getKey(temp)));
        if (curNode->getRightChild() != nullptr) {
          curNode->getRightChild()->setParent(curNode);
        }
      }
    }
    return balanceAfterDelete(curNode);
  }

  void inOrderTraversalRecursive(Node *curNode) const {
    if (curNode == nullptr) return;
    inOrderTraversalRecursive(curNode->getLeftChild());
    std::cout << "\n" << getKey(curNode) << ", ";
    if (curNode->getParent() == nullptr)
      std::cout << "parent: nil\n";
    else
      std::cout << "parent: " << getKey(curNode->getParent()) << "\n";
    inOrderTraversalRecursive(curNode->getRightChild());
  }

  Node *balanceAfterInsert(Node *curNode) {
    if (curNode == nullptr) {
      return nullptr;
    }
    int bf = getBalanceFactor(curNode);
    if (bf > 1 && getBalanceFactor(curNode->getLeftChild()) >= 0) {
      return rightRotate(curNode);
    }
    if (bf < -1 && getBalanceFactor(curNode->getRightChild()) <= 0) {
      return leftRotate(curNode);
    }
    if (bf > 1 && getBalanceFactor(curNode->getLeftChild()) < 0) {
      curNode->setLeftChild(leftRotate(curNode->getLeftChild()));
      return rightRotate(curNode);
    }
    if (bf < -1 && getBalanceFactor(curNode->getRightChild()) > 0) {
      curNode->setRightChild(rightRotate(curNode->getRightChild()));
      return leftRotate(curNode);
    }
    return curNode;
  }

  Node *balanceAfterDelete(Node *curNode) {
    int bf = getBalanceFactor(curNode);
    // bf = left hight - right height
    if (bf == 2 &&
        getBalanceFactor(curNode->getLeftChild()) >= 0) {  // LeftLeft imbalance
      return rightRotate(curNode);
    } else if (bf == 2 && getBalanceFactor(curNode->getLeftChild()) ==
                              -1) {  // LeftRight imbalance
      curNode->setLeftChild(leftRotate(curNode->getLeftChild()));
      return rightRotate(curNode);
    } else if (bf == -2 && getBalanceFactor(curNode->getRightChild()) <=
                               0) {  // RightRight imbalance
      return leftRotate(curNode);
    } else if (bf == -2 && getBalanceFactor(curNode->getRightChild()) ==
                               1) {  // RightLeft imbalance
      curNode->setRightChild(rightRotate(curNode->getRightChild()));
      return leftRotate(curNode);
    }
    return curNode;
  }

  static Node *leftRotate(Node *top) {
    Node *topRight = top->getRightChild();
    topRight->setParent(top->getParent());
    top->setParent(topRight);
    Node *topRightLeft = topRight->getLeftChild();
    topRight->setLeftChild(top);
    top->setRightChild(topRightLeft);
    if (topRightLeft != nullptr) {
      topRightLeft->setParent(top);
    }
    return topRight;
  }

  static Node *rightRotate(Node *top) {
    Node *topLeft = top->getLeftChild();
    topLeft->setParent(top->getParent());
    top->setParent(topLeft);
    Node *topLeftRight = topLeft->getRightChild();
    topLeft->setRightChild(top);
    top->setLeftChild(topLeftRight);
    if (topLeftRight != nullptr) {
      topLeftRight->setParent(top);
    }
    return topLeft;
  }

  void mergeRecursive(Node *curNode) {
    if (curNode != nullptr) {
      insert(curNode->getValue());
      mergeRecursive(curNode->getLeftChild());
      mergeRecursive(curNode->getRightChild());
    }
  }
  const key_type &getKey(Node *curNode) const {
    if constexpr (returnPair) {
      return curNode->getValue().first;
    } else {
      return curNode->getValue();
    }
  }

  const key_type getKeyFromValue(const value_type &value) const {
    key_type newKey;
    if constexpr (returnPair) {
      newKey = value.first;
    } else {
      newKey = value;
    }
    return newKey;
  }

 private:
  Node *root_;
  size_t size_;
};

}  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_AVLTREE_AVLTREE_H