# Ternery Search

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
