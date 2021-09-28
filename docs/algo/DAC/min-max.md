# Min Max

```
int DAC_max (int arr[], int index, int l){
    int max; 

    if(index >= l-2){

        if(arr[index]>arr[index+1]){
            
            return arr[index];

        } 
        
        else {

            return arr[index+1];

        }

    }

    max = DAC_max(arr, index+1, l);

    if(arr[index]>max){
        return arr[index];
    }
    else{
        return max;
    }
}

int DAC_min(int arr[], int index, int l){
    if(index >= l-2){
        if(arr[index]>arr[index+1]){
            return arr[index];
        }
        else{
            return arr[index+1];
        }
    }

    int max = DAC_min(arr, index+1, l);

    if(arr[index]>max){
        return arr[index];
    }

    else{
        return max;
    }
}
```