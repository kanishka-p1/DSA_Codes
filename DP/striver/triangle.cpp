/********************************************************************** QUESTION ***********************************************************************************/

/*
Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
*/

/********************************************************************** RECURSION **********************************************************************************/

class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i, int j) {
        int m = triangle.size();
        int n = triangle[i].size();

        if(i == m - 1) {
            return triangle[i][j];
        }
        
        return triangle[i][j] + min(helper(triangle, i + 1, j), helper(triangle, i + 1, j + 1));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size() == 1) {
            return triangle[0][0];
        }
        return helper(triangle, 0, 0);
    }
};

/*************************************************************************** MEMOIZATION ***************************************************************************/

class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        int m = triangle.size();
        int n = triangle[i].size();

        if(i == m - 1) {
            dp[i][j] = triangle[i][j];
            return dp[i][j];
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        dp[i][j] = triangle[i][j] + min(helper(triangle, i + 1, j, dp), helper(triangle, i + 1, j + 1, dp));

        return dp[i][j];
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        if(triangle.size() == 1) {
            return triangle[0][0];
        }
        return helper(triangle, 0, 0, dp);
    }
};

/******************************************************************************* DP **********************************************************************************/


