#include <pybind11/chrono.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <libdaa/sorting/quicksort.hpp>
#include <string>
#include <vector>

namespace py = pybind11;

using quicksort_vec_int = libdaa::sorting::quicksort<std::vector<int>, int>;
using quicksort_vec_float =
  libdaa::sorting::quicksort<std::vector<float>, float>;
using quicksort_vec_string =
  libdaa::sorting::quicksort<std::vector<std::string>, std::string>;
using quicksort_string = libdaa::sorting::quicksort<std::string, char>;

PYBIND11_MAKE_OPAQUE(std::vector<int>);
PYBIND11_MAKE_OPAQUE(std::vector<float>);
PYBIND11_MAKE_OPAQUE(std::vector<std::string>);

PYBIND11_MODULE(daa, m) {
  m.doc() = "Design and Analysis of Algorithms";

  auto m_sorting = m.def_submodule("sorting", "Sorting algorithms");

  // c++ enum class to python enum class
  py::enum_<libdaa::sorting::pivot>(m_sorting, "pivot")
    .value("FIRST", libdaa::sorting::pivot::FIRST)
    .value("MIDDLE", libdaa::sorting::pivot::MIDDLE)
    .value("LAST", libdaa::sorting::pivot::LAST)
    .value("MEDIAN_OF_THREE", libdaa::sorting::pivot::MEDIAN_OF_THREE);

  // binding specific types to python
  py::class_<quicksort_vec_int>(m_sorting, "quicksort_int")
    .def(py::init<libdaa::sorting::pivot>())
    .def("sort", &quicksort_vec_int::sort);

  py::class_<quicksort_vec_float>(m_sorting, "quicksort_float")
    .def(py::init<libdaa::sorting::pivot>())
    .def("sort", &quicksort_vec_float::sort);

  py::class_<quicksort_vec_string>(m_sorting, "quicksort_vec_string")
    .def(py::init<libdaa::sorting::pivot>())
    .def("sort", &quicksort_vec_string::sort);

  py::class_<quicksort_string>(m_sorting, "quicksort_string")
    .def(py::init<libdaa::sorting::pivot>())
    .def("sort", &quicksort_string::sort);

  // binding std::vector<int> to python
  py::bind_vector<std::vector<int>>(m_sorting, "vector_int");
  py::bind_vector<std::vector<float>>(m_sorting, "vector_float");
  py::bind_vector<std::vector<std::string>>(m_sorting, "vector_string");

  py::implicitly_convertible<py::list, std::vector<int>>();
  py::implicitly_convertible<py::list, std::vector<float>>();
  py::implicitly_convertible<py::list, std::vector<std::string>>();
}
