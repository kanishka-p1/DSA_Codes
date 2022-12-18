/********************************************************************* QUESTION **************************************************************************************/
/*
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

/***************************************************************************** BRUTE FORCE ***************************************************************************/

class Solution {
public:
    int helper(vector<vector<int>>& matrix, int i, int j, int m, int n) {
        if(i >= 0 && j >= 0 && i < m && j < n) {
            if(i == m - 1) {
                return matrix[i][j];
            }
            int x = helper(matrix, i + 1, j - 1, m, n);
            int y = helper(matrix, i + 1, j, m, n);
            int z = helper(matrix, i + 1, j + 1, m, n);

            return matrix[i][j] + min(x, min(y, z));
        }
        else {
            return INT_MAX;
        }
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, helper(matrix, 0, j, m, n));
        }

        return ans;
    }
};

/******************************************************************** MEMOIZATION *********************************************************************************/

class Solution {
public:
    int helper(vector<vector<int>>& matrix, int i, int j, int m, int n, vector<vector<int>>& dp) {
        if(i >= 0 && j >= 0 && i < m && j < n) {
            if(i == m - 1) {
                dp[i][j] = matrix[i][j];
                return dp[i][j];
            }
            if(dp[i][j] != -1) {
                return dp[i][j];
            }

            int x = helper(matrix, i + 1, j - 1, m, n, dp);
            int y = helper(matrix, i + 1, j, m, n, dp);
            int z = helper(matrix, i + 1, j + 1, m, n, dp);

            dp[i][j] = matrix[i][j] + min(x, min(y, z));
            return dp[i][j];
        }
        else {
            return INT_MAX;
        }
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        int ans = INT_MAX;

        for(int j = 0; j < n; j++) {
            ans = min(ans, helper(matrix, 0, j, m, n, dp));
        }

        return ans;
    }
};

/****************************************************************************** DP ********************************************************************************/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        for(int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int x = INT_MAX, y = INT_MAX, z = INT_MAX;
                x = dp[i - 1][j];
                if(j - 1 >= 0) {
                    y = dp[i - 1][j - 1];
                }
                if(j + 1 < m) {
                    z = dp[i - 1][j + 1];
                } 
                dp[i][j] = matrix[i][j] + min(x, min(y, z));
            }
        }

        int ans = INT_MAX;
        for(int j = 0; j < n; j++) {
            ans = min(ans, dp[m - 1][j]);
        }

        return ans;
    }
};
