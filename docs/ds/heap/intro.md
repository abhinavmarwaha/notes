# Binary Heap

* Complete Binary Tree <Efficient in storing in array>
* Max Heap <root = min(left, right)> AND Min Heap <root = max(left, right)>

### Representaion

##### Arrays

root -> Arr[0].

For Arr[i]:

Arr[(i-1)/2] -> parent node
Arr[(2*i)+1] -> left child node
Arr[(2*i)+2] -> right child node

##### Traversal

Level order aka Breadth First as storage is same.

##### Operations 

1. *getMin():* returns root. <O(1)>
2. *extractMin():* Removes minimum. <O(Logn)> as it calls heapify() after removing root. <Mantaining Heap Property>
3. *decreaseKey():*

* Decreases value of key. <O(Logn)> 
* IF key value > parent THEN do anything. 
* ELSE, traverse up to fix the violated heap property.

4. *insert()*: New key <O(Logn)> 

* Add a new key at the end of the tree.
* IF new key is greater than its parent, do nothing.
* Otherwise, traverse up to maintain heap property.

5. *delete():* Deleting a key <O(Logn)>

* We replace the key to be deleted with minum infinite by calling decreaseKey(). 
* After decreaseKey(), 
* the minus infinite value must reach root,
* so we call extractMin() to remove the key.

### Application

1. *Heap Sort*: Heap Sort uses Binary Heap to sort an array in O(nLogn) time.
2. *Priority Queue*: Priority queues can be efficiently implemented using Binary Heap because it supports insert(), delete() and extractmax(), decreaseKey() operations in O(logn) time.  
3. *Binomoial Heap* and *Fibonacci Heap* are variations of Binary Heap. These variations perform __union__ also efficiently.
4. *Graph Algorithms*: priority queues -> Dijkstra’s Shortest Path, Prim’s Minimum Spanning Tree.
5.
   a. K’th Largest Element in an array.
   b. Sort an almost sorted array / Merge K Sorted Arrays.

### Why is Binary Heap Preferred over BST for Priority Queue?

A typical Priority Queue requires following operations to be efficient.

1. Get Top Priority Element (Get minimum or maximum)
2. Insert an element
3. Remove top priority element
4. Decrease Key

A Binary Heap supports above operations with following time complexities:

1. O(1)
2. O(Logn)
3. O(Logn)
4. O(Logn)

A Self Balancing Binary Search Tree like AVL Tree, Red-Black Tree, etc can also support above operations with same time complexities.

* Finding minimum and maximum are not naturally O(1), but can be easily implemented in O(1) by keeping an extra pointer to minimum or maximum and updating the pointer with insertion and deletion if required. With deletion we can update by finding inorder predecessor or successor.
* Inserting an element is naturally O(Logn)
* Removing maximum or minimum are also O(Logn)
* Decrease key can be done in O(Logn) by doing a deletion followed by insertion.

*So why is Binary Heap Preferred for Priority Queue?*

1. arrays-> locallity of refernence -> cache friendliness
2. constants in Binary Search Tree are higher.
3. constructing Binary Heap -> O(n)  Self Balancing BSTs -> O(nLogn)
4. Binary Heap doesn’t require extra space for pointers.
5. Binary Heap is easier to implement.
6. TFibonacci Heap -> insert and decrease-key -> Θ(1) time

*Is Binary Heap always better?*

Although Binary Heap is for Priority Queue, BSTs have their own advantages and the list of advantages is in-fact bigger compared to binary heap.

1. Searching an element in self-balancing BST is O(Logn) which is O(n) in Binary Heap.
2. We can print all elements of BST in sorted order in O(n) time, but Binary Heap requires O(nLogn) time.
3. Floor and ceil can be found in O(Logn) time.
4. K’th largest/smallest element be found in O(Logn) time by augmenting tree with an additional field.

```
// 0(logn) , O(n)

#include<iostream> 
#include<climits> 
using namespace std; 

void swap(int *x, int *y); 

class MinHeap 
{ 
	int *harr;
	int capacity; 
	int heap_size; 

public: 

	MinHeap(int capacity); 

	void MinHeapify(int ); 

	int parent(int i) { return (i-1)/2; } 

	int left(int i) { return (2*i + 1); } 

	int right(int i) { return (2*i + 2); } 

	int extractMin(); 

	void decreaseKey(int i, int new_val); 

	int getMin() { return harr[0]; } 

	void deleteKey(int i); 

	void insertKey(int k); 
}; 

MinHeap::MinHeap(int cap) 
{ 
	heap_size = 0; 
	capacity = cap; 
	harr = new int[cap]; 
} 

void MinHeap::insertKey(int k) // O(logn)
{ 
	if (heap_size == capacity) 
	{ 
		cout << "\nOverflow: Could not insertKey\n"; 
		return; 
	} 

	heap_size++; 
	int i = heap_size - 1; 
	harr[i] = k; 

	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
        swap(&harr[i], &harr[parent(i)]); 
        i = parent(i); 
	} 
} 

void MinHeap::decreaseKey(int i, int new_val) // O(logn)
{ 
	harr[i] = new_val; 
	while (i != 0 && harr[parent(i)] > harr[i]) 
	{ 
        swap(&harr[i], &harr[parent(i)]); 
        i = parent(i); 
	} 
} 

int MinHeap::extractMin() // O(logn)
{ 
	if (heap_size <= 0) 
		return INT_MAX; 
	if (heap_size == 1) 
	{ 
		heap_size--; 
		return harr[0]; 
	} 

	int root = harr[0]; 
	harr[0] = harr[heap_size-1]; 
	heap_size--; 
	MinHeapify(0); 

	return root; 
} 


void MinHeap::deleteKey(int i) // O(logn)
{ 
	decreaseKey(i, INT_MIN); 
	extractMin(); 
} 


void MinHeap::MinHeapify(int i) // O(logn)
{ 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heap_size && harr[l] < harr[i]) 
		smallest = l; 
	if (r < heap_size && harr[r] < harr[smallest]) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swap(&harr[i], &harr[smallest]); 
		MinHeapify(smallest); 
	} 
} 

void swap(int *x, int *y) 
{ 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

int main() 
{ 
	MinHeap h(11); 
	h.insertKey(3); 
	h.insertKey(2); 
	h.deleteKey(1); 
	h.insertKey(15); 
	h.insertKey(5); 
	h.insertKey(4); 
	h.insertKey(45); 
	cout << h.extractMin() << " "; 
	cout << h.getMin() << " "; 
	h.decreaseKey(2, 1); 
	cout << h.getMin(); 
	return 0; 
}
```