# Lowest Common Ancestor

BST in, if node's value is greater than both n1 and n2 then our LCA lies in the left side of the node, if it's is smaller than both n1 and n2, then LCA lies on the right side. Otherwise, the root is LCA (assuming that both n1 and n2 are present in BST).

Time Complexity: O(h).
Space Complexity: O(1).

```
node *lca(node* root, int n1, int n2)  
{  
    if (root == NULL) return NULL;  

    if (root->data > n1 && root->data > n2)  
        return lca(root->left, n1, n2);  
  
    if (root->data < n1 && root->data < n2)  
        return lca(root->right, n1, n2);  
  
    return root;  
}  
```

# Iterative Implementation:

**The above solution uses recursion. The recursive solution requires extra space in the form of the function call stack. So an iterative solution can be implemented which does not occupy space in the form of the function call stack.**

Time Complexity: O(h).
Space Complexity: O(1).

```
struct node *lca(struct node* root, int n1, int n2) 
{ 
    while (root != NULL) 
    { 
        if (root->data > n1 && root->data > n2) 
        root = root->left; 
  
        else if (root->data < n1 && root->data < n2) 
        root = root->right; 
  
        else break; 
    } 
    return root; 
} 
  
```

Exercise
The above functions assume that n1 and n2 both are in BST. If n1 and n2 are not present, then they may return an incorrect result. Extend the above solutions to return NULL if n1 or n2 or both not present in BST.