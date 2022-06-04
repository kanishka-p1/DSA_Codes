#include<algorithm>
int maximumProfit(int budget[], int n) {
    // Write your code here

    sort(budget, budget + n);
    int *cost = new int[n];
    for(int i = 0; i < n; i++)
        cost[i] = budget[i] * (n - i);
    int max = 0;
    for(int i = 0; i < n; i++)
        if(cost[i] > max)
            max = cost[i];
    return max;
}
