
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <daa/dynamic_programming/knapsack.hpp>
#include <iostream>
#include <tuple>
#include <vector>

// Path: knapsack.hpp
namespace daa::greedy {

std::tuple<std::chrono::duration<double>, std::intmax_t, std::vector<std::intmax_t>>
        knapsack(std::intmax_t weight, const std::vector<std::intmax_t>& values,
const std::vector<std::intmax_t>& weights) {
    auto start = std::chrono::high_resolution_clock::now();
    auto n = weights.size();
    std::intmax_t max_value = 0;
    std::vector<std::intmax_t> selected_items;
    std::vector<std::tuple<std::intmax_t, std::intmax_t, std::intmax_t>> items(n);

    // the value of the item is the first element of the tuple
    // the weight of the item is the second element of the tuple
    // the index(original position) of the item is the third element of the tuple
    for (std::size_t i = 0; i < n; ++i) {
        items[i] = {values[i], weights[i], i};
    }

    // sort the items in descending order of the value/weight ratio
    std::sort(items.begin(), items.end(), [](const auto& a, const auto& b) {
        return std::get<0>(a) * std::get<1>(b) > std::get<0>(b) * std::get<1>(a);
    });

    for (const auto& item : items) {
        if (std::get<1>(item) <= weight) {
            selected_items.push_back(std::get<2>(item));
            max_value += std::get<0>(item);
            weight -= std::get<1>(item);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();

    return {end - start, max_value, selected_items};
}
}  // namespace daa::dynamic_programming
