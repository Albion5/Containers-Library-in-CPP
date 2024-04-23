#include <stack>

#include "unit_tests_entry.h"

TEST(Stack, DefaultConstructor) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;

  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
  ASSERT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Stack, PushAndTop) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;

  s21_stack.push(1);
  std_stack.push(1);
  ASSERT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.push(2);
  std_stack.push(2);
  ASSERT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.push(3);
  std_stack.push(3);
  ASSERT_EQ(s21_stack.top(), std_stack.top());
}

TEST(Stack, Pop) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;

  s21_stack.push(1);
  std_stack.push(1);
  ASSERT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.push(2);
  std_stack.push(2);
  ASSERT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.push(3);
  std_stack.push(3);
  ASSERT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.pop();
  std_stack.pop();
  ASSERT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.pop();
  std_stack.pop();
  ASSERT_EQ(s21_stack.top(), std_stack.top());

  s21_stack.pop();
  std_stack.pop();
  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
}

TEST(Stack, Size) {
  s21::Stack<int> s21_stack;
  std::stack<int> std_stack;

  ASSERT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.push(1);
  std_stack.push(1);
  ASSERT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.push(2);
  std_stack.push(2);
  ASSERT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.pop();
  std_stack.pop();
  ASSERT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.push(3);
  std_stack.push(3);
  ASSERT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.pop();
  std_stack.pop();
  ASSERT_EQ(s21_stack.size(), std_stack.size());

  s21_stack.pop();
  std_stack.pop();
  ASSERT_EQ(s21_stack.size(), std_stack.size());
}

TEST(Stack, Swap) {
  s21::Stack<int> s21_stack1;
  s21::Stack<int> s21_stack2;
  std::stack<int> std_stack1;
  std::stack<int> std_stack2;

  s21_stack1.push(1);
  s21_stack1.push(2);
  s21_stack1.push(3);
  std_stack1.push(1);
  std_stack1.push(2);
  std_stack1.push(3);

  s21_stack1.swap(s21_stack2);
  std_stack1.swap(std_stack2);

  ASSERT_EQ(s21_stack1.empty(), std_stack1.empty());
  ASSERT_EQ(s21_stack1.size(), std_stack1.size());

  ASSERT_EQ(s21_stack2.empty(), std_stack2.empty());
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());

  ASSERT_EQ(s21_stack2.top(), std_stack2.top());
}

TEST(Stack, CopyConstructor) {
  s21::Stack<int> s21_stack1;
  std::stack<int> std_stack1;

  s21_stack1.push(1);
  s21_stack1.push(2);
  s21_stack1.push(3);
  std_stack1.push(1);
  std_stack1.push(2);
  std_stack1.push(3);

  s21::Stack<int> s21_stack2(s21_stack1);
  std::stack<int> std_stack2(std_stack1);

  ASSERT_EQ(s21_stack1.empty(), std_stack1.empty());
  ASSERT_EQ(s21_stack1.size(), std_stack1.size());
  ASSERT_EQ(s21_stack2.empty(), std_stack2.empty());
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  ASSERT_EQ(s21_stack1.top(), std_stack1.top());
  ASSERT_EQ(s21_stack2.top(), std_stack2.top());
}

TEST(Stack, MoveConstructor) {
  s21::Stack<int> s21_stack1;
  std::stack<int> std_stack1;

  s21_stack1.push(1);
  s21_stack1.push(2);
  s21_stack1.push(3);
  std_stack1.push(1);
  std_stack1.push(2);
  std_stack1.push(3);

  s21::Stack<int> s21_stack2(std::move(s21_stack1));
  std::stack<int> std_stack2(std::move(std_stack1));

  ASSERT_EQ(s21_stack2.empty(), std_stack2.empty());
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  ASSERT_EQ(s21_stack2.top(), std_stack2.top());
}

TEST(Stack, MoveAssignmentOperator) {
  s21::Stack<int> s21_stack1;
  std::stack<int> std_stack1;

  s21_stack1.push(1);
  s21_stack1.push(2);
  s21_stack1.push(3);
  std_stack1.push(1);
  std_stack1.push(2);
  std_stack1.push(3);

  s21::Stack<int> s21_stack2;
  std::stack<int> std_stack2;

  s21_stack2 = std::move(s21_stack1);
  std_stack2 = std::move(std_stack1);

  ASSERT_EQ(s21_stack2.empty(), std_stack2.empty());
  ASSERT_EQ(s21_stack2.size(), std_stack2.size());
  ASSERT_EQ(s21_stack2.top(), std_stack2.top());
}

TEST(Stack, InitializerListConstructor) {
  s21::Stack<int> s21_stack({1, 2, 3});
  std::stack<int> std_stack({1, 2, 3});

  ASSERT_EQ(s21_stack.empty(), std_stack.empty());
  ASSERT_EQ(s21_stack.size(), std_stack.size());
  ASSERT_EQ(s21_stack.top(), std_stack.top());
}