# Medium Special

findMiddle() which will return middle element of the stack.
deleteMiddle() which will delete the middle element.

```
void push(myStack *ms, int new_data)  
{  
    DLLNode* new_DLLNode = new DLLNode(); 
    new_DLLNode->data = new_data;  
  
    new_DLLNode->prev = NULL;  
  
    new_DLLNode->next = ms->head;  
  
    ms->count += 1;  
  
    if (ms->count == 1)  
    {  
        ms->mid = new_DLLNode;  
    }  
    else
    {  
        ms->head->prev = new_DLLNode;  
  
        if(!(ms->count & 1)) // Update mid if ms->count is even 
        ms->mid = ms->mid->prev;  
    }  
  
    ms->head = new_DLLNode;  
}  
  
int pop(myStack *ms)  
{  
    if (ms->count == 0)  
    {  
        cout<<"Stack is empty\n";  
        return -1;  
    }  
  
    DLLNode *head = ms->head;  
    int item = head->data;  
    ms->head = head->next;  
  
    if (ms->head != NULL)  
        ms->head->prev = NULL;  
  
    ms->count -= 1;  
  
    if ((ms->count) & 1 )  
        ms->mid = ms->mid->next;  
  
    free(head);  
  
    return item;  
}  
```