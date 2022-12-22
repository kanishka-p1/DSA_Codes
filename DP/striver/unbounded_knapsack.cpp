/************************************************************************ QUESTION *************************************************************************************/

/**/

/************************************************************************ MEMOIZATION ***********************************************************************************/

class Solution{
public:
    int helper(int n, int w, int val[], int wt[], vector<vector<int>>& dp) {
        if(n == 0 || w == 0) {
            return 0;
        }
        
        if(dp[n][w] != -1) {
            return dp[n][w];
        }
        
        if(wt[n - 1] <= w) {
            return dp[n][w] = max(val[n - 1] + helper(n, w - wt[n - 1], val, wt, dp), helper(n - 1, w, val, wt, dp));
        }
        else {
            return dp[n][w] = helper(n - 1, w, val, wt, dp);
        }
    }

    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));
        return helper(n, w, val, wt, dp);
    }
};

/************************************************************************** DP ***************************************************************************************/

class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        // code here
        int dp[n + 1][w + 1];
        
        for(int i = 0; i < n + 1; i++) {
            for(int j = 0; j < w + 1; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 0; j < w + 1; j++) {
                if(wt[i - 1] <= j) {
                    dp[i][j] = max(val[i - 1] + dp[i][j - wt[i - 1]], dp[i - 1][j]);
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][w];
    }
};
