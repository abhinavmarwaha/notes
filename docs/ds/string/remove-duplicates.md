# Remove Duplicates

```
char * removeDuplicate(char str[], int n){
    int index = 0;
    for(int i = 0; i< n ; i++){
        int j;
        for(j = 0; j<n; j++)
            if(str[i]==str[j]) break;
        
        if(i==j)
            str[index++] = str[i];
    }
    return str;
}
```