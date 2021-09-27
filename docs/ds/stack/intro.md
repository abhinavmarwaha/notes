# Stack

* push(), pop(), isEmpty() and peek() all take O(1)
* follow LIFO/FILO order.
* real life -> stack of plates
  
Applications of stack:

Balancing of symbols
Infix to Postfix /Prefix conversion
Redo-undo features at many places like editors, photoshop.
Forward and backward feature in web browsers
Used in many algorithms like Tower of Hanoi, tree traversals, stock span problem, histogram problem.
Other applications can be Backtracking, Knight tour problem, rat in a maze, N queen problem and sudoku solver
In Graph Algorithms like Topological Sorting and Strongly Connected Components

# Implementation

## Array

Pros: Easy to implement. Memory is saved as pointers are not involved.
Cons: It is not dynamic. It doesn’t grow and shrink depending on needs at runtime.

```

#define MAX 1000 

class Stack { 
	int top; 

public: 
	int a[MAX]; // Maximum size of Stack 

	Stack() { top = -1; } 
	bool push(int x); 
	int pop(); 
	int peek(); 
	bool isEmpty(); 
}; 

bool Stack::push(int x) 
{ 
	if (top >= (MAX - 1)) { 
		cout << "Stack Overflow"; 
		return false; 
	} 
	else { 
		a[++top] = x; 
		cout << x << " pushed into stack\n"; 
		return true; 
	} 
} 

int Stack::pop() 
{ 
	if (top < 0) { 
		cout << "Stack Underflow"; 
		return 0; 
	} 
	else { 
		int x = a[top--]; 
		return x; 
	} 
} 
int Stack::peek() 
{ 
	if (top < 0) { 
		cout << "Stack is Empty"; 
		return 0; 
	} 
	else { 
		int x = a[top]; 
		return x; 
	} 
} 

bool Stack::isEmpty() 
{ 
	return (top < 0); 
} 

// Driver program to test above functions 
int main() 
{ 
	class Stack s; 
	s.push(10); 
	s.push(20); 
	s.push(30); 
	cout << s.pop() << " Popped from stack\n"; 

	return 0; 
} 

```

## Linked List

Pros: The linked list implementation of stack can grow and shrink according to the needs at runtime.
Cons: Requires extra memory due to involvement of pointers.

```

class StackNode { 
public: 
	int data; 
	StackNode* next; 
}; 

StackNode* newNode(int data) 
{ 
	StackNode* stackNode = new StackNode(); 
	stackNode->data = data; 
	stackNode->next = NULL; 
	return stackNode; 
} 

int isEmpty(StackNode* root) 
{ 
	return !root; 
} 

void push(StackNode** root, int data) 
{ 
	StackNode* stackNode = newNode(data); 
	stackNode->next = *root; 
	*root = stackNode; 
	cout << data << " pushed to stack\n"; 
} 

int pop(StackNode** root) 
{ 
	if (isEmpty(*root)) 
		return INT_MIN; 
	StackNode* temp = *root; 
	*root = (*root)->next; 
	int popped = temp->data; 
	free(temp); 

	return popped; 
} 

int peek(StackNode* root) 
{ 
	if (isEmpty(root)) 
		return INT_MIN; 
	return root->data; 
} 

int main() 
{ 
	StackNode* root = NULL; 

	push(&root, 10); 
	push(&root, 20); 
	push(&root, 30); 

	cout << pop(&root) << " popped from stack\n"; 

	cout << "Top element is " << peek(root) << endl; 

	return 0; 
} 

// This is code is contributed by rathbhupendra 

```

# Problems

* reverse a string -> push push... pop pop (better -> just swap the pointers)
*  2 stacks in an array:
   *  divide space into two (space inefficient)
   *  start from extremes
* check for balanced parenthesis -> push if open the pop if closed and check the equality
* next grater element
  * two loops (o(n^2))
  * using stacks (O(n))

```
Push the first element to stack.
Pick rest of the elements one by one and follow the following steps in loop.
Mark the current element as next.
If stack is not empty, compare top element of stack with next.
If next is greater than the top element,Pop element from stack. next is the next greater element for the popped element.
Keep popping from the stack while the popped element is smaller than next. next becomes the next greater element for all such popped elements
Finally, push the next in the stack.
After the loop in step 2 is over, pop all the elements from stack and print -1 as next element for them.
```

Time Complexity: O(n).
The worst case occurs when all elements are sorted in decreasing order. If elements are sorted in decreasing order, then every element is processed at most 4 times.

Initially pushed to the stack.
Popped from the stack when next element is being processed.
Pushed back to the stack because the next element is smaller.
Popped from the stack in step 3 of algorithm.


in the same order :

```
void printNGE(int arr[], int n) 
{ 
    stack<int> s; 
  
    int arr1[n]; 
  
    // iterating from n-1 to 0 
    for (int i = n - 1; i >= 0; i--)  
    { 
        /*We will pop till we get the  
        greater element on top or stack gets empty*/
        while (!s.empty() && s.top() <= arr[i]) 
            s.pop(); 
  
        /*if stack gots empty means there  
        is no element on right which is greater  
        than the current element. 
        if not empty then the next greater  
        element is on top of stack*/
        if (s.empty())  
            arr1[i] = -1;          
        else 
            arr1[i] = s.top();         
  
        s.push(arr[i]); 
    } 
  
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ---> " << arr1[i] << endl; 
} 
```

## reverse-a-stack-using-recursion/

```
char insert_at_bottom(char x) 
{ 
  
    if(st.size() == 0) 
    st.push(x); 
  
    else
    { 
              
        char a = st.top(); 
        st.pop(); 
        insert_at_bottom(x);
        st.push(a); 
    } 
} 

char reverse() 
{ 
    if(st.size()>0) 
    { 
          
        char x = st.top(); 
        st.pop(); 
        reverse(); 
        insert_at_bottom(x); 
    } 
}
```

## Sort Stack using recursion

Time Complexity: O(n2). 
In the worst case for every sortstack(), sortedinsert() is called for ‘N’ times recursively for putting element to the right place 
Auxiliary Space: O(N)

```
void sortedInsert(struct stack** s, int x) 
{ 
    if (isEmpty(*s) or x > top(*s)) { 
        push(s, x); 
        return; 
    } 
  
    int temp = pop(s); 
    sortedInsert(s, x); 
  
    push(s, temp); 
} 
  
void sortStack(struct stack** s) 
{ 
    if (!isEmpty(*s)) { 
        int x = pop(s); 
  
        sortStack(s); 
  
        sortedInsert(s, x); 
    } 
} 
```