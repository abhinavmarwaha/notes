# Counting 

__O(n)__

### Iterative

```
int getCount(Node* head)  
{  
    int count = 0;
    Node* current = head;
    while (current != NULL)  
    {  
        count++;  
        current = current->next;  
    }  
    return count;  
} 
```

### Recursive

```
int getCount(struct Node* head) 
{ 
    if (head == NULL) 
        return 0; 
    return 1 + getCount(head->next); 
} 
```