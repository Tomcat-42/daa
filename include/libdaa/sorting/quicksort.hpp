#pragma once

namespace libdaa::sorting {

/**
 * @brief Pivot selection strategy for quicksort.
 */
enum class pivot { FIRST, MIDDLE, MEDIAN_OF_THREE };

/**
 * @brief sort the array using quicksort.
 * @param *arr the array to be sorted.
 * @param n the size of the array.
 * @param p the pivot selection strategy.
 */
void quicksort(int* arr, int l, int r, pivot p);

} // namespace libdaa::sorting
