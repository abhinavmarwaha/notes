# Locallity

* Data read operation in registers is generally 100 times faster than in the main memory
* Caches are installed in the middle of CPU registers and the main memory to bridge this time gap in data reading. 

The idea of caching the useful data centers around a fundamental property of computer programs known as locality. Programs with good locality tend to access the same set of data items over and over again from the upper levels of the memory hierarchy (i.e. cache) and thus run faster.

Example: The run time of different matrix multiplication kernels that perform the same number of arithmetic operations, but have different degrees of locality, can vary by a factor of 20!

### Types of Locality

* *Temporal locality* : Temporal locality states that, the same data objects are likely to be reused multiple times by the CPU during the execution of a program
* *Spatial locality* : It states that if a data object is referenced once, then there is a high probability that it’s neighbor data objects will also be referenced in near future.

### Importance of Locality

In operating systems, the principle of locality allows the system to use main memory as a cache of the most recently referenced chunk of virtual address space and also in case of recently used disk blocks in disk file systems.

### Cache Friendly Code

* *Frequently used cases need to be faster* : Programs often invest most of the time in a few core functions and these functions in return have most to do with the loops. So, these loops should be designed in a way that they possess a good locality.
* *Multiple loops* : If a program constitutes of multiple loops then minimize the cache misses in the inner loop to alleviate the performance of the code.

### eg

##### Row major:

```
int sumarrayrows(int a[8][4])
{
 int i, j, sum = 0;
 for (i = 0; i < 8; i++)
    for (j = 0; j < 4; j++)
     sum += a[i][j];
 return sum;
}
```
c -> row major storing of 2 dimensional array.
cache hit -> 75 % in  block size of 4 words each.

##### Column Major

```
int sum_array(int a[8][8])
{
 int i, j, sum = 0;
 for (j = 0; j < 8; j++)
   for (i = 0; i < 8; i++)
   sum += a[i][j];
 return sum;
}
```

As C stores arrays in row-major order but in this case array is being accessed in column major order, so the locality spoils in this case. the references will be made in order: a[0][0], a[1][0], a[2][0] and so on.


### Conclusion

A good example is Quick sort. Though it has a worst case complexity of O(n2), it is the most popular sorting algorithm and one of the important factor is the better cache performance than many other sorting algorithms.

