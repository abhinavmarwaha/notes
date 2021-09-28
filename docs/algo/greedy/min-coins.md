# Minimum Coins

O(1) < O(N*logN)>, O(1)

NOTE: it doesn’t work for denominations {9, 6, 5, 1} and V = 11. The above approach would print 9, 1 and 1. But we can use 2 denominations 5 and 6.
For general input, dynamic programming approach can be used.

```
int minCoins(int x){

    int denom[9] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int no = 0;

    for(int i = 8; i>=0 && x!=0 ; i--){
        int modd = x / denom[i];
        no += modd;
        x %= denom[i]; 
    }

    cout << no;
}
```