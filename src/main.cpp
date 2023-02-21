#include <stdlib.h>

#include <algorithm>
#include <chrono>
#include <daa/sorting/quicksort.hpp>
#include <daa/dynamic_programming/knapsack.hpp>
#include <daa/greedy/knapsack.hpp>
#include <iostream>
#include <iterator>
#include <numeric>

int main() {
    std::cout << "Dynamic Programming Knapsack:" << std::endl;
    std::intmax_t w = 300;
    std::vector<std::intmax_t> weights = { 14, 16, 14, 19, 10, 11, 10, 11};
    std::vector<std::intmax_t> values = { 98, 101, 73, 65, 20, 40, 20, 63};
    std::intmax_t n = values.size();

    const auto &[selected, total_value, execution_time] = daa::dynamic_programming::knapsack(w, weights, values, n);

    std::cout << "Total value: " << total_value << std::endl;
    std::cout << "Execution time: " << execution_time << std::endl;
    std::cout << "Selected items: ";
    std::copy(selected.begin(), selected.end(), std::ostream_iterator<std::intmax_t>(std::cout, " "));

    std::cout << std::endl << std::endl;

    std::cout << "Greedy Knapsack:" << std::endl;
    const auto &[selected_greedy, total_value_greedy, execution_time_greedy] = daa::greedy::knapsack(w, weights, values, n);
    std::cout << "Total value: " << total_value_greedy << std::endl;
    std::cout << "Execution time: " << execution_time_greedy << std::endl;
    std::cout << "Selected items: ";
    std::copy(selected_greedy.begin(), selected_greedy.end(), std::ostream_iterator<std::intmax_t>(std::cout, " "));

    return 0;
}
