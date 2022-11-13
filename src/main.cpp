#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <libdaa/sorting/quicksort.hpp>
#include <numeric>

int divideSortPivot(int arr[], int left, int right) {
  int pivotUnsorted = ((right - left) / 2) + left;
  int pivot =
    arr[pivotUnsorted];  // pivot from middle of array; right - left gives us
  // the range, divide than range in half, then add that
  // to the start position(left)
  int i = -1;
  for (int j = left; j <= right;
       ++j) {  // loop finds true index of pivot to use for comparison in next
    // loop(left/right comparison swaps) - affects time complexity as
    // entire data structure must be iterated through
    if (arr[j] <= pivot) {
      ++i;
    }
  }
  int pivotIndex = i + left;  // amount of elements less than/equal to pivot,
  // plus index of where we began searching
  i = left - 1;
  for (int j = left; j <= right; ++j) {
    if (arr[j] <= pivot) {
      ++i;
      if (j == pivotUnsorted) pivotUnsorted = i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[pivotIndex], arr[pivotUnsorted]);
  return (pivotIndex);
}

void quicksort(int arr[], int left, int right) {
  if (left >=
      right)  // base case: if leftmost index of "sub" array we are recursively
    // sorting is greater than rightmost, then return.
    return;

  int pivot = divideSortPivot(arr, left, right);

  quicksort(arr, left, pivot - 1);
  quicksort(arr, pivot + 1, right);
}

void quicksort(int arr[], int arrLength) { quicksort(arr, 0, arrLength - 1); }

void test_my_quicksort(const int n) {
  std::vector<int> arr(n);
  std::iota(std::begin(arr), std::end(arr), 0);
  // std::reverse(std::begin(arr), std::end(arr));

  auto start = std::chrono::high_resolution_clock::now();
  auto p = libdaa::sorting::quicksort<std::vector<int>, int>::pivot::FIRST;
  libdaa::sorting::quicksort<std::vector<int>, int>(p).sort(arr);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = end - start;
  std::cout << "libdaa::sorting::quicksort -> Elapsed time: " << elapsed.count()
            << std::endl;
}

void test_other_quicksort(const int n) {
  int arr[n];
  std::iota(arr, arr + n, 0);

  auto start = std::chrono::high_resolution_clock::now();
  quicksort(arr, n);
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = end - start;
  std::cout << "quicksort -> Elapsed time: " << elapsed.count() << std::endl;
}

void test_std_sort(const int n) {
  std::vector<int> arr(n);
  std::iota(std::begin(arr), std::end(arr), 0);
  // std::reverse(std::begin(arr), std::end(arr));

  auto start = std::chrono::high_resolution_clock::now();
  std::sort(arr.begin(), arr.end());
  auto end = std::chrono::high_resolution_clock::now();

  std::chrono::duration<double> elapsed = end - start;
  std::cout << "std::sort -> Elapsed time: " << elapsed.count() << std::endl;
}

int main() {
  const int n = 1000000;
  test_my_quicksort(n);
  test_other_quicksort(n);
  test_std_sort(n);
  return 0;
}
