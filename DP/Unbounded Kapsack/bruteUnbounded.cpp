int unbounded(int *weights, int *values, int n, int maxWeight) {
  if(n == 0 || weights == 0) {
    return 0;
  }
  
  if(weights[n - 1] <= maxWeight) {
    return max(values[n - 1] + unbounded(weights, values, n, maxWeight - weights[n - 1]), unbounded(weights, values, n - 1, maxWeight));
  }
  else {
    return unbounded(weights, values, n - 1, maxWeight);
  }
}
