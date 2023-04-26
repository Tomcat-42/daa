#include <gtest/gtest.h>
#include <daa/hashing/separate_chaining.hpp>

class separate_chaining_unlikely_collision : public ::testing::Test {
public:
    using KeyType = int;
    // https://en.wikipedia.org/wiki/MurmurHash
    static auto unlikely_collision_hash_func(KeyType key) -> size_t {
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
    daa::hashing::separate_chaining_hash_table<KeyType, decltype(&unlikely_collision_hash_func)> hash_table;

    separate_chaining_unlikely_collision() : hash_table(100, unlikely_collision_hash_func) {}
};

TEST_F(separate_chaining_unlikely_collision, InsertionTest) {
    // Your insertion test logic here
}

TEST_F(separate_chaining_unlikely_collision, RemovalTest) {
    // Your removal test logic here
}

TEST_F(separate_chaining_unlikely_collision, SearchTest) {
    // Your search test logic here
}
