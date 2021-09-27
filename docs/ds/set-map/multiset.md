# MultiSet

* non-unique values

### Functions

In adition to set's operations it has:

```
a.erase(): Remove all instance of element from multiset having same value
a.erase(a.find()): Remove only one instance of element from multiset having same value
erase(const g): Removes the value ‘g’ from the multiset.
find(const g): Returns an iterator to the element ‘g’ in the multiset if found, else returns the iterator to end.
count(const g): Returns the number of matches to element ‘g’ in the multiset.
swap(): This function is used to exchange the contents of two multisets but the sets must be of same type, although sizes may differ.
```