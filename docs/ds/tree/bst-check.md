# Checking BST

### METHOD 1 (Simple but Wrong)

```
int isBST(struct node* node)  
{  
  if (node == NULL)  
    return 1;  
      
  if (node->left != NULL && node->left->data > node->data)  
    return 0;  
      
  if (node->right != NULL && node->right->data < node->data)  
    return 0;  
    
  if (!isBST(node->left) || !isBST(node->right))  
    return 0;  
      
  return 1;  
} 
```

But it returns true if a node is grater than root but is present in left most leaf

### METHOD 2 (Correct but not efficient)

```
int isBST(struct node* node) 
{ 
if (node == NULL) 
	return 1; 
if (node->left!=NULL && maxValue(node->left) > node->data) 
	return 0; 
	
if (node->right!=NULL && minValue(node->right) < node->data) 
	return 0; 
	
if (!isBST(node->left) || !isBST(node->right)) 
	return 0; 
	
return 1; 
} 
```

### METHOD 3 (Correct and Efficient):

```
int isBST(node* node)  
{  
    return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  
  
int isBSTUtil(node* node, int min, int max)  
{  
    if (node==NULL)  
        return 1;  
              
    if (node->data < min || node->data > max)  
        return 0;  
      
    return
        isBSTUtil(node->left, min, node->data-1) &&   
        isBSTUtil(node->right, node->data+1, max);
}  

```

Time Complexity: O(n)
Auxiliary Space : O(1) if Function Call Stack size is not considered, otherwise O(n)

### Simplified Method 3

```
bool isBST(Node* root, Node* l=NULL, Node* r=NULL) 
{ 
    if (root == NULL) 
        return true; 

    if (l != NULL and root->data <= l->data) 
        return false; 
  
    if (r != NULL and root->data >= r->data) 
        return false; 
  
    return isBST(root->left, l, root) and 
           isBST(root->right, root, r); 
} 
```

### METHOD 4(Using In-Order Traversal)

1. Do In-Order Traversal of the given tree and store the result in a temp array.
2. Check if the temp array is sorted in ascending order, if it is, then the tree is BST.

```
bool isBST(node* root)  
{  
    static node *prev = NULL;  

    if (root)  
    {  
        if (!isBST(root->left))  
        return false;  
  
        if (prev != NULL &&  
            root->data <= prev->data)  
        return false;  
  
        prev = root;  
  
        return isBST(root->right);  
    }  
  
    return true;  
}  
  
```