#include <functional>
#include <vector>
#include <chrono>
#include <optional>
#include <iostream>
#include <concepts>

namespace daa::hashing {

template <typename Key, typename HashFunc = std::hash<Key>>
class open_addressing_hash_table {
private:
    enum class entry_state : uint8_t {
        empty = 0,
        deleted = 1,
        occupied = 2
    };
    std::vector<std::optional<Key>> table;
    std::vector<entry_state> entry_states;
    HashFunc hash_func;
    size_t size;


public:
    open_addressing_hash_table(size_t size, HashFunc hash_func = HashFunc{})
        : table(size, 0), entry_states(size, entry_state::empty), hash_func(std::move(hash_func)), size(size) {}

    auto insert(const Key& key) -> std::pair<bool, std::pair<size_t, size_t>> {
        size_t comparisons = 0;
        auto start = std::chrono::steady_clock::now();

        for (size_t i = 0; i < size; i++) {
            comparisons++;
            size_t index = (hash_func(key) + i) % size;
            if (entry_states[index] == entry_state::empty || entry_states[index] == entry_state::deleted) {
                table[index] = key;
                entry_states[index] = entry_state::occupied;
                auto end = std::chrono::steady_clock::now();
                return std::make_pair(true, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
            }
        }
        auto end = std::chrono::steady_clock::now();
        return std::make_pair(false, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
    }

    auto remove(const Key& key) -> std::pair<bool, std::pair<size_t, size_t>> {
        size_t comparisons = 0;
        auto start = std::chrono::steady_clock::now();

        for (size_t i = 0; i < size; i++) {
            comparisons++;
            size_t index = (hash_func(key) + i) % size;
            if (table[index] && *table[index] == key) {
                entry_states[index] = entry_state::deleted;
                table[index].reset();
                auto end = std::chrono::steady_clock::now();
                return std::make_pair(true, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
            } else if (entry_states[index] == entry_state::empty) {
                auto end = std::chrono::steady_clock::now();
                return std::make_pair(false, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
            }
        }
        auto end = std::chrono::steady_clock::now();
        return std::make_pair(false, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
    }

    auto search(const Key& key) -> std::pair<bool, std::pair<size_t, size_t>> {
        size_t comparisons = 0;
        auto start = std::chrono::steady_clock::now();

        for (size_t i = 0; i < size; i++) {
            comparisons++;
            size_t index = (hash_func(key) + i) % size;
            if (table[index] && *table[index] == key) {
                auto end = std::chrono::steady_clock::now();
                return std::make_pair(true, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
            } else if (entry_states[index] == entry_state::empty) {
                auto end = std::chrono::steady_clock::now();
                return std::make_pair(false, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
            }
        }
        auto end = std::chrono::steady_clock::now();
        return std::make_pair(false, std::make_pair(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count(), comparisons));
    }
};

} // namespace daa::hashing
