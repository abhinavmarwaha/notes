# Binary Tree to Circular DLL

(In Place)

### CDLL
```
struct Node
{
	struct Node *left, *right;
	int data;
};
```

### Concatenate two CDLL's

```
Node *concatenate(Node *leftList, Node *rightList)
{
	if (leftList == NULL)
		return rightList;
	if (rightList == NULL)
		return leftList;

	Node *leftLast = leftList->left;

	Node *rightLast = rightList->left;

	leftLast->right = rightList;
	rightList->left = leftLast;

	leftList->left = rightLast;
    
	rightLast->right = leftList;

	return leftList;
}
```

### Main Function

```
Node *bTreeToCList(Node *root)
{
	if (root == NULL)
		return NULL;

	Node *left = bTreeToCList(root->left);
	Node *right = bTreeToCList(root->right);

	root->left = root->right = root;

	return concatenate(concatenate(left, root), right);
}
```

__Output:__

> Circular Linked List is : 25 12 30 10 36 15