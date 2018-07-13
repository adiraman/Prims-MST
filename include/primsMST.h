#ifndef PRIMS_MST_H
#define PRIMS_MST_H

#include "../include/directed_weighted_graph.h"
#include "../include/heap.h"
#include "../include/undirected_weighted_graph.h"

/*
 * Implementation of the Dijkstra's shortest path algorithm
 */
class primsMST
{
  public:
    primsMST(const graph &g);
    primsMST() = delete;
    ~primsMST() = default;

    undirected_weighted_graph compute() const;

  private:
    std::map<int, std::set<std::pair<int, int>>> m_graph;
};

#endif /* ifndef SHORTEST_PATH_H */
