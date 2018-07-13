# Prims-MST

1.  Initialize costs of all vertices as infinite and parent of each vertex as -1.
2.  Create a min heap to store (weight, vertex) pairs.
3.  Initialize a boolean array to keep track of vertices already included in the MST. Important to ensure that a vertex is not added twice.
4.  Insert source vertex in to the min heap and initialize its cost to be zero.
5.  While the min heap is not empty :-

        i.  extract min vertex 'u' from the heap.
        ii. Mark u as included in the MST.
        iii.  Loop through all adjacent vertices of u and for every such vertex 'v' :- 
        If v is not yet in MST and if the cost of v is greater than the weight of edge (u,v)
      
                a.  Update the cost of v as the weight of (u,v) edge
                b.  Insert v into the min heap along with its cost
                c.  mark the parent of v as u. (parent[v] = u)
 6.  Create a tree using the parent container info.
