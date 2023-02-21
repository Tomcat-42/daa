#include <pybind11/chrono.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <daa/dynamic_programming/knapsack.hpp>
#include <vector>

namespace py = pybind11;

void dynamic_programming(py::module_ &m) {
    auto m_dynamic_programming = m.def_submodule("dynamic_programming", "Dynamic Programming Algorithms");
    m_dynamic_programming.def("knapsack", &daa::dynamic_programming::knapsack, "Knapsack Problem");
}
