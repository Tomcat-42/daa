#include <pybind11/chrono.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <libdaa/sorting/quicksort.hpp>
#include <vector>

int add(int i, int j) { return i + j; }

namespace py = pybind11;

PYBIND11_MODULE(daa, m) {
  m.doc() = "Design and Analysis of Algorithms";
  m.def("add", &add, "A function which adds two numbers");

  auto m_sorting = m.def_submodule("sorting", "Sorting algorithms");

  // c++ enum class to python enum class
  py::enum_<libdaa::sorting::pivot>(m_sorting, "pivot")
    .value("FIRST", libdaa::sorting::pivot::FIRST)
    .value("MIDDLE", libdaa::sorting::pivot::MIDDLE)
    .value("LAST", libdaa::sorting::pivot::LAST)
    .value("MEDIAN_OF_THREE", libdaa::sorting::pivot::MEDIAN_OF_THREE)
    .export_values();

  // binding specific types to python
  m_sorting.def("quicksort", &libdaa::sorting::quicksort<std::vector<int>, int>,
                "Quicksort");
  m_sorting.def("quicksort",
                &libdaa::sorting::quicksort<std::vector<double>, double>,
                "Quicksort");
}
