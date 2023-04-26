#include <pybind11/pybind11.h>
#include <daa/hashing/separate_chaining.hpp>

namespace py = pybind11;

void hashing_separate_chaining(py::module_ &m) {
    using separate_chaining_hash_table_int_likely_collisions = daa::hashing::separate_chaining_hash_table<int, std::function<size_t(int)>>;
    using separate_chaining_hash_table_int_unlikely_collisions = daa::hashing::separate_chaining_hash_table<int, std::function<size_t(int)>>;

    py::class_<separate_chaining_hash_table_int_likely_collisions>(m, "separate_chaining_hash_table_int_likely_collisions")
    .def(py::init<size_t, std::function<size_t(int)>>())
    .def("insert", &separate_chaining_hash_table_int_likely_collisions::insert)
    .def("remove", &separate_chaining_hash_table_int_likely_collisions::remove)
    .def("search", &separate_chaining_hash_table_int_likely_collisions::search);

    py::class_<separate_chaining_hash_table_int_unlikely_collisions>(m, "separate_chaining_hash_table_int_unlikely_collisions")
    .def(py::init<size_t, std::function<size_t(int)>>())
    .def("insert", &separate_chaining_hash_table_int_unlikely_collisions::insert)
    .def("remove", &separate_chaining_hash_table_int_unlikely_collisions::remove)
    .def("search", &separate_chaining_hash_table_int_unlikely_collisions::search);

}
