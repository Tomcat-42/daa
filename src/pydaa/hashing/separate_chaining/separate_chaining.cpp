#include <pybind11/pybind11.h>
#include <daa/hashing/separate_chaining.hpp>

namespace py = pybind11;

void hashing_separate_chaining(py::module_ &m) {
    auto likely_collisions_hash_func = [](int key) -> size_t {
        return key%10;
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

    using separate_chaining_hash_table_int_likely_collisions = daa::hashing::separate_chaining_hash_table<int, decltype(likely_collisions_hash_func)>;
    using separate_chaining_hash_table_int_unlikely_collisions = daa::hashing::separate_chaining_hash_table<int, decltype(unlikely_collision_hash_func)>;

    py::class_<separate_chaining_hash_table_int_likely_collisions>(m, "separate_chaining_hash_table_int_likely_collisions")
    .def(py::init<size_t, decltype(likely_collisions_hash_func)>())
    .def("insert", &separate_chaining_hash_table_int_likely_collisions::insert)
    .def("remove", &separate_chaining_hash_table_int_likely_collisions::remove)
    .def("search", &separate_chaining_hash_table_int_likely_collisions::search);

    py::class_<separate_chaining_hash_table_int_unlikely_collisions>(m, "separate_chaining_hash_table_int_unlikely_collisions")
    .def(py::init<size_t, decltype(unlikely_collision_hash_func)>())
    .def("insert", &separate_chaining_hash_table_int_unlikely_collisions::insert)
    .def("remove", &separate_chaining_hash_table_int_unlikely_collisions::remove)
    .def("search", &separate_chaining_hash_table_int_unlikely_collisions::search);

}
