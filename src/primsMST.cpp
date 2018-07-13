#include "../include/primsMST.h"
#include <queue>

typedef std::pair<int, int> iPair;

primsMST::primsMST(const graph& g)
{
    m_graph = g.getAdjacencyList();
}

undirected_weighted_graph primsMST::compute() const
{
    int N = m_graph.size();
    // initialize and set all distances to infinity.
    int inf = std::numeric_limits<int>::max();
    std::vector<int> cost(N, inf);

    // by default select the 1st vertex as the source
    int source = 0;

    // keep track of the parent of each vertex
    std::vector<int> parent(N, -1);

    // create a min heap to store vertices that are being processed,
    // 1st element of the pair is the distance and 2nd is the vertex.
    heap<iPair> minHeap;
    minHeap.insert(std::make_pair(0, source));
    cost[source] = 0;

    // Keep track of Vertices included in MST
    std::map<int, bool> inMST;
    for (int i = 0; i < N; ++i) {
        inMST.emplace(i, false);
    }

    undirected_weighted_graph mst;

    /* Loop till the heap is empty. */
    while (!minHeap.empty()) {
        /* The first vertex in the pair is the min distance vertex.
         * Extract it from the heap. The second element of the pair
         * is the vertex label. */
        auto up = minHeap.pop();
        int u = up.second;
        // Include the vertex in the MST
        inMST[u] = true;

        for (auto vp : m_graph.at(u)) {
            int v = vp.first;
            int weight = vp.second;

            // if v is not in MST and weight of (u,v) is smaller
            if (inMST[v] == false && cost[v] > weight) {
                cost[v] = weight;
                minHeap.insert(std::make_pair(cost[v], v));
                parent[v] = u;
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        mst.addEdge(parent[i], i, 0);
    }
    return mst;
}
