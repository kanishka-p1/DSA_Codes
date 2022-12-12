//QUESTION

/*
There are n stones and an array of heights and Geek is standing at stone 1 and can jump to one of the following: Stone i+1, i+2, ... i+k stone and cost will be [hi-hj] is incurred, where j is the stone to land on. Find the minimum possible total cost incurred before the Geek reaches Stone N.

Example 1:
Input:
n = 5, k = 3
heights = {10, 30, 40, 50, 20}
Output:
30
Explanation:
Geek will follow the path 1->2->5, the total cost 
would be | 10-30| + |30-20| = 30, which is minimum
Example 2:

Input:
n = 3, k = 1
heights = {10,20,10}
Output:
20
Explanation:
Geek will follow the path 1->2->3, the total cost
would be |10 - 20| + |20 - 10| = 20.
Your Task:
You don't need to read input or print anything. Your task is to complete the function minimizeCost() which takes the array height, and integer n, and integer k and returns the minimum energy that is lost.

Expected Time Complexity: O(n*k)
Expected Space Complexity: O(n)

Constraint:
2 <= n <= 105
1 <= k <= 100
1 <= heights[i] <= 104
*/

/********************************************************************** RECURSIVE *****************************************************************************/

class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        if(n == 1) {
            return 0;
        }
        int ans = INT_MAX;
        
        for(int i = 1; i <= k; i++) {
            if(n - i - 1 >= 0) {
                ans = min(ans, minimizeCost(height, n - i, k) + abs(height[n - 1] - height[n - i - 1]));
            }
        }
        return ans;
    }
};

/*************************************************************** MEMOIZATION **************************************************************************************/

class Solution {
  public:
    int helper(vector<int>& height, int n, int k, vector<int>& dp) {
        if(n == 1) {
            dp[n] = 0;
            return dp[n];
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int ans = INT_MAX;
        
        for(int i = 1; i <= k; i++) {
            if(n - i - 1 >= 0) {
                ans = min(ans, helper(height, n - i, k, dp) + abs(height[n - 1] - height[n - i - 1]));
            }
        }
        
        dp[n] = ans;
        return ans;
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n + 1, -1);
        return helper(height, n, k, dp);
    }
};

/********************************************************************* DP ******************************************************************************************/

class Solution {
  public:
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int> dp(n + 1, 0);
        
        for(int i = 2; i <= n; i++) {
            int ans = INT_MAX;
            
            for(int j = 1; j <= k ; j++) {
                if(i - j - 1 >= 0) {
                    ans = min(ans, dp[i - j] + abs(height[i - 1] - height[i - j - 1]));
                }
            }
            dp[i] = ans;
        }
        return dp[n];
    }
};

