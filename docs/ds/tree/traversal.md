# Traversal

linear data structure -> only one logical way to traverse them,
trees can be traversed in different ways

```
              1                                 
           /    \   
          2      3    
        /  \       
       4    5   
```

Depth First Traversals:

1. Inorder (Left, Root, Right) : 4 2 5 1 3
2. Preorder (Root, Left, Right) : 1 2 4 5 3
3. Postorder (Left, Right, Root) : 4 5 2 3 1

Breadth First or Level Order Traversal : 1 2 3 4 5

### Depth First Traversals

Time Complexity(O(n)):

```
T(n) = T(k) + T(n – k – 1) + c

k -> number of nodes on one side of root
n-k-1 on the other side
```

Analysis of boundary conditions:

Case 1: Skewed tree (One of the subtrees is empty and other subtree is non-empty)

```
k is 0 in this case.
T(n) = T(0) + T(n-1) + c
T(n) = 2T(0) + T(n-2) + 2c
T(n) = 3T(0) + T(n-3) + 3c
T(n) = 4T(0) + T(n-4) + 4c

T(n) = (n-1)T(0) + T(1) + (n-1)c
T(n) = nT(0) + (n)c

Value of T(0) will be some constant say d. (traversing a empty tree will take some constants time)

T(n) = n(c+d)
T(n) = Θ(n)
```

Case 2: Both left and right subtrees have equal number of nodes.

```
T(n) = 2T(n/2) + c

This recursive function is in the standard form (T(n) = aT(n/b) + Θ(n)) for master method
```

Auxiliary Space: size of stack -> O(n).

##### Inorder

```
void inorder(Node* temp)
{
	if (temp == NULL)
		return;

	inorder(temp->left);
	cout << temp->data << ' ';
	inorder(temp->right);
}
```

Application: To get nodes of BST in non-increasing order

##### Preorder

Application:

* to create a copy of the tree.
* to get prefix expression on of an expression tree.

```
void preorder(Node* temp)
{
	if (temp == NULL)
		return;
    cout << temp->data << ' ';
	preorder(temp->left);
	preorder(temp->right);
}
```

##### Postorder

```
void postorder(Node* temp)
{
	if (temp == NULL)
		return;
	postorder(temp->left);
	postorder(temp->right);
    cout << temp->data << ' ';
}
```

Application:

* delete the tree. 
* the postfix expression of an expression tree.

### BFS

##### using call stack

```
void printLevelOrder(node* root) 
{ 
	int h = height(root); 
	int i; 
	for (i = 1; i <= h; i++) 
		printGivenLevel(root, i); 
}

void printGivenLevel(node* root, int level) 
{ 
	if (root == NULL) 
		return; 
	if (level == 1) 
		cout << root->data << " "; 
	else if (level > 1) 
	{ 
		printGivenLevel(root->left, level-1); 
		printGivenLevel(root->right, level-1); 
	} 
}
```

Time Complexity: O(n^2) in worst case. For a skewed tree, printGivenLevel() takes O(n) time where n is the number of nodes in the skewed tree. So time complexity of printLevelOrder() is O(n) + O(n-1) + O(n-2) + .. + O(1) which is O(n^2). 
Space Complexity: O(n) in worst case. For a skewed tree, printGivenLevel() uses O(n) space for call stack. For a Balanced tree, call stack uses O(log n) space, (i.e., height of the balanced tree).

##### using queues

```
void printLevelOrder(Node *root)
{
	if (root == NULL) return;

	queue<Node *> q;

	q.push(root);

	while (q.empty() == false)
	{
		Node *node = q.front();
		cout << node->data << " ";
		q.pop();

		if (node->left != NULL)
			q.push(node->left);

		if (node->right != NULL)
			q.push(node->right);
	}
}
```

Time Complexity: O(n) where n is number of nodes in the binary tree 
Space Complexity: O(n) where n is number of nodes in the binary tree

### BFS vs DFS

##### Time complexity

same -> O(n)

##### Space Complexity

* Level Order Traversal is O(w) where w is maximum width of Binary Tree -> coz using queues
* Depth First Traversals is O(h) where h is maximum height of Binary Tree -> coz using stack (or function call stack) stores all ancestors of a node.

Maximum Width of BT -> 2^h where h starts from 0. (height/width)
worst case -> perfect binry tree -> Ceil(n/2).

Height of BT is O(Log n). 
Worst case occurs -> skewed tree == O(n).

worst case for both -> O(n)

But,

if(more balanced) -> DFS is better than BFS
else BFS is better than DFS

### How to Pick One?

* Extra Space 
* DFS -> recursive thus function call overheads.
* Find closer to root -> BFS ... Find closer to leaves -> DFS