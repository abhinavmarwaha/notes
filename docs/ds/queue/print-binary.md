# Print Binary

### simple

loop from 1 to n.. then call toBin()

### Using Queues

O(n * logn)

```
void generatePrintBinary(int n) 
{ 
	queue<string> q; 

	q.push("1"); 

    // BFS
	while (n--) 
	{ 
		string s1 = q.front(); 
		q.pop(); 
		cout << s1 << "\n"; 

		string s2 = s1; 
	
		q.push(s1.append("0")); 

		q.push(s2.append("1")); 
	} 
} 
```