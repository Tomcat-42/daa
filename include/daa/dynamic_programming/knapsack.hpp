#pragma once

#include <chrono>
#include <cstdint>
#include <iostream>
#include <tuple>
#include <vector>

namespace daa::dynamic_programming {

/// Solves the knapsack problem using dynamic programming
/// @param weight The maximum weight the knapsack can hold.
/// @param benefits The benefits of the items.
/// @param weights The weights of the items.
/// @return A Tuple containing the execution time, the maximum value and the items to be selected.
std::tuple<std::chrono::duration<double>, std::intmax_t, std::vector<std::intmax_t>>
        knapsack(std::intmax_t weight, const std::vector<std::intmax_t>& benefits,
                 const std::vector<std::intmax_t>& weights);

}  // namespace daa::dynamic_programming
