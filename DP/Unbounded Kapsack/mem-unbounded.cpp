int t[100][100];
memset(t, -1, sizeof(t));

int knapsack(int *wt, int *val, int n, int w) {
  if(n == 0 || w == 0) {
    return 0;
  }
  
  if(t[n][w] != -1) {
    return t[n][w];
  }
  
  if(wt[n - 1] <= w) {
    return t[n][w] = max(val[n - 1] + unbounded(wt, val, n, w - wt[n - 1]), unbounded(wt, val, n - 1, wt));
  }
  else {
    return t[n][w] = unbounded(wt, val, n - 1, w);
  }
}
