#include <functional>
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <daa/hashing/open_addressing.hpp>
#include <daa/hashing/separate_chaining.hpp>

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>

auto main() -> int {
    std::vector<int> values = {
        2,
        63,
        38,
        22,
        25,
        50,
        20,
        8,
        88,
        97,
        94,
        19,
        56,
        39,
        41,
        83,
        95,
        74,
        4,
        89,
        91,
        76,
        71,
        3,
        75,
        53,
        7,
        96,
        68,
        10,
        70,
        48,
        82,
        29,
        33,
        55,
        24,
        100,
        34,
        77,
        72,
        62,
        1,
        14,
        59,
        87,
        32,
        79,
        90,
        43
    };



    daa::hashing::open_addressing_hash_table<int, std::function<int(int)>> open_addressing_table(50, [](int key) {
        return key % 10;
    });

    for (auto& value : values) {
        auto res = open_addressing_table.insert(value);
        // print (bool, (time, comps))
        std::cout << res.first<< std::endl;
        std::cout << res.second.first << std::endl;
        std::cout << res.second.second << std::endl;
    }
}
