#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_AVLTREE_ITERATORS_AVLTREE_CONST_ITERATOR_H_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_AVLTREE_ITERATORS_AVLTREE_CONST_ITERATOR_H_

#include "./AVLTree_iterator.h"

namespace s21 {
template <typename Value, bool returnPair>
class ConstAVLTreeIterator : public AVLTreeIterator<Value, returnPair> {
 public:
  using value_type = Value;
  ConstAVLTreeIterator() : AVLTreeIterator<Value, returnPair>() {}
  ConstAVLTreeIterator(const AVLTreeIterator<Value, returnPair>& other)
      : AVLTreeIterator<Value, returnPair>(other) {}
  ConstAVLTreeIterator(AVLTreeNode<Value, returnPair>* const* root)
      : AVLTreeIterator<Value, returnPair>(root) {}
  ConstAVLTreeIterator(AVLTreeNode<Value, returnPair>* curNode,
                       AVLTreeNode<Value, returnPair>* const* root)
      : AVLTreeIterator<Value, returnPair>(curNode, root) {}
  const value_type& operator*() const {
    return AVLTreeIterator<Value, returnPair>::operator*();
  }
  const value_type* operator->() const {
    return AVLTreeIterator<Value, returnPair>::operator->();
  }
};
}  // namespace s21
#endif  //  CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_AVLTREE_ITERATORS_AVLTREE_CONST_ITERATOR_H_