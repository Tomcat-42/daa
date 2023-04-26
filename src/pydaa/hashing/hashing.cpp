#include <pybind11/pybind11.h>
#include <daa/greedy/knapsack.hpp>

namespace py = pybind11;

// modules initialization
void hashing_open_addressing(py::module_ &m);
void hashing_separate_chaining(py::module_ &m);

void hashing(py::module_ &m) {
    // defs hashing submodule
    auto m_hashing = m.def_submodule("hashing", "Hashing Algorithms");

    // Adds open_addressing submodule and separate_chaining submodule
    hashing_open_addressing(m_hashing);
    hashing_separate_chaining(m_hashing);
}
