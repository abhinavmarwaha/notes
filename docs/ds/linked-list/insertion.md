# Insertion

* does not modify head

### Front (O(1))

```
void push(Node** head_ref, int new_data) 
{ 
	Node* new_node = new Node(); 

	new_node->data = new_data; 

	new_node->next = (*head_ref); 

	(*head_ref) = new_node; 
} 
```

### After Node (O(1))

```
void insertAfter(Node* prev_node, int new_data) 
{ 
	
	if (prev_node == NULL) 
	{ 
		cout << "the given previous node cannot be NULL"; 
		return; 
	} 
	Node* new_node = new Node(); 
	new_node->data = new_data; 
	new_node->next = prev_node->next; 
	
	prev_node->next = new_node; 
} 
```


### Last (O(n))

```
void append(Node** head_ref, int new_data) 
{ 
	
	Node* new_node = new Node(); 
	
	Node *last = *head_ref; 
	
	new_node->data = new_data; 
	
	new_node->next = NULL; 
	
	if (*head_ref == NULL) 
	{ 
		*head_ref = new_node; 
		return; 
	} 
	 
	while (last->next != NULL) 
		last = last->next; 
	last->next = new_node; 
	return; 
} 

```