# Stack using Queue

### Costly Push

```
void push(int x) 
    { 
        curr_size++; 
  
        q2.push(x); 
  
        while (!q1.empty()) { 
            q2.push(q1.front()); 
            q1.pop(); 
        } 
  
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
    } 
  
    void pop() 
    { 
  
        if (q1.empty()) 
            return; 
        q1.pop(); 
        curr_size--; 
    } 
  
```

### Costly Pop

```
void pop() 
    { 
        if (q1.empty()) 
            return; 
  
        while (q1.size() != 1) { 
            q2.push(q1.front()); 
            q1.pop(); 
        } 
  
        q1.pop(); 
        curr_size--; 
  
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q; 
    } 
  
    void push(int x) 
    { 
        q1.push(x); 
        curr_size++; 
    } 
```
