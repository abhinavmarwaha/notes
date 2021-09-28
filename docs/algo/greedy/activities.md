# Activity Selection

unsorted O(n^2logn), O(1)
exist A = {B – {k}} U {1}.(Note that the activities in B are independent and k has smallest finishing time among all. Since k is not 1, finish(k) >= finish(1)).

```
struct Activitiy 
{ 
	int start, finish; 
}; 

bool activityCompare(Activitiy s1, Activitiy s2) 
{ 
	return (s1.finish < s2.finish); 
} 

void printMaxActivities(Activitiy arr[], int n) 
{  
	sort(arr, arr+n, activityCompare); 

	cout << "Following activities are selected n"; 

	int i = 0; 
	cout << "(" << arr[i].start << ", " << arr[i].finish << "), "; 

	for (int j = 1; j < n; j++) 
	{ 

	if (arr[j].start >= arr[i].finish) 
	{ 
		cout << "(" << arr[j].start << ", "
			<< arr[j].finish << "), "; 
		i = j; 
	} 
	} 
} 
```