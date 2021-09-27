# Min Special

```
void SpecialStack::push(int x)
{
    if (isEmpty() == true) {
        Stack::push(x);
        min.push(x);
    }
    else {
        Stack::push(x);
        int y = min.pop();
        min.push(y);
        if (x < y)
            min.push(x);
        else
            min.push(y);
    }
}
 
/* SpecialStack's member method to 
remove an element from it. This method
   removes top element from min stack also. */
int SpecialStack::pop()
{
    int x = Stack::pop();
    min.pop();
    return x;
}
```
operations -> push, pop, isempty, getMin -> O(1)
aux. space -> O(n)

# Optimised space for 2 stacks:

```
void SpecialStack::push(int x)
{
	if (isEmpty() == true) {
		Stack::push(x);
		min.push(x);
	}
	else {
		Stack::push(x);
		int y = min.pop();
		min.push(y);

		if (x <= y)
			min.push(x);
	}
}

int SpecialStack::pop()
{
	int x = Stack::pop();
	int y = min.pop();

	if (y != x)
		min.push(y);

	return x;
}

```

operations -> push, pop, isempty, getMin -> O(1)
aux. space -> O(n) (Worst case -> decreasing order)