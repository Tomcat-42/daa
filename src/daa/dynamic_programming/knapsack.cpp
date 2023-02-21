#include <algorithm>
#include <chrono>
#include <cstdint>
#include <daa/dynamic_programming/knapsack.hpp>
#include <iostream>
#include <tuple>
#include <vector>

// Path: knapsack.hpp
namespace daa::dynamic_programming {

std::tuple<std::vector<std::intmax_t>, std::intmax_t,
    std::chrono::duration<double>>
    knapsack(std::intmax_t weight, const std::vector<std::intmax_t>& weights,
const std::vector<std::intmax_t>& values, std::size_t n) {
    auto start = std::chrono::high_resolution_clock::now();

    std::intmax_t max_value = 0;
    std::vector<std::vector<std::intmax_t>> memo(
            n + 1, std::vector<std::intmax_t>(weight + 1));
    std::vector<std::intmax_t> selected_items;

    for (std::size_t i = 0; i <= n; ++i) {
        for (std::intmax_t j = 0; j <= weight; ++j) {
            if (i == 0 || j == 0) {
                memo[i][j] = 0;
            } else if (weights[i - 1] <= j) {
                memo[i][j] =
                    std::max(values[i - 1] + memo[i - 1][j - weights[i - 1]], memo[i - 1][j]);
            } else {
                memo[i][j] = memo[i - 1][j];
            }
        }
    }

    max_value = memo[n][weight];
    std::intmax_t w = weight;

    for (std::size_t i = n; i > 0 && max_value > 0; --i) {
        if (max_value == memo[i - 1][w]) {
            continue;
        } else {
            selected_items.push_back(i - 1);
            max_value -= values[i - 1];
            w -= weights[i - 1];
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    return {selected_items, memo[n][weight], end - start};
}
}  // namespace daa::dynamic_programming
