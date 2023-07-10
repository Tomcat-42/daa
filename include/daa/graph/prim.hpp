#pragma once

#include <chrono>
#include <cstddef>
#include <daa/graph/graph.hpp>
#include <functional>
#include <iostream>
#include <ostream>
#include <queue>

namespace daa::graph {

/**
 * @brief Prim's algorithm for finding the minimum spanning tree of a graph.
 *
 * @param graph The graph to find the minimum spanning tree of.
 * @return A tuple containing the minimum spanning tree, the time taken to
 *        compute the minimum spanning tree, and the number of comparsions
 *        performed.
 */
template <typename T>
auto prim(const daa::graph::Graph<T>& graph)
  -> std::tuple<daa::graph::Graph<T>,
                std::chrono::duration<std::size_t, std::nano>, std::size_t> {
  auto start = std::chrono::high_resolution_clock::now();
  std::size_t comparisons = 0;

  daa::graph::Graph<T> mst;

  std::map<T, T> minEdgeWeight;
  std::map<T, T> parent;
  std::set<T> notVisited;

  for (const auto& vertex : graph.get_vertices()) {
    minEdgeWeight[vertex] = std::numeric_limits<T>::max();
    notVisited.insert(vertex);
  }

  T startVertex = *(graph.get_vertices().begin());
  minEdgeWeight[startVertex] = 0;

  using QueueElement = std::pair<T, T>;
  std::priority_queue<QueueElement, std::vector<QueueElement>, std::greater<>>
    queue;
  queue.push({0, startVertex});

  while (!queue.empty()) {
    T u = queue.top().second;
    queue.pop();

    if (notVisited.find(u) == notVisited.end()) {
      continue;
    }

    notVisited.erase(u);

    for (const auto& [v, weight] : graph.get_edges(u)) {
      comparisons++;
      if (notVisited.find(v) != notVisited.end() && weight < minEdgeWeight[v]) {
        parent[v] = u;
        minEdgeWeight[v] = weight;
        queue.push({weight, v});
      }
    }
  }

  for (const auto& vertex : graph.get_vertices()) {
    if (vertex != startVertex) {
      mst.add_edge(parent[vertex], vertex, minEdgeWeight[vertex]);
    }
  }

  auto end = std::chrono::high_resolution_clock::now();
  return {mst, end - start, comparisons};
}

} // namespace daa::graph
