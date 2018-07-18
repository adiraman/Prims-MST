#ifndef PRIMS_MST_H
#define PRIMS_MST_H

#include "../include/heap.h"
#include "../include/undirected_weighted_graph.h"

/*
 * Implementation of Prims Minimum Spanning Tree Algorithm
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
