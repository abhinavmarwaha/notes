# Reverse LL

### Iterative

Time  O(n) 
Space O(1)

```
void reverse()
{
    Node* current = head;
    Node *prev = NULL, *next = NULL;

    while (current != NULL) {
        next = current->next;

        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;
}
```

### Recursive

Time O(n) 
Space O(1)

```
Node* reverse(Node* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* rest = reverse(head->next);
    head->next->next = head;

    head->next = NULL;

    return rest;
}
```

### Tail Recursive method

```
void reverse(Node** head)
{
    if (!head)
        return;
    reverseUtil(*head, NULL, head);
}

void reverseUtil(Node* curr, Node* prev, Node** head)
{
    if (!curr->next) {
        *head = curr;
 
        curr->next = prev;
        return;
    }
 
    Node* next = curr->next;
 
    curr->next = prev;
 
    reverseUtil(next, curr, head);
}
```

### Stack

```
void reverseLL(Node** head)
{   
    stack<Node*> s; 
    Node* temp = *head;
    while (temp->next != NULL) 
    {
        s.push(temp); 
        temp = temp->next;
    }
    *head = temp;
   
    while (!s.empty()) 
    {
        temp->next = s.top(); 
       
        s.pop(); 
       
        temp = temp->next; 
    }
    temp->next = NULL;
}
```
