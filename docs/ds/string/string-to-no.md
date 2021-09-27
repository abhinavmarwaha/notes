# Strings to Numbers

### Using stringstream class

```
#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	string s = "12345";

	stringstream geek(s);

	int x = 0;
	geek >> x;

	cout << "Value of x : " << x;

	return 0;
}

```

### sscanf()

sscanf() is a C style function similar to scanf(). It reads input from a string rather that standard input.

```
const char *str = "12345";
int x;
sscanf(str, "%d", &x);
printf("\nThe value of x : %d", x);
```

### Functions

```
int stoi (const string&  str, size_t* index = 0, int base = 10): string to value
int atoi (const char * str) : character array or string literal tp value.
```

##### stoi() vs atoi()

| atoi                      | stoi                                    |
|---------------------------|-----------------------------------------|
| legacy c style function   | c++11                                   |
| c char and string literal | c++ string                              |
| 1 parameter               | 3 parameters: string, start index, base |

# String to Double

```
atof(): the converted integral number as an int value. If no valid conversion could be performed, it returns zero.
```