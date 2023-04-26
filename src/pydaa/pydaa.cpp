#include <pybind11/pybind11.h>

namespace py = pybind11;

// modules initialization
void sorting(py::module_ &m);
void dynamic_programming(py::module_ &m);
void hashing_separate_chaining(py::module_ &m);
void hashing(py::module_ &m);

PYBIND11_MODULE(pydaa, m) {
    m.doc() = "Design and Analysis of Algorithms";

    sorting(m);
    dynamic_programming(m);
    hashing_separate_chaining(m);
    hashing(m);
}
