#include <functional>
#include <utility>
#include <vector>
#include <list>
#include <iostream>

#include <functional>
#include <vector>
#include <list>
#include <chrono>
#include <optional>
#include <iostream>
#include <concepts>

namespace daa::hashing {

template <typename Key, typename HashFunc = std::hash<Key>>
class separate_chaining_hash_table {
private:
    std::vector<std::list<Key>> table;
    HashFunc hash_func;
    size_t size;

public:
    separate_chaining_hash_table(size_t size, HashFunc hash_func = HashFunc{})
        : table(size), hash_func(std::move(hash_func)), size(size) {}

    auto insert(const Key& key) -> std::pair<bool, std::pair<size_t, size_t>> {
        size_t comparisons = 0;
        auto start = std::chrono::steady_clock::now();

        size_t index = hash_func(key) % size;
        for (const auto& entry : table[index]) {
            comparisons++;
            if (entry == key) {
                auto end = std::chrono::steady_clock::now();
                return std::make_pair(false, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
            }
        }
        table[index].push_front(key);
        auto end = std::chrono::steady_clock::now();
        return std::make_pair(true, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
    }

    auto remove(const Key& key) -> std::pair<bool, std::pair<size_t, size_t>> {
        size_t comparisons = 0;
        auto start = std::chrono::steady_clock::now();

        size_t index = hash_func(key) % size;
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            comparisons++;
            if (*it == key) {
                table[index].erase(it);
                auto end = std::chrono::steady_clock::now();
                return std::make_pair(true, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
            }
        }
        auto end = std::chrono::steady_clock::now();
        return std::make_pair(false, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
    }

    auto search(const Key& key) -> std::pair<bool, std::pair<size_t, size_t>> {
        size_t comparisons = 0;
        auto start = std::chrono::steady_clock::now();

        size_t index = hash_func(key) % size;
        for (const auto& entry : table[index]) {
            comparisons++;
            if (entry == key) {
                auto end = std::chrono::steady_clock::now();
                return std::make_pair(true, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
            }
        }
        auto end = std::chrono::steady_clock::now();
        return std::make_pair(false, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
    }
};

} // namespace daa::hashing
