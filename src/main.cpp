#include <algorithm>
#include <cstddef>
#include <daa/graph/graph.hpp>
#include <daa/graph/kruskal.hpp>
// #include <daa/graph/prim.hpp>
#include <functional>
#include <iostream>
#include <list>
#include <ostream>
#include <vector>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

auto main() -> int {
  daa::graph::Graph<std::size_t> graph = {{1, {{2, 1}, {3, 3}}},
                                          {2, {{1, 1}, {3, 2}}},
                                          {3, {{1, 3}, {2, 2}}}};

  auto [mst_kruskal, time_kuskal, comparsions_kruskal] = daa::graph::kruskal(graph);
  // auto [mst_prim, time_prim, comparsions_prim] = daa::graph::prim(graph);

  std::cout << "Graph: " << std::endl << graph << std::endl;

  std::cout << "Mst kruskal: " << std::endl << mst_kruskal << std::endl;
  std::cout << "Time kruskal: " << time_kuskal.count() << std::endl;
  std::cout << "Comparsions kruskal: " << comparsions_kruskal << std::endl;

  // std::cout << "Mst prim: " << std::endl << mst_prim << std::endl;
  // std::cout << "Time prim: " << time_prim.count() << std::endl;
  // std::cout << "Comparsions prim: " << comparsions_prim << std::endl;
}
