# Level Order

### Queue

```
void printLevelOrderWithQueue(Node *root)
{
    if (root == NULL)  return;
 
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

### Reverse

```
void reverseLevelOrder(node* root) 
{ 
    int h = height(root); 
    int i; 
    for (i=h; i>=1; i--) //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER 
        printGivenLevel(root, i); 
}

void reverseLevelOrderWithStack(node* root)
{
    stack <node *> S;
    queue <node *> Q;
    Q.push(root);

    while (Q.empty() == false)
    {
        root = Q.front();
        Q.pop();
        S.push(root);
  
        if (root->right)
            Q.push(root->right);

        if (root->left)
            Q.push(root->left);
    }

    while (S.empty() == false)
    {
        root = S.top();
        cout << root->data << " ";
        S.pop();
    }
}
```

### Given Level

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