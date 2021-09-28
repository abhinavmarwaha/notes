# Searching

*best -> binary and hash tables*

### Linear Search

O(n) -> time 

```
int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 
  
```
Improve Linear Search Worst-Case Complexity

if element Found at last  O(n) to O(1)
if element Not found O(n) to O(n/2)

__by running right and left pointers__

```

    public static void search(int arr[], int search_Element) 
    { 
        int left = 0; 
        int length = arr.length; 
        int right = length - 1; 
        int position = -1; 
  
        for (left = 0; left <= right;)  
        { 
             
            if (arr[left] == search_Element)  
            { 
                position = left; 
                System.out.println( 
                    "Element found in Array at "
                    + (position + 1) + " Position with "
                    + (left + 1) + " Attempt"); 
                break; 
            } 
            
            if (arr[right] == search_Element)  
            { 
                position = right; 
                System.out.println( 
                    "Element found in Array at "
                    + (position + 1) + " Position with "
                    + (length - right) + " Attempt"); 
                break; 
            } 
              
            left++; 
            right--; 
        } 
  
        if (position == -1) 
            System.out.println("Not found in Array with "
                               + left + " Attempt"); 
    } 
```