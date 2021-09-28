# Closest Pair

T(n) = 2T(n/2) + O(n) + O(nLogn) + O(n), T(n) = 2T(n/2) + O(nLogn), T(n) = T(n x Logn x Logn) , O(n) <strip[n]>
sorting used mmerge , quick

```
class Point {
    public:
    int x,  y;
};

int compareX(const void* a, const void* b){
    Point *x = (Point*) a;
    Point *y = (Point*) b;
    return (x->x - y->x);
}

int compareY(const void* a, const void* b){
    Point *x = (Point*) a;
    Point *y = (Point*) b;
    return (x->y - y->y);
}

float dist(Point* a, Point* b){
    return sqrt((a->y-b->y) * (a->y-b->y) + (a->x - b->x) * (a->x - b->x));
}

int min(int a , int b){
    return a<b ? a : b;
}

float bruteForce(Point P[], int n)  
{  
    float min = INT_MAX;  
    for (int i = 0; i < n; ++i)  
        for (int j = i+1; j < n; ++j){
            float distance1 = dist(&P[i], &P[j]);
            if (distance1 < min)  
                min = distance1;  

        }
    return min;  
}  

float min(float x, float y){
    return x<y ? x : y;
}

float stripClosest(Point strip[], int size, float d)  
{  
    float min = d;
  
    qsort(strip, size, sizeof(Point), compareY);  

    for (int i = 0; i < size; ++i)  
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j)  
            if (dist(&strip[i],&strip[j]) < min)  
                min = dist(&strip[i], &strip[j]);  
  
    return min;  
}  

float closestUtil(Point P[], int n)  
{  
    if (n <= 3)  
        return bruteForce(P, n);  
  
    int mid = n/2;  
    Point midPoint = P[mid];  
 
    float dl = closestUtil(P, mid);  
    float dr = closestUtil(P + mid, n - mid);  
    
    float d = min(dl, dr);  
    
    Point strip[n];  
    int j = 0;  
    for (int i = 0; i < n; i++)  
        if (abs(P[i].x - midPoint.x) < d)   
            strip[j] = P[i], j++;  
  
    return min(d, stripClosest(strip, j, d) );  
}  
   
float closest(Point P[], int n)  
{  
    qsort(P, n, sizeof(Point), compareX);  
    return closestUtil(P, n);  
}  
  

int main()  
{  
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};  
    int n = sizeof(P) / sizeof(P[0]);  
    cout << "The smallest distance is " << closest(P, n);  
    return 0;  
}
```