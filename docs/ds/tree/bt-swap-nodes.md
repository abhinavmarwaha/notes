# Binary Tree Swapping

* Store inorder of BST in auxiliary array. (will be sorted)
* Sort the auxiliary array. 
* Finally, insert the auxiliary array elements back to the BST, keeping the structure of the BST same. 

The time complexity of this method is O(nLogn) and the auxiliary space needed is O(n).

We can solve this in O(n) time and with a single traversal of the given BST. 

Since inorder traversal of BST is always a sorted array, the problem can be reduced to a problem where two elements of a sorted array are swapped. There are two cases that we need to handle:

1. The swapped nodes are not adjacent in the inorder traversal of the BST. 

```
For example, Nodes 5 and 25 are swapped in {3 5 7 8 10 15 20 25}. 
The inorder traversal of the given tree is 3 25 7 8 10 15 20 5 
```

If we observe carefully, during inorder traversal, we find node 7 is smaller than the previous visited node 25. Here save the context of node 25 (previous node). Again, we find that node 5 is smaller than the previous node 20. This time, we save the context of node 5 (the current node ). Finally, swap the two node’s values.

2. The swapped nodes are adjacent in the inorder traversal of BST.

```
For example, Nodes 7 and 8 are swapped in {3 5 7 8 10 15 20 25}. 
The inorder traversal of the given tree is 3 5 8 7 10 15 20 25 
```

Unlike case #1, here only one point exists where a node value is smaller than the previous node value. 
e.g. node 7 is smaller than node 8. 

How to Solve? We will maintain three-pointers, first, middle, and last. 

When we find the first point where the current node value is smaller than the previous node value, we update the first with the previous node & the middle with the current node. 

When we find the second point where the current node value is smaller than the previous node value, we update the last with the current node.

In the case of #2, we will never find the second point. 
 
So, the last pointer will not be updated. After processing, if the last node value is null, then two swapped nodes of BST are adjacent.