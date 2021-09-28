# Introduction

operations required -> insert, search and delete

### Data Structure can be

* Array           ---- search ->  linear O(n) , or sorted -> O(logn) but insert, delete is costly
* Linked Listed   ---- search -> O(n) , insert -> O(1), delete -> O(1)
* balanced BST  --> O(logn) everything
* Direct Access table --> O(1) but space required is huge *hence we use hashing* 
* O(m * 10n) space for table where m is size of a pointer to record. Another problem is an integer in a programming language may not store n digits.

### Hashing

* Improvement over direct access
* O(1) on average {under reasonable assumptions}
* O(n) worst case

*Idea* -> use small numbers for big ones by hashing them.

### Hash Function

Maps big numbers to small numbers

*Good Hash Funtion*

* Efficiently computable.
* Should uniformly distribute the keys.  (Each table position equally likely for each key)
  
For example for phone numbers a bad hash function is to take first three digits

### Hash table

Array that stores pointer to record of key.

### Collision Handling

When 2 keys have same hash value

How often? -> With only 23 persons, the probability that two people have the same birthday is 50%.

*Collision handling*

* *Chaining*: hash table points to linked list that has same hash value... good but requires extra space outside the hash table.
* *Open Addressing*: all elements are in hash table only.

### Chaining

Advantages:

1. Simple to implement.
2. Hash table never fills up, we can always add more elements to the chain.
3. Less sensitive to the hash function or load factors.
4. It is mostly used when it is unknown how many and how frequently keys may be inserted or deleted.

Disadvantages:

1. Cache performance of chaining coz a linked list. Open addressing provides better cache performance as everything is stored in the same table.
2. Wastage of Space
3. If chain -> long, then search time -> O(n) worst case.
4. extra space -> links.

### Performace

'''
 m = Number of slots in hash table
 n = Number of keys to be inserted in hash table
 
 Load factor α = n/m 
  
 Expected time to search = O(1 + α)
 
 Expected time to delete = O(1 + α)

Time to insert = O(1)

 Time complexity of search insert and delete is 
 O(1) if  α is O(1)
 '''

### Open Addressing

* Insert(k): Keep probing until an empty slot is found.
* Search(k): Keep probing until slot’s key doesn’t become equal to k or an empty slot is reached.
* Delete(k): slots of deleted keys are marked specially as “deleted”. Insert can insert an item in a deleted slot, but the search doesn’t stop at a deleted slot.

S -> size of hash table

*Linear Probing* : (hash(x) + i) % S
Clustering: Many consecutive elements form groups and it starts taking time to find a free slot or to search an element.

*Quadratic Probing*:  (hash(x) + i*i) % S
*Double Hashing*: (hash(x) + i*hash2(x)) % S

*Performance of Open Addressing*

Each key is equally likely to be hashed to any slot of the table (simple uniform hashing)

 m = Number of slots in the hash table
 n = Number of keys to be inserted in the hash table
 
 Load factor α = n/m  ( < 1 )

 Expected time to search/insert/delete < 1/(1 - α) 

 So Search, Insert and Delete take (1/(1 - α)) time

*Linear probing*
* Best cache performance 
* Suffers from clustering. 
* Easy to compute.

Challenges in Linear Probing :

Primary Clustering: One of the problems with linear probing is Primary clustering, many consecutive elements form groups and it starts taking time to find a free slot or to search an element.  
Secondary Clustering: Secondary clustering is less severe, two records do only have the same collision chain(Probe Sequence) if their initial position is the same.

*Quadratic probing* lies between the two

*Double hashing*
* poor cache performance but
* no clustering. 
* More computation

| Separate Chaining                                                                    | Open Addressing                                                    |
|--------------------------------------------------------------------------------------|--------------------------------------------------------------------|
| Simpler to implement                                                                 | more computation.                                                  |
| Can add more elements to chain.                                                      | table may become full.                                             |
| Less sensitive to the hash function or load factors.                                 | Requires extra care for to avoid clustering and load factor.       |
| Used when it is unknown how many and how frequently keys may be inserted or deleted. | used when the frequency and number of keys is known.               |
| Cache performance not good as linked list.                                           | better cache performance as everything is stored in the same table.|
| Wastage of Space (Some Parts of hash table in chaining are never used).              | a slot can be used even if an input doesn’t map to it.             |
| extra space for links.                                                               | No links                                                           |