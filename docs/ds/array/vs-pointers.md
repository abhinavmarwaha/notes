# Array vs Pointers

### Difference

```
#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 10, 20, 30, 40, 50, 60 };
	int* ptr = arr;

	// sizof(int) * (number of element in arr[]) is printed
	cout << "Size of arr[] " << sizeof(arr) << "\n";

	// sizeof a pointer is printed which is same for all
	// type of pointers (char *, void *, etc)
	cout << "Size of ptr " << sizeof(ptr);
	return 0;
}
```

**Output**

```
    Size of arr[] 24
    Size of ptr 8
```

##### Assignment

```
#include <stdio.h>

int main()
{
int arr[] = {10, 20}, x = 10;
int *ptr = &x; // This is fine
arr = &x; // Compiler Error
return 0;
}

```

### Similarities

* Array name -> address of 1st element.
* Members are accessed using pointer arithmetic. ( “arr[i]” <=> *(arr + i))
* Array parameters are always passed as pointers, even when we use square brackets.