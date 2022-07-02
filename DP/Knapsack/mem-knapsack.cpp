int t[100][1000];
memset(t, -1, sizeof(t));

int knapsack(int wt[], int v[], int n, int w) {
  if(n == 0 || w == 0) {
    return 0;
  }
  
  if(t[n][w] != -1) {
    return t[n][w];
  }
  
  if(wt[n - 1] <= w) {
    return t[n][w] = max(v[n - 1] + knapsack(wt, v, n - 1, w - wt[n - 1]), knapsack(wt, v, n - 1, w));
  }
  else {
    return knapsack(wt, v, n - 1, w);
  }
}
