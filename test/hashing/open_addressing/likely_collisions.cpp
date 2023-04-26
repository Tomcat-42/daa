// test/hashing/open_addressing/likely_collisions.cpp
#include <gtest/gtest.h>
#include <daa/hashing/open_addressing.hpp>

class open_addressing_likely_collision : public ::testing::Test {
public:
    using KeyType = int;
    auto static likely_collision_hash_func(KeyType key) -> size_t {
        return key % 10;
    };
    daa::hashing::open_addressing_hash_table<KeyType, decltype(&likely_collision_hash_func)> hash_table;

    open_addressing_likely_collision() : hash_table(100, likely_collision_hash_func) {};
};

TEST_F(open_addressing_likely_collision, InsertionTest) {
    // Your insertion test logic here
}

TEST_F(open_addressing_likely_collision, RemovalTest) {
    // Your removal test logic here
}

TEST_F(open_addressing_likely_collision, SearchTest) {
    // Your search test logic here
}
