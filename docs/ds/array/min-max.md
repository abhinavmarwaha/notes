# Min Max 

### Recursive

```
int getMin(int arr[], int n)
{
	return (n == 1) ? arr[0] : min(arr[0],
						getMin(arr + 1, n - 1));
}

int getMax(int arr[], int n)
{
	return (n == 1) ? arr[0] : max(arr[0],
						getMax(arr + 1, n - 1));
}

```

### Library Functions

```
int getMin(int arr[], int n)
{
	return *min_element(arr, arr + n);
}

int getMax(int arr[], int n)
{
	return *max_element(arr, arr + n);
}

```