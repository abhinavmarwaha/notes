# Recursive

![Recursive](img/recursive.png)

How to calculate time complexity of recursive functions?
Time complexity of a recursive function can be written as a mathematical recurrence relation. To calculate time complexity, we must know how to solve recurrences. We will soon be discussing recurrence solving techniques as a separate post.
 T(n) = 2T(n/2) + cn (Merge Sort)

### Substitution Method 

We make a guess for the solution and then we use mathematical induction to prove the guess is correct or incorrect.

For example consider the recurrence T(n) = 2T(n/2) + n

We guess the solution as T(n) = O(nLogn). Now we use induction
to prove our guess.

We need to prove that T(n) <= cnLogn. We can assume that it is true
for values smaller than n.

T(n) = 2T(n/2) + n
    <= 2cn/2Log(n/2) + n
    =  cnLogn - cnLog2 + n
    =  cnLogn - cn + n
    <= cnLogn

### Recurrence Tree Method

In this method, we draw a recurrence tree and calculate the time taken by every level of tree. Finally, we sum the work done at all levels. To draw the recurrence tree, we start from the given recurrence and keep drawing till we find a pattern among levels. The pattern is typically a arithmetic or geometric series.

For example consider the recurrence relation 
T(n) = T(n/4) + T(n/2) + cn2

```
           cn2
         /      \
     T(n/4)     T(n/2)

If we further break down the expression T(n/4) and T(n/2), 
we get following recursion tree.

                cn2
           /           \      
       c(n2)/16      c(n2)/4
      /      \          /     \
  T(n/16)     T(n/8)  T(n/8)    T(n/4) 
Breaking down further gives us following
                 cn2
            /            \      
       c(n2)/16          c(n2)/4
       /      \            /      \
c(n2)/256   c(n2)/64  c(n2)/64    c(n2)/16
 /    \      /    \    /    \       /    \  
```

To know the value of T(n), we need to calculate sum of tree 
nodes level by level. If we sum the above tree level by level, 
we get the following series

T(n)  = c(n^2 + 5(n^2)/16 + 25(n^2)/256) + ....

The above series is geometrical progression with ratio 5/16.

To get an upper bound, we can sum the infinite series. 

We get the sum as (n2)/(1 - 5/16) which is O(n2)