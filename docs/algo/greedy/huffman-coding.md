# Huffman Coding

O(nlogn) , <Space Complexity>
Heap Tree, Trees

lossless compression algo
build huffman tree, traverse to assign codes to charcters
frequency increases, code decreases

prefix codes
{0,11} - prefix codes
{0,1,11} - non prefix code

```
#define MAX_TREE_HT 100

struct minHeapNode{
    char data;
    unsigned frequency;
    struct minHeapNode *left, *right;
};

struct minHeap{
    unsigned capacity;
    unsigned size;
    struct minHeapNode ** arr;
};

struct minHeapNode* newNode(char data, unsigned freq){
    struct minHeapNode * temp = (struct minHeapNode*) malloc(sizeof(struct minHeapNode));
    temp->frequency = freq;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;

    return temp;

}

struct minHeap* createMinHeap(unsigned capacity){

    struct minHeap* temp = (struct minHeap*)malloc(sizeof(struct minHeap));

    temp->size = 0;
    temp->capacity = capacity;
    temp->arr = (struct minHeapNode**)malloc(sizeof(struct minHeapNode*) * capacity);

    return temp;

}

void swapMinHeapNodes(struct minHeapNode** a, struct minHeapNode** b){
    struct minHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct minHeap* heap, int idx){
    int smallest = idx;
    int left = 2*idx + 1;
    int right = 2*idx + 2;

    if(left<heap->size && heap->arr[left]->frequency < heap->arr[right]->frequency)
        smallest = left;

    if(right<heap->size && heap->arr[right]->frequency < heap->arr[smallest]->frequency)
        smallest = right;

    if(smallest!=idx){
        swapMinHeapNodes(&heap->arr[smallest], &heap->arr[idx]);
        heapify(heap, smallest);
    }
}

bool isSize1(struct minHeap* heap){
    return heap->size == 1;
}

struct minHeapNode* pullMin(struct minHeap* heap){ // TODO doubt why not replace the last node with null
    struct minHeapNode* min = heap->arr[0];

    heap->arr[0] = heap->arr[heap->size -1];
    --heap->size;
    heapify(heap, 0);

    return min;
}

void insertNode(struct minHeap* heap,struct minHeapNode* node){
    ++heap->size;
    int curNode = heap->size -1;
    int root = (curNode-1)/2;
    while(curNode && heap->arr[curNode]->frequency > heap->arr[root]->frequency){
        heap->arr[curNode] = heap->arr[root]; // TODO doubt what happens to curNode?
        curNode = root;
        root = (curNode-1)/2;
    }
    heap->arr[curNode] = node;
}

void buildMinHeap(struct minHeap* heap){
    int n = heap->size -1;
    for(int i = (n-1)/2; i>=0; i--)
        heapify(heap, i);
}

void printArr(int arr[], int n) { 
    for (int i = 0; i < n; ++i) 
        cout << arr[i];
    cout << endl;
} 

bool isLeaf(struct minHeapNode* node){ 
    return !(node->left) && !(node->right);
}

struct minHeap* createAndBuildMinHeap(char data[], int frq[], int size){
    struct minHeap* heap = createMinHeap(size);
    for(int i = 0; i<size; i++)
        heap->arr[i] = newNode(data[i], frq[i]);
    
    heap->size = size;
    buildMinHeap(heap);
    
    return heap;
}

struct minHeapNode* buildHuffmanTree(char data[], int freq[], int size){
    struct minHeapNode *left, *right, *top;

    struct minHeap* heap = createAndBuildMinHeap(data, freq, size);

    while(!isSize1(heap)){
        left = pullMin(heap);
        right = pullMin(heap);

        top = newNode('$', left->frequency + right->frequency);

        top->left = left;
        top->right = right;

        insertNode(heap, top);

    }

    return pullMin(heap);
}

void printCodes(struct minHeapNode* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printCodes(root, arr, top+1);
    }

    if(root->right){ // TODO doubt if top is unchanged then it will be overwritten?
        arr[top] = 1;
        printCodes(root, arr, top+1);
    }
    if(isLeaf(root)){
        cout << root->data;
        printArr(arr,top);
    }

}

void HuffmanCodes(char data[], int freq[], int size){
    struct minHeapNode* heap = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top =0;
    printCodes(heap, arr, top);
}

int main() 
{ 
  
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' }; 
    int freq[] = { 5, 9, 12, 13, 16, 45 }; 
  
    int size = sizeof(arr) / sizeof(arr[0]); 
  
    HuffmanCodes(arr, freq, size); 
  
    return 0; 
}
```