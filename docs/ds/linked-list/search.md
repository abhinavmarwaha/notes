# Search

```
LinkedListNode* search(LinkedListNode* head, int val){
    LinkedListNode* temp = head;
    while(temp!=NULL){
        if(temp->value==val){
            cout << "Found it";
            return temp;
        }
        temp = temp->next;
    }
    cout << "Not Found";
    return NULL;
}
```