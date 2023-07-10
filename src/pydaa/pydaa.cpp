#include <pybind11/pybind11.h>

namespace py = pybind11;

// modules initialization
void sorting(py::module_ &m);
void dynamic_programming(py::module_ &m);
void greedy(py::module_ &m);
void hashing(py::module_ &m);
void graph(py::module_ &m);

PYBIND11_MODULE(pydaa, m) {
    m.doc() = "Design and Analysis of Algorithms";

    sorting(m);
    dynamic_programming(m);
    greedy(m);
    hashing(m);
    graph(m);
}
