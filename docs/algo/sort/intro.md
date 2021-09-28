# Sorting

change order of collected elements to whats required.

### In Place

* Does not use extra space for manipulating the input but may require a small though nonconstant extra space for its operation. 
* Usually, this space is O(log n), though sometimes anything in o(n) (Smaller than linear) is allowed.

### Stable

![Stablity](img/stability.png)

* Stability is mainly important when we have key value pairs with duplicate keys possible (like people names as keys and their details as values).
* And we wish to sort these objects by keys.
* equivalent elements retain their relative positions.
* need stability when in (key, value) -> keys are equal but values have some significance of order.
  * Indistinguishable, (integers), all keys are different. -> do not need.
  * Relative order is maintained in an Unstable Sort -> highly unlikely.
* Does not effect performance and takes some extra space, possibly theta(n). -> to make unstable algo to stable.
* by changing the key comparison operation so that the comparison of two keys considers position as a factor for objects with equal keys.

### External Algo

In computing, external memory algorithms or out-of-core algorithms are algorithms that are designed to process data that are too large to fit into a computer's main memory at once.

### Lower bound for comparison based sorting

Input: <a1, a2, . . . , an>.
Output: permutation / reordering ->  <a‘1, a‘2, . . . , a‘n> when a‘1 <= a‘2 ….. <= a‘n.

* uses comparison operators
* decision trees.
* A decision tree -> full binary tree that represents the comparisons between elements that are performed by a particular sorting algorithm operating on an input of a given size. 
* tracing a path from the root of the decision tree to a leaf.
* At each internal node, a comparison ai <= aj is made. 
* left subtree -> ai <= aj.
* right subtree -> ai > aj.
* When reach leaf, ordering is done.

1. n! permutations on n -> leaves for the sorting algorithm to sort properly.
2. x -> maximum number
3. maximum height of the decison tree_ -> x. 
4. A tree with maximum height x has at most 2^x leaves.

```
    n!  <= 2^x

 Taking Log on both sides.

    log2(n!)  <= x

As log2(n!) = Θ(nLogn) => x = Ω(nLog2n)
```

Hence Heapsort, merge sort -> asymptotically optimal comparison sorts.

### minimum number of memory writes?

Some huge data set is very expensive -> EEPROMs or Flash memory -> each write reduces the lifespan of the memory.

Selection Sort makes least number of writes (it makes O(n) swaps).  

Cycle Sort -> zero times -> correct position or written one time to its correct position.

*Hence Cycle Sort* 