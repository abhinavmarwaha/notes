# Dequeue

* generalised version of queue -> insert and delete at both ends
  
### Operations

* insertFront
* deleteFront
* insertRear
* deleteRear
* isFull
* isEmpty
* getFront
* getRear

### Application

* used as stack and queues.
* clockwise and anticlockwise rotations in O(1) time 
* Also, the problems where elements need to be removed and or added both ends can be efficiently solved using Deque. For example see Maximum of all subarrays of size k problem., 0-1 BFS and Find the first circular tour that visits all petrol pumps.
* A-Steal job scheduling algorithm where Deque is used as deletions operation is required at both ends.

### Implementation
all ops -> O(1)

#####  doubly linked list

TODO

##### circular array. 

```
#define MAX 100 

class Deque 
{ 
	int arr[MAX]; 
	int front; 
	int rear; 
	int size; 
public : 
	Deque(int size) 
	{ 
		front = -1; 
		rear = 0; 
		this->size = size; 
	} 

	void insertfront(int key); 
	void insertrear(int key); 
	void deletefront(); 
	void deleterear(); 
	bool isFull(); 
	bool isEmpty(); 
	int getFront(); 
	int getRear(); 
}; 

bool Deque::isFull() 
{ 
	return ((front == 0 && rear == size-1)|| 
			front == rear+1); 
} 

bool Deque::isEmpty () 
{ 
	return (front == -1); 
} 

void Deque::insertfront(int key) 
{ 
	if (isFull()) 
	{ 
		cout << "Overflow\n" << endl; 
		return; 
	} 

	if (front == -1) 
	{ 
		front = 0; 
		rear = 0; 
	} 

	else if (front == 0) 
		front = size - 1 ; 

	else 
		front = front-1; 

	arr[front] = key ; 
} 

void Deque ::insertrear(int key) 
{ 
	if (isFull()) 
	{ 
		cout << " Overflow\n " << endl; 
		return; 
	} 

	if (front == -1) 
	{ 
		front = 0; 
		rear = 0; 
	} 

	else if (rear == size-1) 
		rear = 0; 

	else
		rear = rear+1; 

	arr[rear] = key ; 
} 

void Deque ::deletefront() 
{ 
	if (isEmpty()) 
	{ 
		cout << "Queue Underflow\n" << endl; 
		return ; 
	} 

	if (front == rear) 
	{ 
		front = -1; 
		rear = -1; 
	} 
	else

		if (front == size -1) 
			front = 0; 

		else 
			front = front+1; 
} 

void Deque::deleterear() 
{ 
	if (isEmpty()) 
	{ 
		cout << " Underflow\n" << endl ; 
		return ; 
	} 

	if (front == rear) 
	{ 
		front = -1; 
		rear = -1; 
	} 
	else if (rear == 0) 
		rear = size-1; 
	else
		rear = rear-1; 
} 

int Deque::getFront() 
{ 
	if (isEmpty()) 
	{ 
		cout << " Underflow\n" << endl; 
		return -1 ; 
	} 
	return arr[front]; 
} 

int Deque::getRear() 
{ 
	if(isEmpty() || rear < 0) 
	{ 
		cout << " Underflow\n" << endl; 
		return -1 ; 
	} 
	return arr[rear]; 
}
```
