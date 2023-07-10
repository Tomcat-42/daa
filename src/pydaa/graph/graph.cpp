#include <cstddef>
#include <daa/graph/graph.hpp>
#include <pybind11/functional.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

void kruskal(py::module_& m);
void prim(py::module_& m);

void graph(py::module_& m) {
  auto m_graph = m.def_submodule("graph", "Graph Algorithms");

  using Graph = daa::graph::Graph<std::size_t>;
  py::class_<Graph>(m_graph, "Graph")
    .def(py::init<>(), "Default constructor.")
    .def(py::init<const Graph&>(), "Copy constructor.")
    .def(
      py::init<
        std::map<std::size_t, std::set<std::pair<std::size_t, std::size_t>>>>(),
      "Construct with adjacency list.")
    .def("add_vertex", &Graph::add_vertex, "Add a vertex to the graph.")
    .def("add_edge", &Graph::add_edge, "Add an edge to the graph.")
    .def("get_vertices", &Graph::get_vertices, "Get all vertices.")
    .def("get_edges",
         py::overload_cast<const std::size_t&>(&Graph::get_edges, py::const_),
         "Get all edges from a specific vertex.")
    .def("get_edges", py::overload_cast<>(&Graph::get_edges, py::const_),
         "Get all edges in the graph.")
    .def("get_adjacent_vertices", &Graph::get_adjacent_vertices,
         "Get adjacent vertices to a specific vertex.")
    .def("get_edge_weight", &Graph::get_edge_weight,
         "Get the weight of an edge.")
    .def("to_string", &Graph::to_string,
         "Get a string representation of the graph.");

  // py::class_<daa::graph::Graph>(m_graph, "Graph")
  kruskal(m_graph);
  prim(m_graph);
}
