# Linked list vs Arrays

### Array

* contagious linear colection of similar datatype 
* indexes -> direct retrival (O(1))
* mem aloc -> compile time
* FROM Data section (e.g. global array) or Stack section (e.g. local array).
* static
* wastage of memory

*For dynamic alloc(FROM heap)*

random access of array + runtime alloc of linked list

``` 
int * dynArr = (int *)malloc(sizeof(int)*arrSize);  __advantage__ -> reduce code-size!! (but other factors e.g. program format etc.)
``` 

__Assuming we aren't allowed to get mem. from heap__

(eg. embedded systems)

due to performance, malloc is costly

we have to do module specific memory management. (not system provided API's)

How to do it?

```
struct sllNode 
{ 
int dataInt; 
int nextIndex; 
}; 

struct sllNode arrayLL[5]; //__this__

```

>0x500 -> 0x508 -> 0x510 -> 0x518.
>
>[(1),1]       [(2),2]      [(3),3]     [(4),-2]     [(0),-1]
> 0x500         0x508        0x510       0x518        0x520
>
>-2 -> end of linked list
>

delete 2nd node

>
>0x500 -> 0x510 -> 0x518
>
>[(1),2]       [(0),-1]      [(3),3]     [(4),-2]     [(0),-1]
> 0x500         0x508         0x510       0x518        0x520
>
>2nd node's mem still there

##### inserting

> 0x500 -> 0x508 -> 0x518 -> 0x520
>
>[(1),1]       [(2),3]      [(0),-1]     [(4),4]     [(5),-2]
> 0x500         0x508        0x510        0x518       0x520

insert a new node with data 8

>[(1),1]       [(2),3]      [(8),0]     [(4),4]     [(5),-2]
> 0x500         0x508        0x510       0x518       0x520
>
>0x510 -> 0x500 -> 0x508 -> 0x518 -> 0x520

##### How to optimise

Maintain to linked lists (with data and other that is empty)

### Linked List

* non-primitive , unordered linked elements (Nodes)
* traversal from head (O(n))
* mem aloc -> runtime
* FROM  Heap section (e.g. using malloc() etc.)
* dynamic