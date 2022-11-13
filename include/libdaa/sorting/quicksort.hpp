#pragma once

#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <libdaa/sorting/quicksort.hpp>
#include <memory>
#include <numeric>
#include <random>
#include <unordered_map>
#include <vector>

namespace libdaa::sorting {

/**
 * @brief QuickSort implementation
 *
 * @tparam C Container Container type
 * @tparam T Type of elements in container
 */
template <typename C, typename T>
class quicksort {
 public:
  /**
   * @brief Pivot selection method enumeration
   */
  enum class pivot { FIRST, MIDDLE, LAST, MEDIAN_OF_THREE };

  /**
   * @brief Construct a new quicksort object
   *
   * @param p Pivot selection method
   */
  quicksort(const pivot p = pivot::FIRST);
  ~quicksort() = default;

  /**
   * @brief set_pivot Set the pivot selection method
   *
   * @param p Pivot selection method
   */
  void set_pivot(const pivot p);

  /**
   * @brief get_pivot Get the pivot selection method
   * @return pivot Pivot selection method
   */
  pivot get_pivot() const;

  /**
   * @brief sort Sort the container
   *
   * @param c Container to sort
   */
  std::chrono::duration<double> sort(C &arr);

 private:
  /**
   * @brief Pivot to partition function map
   */
  static std::unordered_map<
    pivot, std::function<std::intmax_t(C &, const std::intmax_t, const std::intmax_t)>>
    pivot_map;

  /**
   * @brief random number generator
   */
  static std::mt19937 gen;

  /**
   * @brief Partition around the first element
   * @param arr Container to partition
   * @param left Leftmost index of subarray
   * @param right Rightmost index of subarray
   * @return int Index of pivot
   */
  static std::intmax_t partition_first(C &arr, const std::intmax_t l,
                                       const std::intmax_t r);

  /**
   * @brief Partition around the middle element
   * @param arr Container to partition
   * @param left Leftmost index of subarray
   * @param right Rightmost index of subarray
   * @return int Index of pivot
   */
  static std::intmax_t partition_middle(C &arr, const std::intmax_t l,
                                        const std::intmax_t r);

  /**
   * @brief Partition around the last element
   * @param arr Container to partition
   * @param left Leftmost index of subarray
   * @param right Rightmost index of subarray
   * @return int Index of pivot
   */
  static std::intmax_t partition_last(C &arr, const std::intmax_t l,
                                      const std::intmax_t r);

  /**
   * @brief Partition around the median of three elements
   * @param arr Container to partition
   * @param left Leftmost index of subarray
   * @param right Rightmost index of subarray
   * @return int Index of pivot
   */
  static std::intmax_t partition_median_of_three(C &arr, const std::intmax_t l,
                                                 const std::intmax_t r);

  /**
   * @brief Sort a subarray
   * @param arr Container to sort
   * @param left Leftmost index of subarray
   * @param right Rightmost index of subarray
   */
  void sort_range(C &arr, const std::intmax_t l, const std::intmax_t r);

  /**
   * @brief Pivot selection method
   */
  pivot pivot_;

  /**
   * @brief Partition function pointer
   */
  std::function<int(C &, const std::intmax_t, const std::intmax_t)> partition;
};

template <typename C, typename T>
quicksort<C, T>::quicksort(const pivot p)
  : pivot_(p), partition(pivot_map[p]) {}

template <typename C, typename T>
std::unordered_map<
  typename quicksort<C, T>::pivot,
  std::function<std::intmax_t(C &, const std::intmax_t, const std::intmax_t)>>
  quicksort<C, T>::pivot_map = {
    {pivot::FIRST, quicksort<C, T>::partition_first},
    {pivot::MIDDLE, quicksort<C, T>::partition_middle},
    {pivot::LAST, quicksort<C, T>::partition_last},
    {pivot::MEDIAN_OF_THREE, quicksort<C, T>::partition_median_of_three}};

template <typename C, typename T>
std::mt19937 quicksort<C, T>::gen = std::mt19937(std::random_device()());

template <typename C, typename T>
std::intmax_t quicksort<C, T>::partition_first(C &v, const std::intmax_t l,
                                               const std::intmax_t r) {
  std::intmax_t pivot_index = l;  // First element
  T pivot_value = v[pivot_index];

  std::intmax_t c = 0;
  for (std::intmax_t i = l + 1; i <= r; i++)
    if (v[i] < pivot_value) c++;

  std::intmax_t new_pivot_index = l + c;
  std::swap(v[pivot_index], v[new_pivot_index]);

  std::intmax_t i = l, j = r;
  while (i < new_pivot_index && j > new_pivot_index) {
    while (v[i] <= pivot_value) i++;
    while (v[j] > pivot_value) j--;
    if (i < j) std::swap(v[i], v[j]);
  }

  return new_pivot_index;
}

template <typename C, typename T>
std::intmax_t quicksort<C, T>::partition_middle(C &v, const std::intmax_t l,
                                                const std::intmax_t r) {
  std::intmax_t pivot_index = l + ((r - l) / 2);  // Middle element
  T pivot_value = v[pivot_index];

  std::intmax_t c = 0;
  for (std::intmax_t i = l; i <= r; i++)
    if (v[i] < pivot_value) c++;

  std::intmax_t new_pivot_index = l + c;
  std::swap(v[pivot_index], v[new_pivot_index]);

  std::intmax_t i = l, j = r;
  while (i < new_pivot_index && j > new_pivot_index) {
    while (v[i] <= pivot_value) i++;
    while (v[j] > pivot_value) j--;
    if (i < j) std::swap(v[i], v[j]);
  }

  return new_pivot_index;
}

template <typename C, typename T>
std::intmax_t quicksort<C, T>::partition_last(C &v, const std::intmax_t l,
                                              const std::intmax_t r) {
  std::intmax_t pivot_index = r;  // Last element
  T pivot_value = v[pivot_index];

  std::intmax_t c = 0;
  for (std::intmax_t i = l; i < r; i++)
    if (v[i] < pivot_value) c++;

  std::intmax_t new_pivot_index = l + c;
  std::swap(v[pivot_index], v[new_pivot_index]);

  std::intmax_t i = l, j = r;
  while (i < new_pivot_index && j > new_pivot_index) {
    while (v[i] <= pivot_value) i++;
    while (v[j] > pivot_value) j--;
    if (i < j) std::swap(v[i], v[j]);
  }

  return new_pivot_index;
}

template <typename C, typename T>
std::intmax_t quicksort<C, T>::partition_median_of_three(
  C &v, const std::intmax_t l, const std::intmax_t r) {
  std::uniform_int_distribution<> dis(l, r);
  std::intmax_t v1 = dis(gen), v2 = dis(gen), v3 = dis(gen);
  std::intmax_t pivot_index =
    std::max(std::min(v1, v2), std::min(std::max(v1, v2), v3));
  T pivot_value = v[pivot_index];

  std::intmax_t c = 0;
  for (std::intmax_t i = l; i <= r; i++)
    if (v[i] < pivot_value) c++;

  std::intmax_t new_pivot_index = l + c;
  std::swap(v[pivot_index], v[new_pivot_index]);

  std::intmax_t i = l, j = r;
  while (i < new_pivot_index && j > new_pivot_index) {
    while (v[i] <= pivot_value) i++;
    while (v[j] > pivot_value) j--;
    if (i < j) std::swap(v[i], v[j]);
  }

  return new_pivot_index;
}

template <typename C, typename T>
void quicksort<C, T>::sort_range(C &v, const std::intmax_t l,
                                 const std::intmax_t r) {
  if (l >= r) {
    return;
  }
  std::intmax_t pivot_index = partition(v, l, r);
  sort_range(v, l, pivot_index - 1);
  sort_range(v, pivot_index + 1, r);
}

template <typename C, typename T>
std::chrono::duration<double> quicksort<C, T>::sort(C &v) {
  std::intmax_t l = 0, r = v.size() - 1;  // left and right index of the array

  auto start = std::chrono::high_resolution_clock::now();
  sort_range(v, l, r);
  auto end = std::chrono::high_resolution_clock::now();

  return end - start;
}

}  // namespace libdaa::sorting
