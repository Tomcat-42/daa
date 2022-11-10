#include <libdaa/sorting/quicksort.hpp>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <random>
#include <unordered_map>

namespace libdaa::sorting {

int partition_first(int* arr, int l, int r) {
    int pivot_index = l;
    int pivot_value = arr[pivot_index];

    int count = 0;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < pivot_value) {
            count++;
        }
    }

    int new_pivot_index = l + count;
    std::swap(arr[new_pivot_index], arr[pivot_index]);

    int i = l, j = r;

    while (i < new_pivot_index && j > new_pivot_index) {
        while (arr[i] <= pivot_value) {
            i++;
        }

        while (arr[j] > pivot_value) {
            j--;
        }
        if (i < new_pivot_index && j > new_pivot_index) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return new_pivot_index;
}

/**
 * @brief sort the array using quicksort.
 * @param *arr the array to be sorted.
 * @param n the size of the array.
 * @param p the pivot selection strategy.
 */
int partition_middle(int *arr, int l, int r) {
    int pivot_index = l + ((r - l) / 2);
    std::cout << "pivot_index: " << pivot_index << std::endl;
    int pivot_value = arr[pivot_index];

    int count = 0;
    for (int i = l; i <= r; i++) {
        if (arr[i] < pivot_value) {
            count++;
        }
    }

    int new_pivot_index = l + count;
    std::swap(arr[new_pivot_index], arr[pivot_index]);

    int i = l, j = r;
    while (i < new_pivot_index && j > new_pivot_index) {
        while (arr[i] <= pivot_value) {
            i++;
        }

        while (arr[j] > pivot_value) {
            j--;
        }

        if (i < new_pivot_index && j > new_pivot_index) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return new_pivot_index;
}

/*
 * @brief: Partition the array using the median of three pivot selection strategy.
 * @param arr: The array to be partitioned.
 * @param l: The left index of the array.
 * @param r: The right index of the array.
 */
int partition_median_of_three(int *arr, int l, int r) {
    int pivot_index = l + ((r - l) / 2);
    int pivot_value = arr[pivot_index];

    int count = 0;
    for (int i = l; i <= r; i++) {
        if (arr[i] < pivot_value) {
            count++;
        }
    }

    int new_pivot_index = l + count;
    std::swap(arr[new_pivot_index], arr[pivot_index]);

    int i = l, j = r;
    while (i < new_pivot_index && j > new_pivot_index) {
        while (arr[i] <= pivot_value) {
            i++;
        }

        while (arr[j] > pivot_value) {
            j--;
        }

        if (i < new_pivot_index && j > new_pivot_index) {
            std::swap(arr[i++], arr[j--]);
        }
    }

    return new_pivot_index;
}

/*
 * @brief Map pivot selection strategy to partition function.
 */
std::unordered_map<pivot, int (*)(int*, int, int)> partition_map = {
    {pivot::FIRST, partition_first},
    {pivot::MIDDLE, partition_middle},
    {pivot::MEDIAN_OF_THREE, partition_median_of_three},
};

/**
 * @brief sort the array using quicksort.
 * @param *arr the array to be sorted.
 * @param n the size of the array.
 * @param p the pivot selection strategy.
 */
void quicksort(int *arr, int l, int r, pivot p = pivot::FIRST) {
    if (l >=r) {
        return;
    }

    int pivot_index = partition_map[p](arr, l, r);
    quicksort(arr, l, pivot_index - 1, p);
    quicksort(arr, pivot_index + 1, r, p);
}

} // namespace libdaa::sorting
