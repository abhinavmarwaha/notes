# Disconnected DFS

* Create a recursive function that takes the index of node and a visited array.
* Mark the current node as visited and print the node.
* Traverse all the adjacent and unmarked nodes and call the recursive function with index of adjacent node.
* Run a loop from 0 to number of vertices and check if the node is unvisited in previous DFS then call the recursive function with current node.

O(V + E) , O(V).

```
void Graph::DFSUtil(int v, bool visited[]) 
{ 
	visited[v] = true; 
	cout << v << " "; 

	list<int>::iterator i; 
	for(i = adj[v].begin(); i != adj[v].end(); ++i) 
		if(!visited[*i]) 
			DFSUtil(*i, visited); 
} 

void Graph::DFS() 
{  
	bool *visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 

	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			DFSUtil(i, visited); 
} 
```