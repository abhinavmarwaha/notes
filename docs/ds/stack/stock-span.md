# Stock Span

### Naive

```
void calculateSpan(int price[], int n, int S[])  
{  
    S[0] = 1;  
  
    for (int i = 1; i < n; i++)  
    {  
        S[i] = 1; 
  
        for (int j = i - 1; (j >= 0) &&  
                (price[i] >= price[j]); j--)  
            S[i]++;  
    }
}
   
O(n^2), O(n)
```

### using Stack

```
void calculateSpan(int price[], int n, int S[]) 
{ 
    stack<int> st; 
    st.push(0); 
  
    S[0] = 1; 
  
    for (int i = 1; i < n; i++) { 
        
        while (!st.empty() && price[st.top()] <= price[i]) 
            st.pop(); 
  
        S[i] = (st.empty()) ? (i + 1) : (i - st.top()); 
  
        st.push(i); 
    } 
} 

O(2n), O(n)
```

### Without stack

```
void calculateSpan(int A[], int n, int ans[]) 
{ 
    ans[0] = 1; 
  
    for (int i = 1; i < n; i++) { 
        int counter = 1; 
        while ((i - counter) >= 0 && A[i] >= A[i - counter]) { 
            counter += ans[i - counter]; 
        } 
        ans[i] = counter; 
    } 
} 
```
