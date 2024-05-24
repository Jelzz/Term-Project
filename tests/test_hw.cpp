// If you change anything in this file, your changes will be ignored in your
// homework submission.
//
// Check out the TEST_F functions below to learn what is being tested.
#include "../code/Vector10.h"
#include <gtest/gtest.h>

#include <cmath>
#include <fstream>
#include <iostream>

class test_Vector10 : public ::testing::Test {
protected:
  static void SetUpTestCase() {}

  // This function runs only once before any TEST_F function
  static void TearDownTestCase() {
    std::ofstream outgrade("./total_grade.txt");
    if (outgrade.is_open())
      outgrade.clear();

    outgrade << (int)std::ceil(100 * total_grade / max_grade);
    outgrade.close();

    std::cout << "Total Grade is : "
              << (int)std::ceil(100 * total_grade / max_grade) << std::endl;
  }

  // This function runs after all TEST_F functions have been executed
  void add_points_to_grade(int points) {
    max_grade += points;
    if (!::testing::Test::HasFailure()) {
      total_grade += points;
    }
  }

  // this function runs before every TEST_F function
  void SetUp() override {}

  // this function runs after ever TEST_F function
  void TearDown() override {}

  static int total_grade;
  static int max_grade;
};

int test_Vector10::total_grade = 0;
int test_Vector10::max_grade = 0;

TEST_F(test_Vector10, Initialization) {
  Vector10 testvec;

  for (int ii = 0; ii < 10; ii++) {
    EXPECT_EQ(0, testvec.value_at(ii));
    add_points_to_grade(1);
  }
}

TEST_F(test_Vector10, TestPushBackNoRemoval) {
  Vector10 testvec;

  testvec.push_back(12);
  testvec.push_back(45);
  testvec.push_back(93);
  testvec.push_back(1000);
  testvec.push_back(0);
  testvec.push_back(22);

  EXPECT_EQ(12, testvec.value_at(0));
  add_points_to_grade(1);
  EXPECT_EQ(22, testvec.value_at(5));
  add_points_to_grade(1);
  EXPECT_EQ(93, testvec.value_at(2));
  add_points_to_grade(1);
  EXPECT_EQ(45, testvec.value_at(1));
  add_points_to_grade(1);
  EXPECT_EQ(0, testvec.value_at(4));
  add_points_to_grade(1);
  EXPECT_EQ(1000, testvec.value_at(3));
  add_points_to_grade(1);
}

TEST_F(test_Vector10, TestPushBackOverflow) {
  Vector10 testvec;

  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(true, testvec.push_back(i + 12));
    add_points_to_grade(0.3);
  }
  for (int i = 0; i < 10; i++) {
    EXPECT_EQ(false, testvec.push_back(i * 3));
    add_points_to_grade(0.3);
  }
}

TEST_F(test_Vector10, TestCountEmpty) {
  Vector10 testvec;

  EXPECT_EQ(10, testvec.count_empty());
  add_points_to_grade(2);

  testvec.push_back(1);
  EXPECT_EQ(9, testvec.count_empty());
  add_points_to_grade(2);

  testvec.push_back(22);
  testvec.push_back(150);
  testvec.push_back(90);
  EXPECT_EQ(6, testvec.count_empty());
  add_points_to_grade(2);
}

TEST_F(test_Vector10, TestSearch) {
  Vector10 testvec;

  EXPECT_EQ(false, testvec.search(12));
  add_points_to_grade(5);

  testvec.push_back(11);
  testvec.push_back(12);
  testvec.push_back(13);
  EXPECT_EQ(true, testvec.search(12));
  add_points_to_grade(5);
}

TEST_F(test_Vector10, TestRemove) {
  Vector10 testvec;

  testvec.push_back(11);
  testvec.push_back(12);
  testvec.push_back(13);
  testvec.push_back(19);
  testvec.push_back(1000);
  testvec.push_back(3);

  EXPECT_EQ(false, testvec.remove(200));
  add_points_to_grade(2);

  EXPECT_EQ(true, testvec.remove(1));
  add_points_to_grade(2);

  EXPECT_EQ(1000, testvec.value_at(3));
  add_points_to_grade(2);
}
