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


//Approach 2
int knapsack(int wt[], int val[], int n, int w) {
	int t[n + 1][w + 1];
	for(int i = 0; i < n + 1; i++) {
		for (int j = 0; j < w + 1; j++) {
			if(i == 0 || j == 0) {
				t[i][j] = 0;
			}
		}
	}
	
	if(wt[i - 1] <= j) {
		t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
	}
	else {
		t[i][j] = t[i - 1][j];
	}
	
	return t[n][w];
}
