#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <daa/hashing/open_addressing.hpp>

namespace py = pybind11;

void hashing_open_addressing(py::module_ &m) {
    using open_addressing_hash_table_int = daa::hashing::open_addressing_hash_table<int, std::function<size_t(int)>>;

    py::class_<open_addressing_hash_table_int>(m, "open_addressing_hash_table")
    .def(py::init<size_t, std::function<size_t(int)>>())
    .def("insert", &open_addressing_hash_table_int::insert)
    .def("remove", &open_addressing_hash_table_int::remove)
    .def("search", &open_addressing_hash_table_int::search);
}
