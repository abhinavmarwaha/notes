# Subset of Array

Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not. Both the arrays are not in sorted order. It may be assumed that elements in both array are distinct.


### Method 1 -> simple (2 loops)

O(m*n)

```
bool isSubset(int arr1[], int arr2[],
              int m, int n)
{
    int i = 0;
    int j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }

        if (j == m)
            return 0;
    }
 
    return 1;
}
```

### Method 2 -> sorting and binary search

O(mLogm + nLogm). -> merge sort, quick sort -> O(m^2)

```
bool isSubset(int arr1[], int arr2[],
              int m, int n)
{
    int i = 0;
 
    quickSort(arr1, 0, m - 1);
    for (i = 0; i < n; i++) {
        if (binarySearch(arr1, 0, m - 1,
                         arr2[i])
            == -1)
            return 0;
    }

    return 1;
}
 

```

### Method 3 -> sorting and merging

 O(mLogm + nLogn) 

```
bool isSubset(int arr1[], int arr2[], int m, int n)
{
    int i = 0, j = 0;
 
    if (m < n)
        return 0;
 
    sort(arr1, arr1 + m);
    sort(arr2, arr2 + n);
 
    while (i < n && j < m) {
        if (arr1[j] < arr2[i])
            j++;
        else if (arr1[j] == arr2[i]) {
            j++;
            i++;
        }
 
        else if (arr1[j] > arr2[i])
            return 0;
    }
 
    return (i < n) ? false : true;
}
 
```

### Method 4 -> Hashing

```
bool isSubset(int arr1[], int m, int arr2[], int n) { 
   
  set<int>hashset;
   
  for(int i=0;i<m;i++) { 
    hashset.insert(arr1[i]); 
  }
   
  for(int i=0;i<n;i++) {
    if(hashset.find(arr2[i])==hashset.end()) 
      return false;
  } 
  return true; 
}
 
```

Note that method 1, method 2 and method 4 don’t handle the cases when we have duplicates in arr2[]. For example, {1, 4, 4, 2} is not a subset of {1, 4, 2}, but these methods will print it as a subset.  
