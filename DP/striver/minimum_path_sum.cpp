/*************************************************************************** QUESTION *********************************************************************************/

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100
*/

/************************************************************************* RECURSION **********************************************************************************/

class Solution {
public:
    int helper(vector<vector<int>>& grid, int sr, int sc) {
        int m = grid.size();
        int n = grid[0].size();

        if(sr == m - 1 && sc == n - 1) {
            return grid[sr][sc];
        }

        if(sr >= m || sc >= n) {
            return INT_MAX;
        }

        return grid[sr][sc] + min(helper(grid, sr + 1, sc), helper(grid, sr, sc + 1));
    }

    int minPathSum(vector<vector<int>>& grid) {
        return helper(grid, 0, 0);
    }
};

/************************************************************************* MEMOIZATION ******************************************************************************/

class Solution {
public:
    int helper(vector<vector<int>>& grid, int sr, int sc, vector<vector<int>>& dp) {
        int m = grid.size();
        int n = grid[0].size();

        if(sr == m - 1 && sc == n - 1) {
            dp[sr][sc] = grid[sr][sc];
            return dp[sr][sc];
        }

        if(sr >= m || sc >= n) {
            return INT_MAX;
        }

        if(dp[sr][sc] != -1) {
            return dp[sr][sc];
        }

        dp[sr][sc] = grid[sr][sc] + min(helper(grid, sr + 1, sc, dp), helper(grid, sr, sc + 1, dp));

        return dp[sr][sc];
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(grid, 0, 0, dp);
    }
};

/********************************************************************************* DP *******************************************************************************/

//approach 1
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(i == m - 1 && j == n - 1) {
                    dp[i][j] = grid[i][j];
                }
                else if(i == m - 1 && j != n - 1) {
                    dp[i][j] = grid[i][j] + dp[i][j + 1];
                }
                else if(i != m - 1 && j == n - 1) {
                    dp[i][j] = grid[i][j] + dp[i + 1][j];
                }
                else {
                    dp[i][j] = grid[i][j] + min(dp[i + 1][j], dp[i][j + 1]);
                }
            }
        }

        return dp[0][0];
    }
};


//approach 2
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) {
                    dp[i][j] = grid[i][j];
                }
                else if(i == 0 && j != 0) {
                    dp[i][j] = grid[i][j] + dp[i][j - 1];
                }
                else if(i != 0 && j == 0) {
                    dp[i][j] = grid[i][j] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
