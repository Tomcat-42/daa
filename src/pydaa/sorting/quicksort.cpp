#include <pybind11/chrono.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/stl_bind.h>

#include <daa/sorting/quicksort.hpp>
#include <string>
#include <vector>

namespace py = pybind11;

PYBIND11_MAKE_OPAQUE(std::vector<int>);
PYBIND11_MAKE_OPAQUE(std::vector<float>);
PYBIND11_MAKE_OPAQUE(std::vector<std::string>);

using quicksort_vec_int = daa::sorting::quicksort<std::vector<int>, int>;
using quicksort_vec_float = daa::sorting::quicksort<std::vector<float>, float>;
using quicksort_vec_string =
    daa::sorting::quicksort<std::vector<std::string>, std::string>;
using quicksort_string = daa::sorting::quicksort<std::string, char>;

void sorting(py::module_ &m) {
    auto m_sorting = m.def_submodule("sorting", "Sorting algorithms");


    // c++ enum class to python enum class
    py::enum_<daa::sorting::pivot>(m_sorting, "pivot")
    .value("FIRST", daa::sorting::pivot::FIRST)
    .value("MIDDLE", daa::sorting::pivot::MIDDLE)
    .value("LAST", daa::sorting::pivot::LAST)
    .value("MEDIAN_OF_THREE", daa::sorting::pivot::MEDIAN_OF_THREE);

    // binding specific types to python
    py::class_<daa::sorting::quicksort<std::vector<int>, int>>(m_sorting,
            "quicksort_int")
            .def(py::init<daa::sorting::pivot>())
            .def("sort", &daa::sorting::quicksort<std::vector<int>, int>::sort);

    py::class_<daa::sorting::quicksort<std::vector<float>, float>>(
                m_sorting, "quicksort_float")
            .def(py::init<daa::sorting::pivot>())
            .def("sort", &daa::sorting::quicksort<std::vector<float>, float>::sort);

    py::class_<daa::sorting::quicksort<std::vector<std::string>, std::string>>(
                m_sorting, "quicksort_vec_string")
            .def(py::init<daa::sorting::pivot>())
            .def("sort",
                 &daa::sorting::quicksort<std::vector<std::string>, std::string>::sort);

    py::class_<daa::sorting::quicksort<std::string, char>>(m_sorting,
            "quicksort_string")
            .def(py::init<daa::sorting::pivot>())
            .def("sort", &daa::sorting::quicksort<std::string, char>::sort);

    // binding std::vector<int> to python
    py::bind_vector<std::vector<int>>(m_sorting, "vector_int");
    py::bind_vector<std::vector<float>>(m_sorting, "vector_float");
    py::bind_vector<std::vector<std::string>>(m_sorting, "vector_string");

    py::implicitly_convertible<py::list, std::vector<int>>();
    py::implicitly_convertible<py::list, std::vector<float>>();
    py::implicitly_convertible<py::list, std::vector<std::string>>();
}
