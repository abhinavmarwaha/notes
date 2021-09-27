# Doubly LL

```
struct Node { 
	int data; 
	struct Node* next;
	struct Node* prev;
};
```

### Advantages

* traversal -> both directions
* deletion is easy as prev pointer is easily available
* quickly insert 

### Disadvantages

* more mem -> mem efficient is XOR

XOR linked list:

* data
* npx = addr(next) ^ addr(prev)

to trverse we need prev addr then 
prev XOR npx == next addr

* every manipulation -> more steps
  
### Insertion

1. At the front of the DLL
2. After a given node.
3. At the end of the DLL
4. Before a given node.

```
void push(Node** head_ref, int new_data) 
{
	Node* new_node = new Node(); 

	new_node->data = new_data; 

	new_node->next = (*head_ref); 
	new_node->prev = NULL; 

	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 

	(*head_ref) = new_node; 
} 

void insertAfter(Node* prev_node, int new_data) 
{ 
	if (prev_node == NULL) 
	{ 
		cout<<"the given previous node cannot be NULL"; 
		return; 
	} 

	Node* new_node = new Node(); 

	new_node->data = new_data; 

	new_node->next = prev_node->next; 

	prev_node->next = new_node; 

	new_node->prev = prev_node; 

	if (new_node->next != NULL) 
		new_node->next->prev = new_node; 
} 

void append(Node** head_ref, int new_data) 
{
	Node* new_node = new Node(); 

	Node* last = *head_ref;

	new_node->data = new_data; 

	new_node->next = NULL; 

	if (*head_ref == NULL) 
	{ 
		new_node->prev = NULL; 
		*head_ref = new_node; 
		return; 
	} 

	while (last->next != NULL) 
		last = last->next; 

	last->next = new_node; 

	new_node->prev = last; 

	return; 
}
```

### Deletion

Time Complexity: O(1). 
Space Complexity: O(1). 

```
void deleteNode(Node** head_ref, Node* del) 
{ 
    if (*head_ref == NULL || del == NULL) 
        return; 

    if (*head_ref == del) 
        *head_ref = del->next; 

    if (del->next != NULL) 
        del->next->prev = del->prev; 

    if (del->prev != NULL) 
        del->prev->next = del->next; 

    free(del); 
    return; 
}
```

### reverse

```
void reverse(Node **head_ref)  
{  
    Node *temp = NULL;  
    Node *current = *head_ref;  
      
    while (current != NULL)  
    {  
        temp = current->prev;  
        current->prev = current->next;  
        current->next = temp;              
        current = current->prev;  
    }  

    if(temp != NULL )  
        *head_ref = temp->prev;  
}
```

TODO Swapping