# Examples

```
void fun() 
{ 
   int i, j; 
   for (i=1; i<=n; i++) 
      for (j=1; j<=log(i); j++) 
         printf("GeeksforGeeks"); 
} 
```

Θ(log 1) + Θ(log 2) + Θ(log 3) + . . . . + Θ(log n) 

Θ (log n!) ~ Θ(n log n) for large valusee of n

by Stirling’s approximation (or Stirling’s formula).

log n! = n log n - n + O(log(n)) 

```
void fun(int n) 
{ 
   int j = 1, i = 0; 
   while (i < n) 
   { 
       // Some O(1) task 
       i = i + j; 
       j++; 
   } 
} 
```

x(x+1)/2 after x iterations

then x(x+1)/2 < n ===== Θ(√n).

```
void fun(int n, int k) 
{ 
	for (int i=1; i<=n; i++) 
	{ 
	int p = pow(i, k); 
	for (int j=1; j<=p; j++) 
	{ 
		// Some O(1) work 
	} 
	} 
} 
```

1k + 2k + 3k + … n1k.

```
k=1
Sum = 1 + 2 + 3 ... n 
    = n(n+1)/2 
    = n2/2 + n/2

k=2
Sum = 12 + 22 + 32 + ... n12.
    = n(n+1)(2n+1)/6
    = n3/3 + n2/2 + n/6

k=3
Sum = 13 + 23 + 33 + ... n13.
    = n2(n+1)2/4
    = n4/4 + n3/2 + n2/4     
```

(nk+1)/(k+1) + Θ(nk)

Θ(nk+1 / (k+1)) as can ignore lower terms