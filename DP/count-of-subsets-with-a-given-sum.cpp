//                                                                      QUESTION

/*
Given an array arr[] of length N and an integer X, the task is to find the number of subsets with a sum equal to X.

Input: arr[] = {1, 2, 3, 3}, X = 6 
Output: 3 
All the possible subsets are {1, 2, 3}, 
{1, 2, 3} and {3, 3}

Input: arr[] = {1, 1, 1, 1}, X = 1 
Output: 4 
*/


//                                                                    ANSWER



//APPROACH 1 (Brute Force)

int countSubset(vector<int>* arr, int n, int sum) {
  if(n == 0 && sum == 0) {
    return 1;
  }
  
  if(n == 0) {
    return 0;
  }
  
  if(sum == 0) {
    return 1;
  }
  
  if(arr[n - 1] <= sum) {
    return countSubset(arr, n - 1, sum) + countSubset(arr, n - 1, sum - arr[n - 1]);
  }
  else {
    return countSubset(arr, n - 1, sum);
  }
}

//APPROACH 2 (Memoization)

int countSubset(vector<int>* arr, int n, int sum){
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
  
  if(n == 0 && sum == 0) {
    return 1;
  }
  
  if(n == 0) {
    return 0;
  }
  
  if(sum == 0) {
    return 1;
  }
  
  if(dp[n][sum] != -1) {
    return dp[n][sum];
  }
  
  if(arr[n - 1] <= sum) {
    dp[n][sum] = countSubset(arr, n - 1, sum) + countSubset(arr, n - 1, sum - arr[n - 1]);
  }
  else {
    dp[n][sum] = countSubset(arr, n - 1, sum);
  }
  
  return dp[n][sum];
}


//APPROACH 3 (DP)

int countSubset(vector<int>* arr, int n, int sum) {
  vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
  
  for(int i = 0; i < n + 1; i++) {
    dp[i][0] = 1;
  }
  
  for(int j = 1; j < sum + 1; j++) {
    dp[0][j] = 0;
  }
  
  for(int i = 0; i < n + 1; i++) {
    for(int j = 0; j < sum + 1; j++) {
      if(arr[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j - arr[i - 1]] + dp[i - 1][j];
      }
      else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  
  return dp[n][sum];
}
