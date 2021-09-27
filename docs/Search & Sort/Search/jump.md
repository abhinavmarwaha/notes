
## Jump Search

*requirements* : sorted array
*time* : O(√n)
*space* : O(1)

Find arr[km] < x < arr[(k+1)m] then perform linear search

* Optimal Jump Size -> m = root(n) -> min<(n/m) + m-1)>

O(n)  > jump >  O (Log n)

Binary Search > Jump Search

element smallest or largest -> jump better we traverse once.


```
int jumpSearch(int arr[], int x, int n) 
{  
    int step = sqrt(n); 
  
    int prev = 0; 
    while (arr[min(step, n)-1] < x) 
    { 
        prev = step; 
        step += sqrt(n); 
        if (prev >= n) 
            return -1; 
    } 
  

    while (arr[prev] < x) 
    { 
        prev++; 
  
        if (prev == min(step, n)) 
            return -1; 
    } 

    if (arr[prev] == x) 
        return prev; 
  
    return -1; 
} 
```