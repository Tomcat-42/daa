#pragma once


#include <algorithm>
#include <chrono>
#include <cstdint>
#include <daa/dynamic_programming/knapsack.hpp>
#include <iostream>
#include <tuple>
#include <vector>

// Path: knapsack.hpp
namespace daa::greedy {

/// Solves the knapsack problem using a greedy algorithm (with pre-sorting)
/// @param weight The maximum weight the knapsack can hold.
/// @param benefits The benefits of the items.
/// @param weights The weights of the items.
/// @return A Tuple containing the execution time, the maximum value and the items to be selected.
std::tuple<std::chrono::duration<double>, std::intmax_t, std::vector<std::intmax_t>>
        knapsack(std::intmax_t weight, const std::vector<std::intmax_t>& benefits,
                 const std::vector<std::intmax_t>& weights);
}  // namespace daa::dynamic_programming
