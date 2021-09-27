In every finite undirected graph, an even number of vertices will always have odd degree :

The handshaking lemma is a consequence of the degree sum formula (also sometimes called the handshaking lemma):

sum(deg(V)) = 2(E)

#  k-ary tree where every node has either 0 or k children

```
 L = (k - 1)*I + 1
Where L = Number of leaf nodes
      I = Number of internal nodes  
```

## Proof

### With handshaking lemma

Proof can be divided in two cases.

Case 1 (Root is Leaf):There is only one node in tree. The above formula is true for single node as L = 1, I = 0.

Case 2 (Root is Internal Node): For trees with more than 1 nodes, root is always internal node. The above formula can be proved using Handshaking Lemma for this case. A tree is an undirected acyclic graph.

Total number of edges in Tree is number of nodes minus 1, i.e., |E| = L + I – 1.

All internal nodes except root in the given type of tree have degree k + 1. Root has degree k. All leaves have degree 1. Applying the Handshaking lemma to such trees, we get following relation.

```
  Sum of all degrees  = 2 * (Sum of Edges)

  Sum of degrees of leaves + 
  Sum of degrees for Internal Node except root + 
  Root's degree = 2 * (No. of nodes - 1)

  Putting values of above terms,   
  L + (I-1)*(k+1) + k = 2 * (L + I - 1) 
  L + k*I - k + I -1 + k = 2*L  + 2I - 2
  L + K*I + I - 1 = 2*L + 2*I - 2
  K*I + 1 - I = L
  (K-1)*I + 1 = L   
```

So the above property is proved using Handshaking Lemma, let us discuss one more interesting property.

### Without it

Since there are I internal nodes, each having K children, therefore total children in the tree = K * I.

There are I-1 internal nodes which are children of some other node (root has been excluded hence one less than the total number of internal nodes)

That is, out of these K* I children, I-1 are internal nodes and therefore the rest (K*I – (I-1)) are leaves.

Hence L = (K-1)*I + 1.

# In Binary tree,

```
   L = T + 1
Where L = Number of leaf nodes
      T = Number of internal nodes with two children 
```

## Proof

### Case 1

```
T = 0 
L = 1
```

### Case 2

Root has two children, i.e., degree of root is 2.

```
   Sum of degrees of nodes with two children except root + 
   Sum of degrees of nodes with one child + 
   Sum of degrees of leaves + Root's degree = 2 * (No. of Nodes - 1)   

   Putting values of above terms,
   (T-1)*3 + S*2 + L + 2 = (S + T + L - 1)*2

   Cancelling 2S from both sides.
     (T-1)*3 + L + 2 = (T + L - 1)*2
     T - 1 = L - 2
     T = L - 1 
```

### Case 3: 

Root has one child, i.e., degree of root is 1.

```
   Sum of degrees of nodes with two children + 
   Sum of degrees of nodes with one child except root + 
   Sum of degrees of leaves + Root's degree = 2 * (No. of Nodes - 1)   

   Putting values of above terms,
   T*3 + (S-1)*2 + L + 1 = (S + T + L - 1)*2

   Cancelling 2S from both sides.
     3*T + L -1 = 2*T + 2*L - 2
     T - 1 = L - 2
     T = L - 1 
```