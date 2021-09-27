# Graph

### Properties

1. finite set of vertices -> nodes
2. set of ordered pair (u,v) telling aedge bw vertex v and u.
3. f(u,v) weight/value/cost.

### Applications

networks -> facebook, node has person info.

### Representation

1. Adjacency List
2. Adjacency Matrix
3. Incidence Matrix 
4. Incidence List

__Depends on use case__ -> type of operations

### Adjacency matrix

![Adjacency Matrix](img/adjacency-matrix.png)

2D array of size V x V
adj[i][j] = 1, adj[i][j] = w

##### Pros

deletion, isThereAnEdge -> O(1)

##### Cons

space -> O(V^2) even matrix is sparse
inserting an edge -> O(V^2)

### Adjacency List

![Adjacency List](img/adjacency-list.png)

array[i] -> list of vertices adjacent to ith vertex.
Weights -> as lists of pairs

##### Pros 

* Saves space O(|V|+|E|)
* worst case -> O(V^2) 
* Adding a vertex is easier

##### Cons

isThereAnEdge -> O(V)

```
#include <iostream> 
#include <vector> 
using namespace std; 

void addEdge(vector<int> adj[], int u, int v) { 
	adj[u].push_back(v); 
	adj[v].push_back(u); 
} 
 
void printGraph(vector<int> adj[], int V){ 
	for (int v = 0; v < V; ++v) { 
		cout << "\n Adjacency list of vertex "
			<< v << "\n head "; 
		for (auto x : adj[v]) 
		cout << "-> " << x; 
		printf("\n"); 
	} 
} 

int main(){

	int V = 5; 
	vector<int> adj[V]; 
	addEdge(adj, 0, 1); 
	addEdge(adj, 0, 4); 
	addEdge(adj, 1, 2); 
	addEdge(adj, 1, 3); 
	addEdge(adj, 1, 4); 
	addEdge(adj, 2, 3); 
	addEdge(adj, 3, 4); 
	printGraph(adj, V); 
	return 0; 
}
```
