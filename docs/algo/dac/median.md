# Find Median

O(logn) , O(logn) 
simple 2 way merging (linear) will give O(n) time but we need O(logn) hence DAC will be used. 
you should just go till n not 2n. not merge but jst comparing.

```
int med(int arr1[], int arr2[], int N){

     if (N <= 0) 
        return -1; 
    if (N == 1) 
        return (arr1[0] +  
                arr2[0]) / 2; 
                
    if (N == 2) 
        return (max(arr1[0], arr2[0]) +  
                min(arr1[1], arr2[1])) / 2; 

    int med1, med2;

    if(N%2==0){
        med1 = arr1[N/2];
        med2 = arr2[N/2];
    }
    else{
        med1 = (arr1[N/2] + arr1[N/2 -1])/2;
        med2 = (arr2[N/2] + arr2[N/2 -1])/2;
    }

    if(med1>med2){
        if(N%2==0)
            return med(arr1, arr2 + N/2 -1, N/2+1);

            else {
                return med (arr1, arr2 + N/2, N/2);
            }
        
        }
        else if (med1==med2){
            return med1;
        }
        else{
            if(N%2==0)
            return med(arr1 + N/2 -1, arr2, N/2+1);
            else {
                return med (arr1, arr2 + N/2, N/2);
            }
        }

}
```