# Sum of 2 = X

Write a program that, given an array A[] of n numbers and another number x, determines whether or not there exist two elements in S whose sum is exactly x. 

### Method 1: Sorting and Two-Pointers technique.

Time Complexity: 
Merge Sort or Heap Sort -> O(nlogn)
Quick Sort -> O(n^2) 
Auxiliary Space: O(n) for merge sort and O(1) for Heap Sort.


```
bool hasArrayTwoCandidates(int A[], int arr_size,
                           int sum)
{
    int l, r;
 
    sort(A, A + arr_size);
 
    l = 0;
    r = arr_size - 1;
    while (l < r) {
        if (A[l] + A[r] == sum)
            return 1;
        else if (A[l] + A[r] < sum)
            l++;
        else 
            r--;
    }
    return 0;
}
```

### Method 2: Hashing

Time Complexity: O(n). 
Auxiliary Space: O(n).

```
void printPairs(int arr[], int arr_size, int sum)
{
    unordered_set<int> s;
    for (int i = 0; i < arr_size; i++) 
    {
        int temp = sum - arr[i];
 
        if (s.find(temp) != s.end())
            cout << "Pair with given sum "
                 << sum << " is (
                           " << arr[i] << ",
                " 
                    << temp << ")" << endl;
 
        s.insert(arr[i]);
    }
}
```

### Method 3: Using remainders of the elements less than x. 

Time Complexity: O(n+x)
Auxiliary Space: O(x)

```
void printPairs(int a[], int n, int x)
{
      int i;
    int rem[x];

    for (i = 0; i < x; i++) 
    {
        rem[i] = 0;
    }

    for (i = 0; i < n; i++) 
    {
        if (a[i] < x) 
        {
            rem[a[i] % x]++;
        }
    }

    for (i = 1; i < x / 2; i++) 
    {
        if (rem[i] > 0 && rem[x - i] > 0) 
        {
            cout << "Yes"
                 << "\n";
            break;
        }
    }
   
    if (i >= x / 2) 
    {
        if (x % 2 == 0) 
        {
            if (rem[x / 2] > 1) 
            {
                cout << "Yes"
                     << "\n";
            }
            else
            {
                cout << "No"
                     << "\n";
            }
        }
        else
        {
            if (rem[x / 2] > 0 && 
                  rem[x - x / 2] > 0)
            {
                cout << "Yes"
                     << "\n";
            }
            else
            {
                cout << "No"
                     << "\n";
            }
        }
    }
}
```