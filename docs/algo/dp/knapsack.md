# Knapsack

### Iterative

```
knapsack(){
    int K[n+1], W[n+1]; 
}
```

### Recursive

```
int knapsack (int* val, int* weights, int W, int n){

    if(n==0 || W==0) return 0;

    if(val[n-1]>W) return knapsack(val, weights, W, n-1);

    return max( val[n-1] + knapsack(val,weights, W-val[n-1], n-1), knapsack(val,weights, W, n-1));

}
```