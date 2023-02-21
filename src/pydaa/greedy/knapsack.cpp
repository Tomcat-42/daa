#include <pybind11/chrono.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <daa/greedy/knapsack.hpp>
#include <vector>

namespace py = pybind11;

void greedy(py::module_ &m) {
    auto m_greedy = m.def_submodule("greedy", "Greedy Algorithms");
    m_greedy.def("knapsack", &daa::greedy::knapsack, "Knapsack Problem");
}
