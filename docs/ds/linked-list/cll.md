# Circular LL

* end node points to start
* single or doubly
* you can traverse from anywhere, take note of starting node
* good for queues.
* usefl for cyclation. eg cpu shceduling
* fibonici heap

### Representation

```
class Node 
{ 
	public: 
	int data; 
	Node *next; 
};
```

### Traversal

```
void printList(struct Node *first) 
{ 
	struct Node *temp = first; 

	if (first != NULL) 
	{ 
		do
		{ 
			printf("%d ", temp->data); 
			temp = temp->next; 
		} 
		while (temp != first); 
	} 
} 

```

### Insertion

have ext pointer pointing at end

* empty list
* beginning 
* end 
* in between 
  
```
struct Node *addToEmpty(struct Node *last, int data)
{
	if (last != NULL)
	return last;

	struct Node *temp = 
		(struct Node*)malloc(sizeof(struct Node));

	temp -> data = data;
	last = temp;

	last -> next = last;

	return last;
}

struct Node *addBegin(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);

	struct Node *temp = 
			(struct Node *)malloc(sizeof(struct Node));

	temp -> data = data;
	temp -> next = last -> next;
	last -> next = temp;

	return last;
}

struct Node *addEnd(struct Node *last, int data)
{
	if (last == NULL)
		return addToEmpty(last, data);
	
	struct Node *temp = 
		(struct Node *)malloc(sizeof(struct Node));

	temp -> data = data;
	temp -> next = last -> next;
	last -> next = temp;
	last = temp;

	return last;
}

struct Node *addAfter(struct Node *last, int data, int item)
{
	if (last == NULL)
		return NULL;

	struct Node *temp, *p;
	p = last -> next;
	do
	{
		if (p ->data == item)
		{
			temp = (struct Node *)malloc(sizeof(struct Node));
			temp -> data = data;
			temp -> next = p -> next;
			p -> next = temp;

			if (p == last)
				last = temp;
			return last;
		}
		p = p -> next;
	} while(p != last -> next);

	cout << item << " not present in the list." << endl;
	return last;

}

```

### Problems:

* split in halve -> tortoise and haire
* cll sorted insert -> find and insert cases


Case 2 of the above algorithm/code can be optimized. To implement the suggested change we need to modify the case 2 to following.

```
// Case 2 of the above algo 
else if (current->data >= new_node->data) 
{ 
  // swap the data part of head node and new node 
  // assuming that we have a function swap(int *, int *) 
  swap(&(current->data), &(new_node->data));  
 
  new_node->next = (*head_ref)->next; 
  (*head_ref)->next = new_node; 
}
```

### CLL Sorted Insert

```
void sortedInsert(Node** head_ref, Node* new_node) 
{ 
	Node* current = *head_ref; 
	
	if (current == NULL) 
	{ 
		new_node->next = new_node; 
		*head_ref = new_node; 
	} 
	
	else if (current->data >= new_node->data) 
	{ 
		while(current->next != *head_ref) 
			current = current->next; 
		current->next = new_node; 
		new_node->next = *head_ref; 
		*head_ref = new_node; 
	} 
	
	else
	{ 
		while (current->next!= *head_ref && 
			current->next->data < new_node->data) 
		current = current->next; 
	
		new_node->next = current->next; 
		current->next = new_node; 
	} 
} 
```