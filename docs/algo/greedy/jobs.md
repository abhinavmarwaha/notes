# Jobs Selection

O(n^2), O(n) <slots>

sort profits decresingly, put slot in remaining , if no slot drop
can be improved with disjoint subset

```
struct Job{
    char id;
    int deadline;
    int profit;
};

bool campare(Job a, Job b){
    return a.profit > b.profit;
}

void selectjobs(struct Job *jobs, int N){

    sort(jobs, jobs+N, campare);

    int result[N];
    int slots[N];

    for(int i = 0; i<N; i++){
        slots[i] = false;
    }

    for(int i = 0; i<N; i++){
        for(int j= min(N, jobs[i].deadline); j>0; j--){
            if(slots[j] == false){
                slots[j] = true;
                result[j] = i;
                break;
            }
        }
    }

    for(int i = 0; i<N; i++){
        if(slots[i])
        cout << jobs[result[i]].id << ", ";
    }

}
```