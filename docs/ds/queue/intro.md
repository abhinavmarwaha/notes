# Queue

* FIFO

### Operations 

* Enqueue: Adds or overflow.
* Dequeue: Removes or underflow.
* Front 
* Rear

### Application

* Used when elements does not have to be processed immediately
* When a resource is shared among multiple consumers. Examples include CPU scheduling, Disk Scheduling.
* When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes. Examples include IO Buffers, pipes, file IO, etc.

#### Implementation

##### Array

Complexity Analysis:

Time Complexity:
Operations              Complexity
Enque(insertion)           O(1)
Deque(deletion)            O(1)
Front(Get front)           O(1)
Rear(Get Rear)             O(1)              
Auxiliary Space: O(N).

N is the size of array for storing elements.
Pros of Array Implementation:

Easy to implement.
Cons of Array Implementation:

Static Data Structure, fixed size.
If the queue has a large number of enqueue and dequeue operations, at some point we may not we able to insert elements in the queue even if the queue is empty (this problem is avoided by using circular queue).

```

class Queue { 
public: 
	int front, rear, size; 
	unsigned capacity; 
	int* array; 
}; 

Queue* createQueue(unsigned capacity) 
{ 
	Queue* queue = new Queue(); 
	queue->capacity = capacity; 
	queue->front = queue->size = 0; 

	queue->rear = capacity - 1; 
	queue->array = new int[( 
		queue->capacity * sizeof(int))]; 
	return queue; 
} 

int isFull(Queue* queue) 
{ 
	return (queue->size == queue->capacity); 
} 

int isEmpty(Queue* queue) 
{ 
	return (queue->size == 0); 
} 

void enqueue(Queue* queue, int item) 
{ 
	if (isFull(queue)) 
		return; 
	queue->rear = (queue->rear + 1) 
				% queue->capacity; 
	queue->array[queue->rear] = item; 
	queue->size = queue->size + 1; 
	cout << item << " enqueued to queue\n"; 
} 

int dequeue(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	int item = queue->array[queue->front]; 
	queue->front = (queue->front + 1) 
				% queue->capacity; 
	queue->size = queue->size - 1; 
	return item; 
} 

int front(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->front]; 
} 

int rear(Queue* queue) 
{ 
	if (isEmpty(queue)) 
		return INT_MIN; 
	return queue->array[queue->rear]; 
}
```

##### Linked List

Time Complexity: Time complexity of both operations enqueue() and dequeue() is O(1) as we only change few pointers in both operations. There is no loop in any of the operations.

```
struct QNode { 
	int data; 
	QNode* next; 
	QNode(int d) 
	{ 
		data = d; 
		next = NULL; 
	} 
}; 

struct Queue { 
	QNode *front, *rear; 
	Queue() 
	{ 
		front = rear = NULL; 
	} 

	void enQueue(int x) 
	{ 

		QNode* temp = new QNode(x); 

		if (rear == NULL) { 
			front = rear = temp; 
			return; 
		} 

		rear->next = temp; 
		rear = temp; 
	} 

	void deQueue() 
	{ 
		if (front == NULL) 
			return; 

		QNode* temp = front; 
		front = front->next; 

		if (front == NULL) 
			rear = NULL; 

		delete (temp); 
	} 
};
```