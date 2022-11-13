#include <gtest/gtest.h>
#include <libdaa/sorting/quicksort.hpp>

/*
 *  pivot::FIRST tests.
 */
TEST(quicksort_ordered, vector_int_pivot_first) {
  // arrange
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> expected{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // act
  libdaa::sorting::quicksort<std::vector<int>, int>(
    v, libdaa::sorting::pivot::FIRST);

  // assert
  EXPECT_EQ(v, expected);
}

TEST(quicksort_ordered, vector_double_pivot_first) {
  // arrange
  std::vector<double> v{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
  std::vector<double> expected{1.0, 2.0, 3.0, 4.0, 5.0,
                               6.0, 7.0, 8.0, 9.0, 10.0};

  // act
  libdaa::sorting::quicksort<std::vector<double>, double>(
    v, libdaa::sorting::pivot::FIRST);

  // assert
  EXPECT_EQ(v, expected);
}

TEST(quicksort_ordered, vector_string_pivot_first) {
  // arrange
  std::vector<std::string> v{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  std::vector<std::string> expected{"0", "1", "2", "3", "4",
                                    "5", "6", "7", "8", "9"};

  // act
  libdaa::sorting::quicksort<std::vector<std::string>, std::string>(
    v, libdaa::sorting::pivot::FIRST);

  // assert
  EXPECT_EQ(v, expected);
}

TEST(quicksort_ordered, string_pivot_first) {
  // arrange
  std::string v{"0123456789"};
  std::string expected{"0123456789"};

  // act
  libdaa::sorting::quicksort<std::string, char>(v,
                                                libdaa::sorting::pivot::FIRST);

  // assert
  EXPECT_EQ(v, expected);
}

/*
 *  pivot::MIDDLE tests.
 */
TEST(quicksort_ordered, vector_int_pivot_middle) {
  // arrange
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> expected{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // act
  libdaa::sorting::quicksort<std::vector<int>, int>(
    v, libdaa::sorting::pivot::MIDDLE);

  // assert
  EXPECT_EQ(v, expected);
}

TEST(quicksort_ordered, vector_double_pivot_middle) {
  // arrange
  std::vector<double> v{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
  std::vector<double> expected{1.0, 2.0, 3.0, 4.0, 5.0,
                               6.0, 7.0, 8.0, 9.0, 10.0};

  // act
  libdaa::sorting::quicksort<std::vector<double>, double>(
    v, libdaa::sorting::pivot::MIDDLE);

  // assert
  EXPECT_EQ(v, expected);
}

TEST(quicksort_ordered, vector_string_pivot_middle) {
  // arrange
  std::vector<std::string> v{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  std::vector<std::string> expected{"0", "1", "2", "3", "4",
                                    "5", "6", "7", "8", "9"};

  // act
  libdaa::sorting::quicksort<std::vector<std::string>, std::string>(
    v, libdaa::sorting::pivot::MIDDLE);

  // assert
  EXPECT_EQ(v, expected);
}

TEST(quicksort_ordered, string_pivot_middle) {
  // arrange
  std::string v{"0123456789"};
  std::string expected{"0123456789"};

  // act
  libdaa::sorting::quicksort<std::string, char>(v,
                                                libdaa::sorting::pivot::MIDDLE);

  // assert
  EXPECT_EQ(v, expected);
}

/*
 *  pivot::MEDIAN_OF_THREE tests.
 */
TEST(quicksort_ordered, vector_int_pivot_median_of_three) {
  // arrange
  std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::vector<int> expected{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // act
  libdaa::sorting::quicksort<std::vector<int>, int>(
    v, libdaa::sorting::pivot::MEDIAN_OF_THREE);

  // assert
  EXPECT_EQ(v, expected);
}

TEST(quicksort_ordered, vector_double_pivot_median_of_three) {
  // arrange
  std::vector<double> v{1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
  std::vector<double> expected{1.0, 2.0, 3.0, 4.0, 5.0,
                               6.0, 7.0, 8.0, 9.0, 10.0};

  // act
  libdaa::sorting::quicksort<std::vector<double>, double>(
    v, libdaa::sorting::pivot::MEDIAN_OF_THREE);

  // assert
  EXPECT_EQ(v, expected);
}

TEST(quicksort_ordered, vector_string_pivot_median_of_three) {
  // arrange
  std::vector<std::string> v{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
  std::vector<std::string> expected{"0", "1", "2", "3", "4",
                                    "5", "6", "7", "8", "9"};

  // act
  libdaa::sorting::quicksort<std::vector<std::string>, std::string>(
    v, libdaa::sorting::pivot::MEDIAN_OF_THREE);

  // assert
  EXPECT_EQ(v, expected);
}

TEST(quicksort_ordered, string_pivot_median_of_three) {
  // arrange
  std::string v{"0123456789"};
  std::string expected{"0123456789"};

  // act
  libdaa::sorting::quicksort<std::string, char>(
    v, libdaa::sorting::pivot::MEDIAN_OF_THREE);

  // assert
  EXPECT_EQ(v, expected);
}
