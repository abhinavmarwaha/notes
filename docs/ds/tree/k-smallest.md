# K Smallest

### Method 1: Using Inorder Traversal (O(n) time and O(h) auxiliary space) 

```
Node* kthSmallest(Node* root, int& k)
{
    if (root == NULL)
        return NULL;
 
    Node* left = kthSmallest(root->left, k);
 
    if (left != NULL)
        return left;
 
    k--;
    if (k == 0)
        return root;
 
    return kthSmallest(root->right, k);
}
```

### Method 2: Augmented Tree Data Structure (O(h) Time Complexity and O(h) auxiliary space)

Time complexity: O(h) where h is the height of the tree.

```

struct Node {
	int data;
	Node *left, *right;
	int lCount;
	Node(int x)
	{
		data = x;
		left = right = NULL;
		lCount = 0;
	}
};

Node* insert(Node* root, int x)
{
	if (root == NULL)
		return new Node(x);

	if (x < root->data) {
		root->left = insert(root->left, x);
		root->lCount++;
	}

	else if (x > root->data)
		root->right = insert(root->right, x);
	return root;
}

Node* kthSmallest(Node* root, int k)
{
	if (root == NULL)
		return NULL;

	int count = root->lCount + 1;
	if (count == k)
		return root;

	if (count > k)
		return kthSmallest(root->left, k);

	return kthSmallest(root->right, k - count);
}

```