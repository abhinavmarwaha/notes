# Caching

Ignoring the compiler optimizations, which of the two is better implementation of sum?

```
int fun1(int arr[R][C]) 
{ 
    int sum = 0; 
    for (int i=0; i<R; i++) 
      for (int j=0; j<C; j++) 
          sum += arr[i][j]; 
} 

int fun2(int arr[R][C]) 
{ 
    int sum = 0; 
    for (int j=0; j<C; j++) 
      for (int i=0; i<R; i++) 
          sum += arr[i][j]; 
}
```

In C/C++, elements are stored in Row-Major order. So the first implementation has better spatial locality (nearby memory locations are referenced in successive iterations). Therefore, first implementation should always be preferred for iterating multidimensional arrays.