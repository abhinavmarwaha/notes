# XOR DLL

### Representation

```
class Node 
{ 
	public:
	int data; 
	Node* npx; /* XOR of next and previous node */
}; 
```

### XOR Utility

```
Node* XOR (Node *a, Node *b) 
{ 
	return reinterpret_cast<Node *>(
	reinterpret_cast<uintptr_t>(a) ^ 
	reinterpret_cast<uintptr_t>(b)); 
} 
```

### Insert

```
void insert(Node **head_ref, int data) 
{ 
	Node *new_node = new Node(); 
	new_node->data = data; 

	new_node->npx = *head_ref; 

	if (*head_ref != NULL) 
	{ 
		(*head_ref)->npx = XOR(new_node, (*head_ref)->npx); 
	} 

	*head_ref = new_node; 
} 
```

### Print

```
void printList (Node *head) 
{ 
	Node *curr = head; 
	Node *prev = NULL; 
	Node *next; 

	cout << "Following are the nodes of Linked List: \n"; 

	while (curr != NULL) 
	{ 
		cout<<curr->data<<" "; 

		next = XOR (prev, curr->npx); 

		prev = curr; 
		curr = next; 
	} 
} 
```