# Maps 

* key-value pairs
* can't have duplicate keys

```
pair insert(keyvalue, mapvalue): Adds a new element to the map
```

# MultiMap

* can have same keys.
* key-value not unique
* sorted order

```
pair<int,int> insert(keyvalue,multimapvalue) – Adds a new element to the multimap
multimap key_comp(): Returns the object that determines how the elements in the multimap are ordered (‘<‘ by default).
```