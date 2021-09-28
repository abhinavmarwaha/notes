# Merge Sort

### Dummy nodes

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
  
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 

    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 
```

### Local Reference

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

### Recursive (Space is more... Prodution XXX)

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

O(n Log n)
Merge sort is often preferred for sorting a linked list. The slow random-access performance of a linked list makes some other algorithms (such as quicksort) perform poorly, and others (such as heapsort) completely impossible.
sorting image

Let head be the first node of the linked list to be sorted and headRef be the pointer to head. Note that we need a reference to head in MergeSort() as the below implementation changes next links to sort the linked lists (not data at the nodes), so head node has to be changed if the data at the original head is not the smallest value in the linked list.

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

void FrontBackSplit(Node* source, 
					Node** frontRef, Node** backRef) 
{ 
	Node* fast; 
	Node* slow; 
	slow = source; 
	fast = source->next; 

	while (fast != NULL) { 
		fast = fast->next; 
		if (fast != NULL) { 
			slow = slow->next; 
			fast = fast->next; 
		} 
	} 

	*frontRef = source; 
	*backRef = slow->next; 
	slow->next = NULL; 
} 
```

Time : T(n) = 2T(n/2) + θ(n) :  θ(nLogn) in all 3 cases (worst, average and best)
Space: O(n)
Algorithmic Paradigm: Divide and Conquer
Sorting In Place: No in a typical implementation
Stable: Yes

Applications 

* sorting linked lists ->  as  Quick Sort requires a lot of direct access
* Inversion Count Problem
* Used in External Sorting

```
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (int i = 0; i < n1; i++)
		L[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	int i = 0;

	int j = 0;

	int k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[],int l,int r){
	if(l>=r){
		return;
	}
	int m = (l+r-1)/2;
	mergeSort(arr,l,m);
	mergeSort(arr,m+1,r);
	merge(arr,l,m,r);
}
```

O(nlogn) T(n) = 2T(n/2) + \Theta(n) , O(n)
stable, not inplace generally
External sort

```
void merge(int arr[], int l, int mid, int r){

    int i=0, j=0, k=0;

    int n1 = mid-l + 1;
    int n2 = r-mid;

    int L[n1];
    int R[n2];


    while(i<n1){
        L[i] = arr[l+i];
        i++;
    }

    while(j<n2){
        R[j] = arr[mid+1+j];
        j++;
    }
    
    i =0, j=0, k=l;


    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }


    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }

}

void mergesort(int arr[], int l, int r){

    if(l<r){
        int mid = (l+r)/2;

        mergesort(arr, l, mid);
        mergesort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }

}
```

https://www.geeksforgeeks.org/merge-sort-for-linked-list/

O(nlogn), O(1)
merge sort is best for linked list.

```
Node* merge(Node* a, Node* b){
    Node* result = NULL;

    if(a==NULL){
        return b;

    }
    else if(b==NULL)
        return a;

    if(a->data <= b->data){
        result = a;
        result->next = merge(a->next, b);
    }
    else{
        result=b;
        result->next = merge(a, b->next);
    }

    return result;

}

void Split(Node* source, Node** a, Node** b){

    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;
    while(fast!=NULL){
        fast = fast->next;
        while(fast!=NULL){

            slow = slow->next;
            fast = fast->next;
        }
    }

    *a = source;
    *b = (slow->next);

    slow->next = NULL;



}


void mergeSort(Node** headref){
    Node* head = *headref;
    Node* a;
    Node* b;
    if((head==NULL)|| (head->next ==NULL)){
        return;
    }

    Split(head, &a, &b);

    mergeSort(&a);
    mergeSort(&b);

    *headref = merge(a,b);

}
```