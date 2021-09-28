# Selection Sort

*Time* : O(n2)
*Space* : O(1)

* it never makes more than O(n) swap
* useful when memory write is a costly operation.
* not stable, in place

```
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

```
Input : 4A 5 3 2 4B 1
Output : 1 2 3 4B 4A 5
```

Swapping might impact in pushing a key(let’s say A) to a position greater than the key(let’s say B) which are equal keys. which makes them out of desired order.

### Stable

Selection sort can be made Stable if instead of swapping, the minimum element is placed in its position without swapping i.e. by placing the number in its position by pushing every element one step forward.

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
