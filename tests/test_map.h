#include <map>

#include "unit_tests_entry.h"

TEST(map, ConstructorDefault) {
  s21::map<int, char> s21_empty_map;
  std::map<int, char> std_empty_map;
  EXPECT_EQ(s21_empty_map.empty(), std_empty_map.empty());
}

TEST(map, ConstructorInitializer) {
  s21::map<int, char> s21_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
  std::map<int, char> std_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
  EXPECT_EQ(s21_map.size(), std_map.size());
  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }
}

TEST(map, ConstructorInitializer2) {
  s21::map<int, char> s21_map = {};
  std::map<int, char> std_map = {};
  EXPECT_EQ(s21_map.size(), std_map.size());
  auto s21_it = s21_map.end();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++std_it, ++s21_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
    ;
  }
}

TEST(map, ConstructorCopy) {
  s21::map<int, int> s21_map = {{1, 2}, {3, 4}, {5, 6}};
  std::map<int, int> std_map = {{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> s21_map_copy(s21_map);
  std::map<int, int> std_map_copy(std_map);
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  auto s21_it = s21_map_copy.begin();
  auto std_it = std_map_copy.begin();
  for (; s21_it != s21_map_copy.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }
}

TEST(map, OperatorCopy) {
  s21::map<int, int> s21_map = {{1, 2}, {3, 4}, {5, 6}};
  std::map<int, int> std_map = {{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> s21_map_copy = s21_map;
  std::map<int, int> std_map_copy = std_map;
  EXPECT_EQ(s21_map_copy.size(), std_map_copy.size());
  auto s21_it = s21_map_copy.begin();
  auto std_it = std_map_copy.begin();
  for (; s21_it != s21_map_copy.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }
}

TEST(map, ConstructorMove) {
  s21::map<int, int> s21_map = {{1, 2}, {3, 4}, {5, 6}};
  std::map<int, int> std_map = {{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> s21_map2(std::move(s21_map));
  std::map<int, int> std_map2(std::move(std_map));
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map2.size(), std_map2.size());
  auto s21_it = s21_map2.begin();
  auto std_it = std_map2.begin();
  for (; s21_it != s21_map2.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }
}

TEST(map, OperatorMove) {
  s21::map<int, int> s21_map = {{1, 2}, {3, 4}, {5, 6}};
  std::map<int, int> std_map = {{1, 2}, {3, 4}, {5, 6}};
  s21::map<int, int> s21_map2 = std::move(s21_map);
  std::map<int, int> std_map2 = std::move(std_map);
  EXPECT_EQ(s21_map.size(), std_map.size());
  EXPECT_EQ(s21_map2.size(), std_map2.size());
  auto s21_it = s21_map2.begin();
  auto std_it = std_map2.begin();
  for (; s21_it != s21_map2.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }
}

TEST(map, OperatorSubscript) {
  s21::map<char, std::string> s21_map = {
      {'a', "Apple"}, {'b', "Blueberry"}, {'c', "Cherry"}};
  std::map<char, std::string> std_map = {
      {'a', "Apple"}, {'b', "Blueberry"}, {'c', "Cherry"}};
  s21_map['a'] = "Avocado";
  std_map['a'] = "Avocado";
  std_map['b'] = "Blackberry";
  EXPECT_TRUE(s21_map['a'] == std_map['a']);
  EXPECT_FALSE(s21_map['b'] == std_map['b']);
  EXPECT_TRUE(s21_map['c'] == std_map['c']);
}
TEST(map, OperatorSubscript2) {
  s21::map<char, std::string> s21_map = {
      {'a', "Apple"}, {'b', "Blueberry"}, {'c', "Cherry"}};
  std::map<char, std::string> std_map = {
      {'a', "Apple"}, {'b', "Blueberry"}, {'c', "Cherry"}};
  s21_map['d'] = "Dragonfruit";
  std_map['d'] = "Dragonfruit";
  EXPECT_TRUE(s21_map['d'] == std_map['d']);
}

TEST(map, OperatorAtException) {
  s21::map<char, std::string> s21_map = {
      {'a', "Apple"}, {'b', "Blueberry"}, {'c', "Cherry"}};
  EXPECT_THROW(s21_map.at('g') = "Avocado", std::out_of_range);
}

TEST(map, OperatorAt) {
  s21::map<char, std::string> s21_map = {
      {'a', "Apple"}, {'b', "Blueberry"}, {'c', "Cherry"}};
  std::map<char, std::string> std_map = {
      {'a', "Apple"}, {'b', "Blueberry"}, {'c', "Cherry"}};
  s21_map.at('a') = "Avocado";
  std_map.at('a') = "Avocado";
  std_map.at('b') = "Blackberry";
  EXPECT_TRUE(s21_map['a'] == std_map['a']);
  EXPECT_FALSE(s21_map['b'] == std_map['b']);
  EXPECT_TRUE(s21_map['c'] == std_map['c']);
}

TEST(map, Size) {
  s21::map<char, std::string> s21_map = {
      {'a', "Apple"}, {'b', "Blueberry"}, {'c', "Cherry"}};
  std::map<char, std::string> std_map = {
      {'a', "Apple"}, {'b', "Blueberry"}, {'c', "Cherry"}};
  EXPECT_EQ(s21_map.size(), std_map.size());
}

TEST(map, Size1) {
  s21::map<char, std::string> s21_map;
  std::map<char, std::string> std_map;
  EXPECT_TRUE(s21_map.empty() == std_map.empty());
  s21_map.insert('1', "a");
  EXPECT_FALSE(s21_map.empty() == std_map.empty());
  EXPECT_EQ(s21_map.size(), 1);
}

TEST(map, MaxSize) {
  s21::map<char, std::string> s21_map;
  std::map<char, std::string> std_map;
  EXPECT_TRUE(s21_map.empty() == std_map.empty());
  s21_map.insert('1', "a");
  EXPECT_FALSE(s21_map.empty() == std_map.empty());
  EXPECT_EQ(s21_map.size(), 1);
}

TEST(map, Clear) {
  s21::map<int, int> s21_map;
  std::map<int, int> std_map;
  s21_map.clear();
  std_map.clear();
  EXPECT_EQ(s21_map.empty(), std_map.empty());
  s21_map.insert(std::make_pair(1, 1));
  std_map.insert(std::make_pair(1, 1));
  EXPECT_EQ(s21_map.empty(), std_map.empty());
  s21_map.clear();
  std_map.clear();
  EXPECT_EQ(s21_map.empty(), std_map.empty());
}

TEST(map, InsertPair) {
  s21::map<int, char> s21_map;
  std::map<int, char> std_map;
  s21_map.insert(std::make_pair(1, 'a'));
  s21_map.insert(std::make_pair(2, 'a'));
  s21_map.insert(std::make_pair(3, 'a'));
  std_map.insert(std::make_pair(1, 'a'));
  std_map.insert(std::make_pair(2, 'a'));
  std_map.insert(std::make_pair(3, 'a'));

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }

  auto pr1 = s21_map.insert(std::make_pair(1, 'a'));
  auto pr2 = std_map.insert(std::make_pair(1, 'a'));
  EXPECT_TRUE(pr1.second == pr2.second);
}

TEST(map, InsertKeyValue) {
  s21::map<int, char> s21_map;
  std::map<int, char> std_map;
  s21_map.insert(1, 'a');
  s21_map.insert(2, 'a');
  s21_map.insert(3, 'a');
  std_map.insert(std::make_pair(1, 'a'));
  std_map.insert(std::make_pair(2, 'a'));
  std_map.insert(std::make_pair(3, 'a'));

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }

  auto pr1 = s21_map.insert(1, 'a');
  auto pr2 = std_map.insert(std::make_pair(1, 'a'));
  EXPECT_TRUE(pr1.second == pr2.second);
}

TEST(map, InsertOrAssign) {
  s21::map<int, char> s21_map;
  std::map<int, char> std_map;
  s21_map.insert(1, 'a');
  s21_map.insert(2, 'a');
  s21_map.insert(3, 'a');
  std_map.insert(std::make_pair(1, 'a'));
  std_map.insert(std::make_pair(2, 'a'));
  std_map.insert(std::make_pair(3, 'a'));

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }

  auto pr1 = s21_map.insert_or_assign(1, 'b');
  auto i = std_map.begin();
  EXPECT_TRUE((*pr1.first).first == (*i).first);
  EXPECT_FALSE((*pr1.first).second == (*i).second);
}

TEST(map, Erase) {
  s21::map<int, char> s21_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
  std::map<int, char> std_map = {{1, 'x'}, {2, 'b'}, {3, 'z'}, {4, 'y'}};
  EXPECT_EQ(s21_map.size(), std_map.size());
  s21_map.erase(s21_map.begin());
  std_map.erase(std_map.begin());
  EXPECT_EQ(s21_map.size(), std_map.size());
  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }
}

TEST(map, Swap) {
  s21::map<int, int> s21_map = {{1, 1}};
  s21::map<int, int> s21_swap_map = {{3, 3}, {4, 4}};

  s21_map.swap(s21_swap_map);
  EXPECT_EQ(s21_map.size(), 2);
  EXPECT_EQ(s21_swap_map.size(), 1);
  auto x = (*(s21_map.begin())).first;
  auto y = (*(s21_swap_map.begin())).first;
  EXPECT_EQ(x, 3);
  EXPECT_EQ(y, 1);
}

TEST(map, Merge) {
  s21::map<int, int> s21_map = {{1, 1}, {4, 4}, {2, 2}};
  s21::map<int, int> s21_map_merge = {{3, 3}, {4, 4}};

  std::map<int, int> std_map = {{1, 1}, {4, 4}, {2, 2}};
  std::map<int, int> std_map_merge = {{3, 3}, {4, 4}};

  s21_map.merge(s21_map_merge);
  std_map.merge(std_map_merge);

  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }
  EXPECT_EQ(s21_map_merge.contains(4), false);
  EXPECT_EQ(s21_map_merge.contains(3), false);
}

TEST(map, Merge2) {
  s21::map<int, int> s21_map_merge = {{1, 2}, {3, 4}, {5, 6}};
  std::map<int, int> std_map_merge = {{1, 2}, {3, 4}, {5, 6}};

  for (const auto& it : std_map_merge) {
    int key = it.first;
    EXPECT_NE(s21_map_merge.find(key), s21_map_merge.end());
  }
}

TEST(map, InsertMany) {
  s21::map<char, typename std::vector<int>> s21_map;
  std::vector<int> vec1 = {1, 2, 3, 4, 5};
  std::vector<int> vec2 = {4, 8, 13, 0, 55};
  std::map<char, typename std::vector<int>> std_map = {{'a', vec1},
                                                       {'b', vec2}};
  s21_map.insert_many(std::make_pair('a', vec1), std::make_pair('b', vec2));
  auto s21_it = s21_map.begin();
  auto std_it = std_map.begin();
  for (; s21_it != s21_map.end(); ++s21_it, ++std_it) {
    EXPECT_TRUE((*s21_it).first == (*std_it).first);
    EXPECT_TRUE((*s21_it).second == (*std_it).second);
  }
}

bool mapsEqual(s21::map<int, char> M1, std::map<int, char> M2) {
  if (M1.size() != M2.size()) return false;
  s21::map<int, char>::iterator it_M1 = M1.begin();
  std::map<int, char>::iterator it_M2 = M2.begin();
  for (; it_M2 != M2.end(); ++it_M1, ++it_M2) {
    if (*it_M1 != *it_M2) return false;
  }
  return true;
}

TEST(map, MAP_DEFAULT_CONSTRUCTOR) {
  s21::map<int, char> M1;
  std::map<int, char> M2;
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_LIST_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_COPY_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(M3);
  ASSERT_EQ(mapsEqual(M2, M4), true);
  ASSERT_EQ(mapsEqual(M1, M3), true);
}

TEST(map, MAP_MOVE_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(std::move(M1));
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(std::move(M3));
  ASSERT_EQ(mapsEqual(M2, M4), true);
  ASSERT_EQ(mapsEqual(M1, M3), true);
}

TEST(map, MAP_AT_IN_BOUNDS1) {
  s21::map<int, char> M1 = {{3, 'a'}, {2, 'b'}, {1, 'c'}};
  std::map<int, char> M2 = {{3, 'a'}, {2, 'b'}, {1, 'c'}};
  ASSERT_EQ(M1.at(2), M2.at(2));
}

TEST(map, MAP_AT_IN_BOUNDS2) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1.at(2), M2.at(2));
}

TEST(map, MAP_AT_OUT_OF_BOUNDS) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_THROW(M2.at(36), std::out_of_range);
  ASSERT_THROW(M1.at(36), std::out_of_range);
}

TEST(map, MAP_AT_ENTERING_VALUE) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.at(2) = 'q';
  M2.at(2) = 'q';
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_EMPTY_DEFAULT_CONSTRUCTOR) {
  s21::map<int, char> M1;
  std::map<int, char> M2;
  ASSERT_EQ(M1.empty(), M2.empty());
}

TEST(map, MAP_EMPTY_LIST_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1.empty(), M2.empty());
  s21::map<int, char> M3 = {};
  std::map<int, char> M4 = {};
  ASSERT_EQ(M3.empty(), M4.empty());
  s21::map<int, char> M5 = {{1, 'a'}};
  std::map<int, char> M6 = {{1, 'a'}};
  ASSERT_EQ(M5.empty(), M6.empty());
}

TEST(map, MAP_EMPTY_COPY_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(M3);
  ASSERT_EQ(M1.empty(), M3.empty());
  ASSERT_EQ(M2.empty(), M4.empty());
  s21::map<int, char> M5;
  s21::map<int, char> M6(M5);
  std::map<int, char> M7;
  std::map<int, char> M8(M7);
  ASSERT_EQ(M5.empty(), M7.empty());
  ASSERT_EQ(M6.empty(), M8.empty());
}

TEST(map, MAP_EMPTY_MOVE_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(std::move(M1));
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(std::move(M3));
  ASSERT_EQ(M1.empty(), M3.empty());
  ASSERT_EQ(M2.empty(), M4.empty());
  s21::map<int, char> M5;
  s21::map<int, char> M6(std::move(M5));
  std::map<int, char> M7;
  std::map<int, char> M8(std::move(M7));
  ASSERT_EQ(M5.empty(), M7.empty());
  ASSERT_EQ(M6.empty(), M8.empty());
}

TEST(map, MAP_SIZE_DEFAULT_CONSTRUCTOR) {
  s21::map<int, char> M1;
  std::map<int, char> M2;
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(map, MAP_SIZE_LIST_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  ASSERT_EQ(M1.size(), M2.size());
}

TEST(map, MAP_SIZE_COPY_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(M1);
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(M3);
  ASSERT_EQ(M1.size(), M3.size());
  ASSERT_EQ(M2.size(), M4.size());
}

TEST(map, MAP_SIZE_MOVE_CONSTRUCTOR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2(std::move(M1));
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4(std::move(M3));
  ASSERT_EQ(M1.size(), M3.size());
  ASSERT_EQ(M2.size(), M4.size());
}

TEST(map, MAP_MAX_SIZE) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  EXPECT_NEAR(M1.max_size() / M2.max_size(), 1, 1);
}

TEST(map, MAP_CLEAR) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.clear();
  M2.clear();
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_INSERT_BY_PAIR_EXISTING_ELEMENT) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.insert(std::pair<int, char>(3, 'c'));
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_INSERT_BY_VALUE_SEPARATED_EXISTING_ELEMENT) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.insert(3, 'c');
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_INSERT_0_ELEMENTS) {
  s21::map<int, char> M1 = {};
  std::map<int, char> M2 = {};
  M1.insert(std::pair<int, char>(3, 'c'));
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_INSERT_MIDDLE_ELEMENT) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {4, 'd'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {4, 'd'}};
  M1.insert(std::pair<int, char>(3, 'c'));
  M2.insert(std::pair<int, char>(3, 'c'));
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_INSERT_MIDDLE_ELEMENT_DOES_NOT_CONTAIN) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {4, 'd'}};
  auto res = M1.insert_or_assign(3, 'c');

  ASSERT_EQ(res.second, true);
}

TEST(map, MAP_INSERT_MIDDLE_ELEMENT_CONTAINS) {
  s21::map<int, char> M1 = {{1, 'a'}, {3, 'c'}, {4, 'd'}};
  auto res = M1.insert_or_assign(3, 'c');
  ASSERT_EQ(res.second, false);
}

TEST(map, MAP_ERASE_NO_CHILD) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char>::iterator it_M1 = --M1.end();
  std::map<int, char>::iterator it_M2 = --M2.end();
  M1.erase(it_M1);
  M2.erase(it_M2);
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_ERASE_TWO_CHILDREN) {
  s21::map<int, char> M1 = {{3, 'c'}, {1, 'a'}, {2, 'b'}, {4, 'd'}, {5, 'e'}};
  std::map<int, char> M2 = {{3, 'c'}, {1, 'a'}, {2, 'b'}, {4, 'd'}, {5, 'e'}};
  s21::map<int, char>::iterator it_M1 = ++M1.begin();
  std::map<int, char>::iterator it_M2 = ++M2.begin();
  ++it_M1;
  ++it_M2;
  M1.erase(it_M1);
  M2.erase(it_M2);
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_SWAP_ONE_LIST_EMPTY1) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2 = {};
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4 = {};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(map, MAP_SWAP_ONE_LIST_EMPTY2) {
  s21::map<int, char> M1 = {};
  s21::map<int, char> M2 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M3 = {};
  std::map<int, char> M4 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(map, MAP_SWAP_NUMBER_OF_ELEMENTS) {
  s21::map<int, char> M1 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  s21::map<int, char> M2 = {{4, 'd'}, {5, 'e'}, {6, 'f'}};
  std::map<int, char> M3 = {{1, 'a'}, {2, 'b'}, {3, 'c'}};
  std::map<int, char> M4 = {{4, 'd'}, {5, 'e'}, {6, 'f'}};
  M1.swap(M2);
  M3.swap(M4);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(map, MAP_MERGE_DIFFERENT_ELEMENTS) {
  s21::map<int, char> M1 = {{1, 'a'}, {3, 'c'}, {5, 'e'}};
  s21::map<int, char> M2 = {{2, 'b'}, {4, 'd'}, {6, 'f'}};
  std::map<int, char> M3 = {{1, 'a'}, {3, 'c'}, {5, 'e'},
                            {2, 'b'}, {4, 'd'}, {6, 'f'}};
  std::map<int, char> empty;
  M1.merge(M2);
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, empty), true);
}

TEST(map, MAP_CONTAINS_EXISTING_ELEMENT) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'},
                            {10, 'd'}, {40, 'e'}, {51, 'f'}};
  ASSERT_EQ(M1.contains(10), true);
}

TEST(map, MAP_OPERATOR_ASSIGNMENT_COPY_SAME_SET) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  M1 = M1;
  M2 = M2;
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_OPERATOR_ASSIGNMENT_COPY) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char> M2 = {{10, 'q'}, {20, 'w'}, {30, 'e'}, {40, 'r'}};
  std::map<int, char> M3 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M4 = {{10, 'q'}, {20, 'w'}, {30, 'e'}, {40, 'r'}};
  M1 = M2;
  M3 = M4;
  ASSERT_EQ(mapsEqual(M1, M3), true);
  ASSERT_EQ(mapsEqual(M2, M4), true);
}

TEST(map, MAP_OPERATOR_ASSIGNMENT_MOVE_SAME_SET) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  M1 = std::move(M1);
  M2 = std::move(M2);
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_OPERATOR_ACCESS) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(M1[75], M2[75]);
}

TEST(map, MAP_OPERATOR_INSERT) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(mapsEqual(M1, M2), true);
}

TEST(map, MAP_PLUS_PLUS_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char>::iterator it_M1 = ++M1.begin();
  std::map<int, char>::iterator it_M2 = ++M2.begin();
  ASSERT_EQ((*it_M1).first, (*it_M2).first);
  ASSERT_EQ((*it_M1).second, (*it_M2).second);
}

TEST(map, MAP_MINUS_MINUS_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char>::iterator it_M1 = --M1.end();
  std::map<int, char>::iterator it_M2 = --M2.end();
  ASSERT_EQ((*it_M1).first, (*it_M2).first);
  ASSERT_EQ((*it_M1).second, (*it_M2).second);
}

TEST(map, MAP_OPERATOR_PLUS_PLUS) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  s21::map<int, char>::iterator it_M1 = M1.begin();
  std::map<int, char>::iterator it_M2 = M2.begin();
  it_M1++;
  it_M2++;
  ASSERT_EQ((*it_M1).first, (*it_M2).first);
  ASSERT_EQ((*it_M1).second, (*it_M2).second);
}

TEST(map, MAP_OPERATOR_MINUS_MINUS) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {
      {50, 'a'},
      {25, 'b'},
      {75, 'c'},
      {10, 'd'},
  };
  s21::map<int, char>::iterator it_M1 = M1.end();
  std::map<int, char>::iterator it_M2 = M2.end();
  it_M1--;
  it_M2--;
  ASSERT_EQ(*it_M1, *it_M2);
}

TEST(map, MAP_DEREFERENCE_OPERATOR_EXISTING_LIST) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ((*(M1.begin())).first, ((*M2.begin())).first);
  ASSERT_EQ((*(M1.begin())).second, ((*M2.begin())).second);
}

TEST(map, MAP_DEREFERENCE_OPERATOR_NOT_EXISTING_LIST) {
  try {
    s21::map<int, char>::iterator it_S1;
    *it_S1;
  } catch (const std::exception& e) {
    ASSERT_STREQ(e.what(), "Invalid index");
  }
}

TEST(map, MAP_NOT_EQUAL_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(M1.begin() != M1.begin(), M2.begin() != M2.begin());
}

TEST(map, MAP_EQUAL_OPERATOR) {
  s21::map<int, char> M1 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  std::map<int, char> M2 = {{50, 'a'}, {25, 'b'}, {75, 'c'}, {10, 'd'}};
  ASSERT_EQ(M1.begin() == M1.begin(), M2.begin() == M2.begin());
}