# Bits Tricks

### Java

##### >> (Signed right shift)

negative number -> 1 is used as a filler
positive number -> 0 is used as a filler

```
4>>1 -> 2
-4>>1 -> -2
```

##### >>> (Unsigned right shift) 

fills 0

```
-1 >>> 29  ->  00...0111 
-1 >>> 30  ->  00...0011  
-1>>>31 -> 00...0001  
```

### Detect if two integers have opposite signs

##### XOR

```
bool oppositeSigns(int x, int y) 
{ 
    return ((x ^ y) < 0); 
} 
```

##### ternery

```
bool oppositeSigns(int x, int y) 
{ 
    return (x < 0)? (y >= 0): (y < 0); 
} 
```

##### 32 bit ints

```
bool oppositeSigns(int x, int y) 
{ 
    return ((x ^ y) >> 31); 
} 
```

### Count total set bits in all numbers from 1 to n 

A simple solution is to run a loop from 1 to n and sum the count of set bits in all numbers from 1 to n.

```
unsigned int countSetBits(unsigned int n) 
{ 
    int bitCount = 0; 
  
    for (int i = 1; i <= n; i++) 
        bitCount += countSetBitsUtil(i); 
  
    return bitCount; 
} 
  
unsigned int countSetBitsUtil(unsigned int x) 
{ 
    if (x <= 0) 
        return 0; 
    return (x % 2 == 0 ? 0 : 1) + countSetBitsUtil(x / 2); 
} 
```

### Add two numbers without using arithmetic operators

##### iterative 

```
int Add(int x, int y)  
{  
    while (y != 0)  
    {  
        int carry = x & y;  
       
        x = x ^ y;  

        y = carry << 1;  
    }  
    return x;  
}  
  
```

##### Recursive

```
int Add(int x, int y) 
{ 
    if (y == 0) 
        return x; 
    else
        return Add( x ^ y, (x & y) << 1); 
} 
```

### Smallest of three integers without comparison operators

##### Method 1 (Repeated Subtraction)

```
int smallest(int x, int y, int z) 
{ 
    int c = 0; 
    while (x && y && z) { 
        x--; 
        y--; 
        z--; 
        c++; 
    } 
    return c; 
} 
```

##### Method 2 (Use Bit Operations)

```
####define CHAR_BIT 8 

int min(int x, int y) 
{ 
    return y + ((x - y) & ((x - y) >> (sizeof(int) * CHAR_BIT - 1))); 
} 
  
int smallest(int x, int y, int z) 
{ 
    return min(x, min(y, z)); 
}
```

##### Method 3 (Use Division operator)

```
int smallest(int x, int y, int z) 
{ 
    if (!(y / x)) // Same as "if (y < x)" 
        return (!(y / z)) ? y : z; 
    return (!(x / z)) ? x : z; 
}
```

### A Boolean Array Puzzle

Input: A array arr[] of two elements having value 0 and 1

Output: Make both elements 0.
Specifications: Following are the specifications to follow.

1. It is guaranteed that one element is 0 but we do not know its position.
2. We can’t say about another element it can be 0 or 1.
3. We can only complement array elements, no other operation like and, or, multi, division, …. etc.
4. We can’t use if, else and loop constructs.
5. Obviously, we can’t directly assign 0 to array elements.

```
void changeToZero(int a[2])  
{  
    a[ a[1] ] = a[ !a[1] ];  
}  
```

```
void changeToZero(int a[2]) 
{ 
    a[ !a[0] ] = a[ !a[1] ] 
} 
```

```
void changeToZero(int a[2]) 
{ 
    a[ a[1] ] = a[ a[0] ] 
} 
```

```
void changeToZero(int a[2]) 
{ 
  a[0] = a[a[0]]; 
  a[1] = a[0]; 
} 
```

```
int main()  
{  
    int a[] = {1, 0};  
    changeToZero(a);  
      
    cout<<"arr[0] = "<<a[0]<<endl;  
    cout<<" arr[1] = "<<a[1];  
    return 0;  
}  
```