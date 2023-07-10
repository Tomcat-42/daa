#pragma once

#include <chrono>
#include <cstddef>
#include <daa/graph/graph.hpp>
#include <functional>

namespace daa::graph {
/**
 * @brief Kruskal's algorithm for finding the minimum spanning tree of a graph.
 *
 * @param graph The graph to find the minimum spanning tree of.
 * @return A tuple containing the minimum spanning tree, the time taken to
 *        compute the minimum spanning tree, and the number of comparsions
 *        performed.
 */
template <typename T>
auto kruskal(const daa::graph::Graph<T>& graph)
  -> std::tuple<daa::graph::Graph<T>,
                std::chrono::duration<std::size_t, std::nano>, std::size_t> {
  auto start = std::chrono::high_resolution_clock::now();
  std::size_t comparsions = 0;

  daa::graph::Graph<T> mst;
  std::map<T, T> parent;
  std::map<T, int> rank;

  for (const auto& vertex : graph.get_vertices()) {
    parent[vertex] = vertex;
    rank[vertex] = 0;
  }

  std::function<T(const T&)> find = [&](const T& vertex) -> T {
    if (parent[vertex] != vertex) {
      parent[vertex] = find(parent[vertex]);
    }
    return parent[vertex];
  };

  auto unite = [&](const T& x, const T& y) -> void {
    auto xroot = find(x);
    auto yroot = find(y);

    if (rank[xroot] < rank[yroot]) {
      parent[xroot] = yroot;
    } else if (rank[xroot] > rank[yroot]) {
      parent[yroot] = xroot;
    } else {
      parent[yroot] = xroot;
      rank[xroot]++;
    }
  };

  auto edges = graph.get_edges();
  std::sort(edges.begin(), edges.end(), [&](const auto& a, const auto& b) {
    ++comparsions;
    return std::get<2>(a) < std::get<2>(b);
  });

  for (const auto& [from, to, weight] : edges) {
    auto x = find(from);
    auto y = find(to);
    ++comparsions; // Update comparsions each time we find sets of vertices.
    if (x != y) {
      mst.add_edge(from, to, weight);
      unite(x, y);
    }
  }
  auto end = std::chrono::high_resolution_clock::now();

  return {mst, end - start, comparsions};
}

} // namespace daa::graph
