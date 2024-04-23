#include <vector>

#include "unit_tests_entry.h"
TEST(Vector, DefaultConstructor_EmptyVector) {
  s21::Vector<int> v;
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST(Vector, SizeConstructor_PositiveSize) {
  const size_t size = 5;
  s21::Vector<int> v(size);
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), size);
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(v[i], 0);
  }
}

TEST(Vector, SizeConstructor_ZeroSize) {
  const size_t size = 0;
  s21::Vector<int> v(size);
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), size);
}

TEST(Vector, InitializerListConstructor_EmptyList) {
  s21::Vector<int> v = {};
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
}

TEST(Vector, InitializerListConstructor_NonEmptyList) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_FALSE(v.empty());
  EXPECT_EQ(v.size(), 5);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[4], 5);
}

TEST(Vector, CopyConstructor_EmptyVector) {
  s21::Vector<int> v1;
  s21::Vector<int> v2(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(Vector, CopyConstructor_NonEmptyVector) {
  s21::Vector<int> v1 = {1, 2, 3};
  s21::Vector<int> v2(v1);
  EXPECT_EQ(v2.size(), v1.size());
  for (size_t i = 0; i < v1.size(); ++i) {
    EXPECT_EQ(v2[i], v1[i]);
  }
}

TEST(Vector, MoveConstructor_EmptyVector) {
  s21::Vector<int> v1;
  s21::Vector<int> v2(std::move(v1));
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(Vector, MoveConstructor_NonEmptyVector) {
  s21::Vector<int> v1 = {1, 2, 3};
  s21::Vector<int> v2(std::move(v1));
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());
}

TEST(Vector, Destructor_EmptyVector) {
  s21::Vector<int>* v = new s21::Vector<int>();
  delete v;
}

TEST(Vector, Destructor_NonEmptyVector) {
  s21::Vector<int>* v = new s21::Vector<int>{1, 2, 3};
  delete v;
}

TEST(Vector, MoveAssignmentOperator_EmptyToEmpty) {
  s21::Vector<int> v1;
  s21::Vector<int> v2;
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(Vector, MoveAssignmentOperator_NonEmptyToEmpty) {
  s21::Vector<int> v1 = {1, 2, 3};
  s21::Vector<int> v2;
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());
}

TEST(Vector, MoveAssignmentOperator_EmptyToNonEmpty) {
  s21::Vector<int> v1;
  s21::Vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_TRUE(v2.empty());
  EXPECT_EQ(v2.size(), 0);
}

TEST(Vector, MoveAssignmentOperator_NonEmptyToNonEmpty) {
  s21::Vector<int> v1 = {1, 2, 3};
  s21::Vector<int> v2 = {4, 5, 6};
  v2 = std::move(v1);
  EXPECT_EQ(v2.size(), 3);
  EXPECT_TRUE(v1.empty());
}

TEST(Vector, At_ValidIndex) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.at(0), 1);
  EXPECT_EQ(v.at(2), 3);
  EXPECT_EQ(v.at(4), 5);
}

TEST(Vector, At_InvalidIndex) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_THROW(v.at(5), std::out_of_range);
  EXPECT_THROW(v.at(10), std::out_of_range);
}

TEST(Vector, IndexOperator_ValidIndex) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(Vector, IndexOperator_InvalidIndex) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(Vector, ConstIndexOperator_ValidIndex) {
  const s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(v[2], 3);
  EXPECT_EQ(v[4], 5);
}

TEST(Vector, ConstIndexOperator_InvalidIndex) {
  const s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_ANY_THROW(v[5]);
  EXPECT_ANY_THROW(v[10]);
}

TEST(Vector, FrontConst_ValidVector) {
  const s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.front(), 1);
}

TEST(Vector, BackConst_ValidVector) {
  const s21::Vector<int> v = {1, 2, 3, 4, 5};
  EXPECT_EQ(v.back(), 5);
}

TEST(Vector, Data_ValidVector) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  int* dataPtr = v.data();
  EXPECT_EQ(*dataPtr, 1);
  *dataPtr = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(Vector, Data_EmptyVector) {
  s21::Vector<int> v;
  int* dataPtr = v.data();
  EXPECT_EQ(dataPtr, nullptr);
}

TEST(Vector, Begin_ValidVector) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.begin();
  EXPECT_EQ(*it, 1);
  *it = 10;
  EXPECT_EQ(v[0], 10);
}

TEST(Vector, Begin_EmptyVector) {
  s21::Vector<int> v;
  auto it = v.begin();
  EXPECT_EQ(it, v.end());
}

TEST(Vector, End_ValidVector) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.end();
  auto beginIt = v.begin();
  EXPECT_NE(it, beginIt);
}

TEST(Vector, End_EmptyVector) {
  s21::Vector<int> v;
  auto it = v.end();
  EXPECT_EQ(it, v.begin());
}

TEST(Vector, CBegin_ValidVector) {
  const s21::Vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.cbegin();
  EXPECT_EQ(*it, 1);
}

TEST(Vector, CBegin_EmptyVector) {
  const s21::Vector<int> v;
  auto it = v.cbegin();
  EXPECT_EQ(it, v.cend());
}

TEST(Vector, CEnd_ValidVector) {
  const s21::Vector<int> v = {1, 2, 3, 4, 5};
  auto it = v.cend();
  auto beginIt = v.cbegin();
  EXPECT_EQ(it, beginIt + 5);
}

TEST(Vector, CEnd_EmptyVector) {
  const s21::Vector<int> v;
  auto it = v.cend();
  EXPECT_EQ(it, v.cbegin());
}

TEST(Vector, Empty_EmptyVector) {
  const s21::Vector<int> v;
  EXPECT_TRUE(v.empty());
}

TEST(Vector, Empty_NonEmptyVector) {
  const s21::Vector<int> v = {1, 2, 3};
  EXPECT_FALSE(v.empty());
}

TEST(Vector, Size_EmptyVector) {
  const s21::Vector<int> v;
  EXPECT_EQ(v.size(), 0);
}

TEST(Vector, Size_NonEmptyVector) {
  const s21::Vector<int> v = {1, 2, 3};
  EXPECT_EQ(v.size(), 3);
}

TEST(Vector, MaxSize) {
  const s21::Vector<int> v;
  EXPECT_GT(v.max_size(), 0);
}

TEST(Vector, Reserve_IncreaseCapacity) {
  s21::Vector<int> v;
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity + 10;
  v.reserve(newCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(Vector, Reserve_DecreaseCapacity) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  size_t newCapacity = initialCapacity - 2;
  v.reserve(newCapacity);
  EXPECT_LE(v.capacity(), initialCapacity);
  EXPECT_GE(v.capacity(), newCapacity);
}

TEST(Vector, Capacity_EmptyVector) {
  const s21::Vector<int> v;
  EXPECT_GE(v.capacity(), 0);
}

TEST(Vector, Capacity_NonEmptyVector) {
  const s21::Vector<int> v = {1, 2, 3};
  EXPECT_GE(v.capacity(), v.size());
}

TEST(Vector, ShrinkToFit_EmptyVector) {
  s21::Vector<int> v;
  v.shrink_to_fit();
  EXPECT_GE(v.capacity(), 0);
}

TEST(Vector, ShrinkToFit_NonEmptyVector) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  size_t initialCapacity = v.capacity();
  v.pop_back();
  v.shrink_to_fit();
  EXPECT_LE(v.capacity(), v.size());
  EXPECT_LE(v.capacity(), initialCapacity);
}

TEST(Vector, Clear_EmptyVector) {
  s21::Vector<int> v;
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
  EXPECT_GE(v.capacity(), 0);
}

TEST(Vector, Clear_NonEmptyVector) {
  s21::Vector<int> v = {1, 2, 3, 4, 5};
  v.clear();
  EXPECT_TRUE(v.empty());
  EXPECT_EQ(v.size(), 0);
  EXPECT_GE(v.capacity(), 0);
}

TEST(Vector, Insert_Beginning) {
  s21::Vector<int> v = {2, 3, 4};
  auto it = v.insert(v.begin(), 1);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[0], 1);
  EXPECT_EQ(*it, 1);
}

TEST(Vector, Insert_Middle) {
  s21::Vector<int> v = {1, 3, 4};
  auto it = v.insert(v.begin() + 1, 2);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[1], 2);
  EXPECT_EQ(*it, 2);
}

TEST(Vector, Insert_End) {
  s21::Vector<int> v = {1, 2, 3};
  auto it = v.insert(v.end(), 4);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[3], 4);
  EXPECT_EQ(*it, 4);
}

TEST(Vector, Erase_Beginning) {
  s21::Vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin());
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[0], 2);
}

TEST(Vector, Erase_Middle) {
  s21::Vector<int> v = {1, 2, 3, 4};
  v.erase(v.begin() + 1);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[1], 3);
}

TEST(Vector, Erase_End) {
  s21::Vector<int> v = {1, 2, 3, 4};
  v.erase(v.end() - 1);
  EXPECT_EQ(v.size(), 3);
  EXPECT_EQ(v[2], 3);
}

TEST(Vector, PushBack_EmptyVector) {
  s21::Vector<int> v;
  v.push_back(1);
  EXPECT_EQ(v.size(), 1);
  EXPECT_EQ(v[0], 1);
}

TEST(Vector, PushBack_NonEmptyVector) {
  s21::Vector<int> v = {1, 2, 3};
  v.push_back(4);
  EXPECT_EQ(v.size(), 4);
  EXPECT_EQ(v[3], 4);
}

TEST(Vector, PopBack_NonEmptyVector) {
  s21::Vector<int> v = {1, 2, 3};
  v.pop_back();
  EXPECT_EQ(v.size(), 2);
  EXPECT_EQ(v.back(), 2);
}

TEST(Vector, Swap_NonEmptyVectors) {
  s21::Vector<int> v1 = {1, 2, 3};
  s21::Vector<int> v2 = {4, 5, 6};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_EQ(v2.size(), 3);

  EXPECT_EQ(v1[0], 4);
  EXPECT_EQ(v1[2], 6);

  EXPECT_EQ(v2[0], 1);
  EXPECT_EQ(v2[2], 3);
}

TEST(Vector, Swap_EmptyAndNonEmptyVectors) {
  s21::Vector<int> v1;
  s21::Vector<int> v2 = {1, 2, 3};

  v1.swap(v2);

  EXPECT_EQ(v1.size(), 3);
  EXPECT_FALSE(v1.empty());
  EXPECT_EQ(v2.size(), 0);
  EXPECT_TRUE(v2.empty());
}

TEST(Vector, InsertMany) {
  s21::Vector<int> vec = {1, 2, 3, 7, 8};
  s21::Vector<int>::const_iterator pos = vec.cbegin() + 3;

  vec.insert_many(pos, 4, 5, 6);

  EXPECT_EQ(vec.size(), 8);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
  EXPECT_EQ(vec[6], 7);
  EXPECT_EQ(vec[7], 8);
}

TEST(Vector, InsertManyBack) {
  s21::Vector<int> vec = {1, 2, 3};

  vec.insert_many_back(4, 5, 6);
  EXPECT_EQ(vec.size(), 6);
  EXPECT_EQ(vec[0], 1);
  EXPECT_EQ(vec[1], 2);
  EXPECT_EQ(vec[2], 3);
  EXPECT_EQ(vec[3], 4);
  EXPECT_EQ(vec[4], 5);
  EXPECT_EQ(vec[5], 6);
}