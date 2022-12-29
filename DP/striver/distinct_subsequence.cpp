/************************************************************************ QUESTION ************************************************************************************/

/*
Given two strings s and t, return the number of distinct 
subsequences
 of s which equals t.

The test cases are generated so that the answer fits on a 32-bit signed integer.

 

Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag
 

Constraints:

1 <= s.length, t.length <= 1000
s and t consist of English letters.
*/

/********************************************************************** RECUSRION **********************************************************************************/

class Solution {
public:
    int f(int i, int j, string s, string t) {
        if(j < 0) {
            return 1;
        }
        if(i < 0) {
            return 0;
        }

        if(s[i] == t[j]) {
            return f(i - 1, j - 1, s, t) + f(i - 1, j, s, t);
        }

        return f(i - 1, j, s, t);
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();

        return f(m - 1, n - 1, s, t);
    }
};

/***************************************************************************** MEMOIZATION ***************************************************************************/

class Solution {
public:
    int f(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if(j < 0) {
            return 1;
        }
        if(i < 0) {
            return 0;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(s[i] == t[j]) {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        }

        return dp[i][j] = f(i - 1, j, s, t, dp);
    }

    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return f(m - 1, n - 1, s, t, dp);
    }
};

/******************************************************************************** DP ********************************************************************************/

class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        vector<vector<double>> dp(m + 1, vector<double>(n + 1, 0));

        for(int i = 0; i <= m; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[m][n];
    }
};
