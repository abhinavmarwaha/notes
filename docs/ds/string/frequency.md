# Frequency

```
string s = "abcdddssod";
int count[26];
memset(count, 0,  sizeof(count));
for(int i = 0; i<s.size();i++)
    count[s[i]-'a']++;
for(int i =0; i<26; i++)
    if(count[i]>0){
        cout << char('a' + i) << count[i] << endl;
    }
```