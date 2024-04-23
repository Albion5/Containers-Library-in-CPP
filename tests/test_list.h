#include <list>

#include "unit_tests_entry.h"

bool listsEqual(s21::List<int> &L1, std::list<int> &L2) {
  if (L1.size() != L2.size()) {
    // std::cout << L1.size() << "\n";
    // std::cout << L2.size() << "\n";
    return false;
  }
  s21::List<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  for (; it_L1 != L1.end(); ++it_L1, ++it_L2) {
    if (*it_L1 != *it_L2) {
      return false;
    }
  }
  return true;
}

TEST(list, DEFAULT_CONSTRUCTOR) {
  s21::List<int> L1;
  std::list<int> L2;
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, NSIZE_CONSTRUCTOR) {
  s21::List<int> L1(3);
  std::list<int> L2(3);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, LIST_CONSTRUCTOR) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, COPY_CONSTRUCTOR) {
  s21::List<int> L1 = {1, 2, 3};
  s21::List<int> L2(L1);
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4(L3);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, MOVE_CONSTRUCTOR) {
  s21::List<int> L1 = {1, 2, 3};
  s21::List<int> L2(std::move(L1));
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4(std::move(L3));
  // ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, SIZE_DEFAULT_CONTRUCTOR) {
  s21::List<int> L1;
  std::list<int> L2;
  ASSERT_EQ(L1.size(), L2.size());
}

TEST(list, SIZE_NSIZE_CONSTRUCTOR) {
  s21::List<int> L1(3);
  std::list<int> L2(3);
  ASSERT_EQ(L1.size(), L2.size());
}

TEST(list, SIZE_LIST_CONSTRUCTOR) {
  s21::List<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};
  ASSERT_EQ(L1.size(), L2.size());
}

TEST(list, SIZE_COPY_CONSTRUCTOR) {
  s21::List<int> L1 = {1, 2, 3, 4, 5, 6, 7};
  s21::List<int> L2(L1);
  std::list<int> L3 = {1, 2, 3, 4, 5, 6, 7};
  std::list<int> L4(L3);
  ASSERT_EQ(L2.size(), L4.size());
}

TEST(list, SIZE_MOVE_CONSTRUCTOR) {
  s21::List<int> L1 = {1, 2, 3, 4, 5};
  s21::List<int> L2(std::move(L1));
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4(std::move(L3));
  // ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, EMPTY_DEFAULT_CONSTRUCTOR) {
  s21::List<int> L1;
  std::list<int> L2;
  ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(list, EMPTY_NSIZE_CONSTRUCTOR) {
  s21::List<int> L1(1);
  std::list<int> L2(1);
  ASSERT_EQ(L1.empty(), L2.empty());

  s21::List<int> L3(0);
  std::list<int> L4(0);
  ASSERT_EQ(L3.empty(), L4.empty());

  s21::List<int> L5(0);
  std::list<int> L6(0);
  L5.push_back(0);
  L6.push_back(0);
  ASSERT_EQ(L5.empty(), L6.empty());
  L5.pop_front();
  L6.pop_front();
  ASSERT_EQ(L5.empty(), L6.empty());
}

TEST(list, EMPTY_LIST_CONSTRUCTOR) {
  s21::List<int> L1 = {};
  std::list<int> L2 = {};
  ASSERT_EQ(L1.empty(), L2.empty());

  s21::List<int> L3 = {1};
  std::list<int> L4 = {1};
  ASSERT_EQ(L3.empty(), L4.empty());

  L1.push_back(1);
  L2.push_back(1);
  ASSERT_EQ(L1.empty(), L2.empty());
}

TEST(list, EMPTY_COPY_CONSTRUCTOR) {
  s21::List<int> L1;
  s21::List<int> L2(L1);
  std::list<int> L3;
  std::list<int> L4(L3);
  ASSERT_EQ(L2.empty(), L4.empty());

  s21::List<int> L5 = {1};
  s21::List<int> L6(L5);
  std::list<int> L7 = {1};
  std::list<int> L8(L7);
  ASSERT_EQ(L6.empty(), L8.empty());
}

TEST(list, EMPTY_MOVE_CONSTRUCTOR) {
  s21::List<int> L1;
  s21::List<int> L2(std::move(L1));
  std::list<int> L3;
  std::list<int> L4(std::move(L3));
  ASSERT_EQ(L1.empty(), L3.empty());
  ASSERT_EQ(L2.empty(), L4.empty());
}

TEST(list, SWAP_ONE_LIST_EMPTY1) {
  s21::List<int> L1 = {1, 2, 3};
  s21::List<int> L2 = {};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {};
  L1.swap(L2);
  L3.swap(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, SWAP_ONE_LIST_EMPTY2) {
  s21::List<int> L1 = {};
  s21::List<int> L2 = {4, 5, 6};
  std::list<int> L3 = {};
  std::list<int> L4 = {4, 5, 6};
  L1.swap(L2);
  L3.swap(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, SWAP_EMPTY_LISTS) {
  s21::List<int> L1 = {};
  s21::List<int> L2 = {};
  std::list<int> L3 = {};
  std::list<int> L4 = {};
  L1.swap(L2);
  L3.swap(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, SWAP_SAME_NUMBER_OF_ELEMENTS) {
  s21::List<int> L1 = {1, 2, 3};
  s21::List<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1.swap(L2);
  L3.swap(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, SWAP_DIFFERENT_NUMBER_OF_ELEMENTS1) {
  s21::List<int> L1 = {1, 2, 3, 4, 5};
  s21::List<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {4, 5, 6};
  L1.swap(L2);
  L3.swap(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, SWAP_DIFFERENT_NUMBER_OF_ELEMENTS2) {
  s21::List<int> L1 = {1, 2, 3};
  s21::List<int> L2 = {4, 5, 6, 128, 40};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6, 128, 40};
  L1.swap(L2);
  L3.swap(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, REVERSE_5_ELEMENTS) {
  s21::List<int> L1 = {1, 2, 3, 4, 5};
  std::list<int> L2 = {1, 2, 3, 4, 5};
  L1.reverse();
  L2.reverse();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, REVERSE_4_ELEMENTS) {
  s21::List<int> L1 = {1, 2, 3, 4};
  std::list<int> L2 = {1, 2, 3, 4};
  L1.reverse();
  L2.reverse();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, REVERSE_1_ELEMENTS) {
  s21::List<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.reverse();
  L2.reverse();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, REVERSE_0_ELEMENTS) {
  s21::List<int> L1 = {};
  std::list<int> L2 = {};
  L1.reverse();
  L2.reverse();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, INSERT_START_OF_THE_LIST_3_ELEMENTS) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::List<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.insert(it_L1, 128);
  // L1.print();
  L2.insert(it_L2, 128);
  // for (auto it = L2.begin(); it != L2.end(); ++it) {
  //   std::cout << *it << " ";
  // }
  // std::cout << std::endl;
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, INSERT_MIDDLE_OF_THE_LIST) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::List<int>::iterator it_L1 = ++L1.begin();
  std::list<int>::iterator it_L2 = ++L2.begin();
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, INSERT_START_OF_THE_LIST_1_ELEMENT) {
  s21::List<int> L1 = {1};
  std::list<int> L2 = {1};
  s21::List<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, INSERT_END_OF_THE_LIST) {
  s21::List<int> L1 = {1};
  std::list<int> L2 = {1};
  s21::List<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  ++it_L1;
  ++it_L2;
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, INSERT_CYCLIC_SHIFT) {
  s21::List<int> L1 = {1};
  std::list<int> L2 = {1};
  s21::List<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  ++it_L1;
  ++it_L1;
  ++it_L2;
  ++it_L2;
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, INSERT_EMPTY_LIST) {
  s21::List<int> L1 = {};
  std::list<int> L2 = {};
  s21::List<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.insert(it_L1, 128);
  L2.insert(it_L2, 128);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, ERASE_FIRST_ELEM) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::List<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  L1.erase(it_L1);
  L2.erase(it_L2);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, ERASE_LAST_ELEM) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::List<int>::iterator it_L1 = --L1.end();
  std::list<int>::iterator it_L2 = --L2.end();
  L1.erase(it_L1);
  L2.erase(it_L2);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, ERASE_MIDDLE_ELEM) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::List<int>::iterator it_L1 = ++L1.begin();
  std::list<int>::iterator it_L2 = ++L2.begin();
  L1.erase(it_L1);
  L2.erase(it_L2);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, SORT_1) {
  s21::List<int> L1 = {9, 2, 3, 1, 4};
  std::list<int> L2 = {9, 2, 3, 1, 4};
  L1.sort();
  L2.sort();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, SORT_2) {
  s21::List<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.sort();
  L2.sort();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, SORT_3) {
  s21::List<int> L1 = {};
  std::list<int> L2 = {};
  L1.sort();
  L2.sort();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, SORT_TYPE_STRING) {
  s21::List<std::string> L1 = {"abcd", "abcdef", "abc"};
  std::list<std::string> L2 = {"abcd", "abcdef", "abc"};
  L1.sort();
  L2.sort();
  s21::List<std::string>::iterator it_L1 = L1.begin();
  std::list<std::string>::iterator it_L2 = L2.begin();
  for (; it_L2 != L2.end(); ++it_L2, ++it_L1) {
    ASSERT_EQ(*it_L1, *it_L2);
  }
}

TEST(list, SORT_SORTED_LIST) {
  s21::List<int> L1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::list<int> L2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  L1.sort();
  L2.sort();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, MERGE_IDENTICAL_LISTS) {
  s21::List<int> L1 = {1, 2, 3, 4, 5};
  s21::List<int> L2 = {1, 2, 3, 4, 5};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {1, 2, 3, 4, 5};
  L1.merge(L2);
  L3.merge(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, MERGE_FIRST_LIST_REVERSE) {
  s21::List<int> L1 = {5, 4, 3, 2, 1};
  s21::List<int> L2 = {1, 2, 3, 4, 5};
  std::list<int> L3 = {5, 4, 3, 2, 1};
  std::list<int> L4 = {1, 2, 3, 4, 5};
  L1.merge(L2);
  L3.merge(L4);

  // s21::List<int>::iterator it_L1 = L1.begin();
  // std::list<int>::iterator it_L3 = L3.begin();

  // std::cout << std::endl << "L1:" << std::endl;
  // for (; it_L1 != L1.end(); ++it_L1) {
  //   std::cout << *it_L1 << " ";
  // }
  // std::cout << std::endl << "L2" << std::endl;
  // for (; it_L3 != L3.end(); ++it_L3) {
  //   std::cout << *it_L3 << " ";
  // }
  // std::cout << std::endl;

  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, MERGE_SECOND_LIST_REVERSE) {
  s21::List<int> L1 = {1, 2, 3, 4, 5};
  s21::List<int> L2 = {5, 4, 3, 2, 1};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {5, 4, 3, 2, 1};
  L1.merge(L2);
  L3.merge(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, merge) {
  std::list<int> L3 = {5, 4, 3, 2, 1};
  std::list<int> L4 = {1, 2, 3, 4, 5, 10, 12};
  s21::List<int> L1 = {5, 4, 3, 2, 1};
  s21::List<int> L2 = {1, 2, 3, 4, 5, 10, 12};
  L3.merge(L4);
  L1.merge(L2);
  // std::list<int>::iterator it_L3 = L3.begin();
  // std::cout << std::endl << "L3" << std::endl;
  // for (; it_L3 != L3.end(); ++it_L3) {
  //   std::cout << *it_L3 << " ";
  // }
  // std::cout << std::endl;
  // L1.print();
  ASSERT_EQ(listsEqual(L1, L3), true);
}

TEST(list, merge2) {
  std::list<int> L3 = {5, 2, 3};
  std::list<int> L4 = {5, 1};
  s21::List<int> L1 = {5, 2, 3};
  s21::List<int> L2 = {5, 1};
  L3.merge(L4);
  L1.merge(L2);
  // std::list<int>::iterator it_L3 = L3.begin();
  // std::cout << std::endl << "L3" << std::endl;
  // for (; it_L3 != L3.end(); ++it_L3) {
  //   std::cout << *it_L3 << " ";
  // }
  // std::cout << std::endl;
  // L1.print();
  ASSERT_EQ(listsEqual(L1, L3), true);
}

TEST(list, MERGE_FIRST_LIST_EMPTY) {
  s21::List<int> L1 = {};
  s21::List<int> L2 = {5, 4, 3, 2, 1};
  std::list<int> L3 = {};
  std::list<int> L4 = {5, 4, 3, 2, 1};
  L1.merge(L2);
  L3.merge(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, MERGE_SECOND_LIST_EMPTY) {
  s21::List<int> L1 = {1, 2, 3, 4, 5};
  s21::List<int> L2 = {};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {};
  L1.merge(L2);
  L3.merge(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, MERGE_SORTED_LISTS_1) {
  s21::List<int> L1 = {1, 2, 3, 4, 5};
  s21::List<int> L2 = {6, 7, 8, 9, 10};
  std::list<int> L3 = {1, 2, 3, 4, 5};
  std::list<int> L4 = {6, 7, 8, 9, 10};
  L1.merge(L2);
  L3.merge(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, MERGE_SORTED_LISTS_2) {
  s21::List<int> L1 = {1, 3, 5, 7};
  s21::List<int> L2 = {2, 4, 6, 8};
  std::list<int> L3 = {1, 3, 5, 7};
  std::list<int> L4 = {2, 4, 6, 8};
  L1.merge(L2);
  L3.merge(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, MERGE_TYPE_STRING) {
  s21::List<std::string> L1 = {"abc", "abcd", "abcdef"};
  s21::List<std::string> L2 = {"ab", "abcde"};
  std::list<std::string> L3 = {"abc", "abcd", "abcdef"};
  std::list<std::string> L4 = {"ab", "abcde"};
  L1.merge(L2);
  L3.merge(L4);
  s21::List<std::string>::iterator it_L1 = L1.begin();
  s21::List<std::string>::iterator it_L2 = L2.begin();
  std::list<std::string>::iterator it_L3 = L3.begin();
  std::list<std::string>::iterator it_L4 = L4.begin();
  for (; it_L3 != L3.end(); ++it_L3, ++it_L1) {
    ASSERT_EQ(*it_L1, *it_L3);
  }
  for (; it_L4 != L4.end(); ++it_L4, ++it_L2) {
    ASSERT_EQ(*it_L2, *it_L4);
  }
}

TEST(list, UNIQUE_SORTED_LIST) {
  s21::List<int> L1 = {1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 9, 10};
  std::list<int> L2 = {1, 2, 2, 3, 3, 4, 5, 6, 7, 8, 9, 9, 10};
  L1.unique();
  L2.unique();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, UNIQUE_UNSORTED_LIST) {
  s21::List<int> L1 = {1, 3, 3, 1, 1, 1, 5, 6, 128, 128, 4, 1, 1};
  std::list<int> L2 = {1, 3, 3, 1, 1, 1, 5, 6, 128, 128, 4, 1, 1};
  L1.unique();
  L2.unique();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, UNIQUE_EMPTY_LIST) {
  s21::List<int> L1 = {};
  std::list<int> L2 = {};
  L1.unique();
  L2.unique();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, UNIQUE_ONE_ELEM) {
  s21::List<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.unique();
  L2.unique();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, SPLICE_FIRST_ELEM) {
  s21::List<int> L1 = {1, 2, 3};
  s21::List<int> L2 = {4, 5, 6};
  std::list<int> empty_list = {};
  std::list<int> result = {4, 5, 6, 1, 2, 3};
  s21::List<int>::const_iterator it = L1.cbegin();
  L1.splice(it, L2);
  ASSERT_EQ(listsEqual(L1, result), true);
  ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(list, SPLICE_SECOND_ELEM) {
  s21::List<int> L1 = {1, 2};
  s21::List<int> L2 = {4, 5, 6};
  std::list<int> empty_list = {};
  std::list<int> result = {1, 4, 5, 6, 2};
  s21::List<int>::const_iterator it = ++L1.cbegin();
  L1.splice(it, L2);
  ASSERT_EQ(listsEqual(L1, result), true);
  ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(list, SPLICE_TO_EMPTY_LIST) {
  s21::List<int> L1 = {};
  s21::List<int> L2 = {4, 5, 6};
  std::list<int> empty_list = {};
  std::list<int> result = {4, 5, 6};
  s21::List<int>::const_iterator it = L1.cbegin();
  L1.splice(it, L2);
  ASSERT_EQ(listsEqual(L1, result), true);
  ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(list, SPLICE_FROM_EMPTY_LIST) {
  s21::List<int> L1 = {1, 2, 3};
  s21::List<int> L2 = {};
  std::list<int> empty_list = {};
  std::list<int> result = {1, 2, 3};
  s21::List<int>::const_iterator it = L1.cbegin();
  L1.splice(it, L2);
  ASSERT_EQ(listsEqual(L1, result), true);
  ASSERT_EQ(listsEqual(L2, empty_list), true);
}

TEST(list, FRONT_3_ELEMENTS) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.front(), L2.front());
}

TEST(list, BACK_EMPTY_LIST) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.back(), L2.back());
}

TEST(list, PUSH_FRONT) {
  s21::List<int> L1;
  std::list<int> L2;
  L1.push_front(1);
  L2.push_front(1);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, PUSH_BACK) {
  s21::List<int> L1;
  std::list<int> L2;
  L1.push_back(1);
  L2.push_back(1);
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, POP_FRONT) {
  s21::List<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.pop_front();
  L2.pop_front();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, POP_BACK) {
  s21::List<int> L1 = {1};
  std::list<int> L2 = {1};
  L1.pop_back();
  L2.pop_back();
  ASSERT_EQ(listsEqual(L1, L2), true);
}

TEST(list, PLUS_PLUS_OPERATOR_1) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::List<int>::iterator it_L1 = ++L1.begin();
  std::list<int>::iterator it_L2 = ++L2.begin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(list, DEREFERENCE_OPERATOR_EXISTING_LIST_1) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::List<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(list, DEREFERENCE_OPERATOR_EXISTING_LIST_2) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::List<int>::iterator it_L1 = L1.begin();
  std::list<int>::iterator it_L2 = L2.begin();
  *it_L1 = 128;
  *it_L2 = 128;
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(list, DEREFERENCE_OPERATOR_NOT_EXISTING_LIST_2) {
  try {
    s21::List<int>::iterator it_L1;
    *it_L1;
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid index");
  }
}

TEST(list, NOT_EQUAL_OPERATOR) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.begin() != L1.begin(), L2.begin() != L2.begin());
}

TEST(list, EQUAL_OPERATOR) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.begin() == L1.begin(), L2.begin() == L2.begin());
}

TEST(list, PLUS_PLUS_OPERATOR_2) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::List<int>::const_iterator it_L1 = ++L1.cbegin();
  std::list<int>::const_iterator it_L2 = ++L2.cbegin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(list, DEREFERENCE_OPERATOR_EXISTING_LIST_3) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  s21::List<int>::const_iterator it_L1 = L1.cbegin();
  std::list<int>::const_iterator it_L2 = L2.cbegin();
  ASSERT_EQ(*it_L1, *it_L2);
}

TEST(list, DEREFERENCE_OPERATOR_NOT_EXISTING_LIST_3) {
  try {
    s21::List<int>::const_iterator it_L1;
    *it_L1;
  } catch (const std::exception &e) {
    ASSERT_STREQ(e.what(), "Invalid index");
  }
}

TEST(list, NOT_EQUAL_OPERATOR_1) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.cbegin() != L1.cbegin(), L2.cbegin() != L2.cbegin());
}

TEST(list, EQUAL_OPERATOR_1) {
  s21::List<int> L1 = {1, 2, 3};
  std::list<int> L2 = {1, 2, 3};
  ASSERT_EQ(L1.cbegin() == L1.cbegin(), L2.cbegin() == L2.cbegin());
}

TEST(list, OPERATOR_EQUAL_COPY) {
  s21::List<int> L1 = {1, 2, 3};
  s21::List<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1 = L2;
  L3 = L4;
  ASSERT_EQ(listsEqual(L1, L3), true);
  ASSERT_EQ(listsEqual(L2, L4), true);
}

TEST(list, OPERATOR_EQUAL_MOVE) {
  s21::List<int> L1 = {1, 2, 3};
  s21::List<int> L2 = {4, 5, 6};
  std::list<int> L3 = {1, 2, 3};
  std::list<int> L4 = {4, 5, 6};
  L1 = std::move(L2);
  L3 = std::move(L4);
  ASSERT_EQ(listsEqual(L1, L3), true);
}

TEST(list, INSERT_MANY) {
  s21::List<int> L1;
  std::list<int> L3 = {1, 2, 3};
  L1.insert_many_back(1, 2, 3);
  ASSERT_EQ(listsEqual(L1, L3), true);
}

TEST(list, INSERT_MANY_FRONT) {
  s21::List<int> L1;
  std::list<int> L3 = {3, 2, 1};
  L1.insert_many_front(3, 2, 1);
  ASSERT_EQ(listsEqual(L1, L3), true);
}

TEST(List, Insert_Many_Back) {
  s21::List<int> our_list = {1, 2, 3, 4, 5};
  s21::List<int>::iterator our_it;
  our_list.insert_many_back(7, 8, 9);
  our_it = our_list.end();
  --our_it;
  EXPECT_EQ(*our_it, 9);
  --our_it;
  EXPECT_EQ(*our_it, 8);
  --our_it;
  EXPECT_EQ(*our_it, 7);
  --our_it;
  EXPECT_EQ(*our_it, 5);
  --our_it;
  EXPECT_EQ(*our_it, 4);
}

TEST(List, Insert_Many) {
  s21::List<int> our_list = {1, 2, 3, 4, 5};
  s21::List<int>::iterator our_it = our_list.begin();
  ++our_it;
  our_list.insert_many(our_it, 7, 8, 9);
  our_it = our_list.begin();
  EXPECT_EQ(*our_it, 1);
  ++our_it;
  EXPECT_EQ(*our_it, 7);
  ++our_it;
  EXPECT_EQ(*our_it, 8);
  ++our_it;
  EXPECT_EQ(*our_it, 9);
  ++our_it;
  EXPECT_EQ(*our_it, 2);
}