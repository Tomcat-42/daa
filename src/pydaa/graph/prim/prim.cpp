#include <cstddef>
#include <daa/graph/prim.hpp>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/chrono.h>

namespace py = pybind11;

void prim(py::module_& m) {
  m.def("prim", &daa::graph::prim<std::size_t>, py::arg("graph"),
        "Prim's algorithm");
}
