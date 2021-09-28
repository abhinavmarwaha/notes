# K Distance Duplicate

Given an unsorted array that may contain duplicates. Also given a number k which is smaller than size of array. Write a function that returns true if array contains duplicates within k distance.

### Method 1 -> 2 loops -> O(kn)

### Method 2 -> Hashing

Θ(n)

```
bool checkDuplicatesWithinK(int arr[], int n, int k) 
{ 
    unordered_set<int> myset; 
  
    for (int i = 0; i < n; i++) 
    {  
        if (myset.find(arr[i]) != myset.end()) 
            return true; 
  
        myset.insert(arr[i]); 
  
        if (i >= k) 
            myset.erase(arr[i-k]); 
    } 
    return false; 
}
```