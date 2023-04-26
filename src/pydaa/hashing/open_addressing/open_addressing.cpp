#include <pybind11/pybind11.h>
#include <daa/hashing/open_addressing.hpp>

namespace py = pybind11;

void hashing_open_addressing(py::module_ &m) {
    using open_addressing_hash_table_int_likely_collisions = daa::hashing::open_addressing_hash_table<int, std::function<size_t(int)>>;
    using open_addressing_hash_table_int_unlikely_collisions = daa::hashing::open_addressing_hash_table<int, std::function<size_t(int)>>;

    py::class_<open_addressing_hash_table_int_likely_collisions>(m, "open_addressing_hash_table_int_likely_collisions")
    .def(py::init<size_t, std::function<size_t(int)>>())
    .def("insert", &open_addressing_hash_table_int_likely_collisions::insert)
    .def("remove", &open_addressing_hash_table_int_likely_collisions::remove)
    .def("search", &open_addressing_hash_table_int_likely_collisions::search);

    py::class_<open_addressing_hash_table_int_unlikely_collisions>(m, "open_addressing_hash_table_int_unlikely_collisions")
    .def(py::init<size_t, std::function<size_t(int)>>())
    .def("insert", &open_addressing_hash_table_int_unlikely_collisions::insert)
    .def("remove", &open_addressing_hash_table_int_unlikely_collisions::remove)
    .def("search", &open_addressing_hash_table_int_unlikely_collisions::search);
}
