#include <gtest/gtest.h>
#include <daa/hashing/separate_chaining.hpp>

class separate_chaining_likely_collision : public ::testing::Test {
public:
    using KeyType = int;
    static auto likely_collision_hash_func(KeyType key) -> size_t {
        return key % 10;
    }
    daa::hashing::separate_chaining_hash_table<KeyType, decltype(&likely_collision_hash_func)> hash_table;

    separate_chaining_likely_collision() : hash_table(100, likely_collision_hash_func) {}
};

TEST_F(separate_chaining_likely_collision, InsertionTest) {
    // Your insertion test logic here
}

TEST_F(separate_chaining_likely_collision, RemovalTest) {
    // Your removal test logic here
}

TEST_F(separate_chaining_likely_collision, SearchTest) {
    // Your search test logic here
}
