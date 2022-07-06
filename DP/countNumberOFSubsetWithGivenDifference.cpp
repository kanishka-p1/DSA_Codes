//count subset sum code
int subsetSum(vector<int>& nums, int n, int sum) {
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

int countSubs(vector<int>& nums, int diff) {
  int sum = 0;
  int n = nums.size();
  
  for(int i = 0; i <=nums.size(); i++) {
    sum += nums[i];
  }
  
  
  //we need to find the count of such arrays where 2 arrays can be formed with sum s1 and s2 so that s1 - s2 = diff
  //so s1 - s2 = diff is eq1
  //and s1 + s2 = sum(nums) is eq2
  //eq1 + eq2 will give us
  //s1 = (diff + sum(nums)) / 2
  
  x = (diff + sum) / 2;
  
  return subsetSum(nums, n, x);
}  
