#pragma once

#include <memory>
#include <vector>
#include <functional>
#include <libdaa/sorting/quicksort.hpp>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>
#include <chrono>


namespace libdaa::sorting {

/**
 * @brief Pivot selection strategy for quicksort.
 */
enum class pivot { FIRST, MIDDLE, MEDIAN_OF_THREE };

template <typename C, typename T>
static int partition_first(C &v, const int l, const int r) {
    int pivot_index = l;
    T pivot_value = v[pivot_index];

    int count = 0;
    for (int i = l + 1; i <= r; i++) {
        if (v[i] < pivot_value) {
            count++;
        }
    }

    int new_pivot_index = l + count;
    std::swap(v[new_pivot_index], v[pivot_index]);

    int i = l, j = r;

    while (i < new_pivot_index && j > new_pivot_index) {
        while (v[i] <= pivot_value) {
            i++;
        }

        while (v[j] > pivot_value) {
            j--;
        }
        if (i < new_pivot_index && j > new_pivot_index) {
            std::swap(v[i++], v[j--]);
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
template <typename C,typename T>
static int partition_middle(C &v, const int l, const int r) {
    int pivot_index = l + ((r - l) / 2);
    T pivot_value = v[pivot_index];

    int count = 0;
    for (int i = l; i <= r; i++) {
        if (v[i] < pivot_value) {
            count++;
        }
    }

    int new_pivot_index = l + count;
    std::swap(v[new_pivot_index], v[pivot_index]);

    int i = l, j = r;
    while (i < new_pivot_index && j > new_pivot_index) {
        while (v[i] <= pivot_value) {
            i++;
        }

        while (v[j] > pivot_value) {
            j--;
        }

        if (i < new_pivot_index && j > new_pivot_index) {
            std::swap(v[i++], v[j--]);
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
template <typename C,typename T>
static int partition_median_of_three(C &v, const int l, const int r) {
    int pivot_index = l + ((r - l) / 2);
    T pivot_value = v[pivot_index];

    int count = 0;
    for (int i = l; i <= r; i++) {
        if (v[i] < pivot_value) {
            count++;
        }
    }

    int new_pivot_index = l + count;
    std::swap(v[new_pivot_index], v[pivot_index]);

    int i = l, j = r;
    while (i < new_pivot_index && j > new_pivot_index) {
        while (v[i] <= pivot_value) {
            i++;
        }

        while (v[j] > pivot_value) {
            j--;
        }

        if (i < new_pivot_index && j > new_pivot_index) {
            std::swap(v[i++], v[j--]);
        }
    }

    return new_pivot_index;
}

/*
 * @brief Map pivot selection strategy to partition function.
 */
template<typename C, typename T>
static std::unordered_map<pivot, std::function<int(C&, const int,const int)>> partition_map = {
    {pivot::FIRST, partition_first<C, T>},
    {pivot::MIDDLE, partition_middle<C, T>},
    {pivot::MEDIAN_OF_THREE, partition_median_of_three<C, T>},
};

/**
 * @brief sort the array using quicksort.
 * @param C the container to be sorted.
 * @param l the left index of the container.
 * @param r the right index of the container.
 * @param p the pivot selection strategy.
 */
template <typename C, typename T>
static void quicksort_range(C &v, const int l, const int r, const pivot p) {
    if (l >=r) {
        return;
    }
    int pivot_index = partition_map<C, T>[p](v, l, r);
    quicksort_range<C,T>(v, l, pivot_index - 1, p);
    quicksort_range<C,T>(v, pivot_index + 1, r, p);
}

template <typename C, typename T>
std::chrono::duration<double> quicksort(C &v, const pivot p) {
    auto start = std::chrono::high_resolution_clock::now();
    quicksort_range<C,T>(v, 0, v.size() - 1, p);
    auto end = std::chrono::high_resolution_clock::now();
    return end - start;
}


} // namespace libdaa::sorting
