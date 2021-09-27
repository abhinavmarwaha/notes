
# Sort

Recursion

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