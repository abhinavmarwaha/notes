# Set

* unique elements
* immutable
* though can be deleted and added

### Functions

* r -> reverse
* c -> constant

```
begin()
end() 
size()
max_size()
empty()

rbegin()
rend(): Returns a reverse iterator pointing to the theoretical element right before the first element in the set container.
crbegin()
crend(): Returns a constant iterator pointing to the position just before the first element in the container.
cbegin()
cend()
```

##### Manipulation

```
insert(const g)
iterator insert (iterator position, const g) – ‘g’ at the position pointed by iterator.
erase(iterator position) – Removes the element at the position pointed by the iterator.
erase(const g)– Removes the value ‘g’ from the set.
clear() – Removes all the elements from the set.
key_comp() / value_comp() – Returns the object that determines how the elements in the set are ordered (‘<‘ by default).
find(const g) – Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
count(const g) – Returns 1 or 0 based on the element ‘g’ is present in the set or not.
lower_bound(const g) – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.
upper_bound(const g) – Returns an iterator to the first element that will go after the element ‘g’ in the set.
equal_range()– The function returns an iterator of pairs. (key_comp). The pair refers to the range that includes all the elements in the container which have a key equivalent to k.
emplace()– This function is used to insert a new element into the set container, only if the element to be inserted is unique and does not already exists in the set.
emplace_hint()– Returns an iterator pointing to the position where the insertion is done. If the element passed in the parameter already exists, then it returns an iterator pointing to the position where the existing element is.
swap()– This function is used to exchange the contents of two sets but the sets must be of same type, although sizes may differ.
operator= – The ‘=’ is an operator in C++ STL which copies (or moves) a set to another set and set::operator= is the corresponding operator function.
get_allocator()– Returns the copy of the allocator object associated with the set.
```

