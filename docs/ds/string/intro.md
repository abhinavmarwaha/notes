# String

characters as a sequence of bytes allowing access to single byte character.

### std::string vs Character Array

* array of characters terminated by a null character, static allocation  -> array
* class which defines objects, dynamic alocation -> string
* threat of array decay. As strings are represented as objects, no array decay occurs.
* Strings are slower when compared to implementation than character array.
* string has many inbuilt operations.

### Operations on strings

##### Input

```
getline() : store a stream of characters by the user in the object memory.
push_back() : input a character at the end of the string.
pop_back() : delete the last character from the string.
```

##### Capacity

```
capacity() : which can be equal to or more than the size.
resize() : size can be increased or decreased.
length(): length of the string.
shrink_to_fit(): decreases the capacity of the string and makes it equal to the minimum capacity of the string.
```

##### Iterator

```
begin(): iterator to beginning of the string.
end(): iterator to end of the string.
rbegin(): reverse iterator pointing at the end of string.
rend(): reverse iterator pointing at beginning of string.
```

##### Manipulating

```
copy(“char array”, len, pos) :- This function copies the substring in target character array mentioned in its arguments. It takes 3 arguments, target char array, length to be copied and starting position in string to start copying.
swap()
strcpy(s1, s2): Copies string s2 into string s1.
strcat(s1, s2): Concatenates string s2 onto the end of string s1.
strlen(s1)
strcmp(s1, s2): 0 if s1 == s2; less than 0 if s1<s2; greater than 0 if s1>s2.
strchr(s1, ch): pointer to the first occurrence of character ch in string s1.
strstr(s1, s2): pointer to the first occurrence of string s2 in string s1.
```