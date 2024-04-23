CC = g++
CFLAGS = -Wall -Wextra -Werror -std=c++17 -pedantic
GCOVR_FLAGS = --coverage -fprofile-arcs -ftest-coverage -O0 -fPIC
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

SRC_DIR = ./containers
SRC_PLUS_DIR = ./containersplus
TEST_DIR = ./tests
REPORT_DIR = ./report
LEAKS_DIR = ./leaks
TEST_HEADERS = $(shell find $(TEST_DIR) -name "*.h")
LIB_HEADERS = $(shell find $(SRC_DIR) $(SRC_PLUS_DIR) -name "*.h" -o -name "*.hpp")

TEST_OBJ = $(TEST_DIR)/test.out
TEST_COV_OBJ = $(TEST_DIR)/test_cov

GTEST_FLAGS =
OS = $(shell uname -s)
ifeq ($(OS), Linux)
	GTEST_FLAGS = -lcheck -lgtest -lsubunit -lm -lpthread -lrt 
else
	GTEST_FLAGS = -lcheck -lm -lpthread -lgtest
endif

OPEN = open
ifeq ($(OS), Linux)
	OPEN = xdg-open
endif



all: clean test

clean:
	find ./ \( -name "*.o" -o -name "*.gch" -o -name "*.gcda" -o -name "*.gcno" -o -name "*.gcov" -o -name "*.exe" -o -name "*.a" -o -name "*.out" \) -delete
	rm -rf $(LEAKS_DIR)
	rm -rf $(REPORT_DIR)
	rm -rf $(TEST_OBJ)
	rm -rf $(TEST_COV_OBJ)


valgrind: test
	mkdir -p $(LEAKS_DIR)
	valgrind $(VALGRIND_FLAGS) --log-file=$(LEAKS_DIR)/valgrind.log $(TEST_OBJ)

leaks: test
	mkdir -p $(LEAKS_DIR)
	leaks -atExit -- $(TEST_OBJ) > $(LEAKS_DIR)/leaks_report.txt


check_style:
	@echo "┏=========================================┓"
	@echo "┃  Checking your code for Google Style    ┃"
	@echo "┗=========================================┛"
	@find . \( -name '*.h' -o -name '*.hpp' -o -name '*.cpp' -o -name '*.tpp' \) -print0 | xargs -0 clang-format -n -style=Google

format_style:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	@find . \( -name '*.h' -o -name '*.hpp' -name '*.cpp'-o -name '*.tpp' \) -print0 | xargs -0 clang-format -n -style=Google

test: unit_tests_main.o $(LIB_HEADERS)
	$(CC) $(CFLAGS) -o $(TEST_OBJ) unit_tests_main.o $(GTEST_FLAGS) $(GCOVR_FLAGS)
	$(TEST_OBJ) 

unit_tests_main.o: $(TEST_DIR)/unit_tests_main.cpp $(TEST_HEADERS)
	$(CC) $(CFLAGS) $(GCOVR_FLAGS) -c $< -o $@

gcov_report: clean unit_tests_main.o
	mkdir -p $(REPORT_DIR)
	$(CC) $(CFLAGS) $(GCOVR_FLAGS) -o $(TEST_COV_OBJ) unit_tests_main.o $(GTEST_FLAGS)
	$(TEST_COV_OBJ) 
	gcovr -r . --html --html-details -o $(REPORT_DIR)/coverage-report.html
	$(OPEN) $(REPORT_DIR)/coverage-report.html


.PHONY: all clean gcov_report valgrind leaks check_style format_style test
