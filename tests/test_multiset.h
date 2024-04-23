#include <set>

#include "unit_tests_entry.h"

bool multisetsEqual(s21::multiset<int> &M1, std::multiset<int> &M2) {
  if (M1.size() != M2.size()) return false;
  s21::multiset<int>::iterator it_M1 = M1.begin();
  std::multiset<int>::iterator it_M2 = M2.begin();
  for (; it_M2 != M2.end(); ++it_M1, ++it_M2) {
    if (*it_M1 != *it_M2) return false;
  }
  return true;
}

TEST(multiset, MULTISET_DEFAULT_CONSTRUCTOR) {
  s21::multiset<int> M1;
  std::multiset<int> M2;
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_LIST_CONSTRUCTOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  std::multiset<int> M2 = {1, 2, 2, 3};
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_COPY_CONSTRUCTOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  s21::multiset<int> M2(M1);
  std::multiset<int> M3 = {1, 2, 2, 3};
  std::multiset<int> M4(M3);
  ASSERT_EQ(multisetsEqual(M2, M4), true);
  ASSERT_EQ(multisetsEqual(M1, M3), true);
}

TEST(multiset, MULTISET_MOVE_CONSTRUCTOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  s21::multiset<int> M2(std::move(M1));
  std::multiset<int> M3 = {1, 2, 2, 3};
  std::multiset<int> M4(std::move(M3));
  ASSERT_EQ(multisetsEqual(M2, M4), true);
  ASSERT_EQ(multisetsEqual(M1, M3), true);
}

TEST(multiset, UNIQUE_TEST) {
  s21::multiset<int> M1 = {1, 1, 1};
  std::multiset<int> M2 = {1, 1, 1};
  ASSERT_EQ(multisetsEqual(M1, M2), true);
  M1.insert(1);
  M2.insert(1);
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_SIZE_DEFAULT_CONSTRUCTOR) {
  s21::multiset<int> M1;
  std::multiset<int> M2;
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(multiset, MULTISET_SIZE_LIST_CONSTRUCTOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  std::multiset<int> M2 = {1, 2, 2, 3};
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(multiset, MULTISET_SIZE_COPY_CONSTRUCTOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  s21::multiset<int> M2(M1);
  std::multiset<int> M3 = {1, 2, 2, 3};
  std::multiset<int> M4(M3);
  ASSERT_EQ(M1.size(), M3.size());
  ASSERT_EQ(M2.size(), M4.size());
}

TEST(multiset, MULTISET_SIZE_MOVE_CONSTRUCTOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  s21::multiset<int> M2(std::move(M1));
  std::multiset<int> M3 = {1, 2, 2, 3};
  std::multiset<int> M4(std::move(M3));
  ASSERT_EQ(M1.size(), M3.size());
  ASSERT_EQ(M2.size(), M4.size());
}

TEST(multiset, MULTISET_MAX_SIZE) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  std::multiset<int> M2 = {1, 2, 2, 3};
  EXPECT_NEAR(M1.max_size() / M2.max_size(), 1, 1);
}

TEST(multiset, MULTISET_EMPTY_DEFAULT_CONSTRUCTOR) {
  s21::multiset<int> M1;
  std::multiset<int> M2;
  ASSERT_EQ(M1.empty(), M2.empty());
}

TEST(multiset, MULTISET_EMPTY_LIST_CONSTRUCTOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  std::multiset<int> M2 = {1, 2, 2, 3};
  ASSERT_EQ(M1.empty(), M2.empty());
  s21::multiset<int> M3 = {};
  std::multiset<int> M4 = {};
  ASSERT_EQ(M3.empty(), M4.empty());
  s21::multiset<int> S5 = {1};
  std::multiset<int> S6 = {1};
  ASSERT_EQ(S5.empty(), S6.empty());
}

TEST(multiset, MULTISET_EMPTY_COPY_CONSTRUCTOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  s21::multiset<int> M2(M1);
  std::multiset<int> M3 = {1, 2, 2, 3};
  std::multiset<int> M4(M3);
  ASSERT_EQ(M1.empty(), M3.empty());
  ASSERT_EQ(M2.empty(), M4.empty());
  s21::multiset<int> S5;
  s21::multiset<int> S6(S5);
  std::multiset<int> S7;
  std::multiset<int> S8(S7);
  ASSERT_EQ(S5.empty(), S7.empty());
  ASSERT_EQ(S6.empty(), S8.empty());
}

TEST(multiset, MULTISET_EMPTY_MOVE_CONSTRUCTOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  s21::multiset<int> M2(std::move(M1));
  std::multiset<int> M3 = {1, 2, 2, 3};
  std::multiset<int> M4(std::move(M3));
  ASSERT_EQ(M1.empty(), M3.empty());
  ASSERT_EQ(M2.empty(), M4.empty());
  s21::multiset<int> S5;
  s21::multiset<int> S6(std::move(S5));
  std::multiset<int> S7;
  std::multiset<int> S8(std::move(S7));
  ASSERT_EQ(S5.empty(), S7.empty());
  ASSERT_EQ(S6.empty(), S8.empty());
}

TEST(multiset, MULTISET_SWAP_ONE_MULTISET_EMPTY1) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  s21::multiset<int> M2 = {};
  std::multiset<int> M3 = {1, 2, 2, 3};
  std::multiset<int> M4 = {};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(multisetsEqual(M1, M3), true);
  ASSERT_EQ(multisetsEqual(M2, M4), true);
}

TEST(multiset, MULTISET_SWAP_ONE_MULTISET_EMPTY2) {
  s21::multiset<int> M1 = {};
  s21::multiset<int> M2 = {1, 2, 2, 3};
  std::multiset<int> M3 = {};
  std::multiset<int> M4 = {1, 2, 2, 3};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(multisetsEqual(M1, M3), true);
  ASSERT_EQ(multisetsEqual(M2, M4), true);
}

TEST(multiset, MULTISET_SWAP_NUMBER_OF_ELEMENTS) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  s21::multiset<int> M2 = {4, 5, 6, 6};
  std::multiset<int> M3 = {1, 2, 2, 3};
  std::multiset<int> M4 = {4, 5, 6, 6};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(multisetsEqual(M1, M3), true);
  ASSERT_EQ(multisetsEqual(M2, M4), true);
}

TEST(multiset, MULTISET_SWAP_DIFFERENT_NUMBER_OF_ELEMENTS1) {
  s21::multiset<int> M1 = {1, 2, 3, 3, 4, 5};
  s21::multiset<int> M2 = {4, 5, 6};
  std::multiset<int> M3 = {1, 2, 3, 3, 4, 5};
  std::multiset<int> M4 = {4, 5, 6};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(multisetsEqual(M1, M3), true);
  ASSERT_EQ(multisetsEqual(M2, M4), true);
}

TEST(multiset, MULTISET_SWAP_DIFFERENT_NUMBER_OF_ELEMENTS2) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  s21::multiset<int> M2 = {4, 5, 6, 4, 4, 128, 40};
  std::multiset<int> M3 = {1, 2, 2, 3};
  std::multiset<int> M4 = {4, 5, 6, 4, 4, 128, 40};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(multisetsEqual(M1, M3), true);
  ASSERT_EQ(multisetsEqual(M2, M4), true);
}

TEST(multiset, MULTISET_INSERT_EXISTING_ELEMENT) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  std::multiset<int> M2 = {1, 2, 2, 3};
  M1.insert(3);
  M2.insert(3);
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_INSERT_0_ELEMENTS) {
  s21::multiset<int> M1 = {};
  std::multiset<int> M2 = {};
  M1.insert(3);
  M2.insert(3);
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_INSERT_MIDDLE_ELEMENT) {
  s21::multiset<int> M1 = {1, 2, 4};
  std::multiset<int> M2 = {1, 2, 4};
  M1.insert(3);
  M2.insert(3);
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_ERASE_RIGHT_CHILD) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  std::multiset<int> M2 = {1, 2, 2, 3};
  s21::multiset<int>::iterator it_S1 = M1.begin();
  std::multiset<int>::iterator it_S2 = M2.begin();
  M1.erase(it_S1);
  M2.erase(it_S2);
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_ERASE_LEFT_CHILD) {
  s21::multiset<int> M1 = {3, 1, 2};
  std::multiset<int> M2 = {3, 1, 2};
  s21::multiset<int>::iterator it_S1 = --M1.end();
  std::multiset<int>::iterator it_S2 = --M2.end();
  M1.erase(it_S1);
  M2.erase(it_S2);
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_ERASE_NO_CHILD) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  std::multiset<int> M2 = {1, 2, 2, 3};
  s21::multiset<int>::iterator it_S1 = --M1.end();
  std::multiset<int>::iterator it_S2 = --M2.end();
  M1.erase(it_S1);
  M2.erase(it_S2);
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_ERASE_TWO_CHILDREN1) {
  s21::multiset<int> M1 = {3, 1, 2, 4, 5};
  std::multiset<int> M2 = {3, 1, 2, 4, 5};
  s21::multiset<int>::iterator it_S1 = ++M1.begin();
  std::multiset<int>::iterator it_S2 = ++M2.begin();
  ++it_S1;
  ++it_S2;
  M1.erase(it_S1);
  M2.erase(it_S2);
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_ERASE_TWO_CHILDREN2) {
  s21::multiset<int> M1 = {10, 15, 12, 16};
  std::multiset<int> M2 = {10, 15, 12, 16};
  s21::multiset<int>::iterator it_S1 = ++M1.begin();
  std::multiset<int>::iterator it_S2 = ++M2.begin();
  ++it_S1;
  ++it_S2;
  M1.erase(it_S1);
  M2.erase(it_S2);
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_MERGE_DIFFERENT_ELEMENTS) {
  s21::multiset<int> S1 = {1, 3, 5};
  s21::multiset<int> S2 = {2, 4, 6};
  std::multiset<int> S3 = {1, 3, 5, 2, 4, 6};
  std::multiset<int> empty;
  S1.merge(S2);
  ASSERT_EQ(multisetsEqual(S1, S3), true);
  ASSERT_EQ(multisetsEqual(S2, empty), true);
}

TEST(multiset, MULTISET_MERGE_IDENTICAL_ELEMENTS) {
  s21::multiset<int> S1 = {1, 3, 5};
  s21::multiset<int> S2 = {1, 3, 5};
  std::multiset<int> S3 = {1, 3, 5, 1, 3, 5};
  std::multiset<int> empty;
  S1.merge(S2);
  ASSERT_EQ(multisetsEqual(S1, S3), true);
  ASSERT_EQ(multisetsEqual(S2, empty), true);
}

TEST(multiset, MULTISET_MERGE_FIRST_EMPTY) {
  s21::multiset<int> S1 = {};
  s21::multiset<int> S2 = {1, 3, 5};
  std::multiset<int> S3 = {1, 3, 5};
  std::multiset<int> empty;
  S1.merge(S2);
  ASSERT_EQ(multisetsEqual(S1, S3), true);
  ASSERT_EQ(multisetsEqual(S2, empty), true);
}

TEST(multiset, MULTISET_MERGE_SECOND_EMPTY) {
  s21::multiset<int> S1 = {1, 3, 5};
  s21::multiset<int> S2 = {};
  std::multiset<int> S3 = {1, 3, 5};
  std::multiset<int> empty;
  S1.merge(S2);
  ASSERT_EQ(multisetsEqual(S1, S3), true);
  ASSERT_EQ(multisetsEqual(S2, empty), true);
}

TEST(multiset, MULTISET_FIND_EXISTING_ELEMENT) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  s21::multiset<int>::iterator it_S1 = M1.find(75);
  std::multiset<int>::iterator it_S2 = M2.find(75);
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(multiset, MULTISET_CONTAINS_EXISTING_ELEMENT) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  ASSERT_EQ(M1.contains(10), true);
}

TEST(multiset, MULTISET_CONTAINS_NOT_EXISTING_ELEMENT) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  ASSERT_EQ(M1.contains(43), false);
}

TEST(multiset, MULTISET_COUNT_0_ELEMENTS) {
  s21::multiset<int> M1 = {};
  std::multiset<int> M2 = {};
  ASSERT_EQ(M1.count(3), M2.count(3));
}

TEST(multiset, MULTISET_COUNT_5_ELEMENTS_1) {
  s21::multiset<int> M1 = {2, 2, 3, 1, 2};
  std::multiset<int> M2 = {2, 2, 3, 1, 2};
  ASSERT_EQ(M1.count(2), M2.count(2));
}

TEST(multiset, MULTISET_COUNT_5_ELEMENTS_2) {
  s21::multiset<int> M1 = {2, 2, 3, 1, 2};
  std::multiset<int> M2 = {2, 2, 3, 1, 2};
  ASSERT_EQ(M1.count(3), M2.count(3));
}

TEST(multiset, MULTISET_LOWER_BOUND_EXISTING_ELEMENT) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5, 5, 15};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5, 5, 15};
  ASSERT_EQ(*M1.lower_bound(5), *M2.lower_bound(5));
}

TEST(multiset, MULTISET_LOWER_BOUND_NOT_EXISTING_ELEMENT) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5, 5, 15};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5, 5, 15};
  ASSERT_EQ(M1.lower_bound(100) == M1.end(), M2.lower_bound(100) == M2.end());
}

TEST(multiset, MULTISET_UPPER_BOUND_EXISTING_ELEMENT) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5, 5, 15};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5, 5, 15};
  ASSERT_EQ(*M1.upper_bound(74), *M2.upper_bound(74));
}

TEST(multiset, MULTISET_UPPER_BOUND_NOT_EXISTING_ELEMENT) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5, 5, 15};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5, 5, 15};
  ASSERT_EQ(M1.upper_bound(100) == M1.end(), M2.upper_bound(100) == M2.end());
}

TEST(multiset, MULTISET_EQUAL_RANGE_EXISTING_ELEMENT) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5, 5, 15};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5, 5, 15};
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> it_S1 =
      M1.equal_range(6);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> it_S2 =
      M2.equal_range(6);
  ASSERT_EQ(*it_S1.first, *it_S2.first);
  ASSERT_EQ(*it_S1.second, *it_S2.second);
}

TEST(multiset, MULTISET_EQUAL_RANGE_NOT_EXISTING_ELEMENT) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5, 5, 15};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5, 5, 15};
  std::pair<s21::multiset<int>::iterator, s21::multiset<int>::iterator> it_S1 =
      M1.equal_range(100);
  std::pair<std::multiset<int>::iterator, std::multiset<int>::iterator> it_S2 =
      M2.equal_range(100);
  ASSERT_EQ(it_S1.first == M1.end(), it_S2.first == M2.end());
  ASSERT_EQ(it_S1.second == M1.end(), it_S2.second == M2.end());
}

TEST(multiset, MULTISET_OPERATOR_EQUAL_COPY_NOT_EMPTY_MULTISET) {
  s21::multiset<int> M1 = {50, 25, 25, 75, 10};
  s21::multiset<int> M2 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  std::multiset<int> M3 = {50, 25, 25, 75, 10};
  std::multiset<int> M4 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  M1 = M2;
  M3 = M4;
  ASSERT_EQ(multisetsEqual(M1, M3), true);
  ASSERT_EQ(multisetsEqual(M2, M4), true);
}

TEST(multiset, MULTISET_OPERATOR_EQUAL_COPY_EMPTY_MULTISET) {
  s21::multiset<int> M1 = {50, 25, 25, 75, 10};
  s21::multiset<int> M2 = {};
  std::multiset<int> M3 = {50, 25, 25, 75, 10};
  std::multiset<int> M4 = {};
  M1 = M2;
  M3 = M4;
  ASSERT_EQ(multisetsEqual(M1, M3), true);
  ASSERT_EQ(multisetsEqual(M2, M4), true);
}

TEST(multiset, MULTISET_OPERATOR_EQUAL_COPY_SAME_multiset) {
  s21::multiset<int> M1 = {50, 25, 25, 75, 10};
  std::multiset<int> M2 = {50, 25, 25, 75, 10};
  M1 = M1;
  M2 = M2;
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_OPERATOR_EQUAL_MOVE_NOT_EMPTY_MULTISET) {
  s21::multiset<int> M1 = {50, 25, 25, 75, 10};
  s21::multiset<int> M2 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  std::multiset<int> M3 = {50, 25, 25, 75, 10};
  std::multiset<int> M4 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  M1 = std::move(M2);
  M3 = std::move(M4);
  ASSERT_EQ(multisetsEqual(M1, M3), true);
  ASSERT_EQ(multisetsEqual(M2, M4), true);
}

TEST(multiset, MULTISET_OPERATOR_EQUAL_MOVE_EMPTY_MULTISET) {
  s21::multiset<int> M1 = {50, 25, 25, 75, 10};
  s21::multiset<int> M2 = {};
  std::multiset<int> M3 = {50, 25, 25, 75, 10};
  std::multiset<int> M4 = {};
  M1 = std::move(M2);
  M3 = std::move(M4);
  ASSERT_EQ(multisetsEqual(M1, M3), true);
  ASSERT_EQ(multisetsEqual(M2, M4), true);
}

TEST(multiset, MULTISET_OPERATOR_EQUAL_MOVE_SAME_multiset) {
  s21::multiset<int> M1 = {50, 25, 25, 75, 10};
  std::multiset<int> M2 = {50, 25, 25, 75, 10};
  M1 = std::move(M1);
  M2 = std::move(M2);
  ASSERT_EQ(multisetsEqual(M1, M2), true);
}

TEST(multiset, MULTISET_PLUS_PLUS_OPERATOR) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  ASSERT_EQ(*(++M1.begin()), *(++M2.begin()));
}

TEST(multiset, MULTISET_MINUS_MINUS_OPERATOR) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  s21::multiset<int>::iterator it_S1 = ++M1.begin();
  std::multiset<int>::iterator it_S2 = ++M2.begin();
  ASSERT_EQ(*(--it_S1), *(--it_S2));
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(multiset, MULTISET_OPERATOR_PLUS_PLUS) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  s21::multiset<int>::iterator it_S1 = M1.begin();
  std::multiset<int>::iterator it_S2 = M2.begin();
  ASSERT_EQ(*(it_S1++), *(it_S2++));
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(multiset, MULTISET_OPERATOR_MINUS_MINUS) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  s21::multiset<int>::iterator it_S1 = ++M1.begin();
  std::multiset<int>::iterator it_S2 = ++M2.begin();
  ASSERT_EQ(*(it_S1--), *(it_S2--));
  ASSERT_EQ(*it_S1, *it_S2);
}

TEST(multiset, MULTISET_DEREFERENCE_OPERATOR_EXISTING_MULTISET_1) {
  s21::multiset<int> M1 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  std::multiset<int> M2 = {50, 25, 75, 10, 40, 5,  5,  15,
                           35, 45, 80, 60, 70, 55, 90, 78};
  ASSERT_EQ(*M1.begin(), *M2.begin());
}

TEST(multiset, MULTISET_DEREFERENCE_OPERATOR_NOT_EXISTING_MULTISET) {
  try {
    s21::multiset<int>::iterator it_S1;
    *it_S1;
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid index");
  }
}

TEST(multiset, MULTISET_NOT_EQUAL_OPERATOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  std::multiset<int> M2 = {1, 2, 2, 3};
  ASSERT_EQ(M1.begin() != M1.begin(), M2.begin() != M2.begin());
}

TEST(multiset, MULTISET_EQUAL_OPERATOR) {
  s21::multiset<int> M1 = {1, 2, 2, 3};
  std::multiset<int> M2 = {1, 2, 2, 3};
  ASSERT_EQ(M1.begin() == M1.begin(), M2.begin() == M2.begin());
}

TEST(multiset, InsertMany) {
  s21::multiset<typename std::vector<int>> s21_multiset;
  std::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {4, 8, 13, 0, 55};
  s21::multiset<typename std::vector<int>> std_multiset = {vec1, vec2};
  s21_multiset.insert_many(vec1, vec2);
  auto s21_it = s21_multiset.begin();
  auto std_it = std_multiset.begin();
  for (; s21_it != s21_multiset.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE(*std_it == *s21_it);
  }
}

TEST(multiset, InsertMany2) {
  std::multiset<char> std_multiset = {'a', 'l', 'i', 'n', 'a'};
  s21::multiset<char> s21_multiset;
  s21_multiset.insert_many('a', 'l', 'i', 'n', 'a');
  auto s21_it = s21_multiset.begin();
  auto std_it = std_multiset.begin();
  for (; s21_it != s21_multiset.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE(*std_it == *s21_it);
  }
}

TEST(multiset, InsertMany3) {
  std::multiset<char> std_multiset = {'a', 'a', 'a', 'a', 'a'};
  s21::multiset<char> s21_multiset;
  s21_multiset.insert_many('a', 'a', 'a', 'a', 'a');
  auto s21_it = s21_multiset.begin();
  auto std_it = std_multiset.begin();
  for (; s21_it != s21_multiset.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE(*std_it == *s21_it);
  }
  EXPECT_TRUE(s21_multiset.size() == std_multiset.size());
}