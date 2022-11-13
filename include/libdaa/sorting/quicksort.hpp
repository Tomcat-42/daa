#pragma once

#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <libdaa/sorting/quicksort.hpp>
#include <memory>
#include <random>
#include <unordered_map>
#include <vector>

namespace libdaa::sorting {

// Global random number generator
static std::random_device rd;
static std::mt19937 gen(rd());

/**
 * @brief Pivot selection strategy for quicksort.
 */
enum class pivot { FIRST, MIDDLE, LAST, MEDIAN_OF_THREE };

/**
 * @brief partition using the first element as pivot.
 * @param C container to be sorted.
 * @param T type of the container elements.
 * @param l lower bound of the range to be sorted.
 * @param r upper bound of the range to be sorted.
 */
template <typename C, typename T>
static int partition_first(C &v, const int l, const int r) {
  int pivot_index = l;  // First element
  T pivot_value = v[pivot_index];

  int c = 0;
  for (int i = l + 1; i <= r; i++)
    if (v[i] < pivot_value) c++;

  int new_pivot_index = l + c;
  std::swap(v[pivot_index], v[new_pivot_index]);

  int i = l, j = r;
  while (i < new_pivot_index && j > new_pivot_index) {
    while (v[i] <= pivot_value) i++;
    while (v[j] > pivot_value) j--;
    if (i < j) std::swap(v[i], v[j]);
  }

  return new_pivot_index;
}

/**
 * @brief partition using the middle element as pivot.
 * @param C container to be sorted.
 * @param T type of the container elements.
 * @param l lower bound of the range to be sorted.
 * @param r upper bound of the range to be sorted.
 */
template <typename C, typename T>
static int partition_middle(C &v, const int l, const int r) {
  int pivot_index = l + ((r - l) / 2);  // Middle element
  T pivot_value = v[pivot_index];

  int c = 0;
  for (int i = l; i <= r; i++)
    if (v[i] < pivot_value) c++;

  int new_pivot_index = l + c;
  std::swap(v[pivot_index], v[new_pivot_index]);

  int i = l, j = r;
  while (i < new_pivot_index && j > new_pivot_index) {
    while (v[i] <= pivot_value) i++;
    while (v[j] > pivot_value) j--;
    if (i < j) std::swap(v[i], v[j]);
  }

  return new_pivot_index;
}

/**
 * @brief partition using the last element as pivot.
 * @param C container to be sorted.
 * @param T type of the container elements.
 * @param l lower bound of the range to be sorted.
 * @param r upper bound of the range to be sorted.
 */
template <typename C, typename T>
static int partition_last(C &v, const int l, const int r) {
  int pivot_index = r;  // Last element
  T pivot_value = v[pivot_index];

  int c = 0;
  for (int i = l; i < r; i++)
    if (v[i] < pivot_value) c++;

  int new_pivot_index = l + c;
  std::swap(v[pivot_index], v[new_pivot_index]);

  int i = l, j = r;
  while (i < new_pivot_index && j > new_pivot_index) {
    while (v[i] <= pivot_value) i++;
    while (v[j] > pivot_value) j--;
    if (i < j) std::swap(v[i], v[j]);
  }

  return new_pivot_index;
}

/*
 * @brief: Partition the array using the median of three random elements pivot
 * selection strategy.
 * @param arr: The array to be partitioned.
 * @param l: The left index of the array.
 * @param r: The right index of the array.
 */
template <typename C, typename T>
static int partition_median_of_three(C &v, const int l, const int r) {
  std::uniform_int_distribution<> dis(l, r);
  int v1 = dis(gen), v2 = dis(gen), v3 = dis(gen);
  int pivot_index = std::max(std::min(v1, v2), std::min(std::max(v1, v2), v3));
  T pivot_value = v[pivot_index];

  int c = 0;
  for (int i = l; i <= r; i++)
    if (v[i] < pivot_value) c++;

  int new_pivot_index = l + c;
  std::swap(v[pivot_index], v[new_pivot_index]);

  int i = l, j = r;
  while (i < new_pivot_index && j > new_pivot_index) {
    while (v[i] <= pivot_value) i++;
    while (v[j] > pivot_value) j--;
    if (i < j) std::swap(v[i], v[j]);
  }

  return new_pivot_index;
}

/*
 * @brief Map pivot selection strategy to partition function.
 */
template <typename C, typename T>
static std::unordered_map<pivot, std::function<int(C &, const int, const int)>>
  partition_map = {{pivot::FIRST, partition_first<C, T>},
                   {pivot::MIDDLE, partition_middle<C, T>},
                   {pivot::MEDIAN_OF_THREE, partition_median_of_three<C, T>},
                   {pivot::LAST, partition_last<C, T>}};

/**
 * @brief sort the array using quicksort.
 * @param C the container to be sorted.
 * @param T the type of the container elements.
 * @param l the left index of the container.
 * @param r the right index of the container.
 * @param p the pivot selection strategy.
 */
template <typename C, typename T>
static void quicksort_range(C &v, const int l, const int r, const pivot p) {
  if (l >= r) {
    return;
  }
  int pivot_index = partition_map<C, T>[p](v, l, r);
  quicksort_range<C, T>(v, l, pivot_index - 1, p);
  quicksort_range<C, T>(v, pivot_index + 1, r, p);
}

/**
 * @brief sort the array using quicksort and compute the execution time.
 * @param C the container to be sorted.
 * @param T the type of the container elements.
 * @param p the pivot selection strategy.
 */
template <typename C, typename T>
std::chrono::duration<double> quicksort(C &v, const pivot p) {
  auto start = std::chrono::high_resolution_clock::now();
  quicksort_range<C, T>(v, 0, v.size() - 1, p);
  auto end = std::chrono::high_resolution_clock::now();
  return end - start;
}

}  // namespace libdaa::sorting
