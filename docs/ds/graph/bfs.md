# BFS

### Application:

1. shortest path / mst
2. PSP networks
3. Crawlers
4. social netowwrking sites
5. GPS navigation
6. Broadcasting network
7. In Garbage Collection: Cheney’s algorithm. It is preferred over DFS because of better locality of reference:
8. cycle detection
9. Ford–Fulkerson algorithm 
10. bipartite
11. PAth Finding
12. Finding all nodes within one connected component:

**To print all the vertices, we can modify the BFS function to do traversal starting from all nodes one by one (Like the DFS modified version).**

O(V+E)

O(E*V)

```
void BFS(int s) 
{ 
	
	bool *visited = new bool[V]; 
	for(int i = 0; i < V; i++) 
		visited[i] = false; 

	list<int> queue; 

	visited[s] = true; 
	queue.push_back(s); 

	list<int>::iterator i; 

	while(!queue.empty()) 
	{ 
		s = queue.front(); 
		cout << s << " "; 
		queue.pop_front(); 

		for (i = adj[s].begin(); i != adj[s].end(); ++i) 
		{ 
			if (!visited[*i]) 
			{ 
				visited[*i] = true; 
				queue.push_back(*i); 
			} 
		} 
	} 
}
```