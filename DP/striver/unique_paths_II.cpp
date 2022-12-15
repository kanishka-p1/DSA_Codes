/************************************************************************ QUESTION ***********************************************************************************/

/*
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.
*/

/*********************************************************************** RECURSION *********************************************************************************/

class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        //if we go out of bound or reach an obsacle
        if(i >= m || j >= n || grid[i][j] == 1) {
            return 0;
        }

        //if we are at our desired destination
        if(i == m - 1 && j == n - 1) {
            return 1;
        }

        return helper(grid, i + 1, j) + helper(grid, i, j + 1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        //if destination has an obstacle itself
        if(obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        else {
            return helper(obstacleGrid, 0, 0);
        }
    }
};

/*************************************************************************** MEMOIZATION **************************************************************************/

class Solution {
public:
    int helper(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<int>>& dp) {
        
        //if we go out of bound or reach an obsacle
        if(i >= m || j >= n || grid[i][j] == 1) {
            dp[i][j] = 0;
            return 0;
        }

        //if we are at our desired destination
        if(i == m - 1 && j == n - 1) {
            dp[i][j] = 1;
            return 1;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        dp[i][j] = helper(grid, i + 1, j, m, n, dp) + helper(grid, i, j + 1, m, n, dp);

        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

        //if destination has an obstacle itself
        if(obstacleGrid[m - 1][n - 1] == 1) {
            return 0;
        }
        else {
            return helper(obstacleGrid, 0, 0, m, n, dp);
        }
    }
};

/************************************************************************** DP *************************************************************************************/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[0][1] = 1;

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(!obstacleGrid[i - 1][j - 1]) {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
            }
        }

        return dp[m][n];
    }
};
