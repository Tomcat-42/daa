#include <gtest/gtest.h>

#include <chrono>
#include <daa/sorting/quicksort.hpp>
#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
