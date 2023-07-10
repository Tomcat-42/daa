#include <cstddef>
#include <daa/graph/kruskal.hpp>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

void kruskal(py::module_& m) {
  m.def("kruskal", &daa::graph::kruskal<std::size_t>, py::arg("graph"),
        "Kruskal's algorithm");
}
