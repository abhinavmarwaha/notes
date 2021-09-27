# Priority Queue

### Queue with properties:

1. every element has apriority
2. dequeue removes element with highest priority
3. 2 elements with same priority... deletes in the order of queueing
   
### Operations 

* insert(item, priority)
* getHighestPriority():
* deleteHighestPriority()

### Implementation

```
struct item {
   int item;
   int priority;
}
```

##### Arrays

* insert -> O(1)
* getHighest -> linear traversal (O(n))
* deleteHighestPriority -> need to move elements O(n)

##### Linked List

* delete is efficient as no need to move 
  
##### Heap

* best
* insert, delete -> O(logn)
* highest -> O(1)

<!-- TODO https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/ -->

# Applications

1. CPU Scheduling
2. Graph algorithms like Dijkstra’s shortest path algorithm, Prim’s Minimum Spanning Tree, etc
3. All queue applications where priority is involved.