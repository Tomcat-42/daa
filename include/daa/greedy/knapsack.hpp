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
/// @param weights The weights of the items.
/// @param values The values of the items.
/// @param n The number of items.
/// @return A Tuple containing the items to be selected, the maximum value and
/// the time taken to solve the problem.
std::tuple<std::vector<std::intmax_t>, std::intmax_t,
    std::chrono::duration<double>>
    knapsack(std::intmax_t weight, const std::vector<std::intmax_t>& weights,
             const std::vector<std::intmax_t>& values, std::size_t n);
}  // namespace daa::dynamic_programming
