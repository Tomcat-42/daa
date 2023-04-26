#include <pybind11/chrono.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <daa/greedy/knapsack.hpp>
#include <vector>

namespace py = pybind11;

// modules initialization
void open_addressing(py::module_ &m);
void separate_chaining(py::module_ &m);

void hashing(py::module_ &m) {
    // defs hashing submodule
    auto m_hashing = m.def_submodule("hashing", "Hashing Algorithms");

    // Adds open_addressing submodule and separate_chaining submodule
    open_addressing(m_hashing);
    separate_chaining(m_hashing);
}
