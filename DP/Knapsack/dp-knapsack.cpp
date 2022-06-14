int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    int dp[n + 1][maxWeight + 1];
	 for(int i = 0; i <= n; i++) { 
         for(int j = 0; j <= maxWeight; j++) {
             if(i == 0 || j == 0)
 			        dp[i][j] = 0;
 			    else {  
                    if(weight[i - 1] > j)
 		  	         dp[i][j] = dp[i - 1][j];
 			        else
 			         dp[i][j] = max(value[i - 1] + dp[i - 1][j - weight[i - 1]], dp[i - 1][j]); 
                }
         }
     }
 return dp[n][maxWeight];
}
