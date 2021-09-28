# Quick Sort

T(n) = T(k) + T(n-k-1) + theta(n)

Worst Case: greatest or smallest element as pivot-> already sorted in increasing or decreasing order:

T(n) = T(n-1) + theta(n) == theta(n^2).

Best Case:always picks the middle element as pivot

T(n) = 2T(n/2) + theta(n) == theta(nLogn)

### Average Case:

all possible permutation of array and calculate time taken by every permutation which doesn’t look easy.

by considering the case when partition puts O(n/9) elements in one set and O(9n/10) elements in other set.

 T(n) = T(n/9) + T(9n/10) + theta(n) ==  O(nLogn)

### Disadvantages

* worst case -> worse than others
* merge sort -> when data is huge and stored in external storage.

### Advantages

* faster in practice -> inner loop can be efficiently implemented on most architectures and in most real-world data. 
* cache friendly -> good locality of reference when used for arrays.
* tail recursive, therefore tail call optimizations is done.
* requires no extra space -> merge sort requires..... averrage O(nlogn) similar


### Stable

nope

### In-place?

space -> recursive function calls but not for manipulating the input. *hence in-place*

### 3-Way QuickSort?

*For redundant data*

{1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4}

1. arr[l..i] < pivot.
2. arr[i+1..j-1] == pivot.
3. arr[j..r] > pivot.

see __Singly Linked List, Doubly Linked List, Iterative Implementation__


### Why MergeSort for Linked Lists?

* merge sort -> without extra space for linked lists.
* overhead increases for quick sort in linked list -> as A[i] is required and direct access is costly.

### When does worst case occur

* depends on strategy of choosing pivot.
* when rightmost or leftmost -> array is reverse / sorted -> all same (special case)
* whenever max , min is chosen

##### Solution?

* random
* middle
* median of first, middle and last

```

int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high];
	int i = (low - 1); 

	for (int j = low; j <= high - 1; j++) 
	{ 
		if (arr[j] < pivot) 
		{ 
			i++;
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{
		int pi = partition(arr, low, high); 

		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 
```

T(n) = T(k) + T(n-k-1) + \theta(n), T(n) = T(n-1) + \theta(n) ---  T(n) = 2T(n/2) + \theta(n) O(n^2) - O(nlogn), O(1)

Although the worst case time complexity of QuickSort is O(n2) which is more than many other sorting algorithms like Merge Sort and Heap Sort, QuickSort is faster in practice, because its inner loop can be efficiently implemented on most architectures, and in most real-world data. QuickSort can be implemented in different ways by changing the choice of pivot, so that the worst case rarely occurs for a given type of data. However, merge sort is generally considered better when data is huge and stored in external storage.

inplace, not stable.

Related: 3 way quicksort: https:www.geeksforgeeks.org/3-way-quicksort/, iterative, linked list , doubly linked list

Quick sort vs merge sort?

merge sortrequires O(n) space complexity, casche friendly

Randomised Quicksort - average O(nlogn) - worst doesn't occur in patterns like sorted or not.

tail recursiv - tail optimisation is done.

linked list - merge sort as random access for qsort is not feasable in linked list.

```
int partition (int arr[], int low, int high) 
{ 
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) 
	{ 
		if (arr[j] < pivot) 
		{ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

void quickSort(int arr[], int low, int high) 
{ 
	if (low < high) 
	{ 
		int pi = partition(arr, low, high); 

		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
	} 
} 
```