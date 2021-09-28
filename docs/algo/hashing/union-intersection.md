# Union & Intersection

Given two Linked Lists, create union and intersection lists that contain union and intersection of the elements present in the given lists. Order of elements in output lists doesn’t matter.

### Method 1 -> Simple

Time Complexity: O(m*n).
Auxiliary Space: O(1).


```
struct Node* getUnion( 
    struct Node* head1, 
    struct Node* head2) 
{ 
    struct Node* result = NULL; 
    struct Node *t1 = head1, *t2 = head2; 
  
    while (t1 != NULL) { 
        push(&result, t1->data); 
        t1 = t1->next; 
    } 

    while (t2 != NULL) { 
        if (!isPresent(result, t2->data)) 
            push(&result, t2->data); 
        t2 = t2->next; 
    } 
  
    return result; 
} 

struct Node* getIntersection(struct Node* head1, 
                             struct Node* head2) 
{ 
    struct Node* result = NULL; 
    struct Node* t1 = head1; 
  
    while (t1 != NULL) { 
        if (isPresent(head2, t1->data)) 
            push(&result, t1->data); 
        t1 = t1->next; 
    } 
  
    return result; 
} 
  
bool isPresent(struct Node* head, int data) 
{ 
    struct Node* t = head; 
    while (t != NULL) { 
        if (t->data == data) 
            return 1; 
        t = t->next; 
    } 
    return 0; 
} 
```

### Method 2 -> merge sort

O(mLogm + nLogn)

```
1. merge sort both lists
2. traverse and add (if not present for uninun and if present add)
```

### Method 3 -> Hashing

Time Complexity: O(m+n). (assuming hashset alsgos -> O(1) )
Auxiliary Space:O(m+n).

```
see file
```