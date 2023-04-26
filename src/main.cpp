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
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(1, 1000);

    std::vector<int> keys(1000);
    std::generate(keys.begin(), keys.end(), [&]() {
        return dist(gen);
    });

    auto likely_collision_hash_func = [](int key) {
        return key % 10;
    };

    // https://en.wikipedia.org/wiki/MurmurHash
    auto unlikely_collision_hash_func = [](int key) -> size_t {
        // MurmurHash3_x86_32 as a lambda function (adapted from the public domain MurmurHash3 implementation)
        const uint32_t c1 = 0xcc9e2d51;
        const uint32_t c2 = 0x1b873593;
        const uint32_t seed = 0;
        const int r1 = 15;
        const int r2 = 13;
        const uint32_t m = 5;
        const uint32_t n = 0xe6546b64;

        uint32_t h1 = seed;
        auto k1 = static_cast<uint32_t>(key);
        k1 *= c1;
        k1 = (k1 << r1) | (k1 >> (32 - r1));
        k1 *= c2;

        h1 ^= k1;
        h1 = (h1 << r2) | (h1 >> (32 - r2));
        h1 = h1 * m + n;

        h1 ^= 4;
        h1 ^= h1 >> 16;
        h1 *= 0x85ebca6b;
        h1 ^= h1 >> 13;
        h1 *= 0xc2b2ae35;
        h1 ^= h1 >> 16;

        return h1;
    };

    // hash functions to string
    std::vector<std::pair<std::function<size_t(int)>, std::string>> hash_functions = {
        {likely_collision_hash_func, "likely collision"},
        {unlikely_collision_hash_func, "unlikely collision"}
    };

    for (const auto& [hash_func, hash_func_name] : hash_functions) {
        std::cout << "Testing with " << hash_func_name << " hash function" << std::endl;

        daa::hashing::open_addressing_hash_table<int, std::function<size_t(int)>> oa_hash_table(keys.size(), hash_func);
        daa::hashing::separate_chaining_hash_table<int, std::function<size_t(int)>> sc_hash_table(keys.size(), hash_func);

        size_t oa_insertion_time = 0, sc_insertion_time = 0;
        size_t oa_key_comparisons_insert = 0, sc_key_comparisons_insert = 0;

        for (const auto& key : keys) {
            auto oa_insert_result = oa_hash_table.insert(key);
            oa_insertion_time += oa_insert_result.second.first;
            oa_key_comparisons_insert += oa_insert_result.second.second;

            auto sc_insert_result = sc_hash_table.insert(key);
            sc_insertion_time += sc_insert_result.second.first;
            sc_key_comparisons_insert += sc_insert_result.second.second;
        }

        std::shuffle(keys.begin(), keys.end(), gen);

        size_t oa_search_time = 0, sc_search_time = 0;
        size_t oa_key_comparisons_search = 0, sc_key_comparisons_search = 0;

        for (const auto& key : keys) {
            auto oa_search_result = oa_hash_table.search(key);
            oa_search_time += oa_search_result.second.first;
            oa_key_comparisons_search += oa_search_result.second.second;

            auto sc_search_result = sc_hash_table.search(key);
            sc_search_time += sc_search_result.second.first;
            sc_key_comparisons_search += sc_search_result.second.second;
        }

        std::cout << "Open addressing: \n"
                  << "  Total insertion time: " << oa_insertion_time << " ns\n"
                  << "  Total key comparisons (insert): " << oa_key_comparisons_insert << "\n"
                  << "  Total search time: " << oa_search_time << " ns\n"
                  << "  Total key comparisons (search): " << oa_key_comparisons_search << "\n";

        std::cout << "Separate chaining: \n"
                  << "  Total insertion time: " << sc_insertion_time << " ns\n"
                  << "  Total key comparisons (insert): " << sc_key_comparisons_insert << "\n"
                  << "  Total search time: " << sc_search_time << " ns\n"
                  << "  Total key comparisons (search): " << sc_key_comparisons_search << "\n";
    }

    return 0;
}
