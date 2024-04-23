#ifndef CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_LISTNODE_LIST_NODE_HPP_
#define CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_LISTNODE_LIST_NODE_HPP_
namespace s21 {
template <typename T>
class List_Node_ {
 public:
  T value_;
  List_Node_* ptr_next_;
  List_Node_* ptr_prev_;
  List_Node_() : value_(), ptr_next_(nullptr), ptr_prev_(nullptr) {}
  List_Node_(const T& value, List_Node_<T>* prev, List_Node_<T>* next)
      : value_(value), ptr_next_(next), ptr_prev_(prev) {}
  explicit List_Node_(T value) noexcept
      : value_(value), ptr_next_(nullptr), ptr_prev_(nullptr) {}
  ~List_Node_() = default;
};
}  // namespace s21

#endif  //  CPP2_S21_CONTAINERS_1_SRC_CONTAINERS_LIST_LISTNODE_LIST_NODE_HPP_