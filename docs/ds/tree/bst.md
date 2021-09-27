# Binary Search Tree

### Insertion

```
struct node* insert(struct node* node, int key)
{
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);

	return node;
}
```

### Min Value

```
struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}
```

### Deletion

```
struct node* deleteNode(struct node* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);

	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	else {
		if (root.left==NULL and root.right==NULL):
			return NULL
	
		elif (root->left == NULL) {
			struct node* temp = root->right;
			free(root);
			return temp;
		}

		else if (root->right == NULL) {
			struct node* temp = root->left;
			free(root);
			return temp;
		}

		struct node* temp = minValueNode(root->right);

		root->key = temp->key;

		root->right = deleteNode(root->right, temp->key);
	}
	return root;
}
```

*node-based binary tree data structure* 

* The left subtree of a node contains only nodes with keys lesser than the node’s key.
* The right subtree of a node contains only nodes with keys greater than the node’s key.
* The left and right subtree -> binary search tree. 
* no duplicate nodes.

### Facts

* Inorder traversal -> sorted output.
* We can construct a BST with only Preorder or Postorder or Level Order traversal. Note that we can always get inorder traversal by sorting the only given traversal.
* Number of unique BSTs with n distinct keys is Catalan Number
* Each node (item in the tree) has a distinct key.
 
### Search

```
struct node* search(struct node* root, int key)
{
    if (root == NULL || root->key == key)
       return root;
   
    if (root->key < key)
       return search(root->right, key);
 
    return search(root->left, key);
}
```

### Insert

```
BST* BST ::Insert(BST* root, int value)
{
    if (!root) 
    {
        return new BST(value);
    }
 
    if (value > root->data) 
    {
        root->right = Insert(root->right, value);
    }
    else
    {
        root->left = Insert(root->left, value);
    }
 
    return root;
}
```

### Deletion

* leaf -> simply delete
* one child -> put it in the deleted place
* two child -> place the inorder successor or predeccesor in its place
               The important thing to note is, inorder successor is needed only when right child is not empty. In this particular case, inorder successor can be obtained by finding the minimum value in right child of the node.



```

struct node* deleteNode(struct node* root, int key) 
{ 
    if (root == NULL) return root; 

    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    else
    {  
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        struct node* temp = minValueNode(root->right); 
  
        root->key = temp->key; 
  
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
```

Time Complexity:  O(h)... skewed tree -> O(n)

*Optimization*

In the above recursive code, we recursively call delete() for successor. We can avoid recursive call by keeping track of parent node of successor so that we can simply remove the successor by making child of parent as NULL. We know that successor would always be a leaf node.

```
Node* deleteNode(Node* root, int k) 
{ 
    if (root == NULL) 
        return root; 
  
    if (root->key > k) { 
        root->left = deleteNode(root->left, k); 
        return root; 
    } 
    else if (root->key < k) { 
        root->right = deleteNode(root->right, k); 
        return root; 
    } 
  
    if (root->left == NULL) { 
        Node* temp = root->right; 
        delete root; 
        return temp; 
    } 
    else if (root->right == NULL) { 
        Node* temp = root->left; 
        delete root; 
        return temp; 
    } 
  
    else { 
  
        Node* succParent = root; 
          
        Node *succ = root->right; 
        while (succ->left != NULL) { 
            succParent = succ; 
            succ = succ->left; 
        } 
  
        
        if (succParent != root) 
            succParent->left = succ->right; 
        else
            succParent->right = succ->right; 
  
        root->key = succ->key; 
  
        delete succ;          
        return root; 
    } 
} 
```

### MinValue

O(n) Worst case happens for left skewed trees.

Similarly we can get the maximum value by recursively traversing the right node of a binary search tree.

```
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
```

### Inorder predecessor and successor for a given key in BST

```
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) 
{ 
    if (root == NULL)  return ; 
  
    if (root->key == key) 
    { 
        if (root->left != NULL) 
        { 
            Node* tmp = root->left; 
            while (tmp->right) 
                tmp = tmp->right; 
            pre = tmp ; 
        } 
  
        if (root->right != NULL) 
        { 
            Node* tmp = root->right ; 
            while (tmp->left) 
                tmp = tmp->left ; 
            suc = tmp ; 
        } 
        return ; 
    } 
  
    if (root->key > key) 
    { 
        suc = root ; 
        findPreSuc(root->left, pre, suc, key) ; 
    } 
    else // go to right subtree 
    { 
        pre = root ; 
        findPreSuc(root->right, pre, suc, key) ; 
    } 
} 
  
```

Another Approach : 
We can also find the inorder successor and inorder predecessor using inorder traversal . Check if the current node is smaller than the given key for predecessor and for successor, check if it is greater than the given key . If it is greater than the given key then, check if it is smaller than the already stored value in successor then, update it . At last, get the predecessor and successor stored in q(successor) and p(predecessor). 

```
void find_p_s(Node* root,int a,  
              Node** p, Node** q) 
{ 
    if(!root) 
        return ; 
              
    find_p_s(root->left, a, p, q); 
      
    if(root&&root->data > a) 
    { 
          
        if((!*q) || (*q) && (*q)->data > root->data) 
                *q = root; 
    } 

    else if(root && root->data < a) 
    { 
        *p = root; 
    } 
      
    find_p_s(root->right, a, p, q); 
} 
```