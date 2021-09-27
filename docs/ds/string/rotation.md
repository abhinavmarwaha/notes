# Rotation

if 2 strings are rotation of each other.

```
string s = "ABCDE";
string temp = s + s;
string str2 = "BCDEA";
cout << (temp.find(str2) != string::npos);
```