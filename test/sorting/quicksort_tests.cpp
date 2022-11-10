#include <gtest/gtest.h>
#include <libdaa/sorting/quicksort.hpp>


/*
 *  ============================= Ordened array tests. =========================================
 */
TEST(quicksort, first_pivot_ordened_array) {
    // arrange
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // act
    libdaa::sorting::quicksort(arr, 0, n - 1, libdaa::sorting::pivot::FIRST);
    std::sort(expected, expected + n);

    // assert
    EXPECT_EQ(0, memcmp(arr, expected, n * sizeof(int)));

}

TEST(quicksort, middle_pivot_ordened_array) {
    // arrange
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // act
    libdaa::sorting::quicksort(arr, 0, n - 1, libdaa::sorting::pivot::MIDDLE);
    std::sort(expected, expected + n);

    // assert
    EXPECT_EQ(0, memcmp(arr, expected, n * sizeof(int)));

}

TEST(quicksort, median_of_three_pivot_ordened_array) {
    // arrange
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // act
    libdaa::sorting::quicksort(arr, 0, n - 1, libdaa::sorting::pivot::MEDIAN_OF_THREE);
    std::sort(expected, expected + n);

    // assert
    EXPECT_EQ(0, memcmp(arr, expected, n * sizeof(int)));
}

/*
 *  ============================= Reverse ordened array tests. =========================================
 */
TEST(quicksort, first_pivot_reverse_ordened_array) {
    // arrange
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // act
    libdaa::sorting::quicksort(arr, 0, n - 1, libdaa::sorting::pivot::FIRST);
    std::sort(expected, expected + n);

    // assert
    EXPECT_EQ(0, memcmp(arr, expected, n * sizeof(int)));
}

TEST(quicksort, middle_pivot_reverse_ordened_array) {
    // arrange
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // act
    libdaa::sorting::quicksort(arr, 0, n - 1, libdaa::sorting::pivot::MIDDLE);
    std::sort(expected, expected + n);

    // assert
    EXPECT_EQ(0, memcmp(arr, expected, n * sizeof(int)));
}

TEST(quicksort, median_of_three_pivot_reverse_ordened_array) {
    // arrange
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // act
    libdaa::sorting::quicksort(arr, 0, n - 1, libdaa::sorting::pivot::MEDIAN_OF_THREE);
    std::sort(expected, expected + n);

    // assert
    EXPECT_EQ(0, memcmp(arr, expected, n * sizeof(int)));
}

/*
 *  ============================= Random array tests. =========================================
 */
TEST(quicksort, first_pivot_random_array) {
    // arrange
    int arr[] = {4, 7, 1, 9, 2, 5, 3, 8, 6, 10};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // act
    libdaa::sorting::quicksort(arr, 0, n - 1, libdaa::sorting::pivot::FIRST);
    std::sort(expected, expected + n);

    // assert
    EXPECT_EQ(0, memcmp(arr, expected, n * sizeof(int)));
}

TEST(quicksort, middle_pivot_random_array) {
    // arrange
    int arr[] = {4, 7, 1, 9, 2, 5, 3, 8, 6, 10};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // act
    libdaa::sorting::quicksort(arr, 0, n - 1, libdaa::sorting::pivot::MIDDLE);
    std::sort(expected, expected + n);

    // assert
    EXPECT_EQ(0, memcmp(arr, expected, n * sizeof(int)));
}

TEST(quicksort, median_of_three_pivot_random_array) {
    // arrange
    int arr[] = {4, 7, 1, 9, 2, 5, 3, 8, 6, 10};
    int expected[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // act
    libdaa::sorting::quicksort(arr, 0, n - 1, libdaa::sorting::pivot::MEDIAN_OF_THREE);
    std::sort(expected, expected + n);

    // assert
    EXPECT_EQ(0, memcmp(arr, expected, n * sizeof(int)));
}
