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
    // std::intmax_t w = 300;
    // std::vector<std::intmax_t> benefits = { 98, 101, 73, 65, 20, 40, 20, 63};
    // std::vector<std::intmax_t> weights = { 14, 16, 14, 19, 10, 11, 10, 11};

    std::intmax_t w = 100;
    std::vector<std::intmax_t> benefits = { 91, 101, 73, 65, 20, 40, 20, 63};
    std::vector<std::intmax_t> weights = { 14, 14, 14, 19, 5, 11, 10, 9};

    const auto &[execution_time, max_benefit, items ] = daa::dynamic_programming::knapsack(w, benefits, weights);
    std::cout << "Execution time: " << execution_time.count() << "s" << std::endl;
    std::cout << "Maximum benefit: " << max_benefit << std::endl;
    std::copy(items.begin(), items.end(), std::ostream_iterator<std::intmax_t>(std::cout, " "));
    std::cout << std::endl;

    std::cout << "Greedy Knapsack:" << std::endl;
    const auto &[execution_time_greedy, max_benefit_greedy, items_greedy ] = daa::greedy::knapsack(w, benefits, weights);
    std::cout << "Execution time: " << execution_time_greedy.count() << "s" << std::endl;
    std::cout << "Maximum benefit: " << max_benefit_greedy << std::endl;
    std::copy(items_greedy.begin(), items_greedy.end(), std::ostream_iterator<std::intmax_t>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
