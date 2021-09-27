# Merge Sort

## Dummy nodes

The strategy here uses a temporary dummy node as the start of the result list. The pointer Tail always points to the last node in the result list, so appending new nodes is easy. 
The dummy node gives the tail something to point to initially when the result list is empty. This dummy node is efficient, since it is only temporary, and it is allocated in the stack. The loop proceeds, removing one node from either ‘a’ or ‘b’, and adding it to the tail. When 
We are done, the result is in dummy.next. 

```
void MergeSort(Node** headRef) 
{ 
    Node* head = *headRef; 
    Node* a; 
    Node* b; 
  
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 

    FrontBackSplit(head, &a, &b); 
  
    MergeSort(&a); 
    MergeSort(&b); 
  
    *headRef = SortedMerge(a, b); 
} 
  
Node* SortedMerge(Node* a, Node* b) 
{ 
    Node* result = NULL; 
  
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 

void FrontBackSplit(Node* source, 
                    Node** frontRef, Node** backRef) 
{ 
    Node* fast; 
    Node* slow; 
    slow = source; 
    fast = source->next; 
  
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 
```

## Local Reference

lastPtrRef is same as dummy node (this is tail before was head)

```
Node* SortedMerge(Node* a, Node* b) 
{ 
Node* result = NULL; 
	
Node** lastPtrRef = &result; 
	
while(1) 
{ 
	if (a == NULL) 
	{ 
	*lastPtrRef = b; 
	break; 
	} 
	else if (b==NULL) 
	{ 
	*lastPtrRef = a; 
	break; 
	} 
	if(a->data <= b->data) 
	{ 
	MoveNode(lastPtrRef, &a); 
	} 
	else
	{ 
	MoveNode(lastPtrRef, &b); 
	} 
	
	lastPtrRef = &((*lastPtrRef)->next); 
} 
return(result); 
} 


```

## Recursive (Space is more... Prodution XXX)

```
Node* SortedMerge(Node* a, Node* b) 
{ 
	Node* result = NULL; 
	
	if (a == NULL) 
		return(b); 
	else if (b == NULL) 
		return(a); 
	
	if (a->data <= b->data) 
	{ 
		result = a; 
		result->next = SortedMerge(a->next, b); 
	} 
	else
	{ 
		result = b; 
		result->next = SortedMerge(a, b->next); 
	} 
	return(result); 
} 

```


```
// O(n Log n)
// Merge sort is often preferred for sorting a linked list. The slow random-access performance of a linked list makes some other algorithms (such as quicksort) perform poorly, and others (such as heapsort) completely impossible.
// sorting image

// Let head be the first node of the linked list to be sorted and headRef be the pointer to head. Note that we need a reference to head in MergeSort() as the below implementation changes next links to sort the linked lists (not data at the nodes), so head node has to be changed if the data at the original head is not the smallest value in the linked list.
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
class Node { 
public: 
	int data; 
	Node* next; 
}; 

/* function prototypes */
Node* SortedMerge(Node* a, Node* b); 
void FrontBackSplit(Node* source, 
					Node** frontRef, Node** backRef); 

/* sorts the linked list by changing next pointers (not data) */
void MergeSort(Node** headRef) 
{ 
	Node* head = *headRef; 
	Node* a; 
	Node* b; 

	/* Base case -- length 0 or 1 */
	if ((head == NULL) || (head->next == NULL)) { 
		return; 
	} 

	/* Split head into 'a' and 'b' sublists */
	FrontBackSplit(head, &a, &b); 

	/* Recursively sort the sublists */
	MergeSort(&a); 
	MergeSort(&b); 

	/* answer = merge the two sorted lists together */
	*headRef = SortedMerge(a, b); 
} 

/* See https:// www.geeksforgeeks.org/?p=3622 for details of this 
function */
Node* SortedMerge(Node* a, Node* b) 
{ 
	Node* result = NULL; 

	/* Base cases */
	if (a == NULL) 
		return (b); 
	else if (b == NULL) 
		return (a); 

	/* Pick either a or b, and recur */
	if (a->data <= b->data) { 
		result = a; 
		result->next = SortedMerge(a->next, b); 
	} 
	else { 
		result = b; 
		result->next = SortedMerge(a, b->next); 
	} 
	return (result); 
} 

/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves, 
	and return the two lists using the reference parameters. 
	If the length is odd, the extra node should go in the front list. 
	Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source, 
					Node** frontRef, Node** backRef) 
{ 
	Node* fast; 
	Node* slow; 
	slow = source; 
	fast = source->next; 

	/* Advance 'fast' two nodes, and advance 'slow' one node */
	while (fast != NULL) { 
		fast = fast->next; 
		if (fast != NULL) { 
			slow = slow->next; 
			fast = fast->next; 
		} 
	} 

	/* 'slow' is before the midpoint in the list, so split it in two 
	at that point. */
	*frontRef = source; 
	*backRef = slow->next; 
	slow->next = NULL; 
} 

/* Function to print nodes in a given linked list */
void printList(Node* node) 
{ 
	while (node != NULL) { 
		cout << node->data << " "; 
		node = node->next; 
	} 
} 

/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node = new Node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Driver program to test above functions*/
int main() 
{ 
	/* Start with the empty list */
	Node* res = NULL; 
	Node* a = NULL; 

	/* Let us create a unsorted linked lists to test the functions 
Created lists shall be a: 2->3->20->5->10->15 */
	push(&a, 15); 
	push(&a, 10); 
	push(&a, 5); 
	push(&a, 20); 
	push(&a, 3); 
	push(&a, 2); 

	/* Sort the above created Linked List */
	MergeSort(&a); 

	cout << "Sorted Linked List is: \n"; 
	printList(a); 

	return 0; 
} 

// This is code is contributed by rathbhupendra 

```