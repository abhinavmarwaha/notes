# DFS

* Create a recursive function that takes the index of node and a visited array.
* Mark the current node as visited and print the node.
* Traverse all the adjacent and unmarked nodes and call the recursive function with index of adjacent node.

### Application:

1. mst, shortest path tree
2. detect cycle, if there is back egde in dfs then there is cycle 
3. Pth finding: prepare stack when v detect pop it.
4. topological sorting: scheduling jobs from the given dependencies among jobs.
5. bipartite graph test
6. strongly connected graph
7. solving puzzles wiht only one solutiion such as mazes

O(V + E) , O(V).

```
void DFSUtil(int v, bool visited[]) 
{ 
	visited[v] = true; 
	cout << v << " "; 

	list<int>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) 
		if (!visited[*i]) 
			DFSUtil(*i, visited); 
} 

void DFS(int v) 
{ 

	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	DFSUtil(v, visited); 
} 
```