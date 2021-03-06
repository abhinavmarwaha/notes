
# Binary Search

*requirements* : sorted array
*time* : theta(logn) <T(n) = T(n/2) + c >
*Auxiliary Space*: O(1) -> iterative, O(Logn) -> recursion

### Problem -> m = (l+r)/2 might overflow 

use -> mid = low + ((high - low) / 2); 

in java .. faster -> mid = (low + high) >>> 1; 

in c++ ... -> mid = ((unsigned int)low + (unsigned int)high)) >> 1 

http://locklessinc.com/articles/binary_search/ ----> above solutions may not always work.

The above problem occurs when array length is 230 or greater and the search repeatedly moves to second half of the array. This much size of array is not likely to appear most of the time. For example, when we try the below program with 32 bit Code Blocks compiler, we get compiler error.

```
int main() 
{ 
	int arr[1<<30]; 
	return 0; 
}
```
error: size of array 'arr' is too large
Even when we try boolean array, the program compiles fine, but crashes when run in Windows 7.0 and Code Blocks 32 bit compiler

```
#include <stdbool.h> 
int main() 
{ 
	bool arr[1<<30]; 
	return 0; 
}

```

Output: No compiler error, but crashes at run time.


### Recursive

```
int binarySearch(int arr[], int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 

        if (arr[mid] == x) 
            return mid; 
  
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
} 
```

### Iterative

```
int binarySearch(int arr[], int l, int r, int x) 
{ 
    while (l <= r) { 
        int m = l + (r - l) / 2; 
  
        if (arr[m] == x) 
            return m; 
  
        if (arr[m] < x) 
            l = m + 1; 
  
        else
            r = m - 1; 
    } 

    return -1; 
} 
```