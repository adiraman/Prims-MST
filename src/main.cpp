#include "../include/heap.h"
#include "../include/primsMST.h"
#include "../include/undirected_weighted_graph.h"

int main()
{
    undirected_weighted_graph g;
    std::cout << "Undirected Graph \n";
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(7, 8, 7);
    g.addEdge(7, 6, 1);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 3, 7);
    g.addEdge(8, 6, 6);
    g.addEdge(6, 5, 2);
    g.addEdge(3, 5, 14);
    g.addEdge(3, 4, 9);
    g.addEdge(5, 4, 10);
    g.writeDot("graph1.dot");
    std::cout << g << std::endl;

    primsMST mst(g);
    auto g1 = mst.compute();
    g1.writeDot("minSpanTree.dot");
    std::cout << g1 << std::endl;

    return 0;
}
