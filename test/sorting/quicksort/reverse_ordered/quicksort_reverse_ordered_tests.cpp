#include <gtest/gtest.h>

#include <libdaa/sorting/quicksort.hpp>

using quicksort_vec_int = libdaa::sorting::quicksort<std::vector<int>, int>;
using quicksort_vec_double =
  libdaa::sorting::quicksort<std::vector<double>, double>;
using quicksort_vec_string =
  libdaa::sorting::quicksort<std::vector<std::string>, std::string>;
using quicksort_string = libdaa::sorting::quicksort<std::string, char>;

/**
 * @brief Test fixture for quicksort reverse ordered vector int
 */
class quicksort_reverse_ordered_vector_int : public ::testing::Test {
 protected:
  void SetUp() override {
    // Set up test data
    vec_int = std::vector<int>(n);
    vec_int_expected = std::vector<int>(n);

    std::iota(std::begin(vec_int), std::end(vec_int), 0);
    std::reverse(std::begin(vec_int), std::end(vec_int));
    std::iota(std::begin(vec_int_expected), std::end(vec_int_expected), 0);

    qs_vec_int_first = quicksort_vec_int(libdaa::sorting::pivot::FIRST);
    qs_vec_int_last = quicksort_vec_int(libdaa::sorting::pivot::LAST);
    qs_vec_int_middle = quicksort_vec_int(libdaa::sorting::pivot::MIDDLE);
    qs_vec_int_median_of_three =
      quicksort_vec_int(libdaa::sorting::pivot::MEDIAN_OF_THREE);
  }

  void TearDown() override {}

  const int n = 10;

  std::vector<int> vec_int;
  std::vector<int> vec_int_expected;

  quicksort_vec_int qs_vec_int_first;
  quicksort_vec_int qs_vec_int_last;
  quicksort_vec_int qs_vec_int_middle;
  quicksort_vec_int qs_vec_int_median_of_three;
};

/**
 * @brief Test fixture for quicksort reverse ordered vector double
 */
class quicksort_reverse_ordered_vector_double : public ::testing::Test {
 protected:
  void SetUp() override {
    // Set up test data
    vec_double = std::vector<double>(n);
    vec_double_expected = std::vector<double>(n);

    std::iota(std::begin(vec_double), std::end(vec_double), 0.0);
    std::reverse(std::begin(vec_double), std::end(vec_double));
    std::iota(std::begin(vec_double_expected), std::end(vec_double_expected),
              0.0);

    qs_vec_double_first =
      quicksort_vec_double(libdaa::sorting::pivot::FIRST);
    qs_vec_double_last =
      quicksort_vec_double(libdaa::sorting::pivot::LAST);
    qs_vec_double_middle =
      quicksort_vec_double(libdaa::sorting::pivot::MIDDLE);
    qs_vec_double_median_of_three =
      quicksort_vec_double(libdaa::sorting::pivot::MEDIAN_OF_THREE);
  }

  void TearDown() override {}

  const int n = 10;

  std::vector<double> vec_double;
  std::vector<double> vec_double_expected;

  quicksort_vec_double qs_vec_double_first;
  quicksort_vec_double qs_vec_double_last;
  quicksort_vec_double qs_vec_double_middle;
  quicksort_vec_double qs_vec_double_median_of_three;
};

/**
 * @brief Test fixture for quicksort reverse ordered vector string
 */
class quicksort_reverse_ordered_vector_string : public ::testing::Test {
 protected:
  void SetUp() override {
    // Set up test data
    vec_string = std::vector<std::string>(n);
    vec_string_expected = std::vector<std::string>(n);

    std::iota(std::begin(vec_string), std::end(vec_string), 0);
    std::reverse(std::begin(vec_string), std::end(vec_string));
    std::iota(std::begin(vec_string_expected), std::end(vec_string_expected),
              0);

    qs_vec_string_first =
      quicksort_vec_string(libdaa::sorting::pivot::FIRST);
    qs_vec_string_last =
      quicksort_vec_string(libdaa::sorting::pivot::LAST);
    qs_vec_string_middle =
      quicksort_vec_string(libdaa::sorting::pivot::MIDDLE);
    qs_vec_string_median_of_three =
      quicksort_vec_string(libdaa::sorting::pivot::MEDIAN_OF_THREE);
  }

  void TearDown() override {}

  const int n = 10;

  std::vector<std::string> vec_string;
  std::vector<std::string> vec_string_expected;

  quicksort_vec_string qs_vec_string_first;
  quicksort_vec_string qs_vec_string_last;
  quicksort_vec_string qs_vec_string_middle;
  quicksort_vec_string qs_vec_string_median_of_three;
};

/**
 * @brief Test fixture for quicksort reverse ordered string
 */
class quicksort_reverse_ordered_string : public ::testing::Test {
 protected:
  void SetUp() override {
    // Set up test data
    str = "0123456789";
    str_expected = "0123456789";

    std::reverse(std::begin(str), std::end(str));

    qs_str_first = quicksort_string(libdaa::sorting::pivot::FIRST);
    qs_str_last = quicksort_string(libdaa::sorting::pivot::LAST);
    qs_str_middle = quicksort_string(libdaa::sorting::pivot::MIDDLE);
    qs_str_median_of_three =
      quicksort_string(libdaa::sorting::pivot::MEDIAN_OF_THREE);
  }

  void TearDown() override {}

  const int n = 10;

  std::string str;
  std::string str_expected;

  quicksort_string qs_str_first;
  quicksort_string qs_str_last;
  quicksort_string qs_str_middle;
  quicksort_string qs_str_median_of_three;
};

/*
 *  pivot::FIRST tests.
 */
TEST_F(quicksort_reverse_ordered_vector_int, pivot_first) {
  qs_vec_int_first.sort(vec_int);
  EXPECT_EQ(vec_int, vec_int_expected);
}

TEST_F(quicksort_reverse_ordered_vector_double, pivot_first) {
  qs_vec_double_first.sort(vec_double);
  EXPECT_EQ(vec_double, vec_double_expected);
}

TEST_F(quicksort_reverse_ordered_vector_string, pivot_first) {
  qs_vec_string_first.sort(vec_string);
  EXPECT_EQ(vec_string, vec_string_expected);
}

TEST_F(quicksort_reverse_ordered_string, pivot_first) {
  qs_str_first.sort(str);
  EXPECT_EQ(str, str_expected);
}

/*
 *  pivot::LAST tests.
 */
TEST_F(quicksort_reverse_ordered_vector_int, pivot_last) {
  qs_vec_int_last.sort(vec_int);
  EXPECT_EQ(vec_int, vec_int_expected);
}

TEST_F(quicksort_reverse_ordered_vector_double, pivot_last) {
  qs_vec_double_last.sort(vec_double);
  EXPECT_EQ(vec_double, vec_double_expected);
}

TEST_F(quicksort_reverse_ordered_vector_string, pivot_last) {
  qs_vec_string_last.sort(vec_string);
  EXPECT_EQ(vec_string, vec_string_expected);
}

TEST_F(quicksort_reverse_ordered_string, pivot_last) {
  qs_str_last.sort(str);
  EXPECT_EQ(str, str_expected);
}

/*
 *  pivot::MIDDLE tests.
 */
TEST_F(quicksort_reverse_ordered_vector_int, pivot_middle) {
  qs_vec_int_middle.sort(vec_int);
  EXPECT_EQ(vec_int, vec_int_expected);
}

TEST_F(quicksort_reverse_ordered_vector_double, pivot_middle) {
  qs_vec_double_middle.sort(vec_double);
  EXPECT_EQ(vec_double, vec_double_expected);
}

TEST_F(quicksort_reverse_ordered_vector_string, pivot_middle) {
  qs_vec_string_middle.sort(vec_string);
  EXPECT_EQ(vec_string, vec_string_expected);
}

TEST_F(quicksort_reverse_ordered_string, pivot_middle) {
  qs_str_middle.sort(str);
  EXPECT_EQ(str, str_expected);
}

/*
 *  pivot::MEDIAN_OF_THREE tests.
 */
TEST_F(quicksort_reverse_ordered_vector_int, pivot_median_of_three) {
  qs_vec_int_median_of_three.sort(vec_int);
  EXPECT_EQ(vec_int, vec_int_expected);
}

TEST_F(quicksort_reverse_ordered_vector_double, pivot_median_of_three) {
  qs_vec_double_median_of_three.sort(vec_double);
  EXPECT_EQ(vec_double, vec_double_expected);
}

TEST_F(quicksort_reverse_ordered_vector_string, pivot_median_of_three) {
  qs_vec_string_median_of_three.sort(vec_string);
  EXPECT_EQ(vec_string, vec_string_expected);
}

TEST_F(quicksort_reverse_ordered_string, pivot_median_of_three) {
  qs_str_median_of_three.sort(str);
  EXPECT_EQ(str, str_expected);
}
