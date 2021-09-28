# Exponential Search

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