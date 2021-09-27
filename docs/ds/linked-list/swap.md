# Swapping

__Possibilities__

1. x and y may or may not be adjacent. 
2. Either x or y may be a head node. 
3. Either x or y may be the last node. 
4. x and/or y may not be present in the linked list.

```
void swap(Node*& a, Node*& b) 
{ 
  
    Node* temp = a; 
    a = b; 
    b = temp; 
} 


void swapNodes(Node** head_ref, int x, int y) 
{ 
  
    if (x == y) 
        return; 
  
    Node **a = NULL, **b = NULL; 
  
    while (*head_ref) { 
  
        if ((*head_ref)->data == x) { 
            a = head_ref; 
        } 
  
        else if ((*head_ref)->data == y) { 
            b = head_ref; 
        } 
  
        head_ref = &((*head_ref)->next); 
    } 
  
    if (a && b) { 
  
        swap(*a, *b); 
        swap(((*a)->next), ((*b)->next)); 
    } 
} 
```