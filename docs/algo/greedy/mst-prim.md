# Prim's MST

O(V^2) , O(V)

Starts empty spanning tree. 
maintain two sets of vertices.
first set -> included in mst, otherwise second set. 
Min weight edge from all edges that connects the sets
After picking the edge, it moves the other endpoint of the edge to the set containing MST. 
A group of edges that connects two set of vertices in a graph is called cut in graph theory. 
So, at every step of Prim’s algorithm, we find a cut (of two sets, one contains the vertices already included in MST and other contains rest of the vertices), pick the minimum weight edge from the cut and include this vertex to MST Set (the set that contains already included vertices).
How does Prim’s Algorithm Work? The idea behind Prim’s algorithm is simple, a spanning tree means all vertices must be connected. So the two disjoint subsets (discussed above) of vertices must be connected to make a Spanning Tree. And they must be connected with the minimum weight edge to make it a Minimum Spanning Tree.

1. Create a set mstSet that keeps track of vertices already included in MST. 
2. Assign a key value to all vertices in the input graph. Initialize all key values as INFINITE. Assign key value as 0 for the first vertex so that it is picked first. 
3. While mstSet doesn’t include all vertices 
   1.  Pick a vertex u which is not there in mstSet and has minimum key value. 
   2.  Include u to mstSet. 
   3.  Update key value of all adjacent vertices of u. To update the key values, iterate through all adjacent vertices. For every adjacent vertex v, if weight of edge u-v is less than the previous key value of v, update the key value as weight of u-v

The idea of using key values is to pick the minimum weight edge from cut. The key values are used only for vertices which are not yet included in MST, the key value for these vertices indicate the minimum weight edges connecting them to the set of vertices included in MST. 

```
#define V 5 
 
int minKey(int key[], bool mstSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 

void printMST(int parent[], int graph[V][V]) 
{ 
	cout<<"Edge \tWeight\n"; 
	for (int i = 1; i < V; i++) 
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
} 

void primMST(int graph[V][V]) 
{ 
	int parent[V]; 

	int key[V]; 
	
	bool mstSet[V]; 

	for (int i = 0; i < V; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 

	key[0] = 0; 
	parent[0] = -1;

	for (int count = 0; count < V - 1; count++)
	{  
		int u = minKey(key, mstSet); 

		mstSet[u] = true; 

		for (int v = 0; v < V; v++) 

			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 

	printMST(parent, graph); 
} 

int main() 
{ 
	/* 
		2 3 
	(0)--(1)--(2) 
	| / \ | 
	6| 8/ \5 |7 
	| / \ | 
	(3)-------(4) 
			9	 */
	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; 
	primMST(graph); 

	return 0; 
} 
```