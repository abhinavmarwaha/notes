# Frequency of a Number

### simple

```
void countFreq(int arr[], int n)
{
    vector<bool> visited(n, false);
 
    for (int i = 0; i < n; i++) {
 
        if (visited[i] == true)
            continue;
 
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}

```

### Sort then Binary search

### Hashing

```
void countFreq(int arr[], int n)
{
    unordered_map<int, int> mp;
 
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;
 
    for (auto x : mp)
        cout << x.first << " " << x.second << endl;
}
```