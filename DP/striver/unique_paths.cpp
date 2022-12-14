/************************************************************************* QUESTION ************************************************************************************/

/*
There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100
*/

/********************************************************************* RECURSION ************************************************************************************/

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) {
            return 1;
        }
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);

        // vector<int> dp(n, 1);
        // for(int i = 1; i < m; i++){
        //     for(int j = 1; j < n; j++){
        //         dp[j] += dp[j-1];
        //     }
        // }
        // return dp[n-1];
    }
};

/**************************************************************************** MEMOIZATION ****************************************************************************/

class Solution {
public:
    int helper(int m , int n, vector<vector<int>>& dp) {
        if(m == 1 || n == 1) {
            dp[m][n] = 1;
            return dp[m][n];
        }

        if(dp[m][n] != -1) {
            return dp[m][n];
        }

        dp[m][n] = helper(m - 1, n, dp) + helper(m, n - 1, dp);
        return dp[m][n];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(m , n, dp);
    }
};

/***************************************************************************** DP ************************************************************************************/

//approach 1
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for(int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};


//approach 2

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];


        // vector<vector<int>> dp(m, vector<int>(n, 0));

        // for(int i = 0; i < m; i++) {
        //     dp[i][0] = 1;
        // }
        // for(int j = 0; j < n; j++) {
        //     dp[0][j] = 1;
        // }

        // for(int i = 1; i < m; i++) {
        //     for(int j = 1; j < n; j++) {
        //         dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        //     }
        // }

        // return dp[m - 1][n - 1];
    }
};
