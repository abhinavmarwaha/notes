# Introduction

* collection of similar data items stored at contiguous memory locations
* random access
* int, float, double, char, objects, structs, etc

### Why

The idea of an array is to represent many instances in one variable.

### Declaration

```
int arr1[10];
int n = 10;
int arr2[n];

int arr[] = { 10, 20, 30, 40 }

int arr[6] = { 10, 20, 30, 40 }
// same as
int arr[] = {10, 20, 30, 40, 0, 0}
```

### Advantages

* Random access
* less lines of code 
* Easy access
* easy Traversal
* easy Sorting 

### Disadvantages

* fixed number of elements
* Insertion and deletion of elements costly

### Accessing

```
int arr[5];
arr[0] = 5;
arr[2] = -10;
arr[3 / 2] = 2; // this is same as arr[1] = 2
arr[3] = arr[0];

printf("%d %d %d %d", arr[0], arr[1], arr[2], arr[3]);
```

##### In C, no index out of bound checking

```
int arr[2];

printf("%d ", arr[3]);
printf("%d ", arr[-2]);

int arr[2] = { 10, 20, 30, 40, 50 }; // The program won’t compile in C++. If we save the above program as a .cpp, the program generates compiler error “error: too many initializers for ‘int [2]'”. 
```

### Traversal

```
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int arr[6]={11,12,13,14,15,16};
	// Way -1
	for(int i=0;i<6;i++)
		cout<<arr[i]<<" ";

cout<<endl;
	// Way 2
	cout<<"By Other Method:"<<endl;
	for(int i=0;i<6;i++)
		cout<<i[arr]<<" ";

	cout<<endl;

	return 0;
}
```