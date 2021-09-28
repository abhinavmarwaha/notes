# Merge vs Quick Sort

### Quick Sort 

* internal algorithm
* unstable | can be made
* arrays preffered
* small db
* worst case -> O(n^2)
* divide untill you can't (DAC) (any length)
* partition exchange sort
* pivot
* in place
* left of pivot < pivot < right of pivot
* good cache locallity

### Merge Sort
* external
* stable
* link list preffered
* any length db
* worst case -> O(nlogn)
* DAC (n/2)
* 3 arrays -> 2 to sort, 1 to store | not in place