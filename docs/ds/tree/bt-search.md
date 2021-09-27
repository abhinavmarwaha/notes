# Search

```
bool iterativeSearch(node *root, int x) 
{
    if (root == NULL) 
        return false; 

    queue<node *> q; 

    q.push(root); 

    while (q.empty() == false) 
    {
        node *node = q.front(); 
        if (node->data == x) 
            return true; 

        q.pop(); 
        if (node->left != NULL) 
            q.push(node->left); 
        if (node->right != NULL) 
            q.push(node->right); 
    } 

    return false; 
} 
```