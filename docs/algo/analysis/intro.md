# Why

Care about user friendliness, modularity, security, maintainability, etc?

turns out you cant do that wihtout perfoormance.
So performance is like currency through which we can buy all the above things

, performance == scale.

# Why not just run it? :/ see running time

1) diffrent machines different comparison.
2) Different input different comparison.

Big Idea -> Asymptotic analysis (just depends on inputt)

The reason is the order of growth of Binary Search with respect to input size is logarithmic while the order of growth of Linear Search is linear. So the machine dependent constants can always be ignored after a certain value of input size.

Linear Search running time in seconds on A: 0.2 * n
Binary Search running time in seconds on B: 1000*log(n)

So, With Asymptotic Analysis, we can’t judge which one is better as we ignore constants in Asymptotic Analysis.

Also, in Asymptotic analysis, we always talk about input sizes larger than a constant value
So, you may end up choosing an algorithm that is Asymptotically slower but faster for your software.

# Worst Case

Upper bound of running -> should know when.
Θ(n)

# Average Case (Rarely)

 For the linear search problem, let us assume that all cases are uniformly distributed (including the case of x not being present in array). So we sum all the cases and divide the sum by (n+1). Following is the value of average case time complexity.

# Best Case Analysis (Bogus)

 Θ(1)

 # Why not average?

 The average case analysis is not easy to do in most of the practical cases and it is rarely done. In the average case analysis, we must know (or predict) the mathematical distribution of all possible inputs.

 For some algorithms, all the cases are asymptotically same, i.e., there are no worst and best cases.
 eg Merge sort - > Θ(nLogn) 

Most of the other sorting algorithms have worst and best cases.
 For example, in the typical implementation of Quick Sort (where pivot is chosen as a corner element), the worst occurs when the input array is already sorted and the best occur when the pivot elements always divide array in two halves. For insertion sort, the worst case occurs when the array is reverse sorted and the best case occurs when the array is sorted in the same order as output. 

 The main idea of asymptotic analysis is to 
 * have a measure of efficiency of algorithms that doesn’t depend on machine specific constants, 
 * and doesn’t require algorithms to be implemented and time taken by programs to be compared. 

# Notations

```
Θ(g(n)) = {f(n): there exist positive constants c1, c2 and n0 such 
                 that 0 <= c1*g(n) <= f(n) <= c2*g(n) for all n >= n0}
```

The theta notation bounds a functions from above and below, so it defines exact asymptotic behavior.
A simple way to get Theta notation of an expression is to drop low order terms and ignore leading constants

*f(n) must be non-negative for values of n greater than n0.*

### Why drop?
its fine chill.

```
O(g(n)) = { f(n): there exist positive constants c and 
                  n0 such that 0 <= f(n) <= c*g(n) for 
                  all n >= n0}
```

he Big O notation defines an upper bound of an algorithm, it bounds a function only from above

O(n^2) also covers linear time. -> quick sort

```
Ω (g(n)) = {f(n): there exist positive constants c and
                  n0 such that 0 <= c*g(n) <= f(n) for
                  all n >= n0}.
```

 Ω notation provides an asymptotic lower bound.

 # Properties


1 General Properties :

If f(n) is O(g(n)) then a*f(n) is also O(g(n)) ; where a is a constant.
If f(n) is Θ(g(n)) then a*f(n) is also Θ(g(n)) ; where a is a constant.
If f(n) is Ω (g(n)) then a*f(n) is also Ω (g(n)) ; where a is a constant.

2 Reflexive Properties :

If f(n) is given then f(n) is O(f(n)).
If f(n) is given then f(n) is Θ(f(n)).
If f(n) is given then f(n) is Ω (f(n)).

Transitive Properties :
  
If f(n) is O(g(n)) and g(n) is O(h(n)) then f(n) = O(h(n)) .
If f(n) is Θ(g(n)) and g(n) is Θ(h(n)) then f(n) = Θ(h(n)) .
If f(n) is Ω (g(n)) and g(n) is Ω (h(n)) then f(n) = Ω (h(n))

Symmetric Properties :

If f(n) is Θ(g(n)) then g(n) is Θ(f(n)) .
*This property only satisfies for Θ notation.*

Transpose Symmetric Properties :

If f(n) is O(g(n)) then g(n) is Ω (f(n)).
*This property only satisfies for O and Ω notations.*

Some More Properties :
If f(n) = O(g(n)) and f(n) = Ω(g(n)) then f(n) = Θ(g(n))
If f(n) = O(g(n)) and d(n)=O(e(n))
then f(n) + d(n) = O( max( g(n), e(n) ))
Example: f(n) = n i.e O(n)
d(n) = n² i.e O(n²)
then f(n) + d(n) = n + n² i.e O(n²)
If f(n)=O(g(n)) and d(n)=O(e(n))
then f(n) * d(n) = O( g(n) * e(n) )
Example: f(n) = n i.e O(n)
d(n) = n² i.e O(n²)
then f(n) * d(n) = n * n² = n³ i.e O(n³)

Time complexity of all computer algorithms can be written as Ω(1)

Little o provides strict upper bound (equality condition is removed from Big O) and little omega provides strict lower bound (equality condition removed from big omega)

Little ο asymptotic notation
: Let f(n) and g(n) be functions that map positive integers to positive real numbers. We say that f(n) is ο(g(n)) (or f(n) Ε ο(g(n))) if for any real constant c > 0, there exists an integer constant n0 ≥ 1 such that 0 ≤ f(n) < c*g(n).

Thus, little o() means loose upper-bound of f(n). Little o is a rough estimate of the maximum order of growth whereas Big-Ο may be the actual order of growth.

In mathematical relation,
f(n) = o(g(n)) means
lim  f(n)/g(n) = 0
n→∞

lim  f(n)/g(n) = lim  (7n + 8)/(n2) = lim  7/2n = 0 (l’hospital)
n→∞ n→∞ n→∞
hence 7n + 8 ∈ o(n2)

Little ω asymptotic notation

Let f(n) and g(n) be functions that map positive integers to positive real numbers. We say that f(n) is ω(g(n)) (or f(n) ∈ ω(g(n))) if for any real constant c > 0, there exists an integer constant n0 ≥ 1 such that f(n) > c * g(n) ≥ 0 for every integer n ≥ n0.

Little Omega (ω) is a rough estimate of the order of the growth whereas Big Omega (Ω) may represent exact order of growth. We use ω notation to denote a lower bound that is not asymptotically tight.
And, f(n) ∈ ω(g(n)) if and only if g(n) ∈ ο((f(n)).

if f(n) ∈ ω(g(n)) then,

lim  f(n)/g(n) = ∞
n→∞

Prove that 4n + 6 ∈ ω(1);

Lower and Upper Bound Theory

Lower Bound –
Let L(n) be the running time of an algorithm A(say), then g(n) is the Lower Bound of A if there exist two constants C and N such that L(n) >= C*g(n) for n > N. Lower bound of an algorithm is shown by the asymptotic notation called Big Omega (or just Omega).
Upper Bound –
Let U(n) be the running time of an algorithm A(say), then g(n) is the Upper Bound of A if there exist two constants C and N such that U(n) <= C*g(n) for n > N. Upper bound of an algorithm is shown by the asymptotic notation called Big Oh(O) (or just Oh).

1. Lower Bound Theory:
According to the lower bound theory, for a lower bound L(n) of an algorithm, it is not possible to have any other algorithm (for a common problem) whose time complexity is less than L(n) for random input. Also every algorithm must take at least L(n) time in worst case. Note that L(n) here is the minimum of all the possible algorithm, of maximum complexity.

The Lower Bound is a very important for any algorithm. Once we calculated it, then we can compare it with the actual complexity of the algorithm and if their order are same then we can declare our algorithm as optimal. So in this section we will be discussing about techniques for finding the lower bound of an algorithm.

Note that our main motive is to get an optimal algorithm, which is the one having its Upper Bound Same as its Lower Bound (U(n)=L(n)). Merge Sort is a common example of an optimal algorithm.

Trivial Lower Bound –
It is the easiest method to find the lower bound. The Lower bounds which can be easily observed on the basis of the number of input taken and the number of output produces are called Trivial Lower Bound.

Example: Multiplication of n x n matrix, where,

Input: For 2 matrix we will have 2n2 inputs
Output: 1 matrix of order n x n, i.e.,  n2 outputs 
In the above example its easily predictable that the lower bound is O(n2).

Computational Model –
The method is for all those algorithms that are comparison based. For example in sorting we have to compare the elements of the list among themselves and then sort them accordingly. Similar is the case with searching and thus we can implement the same in this case. Now we will look at some examples to understand its usage.

Ordered Searching –
It is a type of searching in which the list is already sorted.

Example-1: Linear search
Explanation –
In linear search we compare the key with first element if it does not match we compare with second element and so on till we check against the nth element. Else we will end up with a failure.

Example-2: Binary search
Explanation –
In binary search, we check the middle element against the key, if it is greater we search the first half else we check the second half and repeat the same process.
The diagram below there is an illustration of binary search in an array consisting of 4 elements

Calculating the lower bound: The max no of comparisons are n. Let there be k levels in the tree.

No. of nodes will be 2k-1
The upper bound of no of nodes in any comparison based search of an element in list of size n will be n as there are maximum of n comparisons in worst case scenario 2k-1
Each level will take 1 comparison thus no. of comparisons k≥|log2n|
Thus the lower bound of any comparison based search from a list of n elements cannot be less than log(n). Therefore we can say that Binary Search is optimal as its complexity is Θ(log n).

Sorting –
The diagram below is an example of tree formed in sorting combinations with 3 elements.

Example – For n elements, finding lower bound using computation model.
Explanation –
For n elements we have a total on n! combinations (leaf nodes). (Refer the diagram the total combinations are 3! or 6) also it is clear that the tree formed is a binary tree. Each level in the diagram indicates a comparison. Let there be k levels => 2k is the total number of leaf nodes in a full binary tree thus in this case we have n!≤2k.

As the k in the above example is the no of comparisons thus by computational model lower bond = k.

Now we can say that,
n!≤2T(n)
Thus, 
T(n)>|log n!| 
=> n!<=nn
Thus,
log n!<=log nn
Taking ceiling function on both sides, we get
|-log nn-|>=|-log n!-|
Thus complexity becomes Θ(lognn) or Θ(nlogn) 

Using Lower bond theory to solve algebraic problem:

Straight Line Program –
The type of programs build without any loops or control structures is called Straight Line Program. For example,
filter_none
brightness_4
//summing to nos 
Sum(a, b) 
{ 
    //no loops and no control structures 
    c:= a+b; 
    return c; 
} 
Algebraic Problem –
Problems related to algebra like solving equations inequalities etc., comes under algebraic problems. For example, solving equation ax2+bx+c with simple programming.
filter_none
brightness_4
Algo_Sol(a, b, c, x) 
{  
    //1 assignment 
    v:=a*x;  
  
    //1 assignment 
    v:=v+b; 
  
    //1 assignment 
    v:=v*x; 
  
    //1 assignment 
    ans:=v+c; 
    return ans; 
}     
Complexity for solving here is 4 (excluding the returning).



The above example shows us a simple way to solve an equation for 2 degree polynomial i.e., 4 thus for nth degree polynomial we will have complexity of O(n2).

Let us demonstrate via an algorithm.

Example: anxn+an-1xn-1+an-2xn-2+…+a1x+a0 is a polynomial of degree n.

filter_none
brightness_4
pow(x, n)  
  {  
    p := 1;  
    
    //loop from 1 to n  
    for i:=1 to n  
        p := p*x;  
  
    return p;  
  }  
  
polynomial(A, x, n)  
  {  
     int p, v:=0;  
     for i := 0 to n  
    
         //loop within a loop from 0 to n 
         v := v + A[i]*pow(x, i);  
     return v;  
  }  
Loop within a loop => complexity = O(n2);

Now to find an optimal algorithm we need to find the lower bound here (as per lower bound theory). As per Lower Bound Theory, The optimal algorithm to solve the above problem is the one having complexity O(n). Lets prove this theorem using lower bounds.

Theorem: To prove that optimal algo of solving a n degree polynomial is O(n)
Proof: The best solution for reducing the algo is to make this problem less complex by dividing the polynomial into several straight line problems.

=> anxn+an-1xn-1+an-2xn-2+...+a1x+a0 
can be written as, 
((..(anx+an-1)x+..+a2)x+a1)x+a0
Now, algorithm will be as,
v=0
v=v+an
v=v*x
v=v+an-1
v=v*x
...
v=v+a1
v=v*x
v=v+a0 
filter_none
brightness_4
polynomial(A, x, n)  
     { 
      int p, v=0;  
  
      // loop executed n times 
      for i = n to 0  
             v = (v + A[i])*x; 
  
         return v; 
      } 
Clearly, the complexity of this code is O(n). This way of solving such equations is called Horner’s method. Here is were lower bound theory works and give the optimum algorithm’s complexity as O(n).

2. Upper Bound Theory:
According to the upper bound theory, for an upper bound U(n) of an algorithm, we can always solve the problem in at most U(n) time.Time taken by a known algorithm to solve a problem with worse case input gives us the upper bound.


# Time complexity classes

O(1)
loop with constant 
swap

1) O(n): if the loop variables is incremented / decremented by a constant amount.
3) O(nc): Time complexity of nested loops is equal to the number of times the innermost statement is executed.
4) O(Logn) Time Complexity of a loop is considered as O(Logn) if the loop variables is divided / multiplied by a constant amount.
5) Binary -> is 1, c, c2, c3, … ck. If we put k equals to Logcn, we get cLogcn which is n.
5) O(LogLogn) Time Complexity of a loop is considered as O(LogLogn) if the loop variables is reduced / increased exponentially by a constant amount.

   // Here c is a constant greater than 1   
   for (int i = 2; i <=n; i = pow(i, c)) { 
       // some O(1) expressions
   }
   //Here fun is sqrt or cuberoot or any other constant root
   for (int i = n; i > 1; i = fun(i)) { 
       // some O(1) expressions
   }
See this for mathematical details.

https://www.geeksforgeeks.org/time-complexity-loop-loop-variable-expands-shrinks-exponentially/

How to combine time complexities of consecutive loops?
When there are consecutive loops, we calculate time complexity as sum of time complexities of individual loops.

How to calculate time complexity when there are many if, else statements inside loops?

Consider worst case bitch! What did you expect you little piece of shit

For example consider the linear search function where we consider the case when element is present at the end or not present at all.
When the code is too complex to consider all if-else cases, we can get an upper bound by ignoring if else and other complex control statements.



How to calculate time complexity of recursive functions?
Time complexity of a recursive function can be written as a mathematical recurrence relation. To calculate time complexity, we must know how to solve recurrences. We will soon be discussing recurrence solving techniques as a separate post.

# Recursive

 T(n) = 2T(n/2) + cn (Merge Sort)

1) Substitution Method: We make a guess for the solution and then we use mathematical induction to prove the guess is correct or incorrect.

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

2) Recurrence Tree Method: In this method, we draw a recurrence tree and calculate the time taken by every level of tree. Finally, we sum the work done at all levels. To draw the recurrence tree, we start from the given recurrence and keep drawing till we find a pattern among levels. The pattern is typically a arithmetic or geometric series.

For example consider the recurrence relation 
T(n) = T(n/4) + T(n/2) + cn2

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

To know the value of T(n), we need to calculate sum of tree 
nodes level by level. If we sum the above tree level by level, 
we get the following series
T(n)  = c(n^2 + 5(n^2)/16 + 25(n^2)/256) + ....
The above series is geometrical progression with ratio 5/16.

To get an upper bound, we can sum the infinite series. 
We get the sum as (n2)/(1 - 5/16) which is O(n2)
3) Master Method:
Master Method is a direct way to get the solution. The master method works only for following type of recurrences or for recurrences that can be transformed to following type.



T(n) = aT(n/b) + f(n) where a >= 1 and b > 1
There are following three cases:
1. If f(n) = Θ(nc) where c < Logba then T(n) = Θ(nLogba)

2. If f(n) = Θ(nc) where c = Logba then T(n) = Θ(ncLog n)

3.If f(n) = Θ(nc) where c > Logba then T(n) = Θ(f(n))

How does this work?
Master method is mainly derived from recurrence tree method. If we draw recurrence tree of T(n) = aT(n/b) + f(n), we can see that the work done at root is f(n) and work done at all leaves is Θ(nc) where c is Logba. And the height of recurrence tree is Logbn
Master Theorem
In recurrence tree method, we calculate total work done. If the work done at leaves is polynomially more, then leaves are the dominant part, and our result becomes the work done at leaves (Case 1). If work done at leaves and root is asymptotically same, then our result becomes height multiplied by work done at any level (Case 2). If work done at root is asymptotically more, then our result becomes work done at root (Case 3).

Examples of some standard algorithms whose time complexity can be evaluated using Master Method
Merge Sort: T(n) = 2T(n/2) + Θ(n). It falls in case 2 as c is 1 and Logba] is also 1. So the solution is Θ(n Logn)

Binary Search: T(n) = T(n/2) + Θ(1). It also falls in case 2 as c is 0 and Logba is also 0. So the solution is Θ(Logn)

Notes:
1) It is not necessary that a recurrence of the form T(n) = aT(n/b) + f(n) can be solved using Master Theorem. The given three cases have some gaps between them. For example, the recurrence T(n) = 2T(n/2) + n/Logn cannot be solved using master method.

2) Case 2 can be extended for f(n) = Θ(ncLogkn)
If f(n) = Θ(ncLogkn) for some constant k >= 0 and c = Logba, then T(n) = Θ(ncLogk+1n)

http://www.csd.uwo.ca/~moreno//CS424/Ressources/master.pdf
























MISSSING











# Auxiliary Space 
extra or temporary space used by an algorithm.

# Space Complexity 
total space taken by the algorithm with respect to the input size. 
Space complexity includes both Auxiliary space and space used by input.

For example, if we want to compare standard sorting algorithms on the basis of space, then Auxiliary Space would be a better criteria than Space Complexity. Merge Sort uses O(n) auxiliary space, Insertion sort and Heap Sort use O(1) auxiliary space. Space complexity of all these sorting algorithms is O(n) though.


## Example

```

void fun() 
{ 
   int i, j; 
   for (i=1; i<=n; i++) 
      for (j=1; j<=log(i); j++) 
         printf("GeeksforGeeks"); 
} 
```

Θ(log 1) + Θ(log 2) + Θ(log 3) + . . . . + Θ(log n) 

 Θ (log n!)
approxs
Θ(n log n)
for large valusee of n

by Stirling’s approximation (or Stirling’s formula).

      log n! = n log n - n + O(log(n)) 


'''

void fun(int n) 
{ 
   int j = 1, i = 0; 
   while (i < n) 
   { 
       // Some O(1) task 
       i = i + j; 
       j++; 
   } 
} 
'''

 x(x+1)/2 after x iterations

 then x(x+1)/2 < n ===== Θ(√n).

 '''
 void fun(int n, int k) 
{ 
	for (int i=1; i<=n; i++) 
	{ 
	int p = pow(i, k); 
	for (int j=1; j<=p; j++) 
	{ 
		// Some O(1) work 
	} 
	} 
} 

 '''

 1k + 2k + 3k + … n1k.

'''
k=1
Sum = 1 + 2 + 3 ... n 
    = n(n+1)/2 
    = n2/2 + n/2

k=2
Sum = 12 + 22 + 32 + ... n12.
    = n(n+1)(2n+1)/6
    = n3/3 + n2/2 + n/6

k=3
Sum = 13 + 23 + 33 + ... n13.
    = n2(n+1)2/4
    = n4/4 + n3/2 + n2/4     
'''

(nk+1)/(k+1) + Θ(nk)

Θ(nk+1 / (k+1)) as can ignore lower terms


# Performance of loops (A caching question)

 Ignoring the compiler optimizations, which of the two is better implementation of sum?

'''

// Function 1 
int fun1(int arr[R][C]) 
{ 
    int sum = 0; 
    for (int i=0; i<R; i++) 
      for (int j=0; j<C; j++) 
          sum += arr[i][j]; 
} 
  
// Function 2 
int fun2(int arr[R][C]) 
{ 
    int sum = 0; 
    for (int j=0; j<C; j++) 
      for (int i=0; i<R; i++) 
          sum += arr[i][j]; 
} 
'''

In C/C++, elements are stored in Row-Major order. So the first implementation has better spatial locality (nearby memory locations are referenced in successive iterations). Therefore, first implementation should always be preferred for iterating multidimensional arrays.