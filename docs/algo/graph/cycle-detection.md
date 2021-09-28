// https://www.geeksforgeeks.org/union-find/
// https://ide.geeksforgeeks.org/hB3sIlWa48
// O(E^2) , parent array O(n)
// NOTE: using disjoint and uninion-find algo

// 0   1   2
// -1 -1  -1 

// 0   1   2    <----- 1 is made parent of 0 (1 is now representative of subset {0, 1})
// 1  -1  -1

// 0   1   2    <----- 2 is made parent of 1 (2 is now representative of subset {0, 1, 2})
// 1   2  -1

#include<iostream>
#include<cstring>
using namespace std;

class Edge {
    public:
    int src, dest;
};

class Graph{
    public:
    int V, E;
    Edge* edges;
};

Graph* createGraph(int V, int E){
    Graph* graph = new Graph();
    graph->V = V;
    graph->E = E;
    graph->edges = new Edge[graph->E * sizeof(Edge)];
    return graph;
}

int find(int parent[], int i){ // takes O(n) if skewed
    if(parent[i]==-1)
        return i;
    return find(parent, parent[i]);
}

void Union(int parent[], int x, int y){ // takes O(n) if skewed
    int xset = find(parent, x);
    int yset = find(parent, y);

    if(xset!=yset){
        parent[xset] = yset;
    }
}

bool isCycle(Graph* graph){ 
    int *parent = new int[graph->V * sizeof(int)];
    memset(parent,-1,graph->V * sizeof(int));
    for (int i = 0; i < graph->E; i++){
        int x = find(parent, graph->edges[i].src);
        int y = find(parent, graph->edges[i].dest);
        if(x == y){
            return 1;
        }

        Union(parent, x, y);
    }

    return 0;
}


int main(){
    /*   0  
        | \  
        |  \  
        1---2 */

    int V=3, E=3;
    Graph* graph = createGraph(V,E);

    graph->edges[0].src = 0;  
    graph->edges[0].dest = 1;  
  
    graph->edges[1].src = 1;  
    graph->edges[1].dest = 2;  
  
    graph->edges[2].src = 0;  
    graph->edges[2].dest = 2;  
  
    if (isCycle(graph))  
        cout<<"graph contains cycle";  
    else
        cout<<"graph doesn't contain cycle";

    return 0;
}



// <gfg link>
// https://ide.geeksforgeeks.org/GYaaRIEaD8
// O(nlogn + V) , subsets O(n)
// NOTE: find and union takes O(n) due to union by rank and path compression
//      This technique is called union by rank. The term rank is preferred instead of height because 
//      if path compression technique is used, then rank is not always equal to height. 
// Path Compression. The idea is to flatten the tree when find() is called.

// Also, size (in place of height) of trees can also be used as rank. Using size as rank also yields worst case time complexity as O(Logn)




#include<iostream>
using namespace std;

struct Edge{
    int src, dest;
};


struct Graph{
    int E, V;
    Edge * Edges;
};

struct subset{
    int parent;
    int rank;
};

Graph* createGraph(int E, int V){

    Graph* graph = (Graph*)malloc(sizeof(struct Graph));
    graph->E = E;
    graph->V = V;
    graph->Edges = (Edge*)malloc(sizeof(Edge)*graph->E);
    return graph;

}

int Find(struct subset subsets[], int i){ // takes O(logn)
    if(subsets[i].parent!=i)
        return Find(subsets, subsets[i].parent);
    
    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y){ // takes O(logn)
    int xset = Find(subsets, x);
    int yset = Find(subsets, y);
    if(subsets[xset].rank <= subsets[yset].rank){
        subsets[xset].parent = yset;
    }
    else if(subsets[xset].rank > subsets[yset].rank){
        subsets[yset].parent = xset;
    }
    else {
        subsets[yset].parent = xset;
        subsets[xset].rank++;
    }

}

bool isCycle(Graph* graph){

    int V = graph->V;
    int E = graph->E;

    struct subset* subsets = (struct subset*) malloc(sizeof(subset)*V);

    for(int v =0; v<V; v++){
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    for(int e=0; e<E; e++){

        int x = Find(subsets, graph->Edges[e].src);
        int y = Find(subsets, graph-> Edges[e].dest);

        if(x==y)
            return 1;

        Union(subsets, x, y);

    }


    return 0;
}


int main() 
{ 
    /*
         0 
        |  \ 
        |    \ 
        1-----2 */
  
    int V = 3, E = 3; 
    struct Graph* graph = createGraph(V, E); 
  
    // add 0-1 
    graph->Edges[0].src = 0; 
    graph->Edges[0].dest = 1; 
  
    // add 1-2 
    graph->Edges[1].src = 1; 
    graph->Edges[1].dest = 2; 
  
    // add 0-2 
    graph->Edges[2].src = 0; 
    graph->Edges[2].dest = 2; 
  
    if (isCycle(graph)) 
        printf( "Graph contains cycle" ); 
    else
        printf( "Graph doesn't contain cycle" ); 
  
    return 0; 
}