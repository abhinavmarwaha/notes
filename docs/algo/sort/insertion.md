
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

### Uses

* number of elements is small. 
* It can also be useful when input array is almost sorted, only few elements are misplaced in complete big array.

### Binary Insertion Sort

* We can use binary search to reduce the number of comparisons in normal insertion sort. 
* Binary Insertion Sort uses binary search to find the proper location to insert the selected item at each iteration. 
* In normal insertion, sorting takes O(i) (at ith iteration) in worst case. We can reduce it to O(logi) by using binary search. 
* The algorithm, as a whole, still has a running worst case running time of O(n2) because of the series of swaps required for each insertion.

### Insertion Sort for Linked List

1. Create an empty sorted (or result) list
2. Traverse the given list, do following for every node.
   1. Insert current node in sorted way in sorted or result list.
3. Change head of given linked list to head of sorted list. 