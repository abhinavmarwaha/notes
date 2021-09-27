# Pseudo-polynomial

* An algorithm whose worst case time complexity depends on numeric value of input (not number of inputs) is called Pseudo-polynomial algorithm.
* For example, consider the problem of counting frequencies of all elements in an array of positive numbers.
* A pseudo-polynomial time solution for this is to first find the maximum value, then iterate from 1 to maximum value and for each value, find its frequency in array.
* This solution requires time according to maximum value in input array, therefore pseudo-polynomial.
* On the other hand, an algorithm whose time complexity is only based on number of elements in array (not value) is considered as polynomial time algorithm.

# Pseudo-polynomial and NP-Completeness

* Some NP-Complete problems have Pseudo Polynomial time solutions.
* For example, Dynamic Programming Solutions of 0-1 Knapsack, Subset-Sum and Partition problems are Pseudo-Polynomial.
* NP complete problems that can be solved using a pseudo-polynomial time algorithms are called weakly NP-complete.