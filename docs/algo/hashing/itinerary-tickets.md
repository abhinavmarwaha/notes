# Itinerary Tickets

```
Input:
"Chennai" -> "Banglore"
"Bombay" -> "Delhi"
"Goa"    -> "Chennai"
"Delhi"  -> "Goa"

Output: 
Bombay->Delhi, Delhi->Goa, Goa->Chennai, Chennai->Banglore,
```

Given a list of tickets, find itinerary in order using the given list.

It may be assumed that the input list of tickets is not cyclic and there is one ticket from every city except final destination.

One Solution is to build a graph and do Topological Sorting of the graph. Time complexity of this solution is O(n).

We can also use hashing to avoid building a graph. The idea is to first find the starting point.

A starting point would never be on ‘to’ side of a ticket. 

Once we find the starting point, we can simply traverse the given map to print itinerary in order.
                              

```
void printItinerary(map<string, string> dataSet) 
{ 
    map<string, string> reversemap; 
    map<string, string>::iterator it; 
  
    for (it = dataSet.begin(); it!=dataSet.end(); it++) 
        reversemap[it->second] = it->first; 
  
    string start; 
  
    for (it = dataSet.begin(); it!=dataSet.end(); it++) 
    { 
        if (reversemap.find(it->first) == reversemap.end()) 
        { 
            start = it->first; 
            break; 
        } 
    } 
  
     if (start.empty()) 
     { 
        cout << "Invalid Input" << endl; 
        return; 
     } 
  
    it = dataSet.find(start); 
    while (it != dataSet.end()) 
    { 
        cout << it->first << "->" << it->second << endl; 
        it = dataSet.find(it->second); 
    } 
  
} 
```