#include "test_array.h"
#include "test_list.h"
#include "test_map.h"
#include "test_multiset.h"
#include "test_queue.h"
#include "test_set.h"
#include "test_stack.h"
#include "test_vector.h"
#include "unit_tests_entry.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}