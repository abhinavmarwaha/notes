Graph coloring problem is to assign colors to certain elements of a graph subject to certain constraints.

# Vertex coloring 

The problem is, given m colors, find a way of coloring the vertices of a graph such that no two adjacent vertices are colored using same color. 
Edge Coloring  and Face Coloring can be transformed into vertex coloring.

# Chromatic Number

The smallest number of colors needed to color a graph G is called its chromatic number.

# Applications

*Making Schedule or Time Table*

This problem can be represented as a graph where every vertex is a subject and an edge between two vertices mean there is a common student. So this is a graph coloring problem where minimum number of time slots is equal to the chromatic number of the graph.

*Mobile Radio Frequency Assignment* 

When frequencies are assigned to towers, frequencies assigned to all towers at the same location must be different. How to assign frequencies with this constraint? What is the minimum number of frequencies needed? This problem is also an instance of graph coloring problem where every tower represents a vertex and an edge between two towers represents that they are in range of each other.

*Sudoku*

Sudoku is also a variation of Graph coloring problem where every cell represents a vertex. There is an edge between two vertices if they are in same row or same column or same block.

*Register Allocation*

In compiler optimization, register allocation is the process of assigning a large number of target program variables onto a small number of CPU registers. This problem is also a graph coloring problem.

*Bipartite Graphs*

We can check if a graph is Bipartite or not by coloring the graph using two colors. If a given graph is 2-colorable, then it is Bipartite, otherwise not. 
ref-> https://www.geeksforgeeks.org/bipartite-graph/ 

*Map Coloring*

Geographical maps of countries or states where no two adjacent cities cannot be assigned same color. Four colors are sufficient to color any map 
Four Color Theorem-> http://en.wikipedia.org/wiki/Four_color_theorem

*Updates on servers distributing content on internet*

* Updates-> every week
* The update cannot be deployed on every server at the same time, because the server may have to be taken down for the install. 
* Also, the update should not be done one at a time, because it will take a lot of time. 
* There are sets of servers that cannot be taken down together, because they have certain critical functions. 
* This is a typical scheduling application of graph coloring problem. 
* It turned out that 8 colors were good enough to color the graph of 75000 nodes. So they could install updates in 8 passes.

# Greedy Aproach

TODO