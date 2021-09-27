
# Binary Tree 

Each node -> 2 children -> left and right

### Representaion

A node have:

1. Data
2. Pointer to left child
3. Pointer to right child

```
struct node  
{ 
  int data; 
  struct node *left; 
  struct node *right; 
};
```

### Example

```
#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
	int data; 
	struct node *left; 
	struct node *right; 
}; 

struct node* newNode(int data) 
{ 

   struct node* node = (struct node*)malloc(sizeof(struct node)); 

   node->data = data; 

   node->left = NULL; 
   node->right = NULL; 
   return(node); 
} 


int main() 
{ 

   struct node *root = newNode(1); 
/* 

	1 
	/ \ 
	NULL NULL 
*/

   root->left	 = newNode(2); 
   root->right	 = newNode(3); 

/* 
	1
	/ \ 
	2	 3 
	/ \ / \ 
	NULL NULL NULL NULL 
*/


   root->left->left = newNode(4); 

/*
	    1 
    /	 \ 
	 2		3 
	/ \	 / \ 
4 NULL NULL NULL 
    / \ 
  NULL NULL 
*/

   getchar(); 
   return 0; 
} 

```

### Properties

Nomenclature

```
l -> level
h -> height
n -> nodes
L -> Levels
```

1. max n at l is 2^l
2. max n at h -> 2^h -1 (when root's h = 1) as 1 + 2 + 4 + .. + 2^(h-1) , 2^(h+1) -1 (when root's h = 0) 
3. min h in Binary tree = Log2(N+1) __reverse of point 2__
4. A Binary Tree with L leaves has at least Log2L + 1 levels

```
 L <=  2^l-1  [From Point 1]
 l =   Log2L + 1 
 where l is the minimum number of levels. 
```

##### Full Binary Tree 

Only 0 or 2 children i.e. only leaf nodes have 0 children.

```
L = I + 1
Where L = Number of leaf nodes, I = Number of internal nodes

PROOF: https://www.geeksforgeeks.org/handshaking-lemma-and-interesting-tree-properties/
```

##### Complete Binary Tree

* All levels filled except
* last level -> all nodes are as left as possible 
  
APPLICATION: binary-heap

##### Perfect Binary Tree

* all nodes have 2 children except leaf -> 0 
* All levels filled 
* n -> 2^h - 1 n with root's h = 1

##### Balanced Binary Tree

* h = log2n
* AVL - h(left sub tree) - h(right sub tree) ≈ 1
* Red-Black trees - Black nodes on every root to leaf paths is the same and there are no adjacent red nodes // TODO don't know
* O(log n) time for search, insert and delete. <performance wise good>

##### A degenerate (or pathological) tree 

* internal node -> 1 child 
* Performance = Linked List

##### Full

```
            18                                  
           /    \   
         15     20    
        /  \       
      40    50   
    /   \
   30   50
```

##### Complete

```
               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
     /  \   /
    8   7  9 
```

##### Perfect

```
               18
           /       \  
         15         30  
        /  \        /  \
      40    50    100   40
```

##### Balanced

// TODO example

##### Degenerate

```
      10
      /
    20
     \
     30
      \
      40
```  

### Applications

* Store hierarchical data, like folder structure, organization structure, XML/HTML data.
* Binary Search Tree is a tree that allows fast search, insert, delete on a sorted data. It also allows finding closest item
* Heap is a tree data structure which is implemented using arrays and used to implement priority queues.
B-Tree and B+ Tree : They are used to implement indexing in databases.
Syntax Tree: Used in Compilers.
K-D Tree: A space partitioning tree used to organize points in K dimensional space.
Trie : Used to implement dictionaries with prefix lookup.
Suffix Tree : For quick pattern searching in a fixed text.
Spanning Trees and shortest path trees are used in routers and bridges respectively in computer networks
As a workflow for compositing digital images for visual effects.