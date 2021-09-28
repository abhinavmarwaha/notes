# Imporved Huffman Coding

O(n) , <Space Complexity>

non-deacreasing freq sorted

1. 2 queues.
2. Create a leaf node for each unique character and Enqueue it to the first queue in non-decreasing order of frequency. Initially second queue is empty.
3. Dequeue two nodes with the minimum frequency by examining the front of both queues. Repeat following steps two times
   1.  If second queue is empty, dequeue from first queue.
   2.  If first queue is empty, dequeue from second queue.
   3.  Else, compare the front of two queues and dequeue the minimum.
4. Create a new internal node with frequency equal to the sum of the two nodes frequencies. Make the first Dequeued node as its left child and the second Dequeued node as right child. Enqueue this node to second queue.
5. Repeat until there is more than one node in the queues. The remaining node is the root node and the tree is complete.

```
#define MAX_TREE_HT 100

class QueueNode{
    public:
    char data;
    unsigned freq;
    QueueNode *left, *right; 

};

class Queue{
    public:
    int front, rear;
    int capacty;
    QueueNode **arr;
};

QueueNode* newNode(char data, unsigned freq){
    QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
    node->right = node->left = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

Queue* createQueue(unsigned capacity){
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->rear = queue->front = -1;
    queue->capacty = capacity;
    queue->arr = (QueueNode**)malloc(sizeof(QueueNode*) * capacity);
    return queue;
}

int isSizeOne(Queue* queue){
    return queue->front == queue->rear && queue->front!=-1;
}

int isEmpty(Queue* queue){
    return queue->rear == -1;
}

int isFull(Queue* queue){
    return queue->rear == queue->capacty -1;
}

void enQueue(Queue* queue, QueueNode* node){
    if(isFull(queue))
        return;
    
    queue->arr[++queue->rear] = node;
    if(queue->front==-1)
        queue->front++;
}

QueueNode* deQueue(Queue* queue){
    if(isEmpty(queue))
        return NULL;
    
    QueueNode* node = queue->arr[queue->front];
    if(queue->rear == queue->front)
        queue->front = queue->rear = -1;
    else
        queue->front++;
    return node;
}

QueueNode* getFront(Queue* queue){
    if(isEmpty(queue))
        return NULL;
    return queue->arr[queue->front];
}

QueueNode* getMin(Queue* first, Queue* second){
    if(isEmpty(first))
        return deQueue(second);
    
    if(isEmpty(second))
        return deQueue(first);

    if(getFront(first)->freq< getFront(second)->freq)
        return deQueue(first);
    else
        return deQueue(second);
}

int isLeaf(QueueNode* node){
    return !(node->right) && !(node->left);
}

void printArr(int arr[], int N){
    for(int i = 0; i<N; i++){
        cout << arr[i] << ", ";
    }
    cout << endl;
}

QueueNode* buildHuffmanTree(char data[], int freq[], int N){
    QueueNode *top, *right, *left;

    Queue* firstQueue = createQueue(N);
    Queue* secondQueue = createQueue(N);

    for(int i = 0; i<N; i++)
        enQueue(firstQueue, newNode(data[i], freq[i]));
    
    while(!(isEmpty(firstQueue)) && !isSizeOne(secondQueue)){

        left = getMin(firstQueue, secondQueue);
        right = getMin(firstQueue, secondQueue);

        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        enQueue(secondQueue, top);
    }

    return deQueue(secondQueue);
}

void printCodes(QueueNode* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }

    if(root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }

    if(isLeaf(root)){
        cout << root->data <<": ";
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size){
    QueueNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT] , top = 0;
    printCodes(root, arr, top);
}

int main()  
{  
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};  
    int freq[] = {5, 9, 12, 13, 16, 45};  
    int size = sizeof(arr)/sizeof(arr[0]);  
    HuffmanCodes(arr, freq, size);  
    return 0;  
}
```