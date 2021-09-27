# Selection Sort

*Time* : O(n2)
*Space* : O(1)

* it never makes more than O(n) swap
* useful when memory write is a costly operation.
* not stable, in place

```
Input : 4A 5 3 2 4B 1
Output : 1 2 3 4B 4A 5
```
Swapping might impact in pushing a key(let’s say A) to a position greater than the key(let’s say B) which are equal keys. which makes them out of desired order.

if want stable ->

Selection sort can be made Stable if instead of swapping, the minimum element is placed in its position without swapping i.e. by placing the number in its position by pushing every element one step forward.

```
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
        
        swap(&arr[min_idx], &arr[i]);  
    }  
} 
```

## Stable

```
void stableSelectionSort(int a[], int n) 
{ 
    for (int i = 0; i < n - 1; i++)  
    { 
  
        int min = i; 
        for (int j = i + 1; j < n; j++) 
            if (a[min] > a[j]) 
                min = j; 
  
        int key = a[min]; 
        while (min > i)  
        { 
            a[min] = a[min - 1]; 
            min--; 
        } 
        a[i] = key; 
    } 
} 
```

# Bubble sort

*optimisation* :  O(n^2) time even if the array is sorted. It can be optimized by stopping the algorithm if inner loop didn’t cause any swap.

```
void bubbleSort(int arr[], int n)  
{  
    int i, j;  
    for (i = 0; i < n-1; i++)      
       
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  
```

Worst and Average Case Time Complexity: O(n*n). Worst case occurs when array is reverse sorted.

Best Case Time Complexity: O(n). Best case occurs when array is already sorted.

Auxiliary Space: O(1)

Boundary Cases: Bubble sort takes minimum time (Order of n) when elements are already sorted.

Sorting In Place: Yes
Stable: Yes

In computer graphics it is popular for its capability to detect a very small error (like swap of just two elements) in almost-sorted arrays and fix it with just linear complexity (2n). For example, it is used in a polygon filling algorithm, where bounding lines are sorted by their x coordinate at a specific scan line (a line parallel to x axis) and with incrementing y their order changes (two elements are swapped) only at intersections of two lines.


# Insertion Sort

```
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1; 
        
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}

```

Time Complexity: O(n*2)

Auxiliary Space: O(1)

Boundary Cases: Insertion sort takes maximum time to sort if elements are sorted in reverse order. And it takes minimum time (Order of n) when elements are already sorted.

Algorithmic Paradigm: Incremental Approach

Sorting In Place: Yes

Stable: Yes

Online: Yes

Uses: Insertion sort is used when number of elements is small. It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

What is Binary Insertion Sort?
We can use binary search to reduce the number of comparisons in normal insertion sort. Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration. In normal insertion, sorting takes O(i) (at ith iteration) in worst case. We can reduce it to O(logi) by using binary search. The algorithm, as a whole, still has a running worst case running time of O(n2) because of the series of swaps required for each insertion. Refer this for implementation.

How to implement Insertion Sort for Linked List?
Below is simple insertion sort algorithm for linked list.

1) Create an empty sorted (or result) list
2) Traverse the given list, do following for every node.
......a) Insert current node in sorted way in sorted or result list.
3) Change head of given linked list to head of sorted (or result) list. 



# Lower bound for comparison based sorting

Input: <a1, a2, . . . , an>.
Output: permutation / reordering ->  <a‘1, a‘2, . . . , a‘n> when a‘1 <= a‘2 ….. <= a‘n.

* uses comparison operators
* decision trees.
* A decision tree -> full binary tree that represents the comparisons between elements that are performed by a particular sorting algorithm operating on an input of a given size. 
* tracing a path from the root of the decision tree to a leaf.
* At each internal node, a comparison ai <= aj is made. 
* left subtree -> ai <= aj.
* right subtree -> ai > aj.
* When reach leaf, ordering is done.

1) n! permutations on n -> leaves for the sorting algorithm to sort properly.
2) x -> maximum number
3) maximum height of the decison tree_ -> x. 
4) A tree with maximum height x has at most 2^x leaves.
  
    n!  <= 2^x

 Taking Log on both sides.

    log2(n!)  <= x

As log2(n!) = Θ(nLogn) => x = Ω(nLog2n)

Hence Heapsort, merge sort -> asymptotically optimal comparison sorts.

# minimum number of memory writes?

Some huge data set is very expensive -> EEPROMs or Flash memory -> each write reduces the lifespan of the memory.

Selection Sort makes least number of writes (it makes O(n) swaps).  

Cycle Sort -> zero times -> correct position or written one time to its correct position.

*Hence Cycle Sort* 

