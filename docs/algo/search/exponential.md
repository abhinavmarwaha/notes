## Exponential Search

*Time* : O(Log n) 
*Space* : O(Log n) / O(1) 

*useful* :

* for unbounded searches, where size of array is infinite.
* search is closer to the first element

*Idea* :

* Find range where element is present
* Do Binary Search in above found range.

How to find the range where element may be present? 

The idea is to start with subarray size 1, compare its last element with x, then try size 2, then 4 and so on until last element of a subarray is not greater. 
Once we find an index i (after repeated doubling of i), we know that the element must be present between i/2 and i (Why i/2? because we could not find a greater value in previous iteration)

```
int exponentialSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0;
 
    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
 
    return binarySearch(arr, i/2, 
                            min(i, n-1), x);
}
```

## Ternery Search

The following is recursive formula for counting comparisons in worst case of Binary Search.

   T(n) = T(n/2) + 2,  T(1) = 1

The following is recursive formula for counting comparisons in worst case of Ternary Search.

   T(n) = T(n/3) + 4, T(1) = 1

In binary search, there are 2Log2n + 1 comparisons in worst case. In ternary search, there are 4Log3n + 1 comparisons in worst case.

Time Complexity for Binary search = 2clog2n + O(1)
Time Complexity for Ternary search = 4clog3n + O(1)
Therefore, the comparison of Ternary and Binary Searches boils down the comparison of expressions 2Log3n and Log2n . The value of 2Log3n can be written as (2 / Log23) * Log2n . Since the value of (2 / Log23) is more than one, Ternary Search does more comparisons than Binary Search in worst case.

Exercise:
Why Merge Sort divides input array in two halves, why not in three or more parts?

```
int ternarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid1 = l + (r - l)/3; 
        int mid2 = mid1 + (r - l)/3; 
  
        if (arr[mid1] == x)  return mid1; 
  
        if (arr[mid2] == x)  return mid2; 

        if (arr[mid1] > x) return ternarySearch(arr, l, mid1-1, x); 
  
        if (arr[mid2] < x) return ternarySearch(arr, mid2+1, r, x); 
  
        return ternarySearch(arr, mid1+1, mid2-1, x); 
   }
   
   return -1; 
}
```
