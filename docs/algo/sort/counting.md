# Counting Sort

1. Counting sort is efficient if the range of input data is not significantly greater than the number of objects to be sorted. Consider the situation where the input sequence is between range 1 to 10K and the data is 10, 5, 10K, 5K. 
2. It is not a comparison based sorting. It running time complexity is O(n) with space proportional to the range of data. 
3. It is often used as a sub-routine to another sorting algorithm like radix sort. 
4. Counting sort uses a partial hashing to count the occurrence of the data object in O(1). 
5. Counting sort can be extended to work for negative inputs also
6. Modify above code to sort the input data in the range from M to N. 
7. Is counting sort stable and online? 
8. Thoughts on parallelizing the counting sort algorithm.


```
void countSort(char arr[]) 
{
	char output[strlen(arr)]; 

	int count[RANGE + 1], i; 
	memset(count, 0, sizeof(count)); 

	for (i = 0; arr[i]; ++i) 
		++count[arr[i]]; 

	for (i = 1; i <= RANGE; ++i) 
		count[i] += count[i - 1]; 

	for (i = 0; arr[i]; ++i) { 
		output[count[arr[i]] - 1] = arr[i]; 
		--count[arr[i]]; 
	} 

	/* 
	For Stable algorithm 
	for (i = sizeof(arr)-1; i>=0; --i) 
	{ 
		output[count[arr[i]]-1] = arr[i]; 
		--count[arr[i]]; 
	} 
	
	*/

	for (i = 0; arr[i]; ++i) 
		arr[i] = output[i]; 
}
```