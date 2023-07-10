#pragma once

#include <map>
#include <set>
#include <string>
#include <vector>

namespace daa::graph {

/**
 * @brief A damn simple graph data structure.
 *
 * @tparam T The type of the vertices and the weight of the edges.
 * @details The graph is represented as an adjacency list.
 * @details The graph is undirected.
 */
template <typename T>
class Graph {
  std::map<T, std::set<std::pair<T, T>>> adjacency_list;

public:
  Graph() = default;
  Graph(const Graph&) = default;
  Graph(Graph&&) = default;
  Graph(std::map<T, std::set<std::pair<T, T>>> adjacency_list)
    : adjacency_list{std::move(adjacency_list)} {}
  Graph(
    std::initializer_list<std::pair<T, std::set<std::pair<T, T>>>> init_list);
  ~Graph() = default;

  auto operator=(const Graph&) -> Graph& = default;
  auto operator=(Graph&&) -> Graph& = default;
  auto operator=(std::map<T, std::set<std::pair<T, T>>>) -> Graph&;

  auto add_vertex(const T& vertex) -> void;
  auto add_edge(const T& from, const T& to, const T& weight) -> void;
  auto get_vertices() const -> std::set<T>;
  auto get_edges(const T& vertex) const -> std::set<std::pair<T, T>>;
  auto get_edges() const -> std::vector<std::tuple<T, T, T>>;
  auto get_adjacent_vertices(const T& vertex) const -> std::set<T>;
  auto get_edge_weight(const T& from, const T& to) const -> T;
  [[nodiscard]] auto to_string() const -> std::string;
};

template <typename T>
auto operator<<(std::ostream& os, const Graph<T>& graph) -> std::ostream& {
  return os << graph.to_string();
}

template <typename T>
Graph<T>::Graph(
  std::initializer_list<std::pair<T, std::set<std::pair<T, T>>>> init_list) {
  for (const auto& [vertex, edges] : init_list) {
    adjacency_list[vertex] = edges;
  }
}

template <typename T>
auto Graph<T>::operator=(std::map<T, std::set<std::pair<T, T>>>) -> Graph& {
  adjacency_list = std::move(adjacency_list);
  return *this;
}

template <typename T>
auto Graph<T>::add_vertex(const T& vertex) -> void {
  if (adjacency_list.find(vertex) == adjacency_list.end()) {
    adjacency_list[vertex] = {};
  }
}

template <typename T>
auto Graph<T>::add_edge(const T& from, const T& to, const T& weight) -> void {
  add_vertex(from);
  add_vertex(to);
  adjacency_list[from].insert({to, weight});
  adjacency_list[to].insert({from, weight});
}

template <typename T>
auto Graph<T>::get_vertices() const -> std::set<T> {
  std::set<T> vertices;
  for (const auto& [vertex, _] : adjacency_list) {
    vertices.insert(vertex);
  }
  return vertices;
}

template <typename T>
auto Graph<T>::get_edges(const T& vertex) const -> std::set<std::pair<T, T>> {
  std::set<std::pair<T, T>> edges;
  for (const auto& [to, weight] : adjacency_list.at(vertex)) {
    edges.insert({to, weight});
  }
  return edges;
}

template <typename T>
auto Graph<T>::get_edges() const -> std::vector<std::tuple<T, T, T>> {
  std::vector<std::tuple<T, T, T>> edges;
  for (const auto& [from, to_weight] : adjacency_list) {
    for (const auto& [to, weight] : to_weight) {
      edges.push_back({from, to, weight});
    }
  }
  return edges;
}

template <typename T>
auto Graph<T>::get_adjacent_vertices(const T& vertex) const -> std::set<T> {
  std::set<T> adjacent_vertices;
  for (const auto& [to, _] : adjacency_list.at(vertex)) {
    adjacent_vertices.insert(to);
  }
  return adjacent_vertices;
}

template <typename T>
auto Graph<T>::get_edge_weight(const T& from, const T& to) const -> T {
  return adjacency_list.at(from).at(to);
}

template <typename T>
auto Graph<T>::to_string() const -> std::string {
  std::string str = "";
  for (const auto& [vertex, edges] : adjacency_list) {
    str += std::to_string(vertex) + ": ";
    for (const auto& [to, weight] : edges) {
      str += "(" + std::to_string(to) + ", " + std::to_string(weight) + ") ";
    }
    str += "\n";
  }
  return str;
}

} // namespace daa::graph
