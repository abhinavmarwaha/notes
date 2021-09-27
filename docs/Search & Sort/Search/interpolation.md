
## interpolation Search

*requirements* : sorted array
*time* : uniformly distributed -> O (log log n). worst case -> O(n).
*space* : O(1)

Improved over binary when the data is uniformaly distributed

pos = lo + [ (x-arr[lo])*(hi-lo) / (arr[hi]-arr[Lo]) ]

### Iterative

```
int interpolationSearch(int arr[], int n, int x) 
{ 
    int lo = 0, hi = (n - 1); 
  
    while (lo <= hi && x >= arr[lo] && x <= arr[hi]) 
    { 
        if (lo == hi) 
        { 
            if (arr[lo] == x) return lo; 
            return -1; 
        } 
        
        int pos = lo + (((double)(hi - lo) / 
            (arr[hi] - arr[lo])) * (x - arr[lo])); 
  
        if (arr[pos] == x) 
            return pos; 
  
        if (arr[pos] < x) 
            lo = pos + 1; 
  
        else
            hi = pos - 1; 
    } 
    return -1; 
} 
```

### Reursive

```
int interpolationSearch(int arr[], int lo,  
                        int hi, int x) 
{ 
    int pos; 

    if ( lo <= hi && x >= arr[lo] && 
                     x <= arr[hi]) 
    {  
          
        pos = lo + (((double)( hi - lo ) / 
                         (arr[hi] - arr[lo])) *  
                               (x - arr[lo])); 
          
        if( arr[pos] == x ) 
            return pos; 
              
        if( arr[pos] < x ) 
            return interpolationSearch(arr, pos + 1, 
                                       hi, x); 
              
        if( arr[pos] > x ) 
            return interpolationSearch(arr, lo,  
                                       pos - 1, x); 
    } 
    return -1; 
} 
```

# Interpolation vs Binary

log(log(n)) comparisons -> uniformly distributed

In the worst case:

(for instance where the numerical values of the keys increase exponentially)

It can make up to O(n) comparisons.