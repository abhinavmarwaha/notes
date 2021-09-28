# Topological Sort

O(V+E) , O(V)

* Directed Acyclic Graph (DAG)
* for every directed edge uv, vertex u comes before v in the ordering.
* first element -> in-degree as 0 (a vertex with no incoming edges).
* can be more than one sorting
* different from DFS

### Application

* Instruction scheduling
* ordering of formula cell evaluation when recomputing formula values in spreadsheets
* logic synthesis,
* determining the order of compilation tasks to perform in makefiles
* data serialization
* resolving symbol dependencies in linkers

```
sortUtil(int v, bool visited[], stack<int> &Stack){
    visited[v] = true;

    list<int>::iterator i;
    for(i = adj[v].begin(); i!=adj[v].end(); ++i){
        if(!visited[v])
            sortUtil(v, visited, Stack);
    }

    Stack.push(v);
}

topologicalSort(int v){
    stack<int> Stack;

    bool *visited = new bool[V];
    for(int i = 0; i<V; i++)
        visited[i] = false;
    
    for(int i=0;i<V;i++)
        if(visited[i]==false)
            sortUtil(i, visited, Stack);
    
    while(Stack.empty() == false){
        cout << Stack.pop() << " ";
        Stack.pop();
    }
}
```