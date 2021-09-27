# Linked List

* Linear DS
* Non-contagious 
* Pointers

# Why ?

* dynamic size
* inserting / deleting -> less expensive
  
# Drawbacks 

* Random Access not allowed
* extra memory for pointer
* not cache friendly -> no locallity of refernce -> non contagious
  
# Representation 

* Data + next pointer -> node
* Linked List -> Meta data + Start
  
```
class Node { 
public: 
    int data; 
    Node* next; 
};
```

# Traversal

```
void printList(Node* n) 
{ 
    while (n != NULL) { 
        cout << n->data << " "; 
        n = n->next; 
    } 
} 
```