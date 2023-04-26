#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/functional.h>
#include <daa/hashing/separate_chaining.hpp>

namespace py = pybind11;

void hashing_separate_chaining(py::module_ &m) {
    using separate_chaining_hash_table_int = daa::hashing::separate_chaining_hash_table<int, std::function<size_t(int)>>;

    py::class_<separate_chaining_hash_table_int>(m, "separate_chaining_hash_table")
    .def(py::init<size_t, std::function<size_t(int)>>())
    .def("insert", &separate_chaining_hash_table_int::insert)
    .def("remove", &separate_chaining_hash_table_int::remove)
    .def("search", &separate_chaining_hash_table_int::search);
}
