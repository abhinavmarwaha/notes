# Deletion

### First

```
void deleteFirst(struct Node **head_ref) { 
  	if(*head_ref != NULL) 
  	{ 
  	struct Node *temp = *head_ref; 

  	*head_ref = (*head_ref)->next; 

  	free(temp); 
      } 
}
```

### Any

```
void deleteNode(struct Node **head_ref, int key)
{
	struct Node* temp = *head_ref, *prev;

	if (temp != NULL && temp->data == key)
	{
		*head_ref = temp->next;
		free(temp);			
		return;
	}

	while (temp != NULL && temp->data != key)
	{
		prev = temp;
		temp = temp->next;
	}

	if (temp == NULL) return;
	prev->next = temp->next;
	free(temp); 
}
```