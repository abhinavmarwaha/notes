# Power

O(n) , O(1)
Space complexity - O(logn)

```
int power(int x, unsigned int y){
    if(y<=0)return 1;

    if(y%2==0){
        return power(x, y/2) * power(x, y/2);
    }
    else{
        return x * power(x, y/2) * power(x, y/2);
    }
    
}
```