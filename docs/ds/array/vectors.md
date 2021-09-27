
# Vectors in cpp

### Iterators

* begin -> 1st element
* end -> last element
* r -> reverse
* c -> constant

```
begin()
end()
rbegin()
rend()
cbegin() – constant iterator pointing to 1st element
cend()
crbegin()
crend() – constant reverse iterator, pointing to theoretical element i.e. preceding the 1st element
```

### Capacity

```
size() – number of elements
max_size() – maximum number of elements
capacity() – space currently allocated expressed as number of elements.
resize(n) – Resizes the container to n elements.
empty() – whether is empty.
shrink_to_fit() – Reduces the capacity to fit its size and destroys all elements beyond the capacity.
reserve() – Requests that the vector capacity be at least enough to contain n elements.
```

### Element access:

```
reference operator [g] – reference to the element at position ‘g’ in the vector
at(g) – reference to the element at position ‘g’ in the vector
front() – reference to the first element in the vector
back() – reference to the last element in the vector
data() – direct pointer to the memory array used internally by the vector to store its owned elements.
```

### Modifiers:

```
assign() – assigns new value to the elements by replacing old ones
push_back() – push the elements from the back
pop_back() – pop elements from the back.
insert() – inserts new elements before specified position
erase() – remove element at position or range.
swap() – swap one vector with another (size may differ).
clear() – remove all elements.
emplace() – extends the container by inserting new element at position.
emplace_back() – insert new element to the end.
```
