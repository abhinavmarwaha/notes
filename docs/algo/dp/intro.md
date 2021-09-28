# Dynamic Programming

Divide and Conquer with overlapping results.

### Properties

1) Overlapping Subproblems
2) Optimal Substructure

##### Overlapping Subproblems

subproblems overlap and solutions of them are needed again and again.

Binary Search -> ❎

fibonnici -> ✅

Solutions of same subproblems are needed again and again.

```
                        fib(5)
                     /             \
               fib(4)                fib(3)
             /      \                /     \
         fib(3)      fib(2)         fib(2)    fib(1)
        /     \        /    \       /    \
  fib(2)   fib(1)  fib(1) fib(0) fib(1) fib(0)
  /    \
fib(1) fib(0)
```

fib(3) is being called multiple times

*Methods*

a) Memoization (Top Down)

```
int fib(int n)  
{  
    if (lookup[n] == NIL)  
    {  
        if (n <= 1)  
            lookup[n] = n;  
        else
            lookup[n] = fib(n - 1) + fib(n - 2);  
}  
```

b) Tabulation (Bottom Up)

```
int fib(int n) 
{ 
  int f[n+1]; 
  int i; 
  f[0] = 0;   f[1] = 1;  
  for (i = 2; i <= n; i++) 
      f[i] = f[i-1] + f[i-2]; 
  
  return f[n]; 
} 
```

*Comparison*

| Memotisation | Tabular      |
|--------------|--------------|
| Top down     | bottom up    |
| on demand    | all          |

```
fib(40) tabulated ->  0.000066 sec
fib(40) memotised -> 0.000047
fib(40) naive recursive -> 0.938955 
```

##### Optimal Substructure

Optimal(problem) == Optimal(Union of subproblems)

Longest Path  -> ❎

Shortest path -> ✅
