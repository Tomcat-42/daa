
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
const std::vector<std::intmax_t>& values, std::size_t n) {
    auto start = std::chrono::high_resolution_clock::now();
    std::intmax_t max_value = 0;
    std::vector<std::intmax_t> selected_items;
    std::vector<std::pair<std::intmax_t, std::intmax_t>> items(n);
    for (std::size_t i = 0; i < n; ++i) {
        items[i] = std::make_pair(values[i], weights[i]);
    }
    std::sort(items.begin(), items.end(),
              [](const std::pair<std::intmax_t, std::intmax_t>& a,
    const std::pair<std::intmax_t, std::intmax_t>& b) {
        return a.first > b.first;
    });

    for (std::size_t i = 0; i < n; ++i) {
        if (weight >= items[i].second) {
            weight -= items[i].second;
            max_value += items[i].first;
            selected_items.push_back(i);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    return std::make_tuple(selected_items, max_value, end - start);
}
}  // namespace daa::dynamic_programming
