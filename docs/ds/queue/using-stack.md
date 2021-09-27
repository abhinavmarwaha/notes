# Queue using Stack

### Costly Enqueue

Push O(N): In the worst case we have empty whole of stack 1 into stack 2.

Pop operation: O(1).

Auxiliary Space: O(N).

```
struct Queue { 
	stack<int> s1, s2; 

	void enQueue(int x) 
	{ 
		while (!s1.empty()) { 
			s2.push(s1.top()); 
			s1.pop(); 
		} 

		s1.push(x); 

		while (!s2.empty()) { 
			s1.push(s2.top()); 
			s2.pop(); 
		} 
	} 

	int deQueue() 
	{ 
		if (s1.empty()) { 
			cout << "Q is Empty"; 
			exit(0); 
		} 

		int x = s1.top(); 
		s1.pop(); 
		return x; 
	} 
};
```

### Costly Dequeue

Push operation: O(1).
Pop operation: O(N): In the worst case we have empty whole of stack 1 into stack 2
Auxiliary Space: O(N).

Method 2 is definitely better than method 1.
Method 1 moves all the elements twice in enQueue operation, while method 2 (in deQueue operation) moves the elements once and moves elements only if stack2 empty. So, the amortized complexity of the dequeue operation becomes  \Theta (1) .

```
struct Queue { 
    stack<int> s1, s2; 
  
    void enQueue(int x) 
    { 
        s1.push(x); 
    } 
  
    int deQueue() 
    { 
        if (s1.empty() && s2.empty()) { 
            cout << "Q is empty"; 
            exit(0); 
        } 
  
        if (s2.empty()) { 
            while (!s1.empty()) { 
                s2.push(s1.top()); 
                s1.pop(); 
            } 
        } 
  
        int x = s2.top(); 
        s2.pop(); 
        return x; 
    } 
}; 
```

### Using one user stack and function call stack (recurion)

Push operation : O(1).
Pop operation : O(N).
The difference from above method is that in this method element is returned and all elements are restored back in a single call.
Auxiliary Space: O(N).

```
struct Queue { 
    stack<int> s; 
  
    void enQueue(int x) 
    { 
        s.push(x); 
    } 
  
    int deQueue() 
    { 
        if (s.empty()) { 
            cout << "Q is empty"; 
            exit(0); 
        } 
  
        int x = s.top(); 
        s.pop(); 
  
        if (s.empty()) 
            return x; 
  
        int item = deQueue(); 
  
        s.push(x); 
  
        return item; 
    } 
}; 
```

