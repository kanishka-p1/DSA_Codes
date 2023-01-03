/********************************************************************** QUESTION ****************************************************************************************/

/*
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

 

Example 1:

Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
Example 2:

Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.
Example 3:

Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
 

Constraints:

0 <= s.length, p.length <= 2000
s contains only lowercase English letters.
p contains only lowercase English letters, '?' or '*'.
*/

/*************************************************************************** RECURSION *******************************************************************************/

class Solution {
public:
    bool f(int i, int j, string &s, string &p) {
        if(i < 0 && j < 0) {
            return true;
        }
        if(i < 0 && j >= 0) {
            return false;
        }
        if(j < 0 && i >= 0) {
            for(int k = 0; k < i; k++) {
                if(p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(p[i] == s[i] || p[i] == '?') {
            return f(i - 1, j - 1, s, p);
        }
        if(p[i] == "*") {
            return f(i - 1, j, s, p) | f(i, j - 1, s, p);
        }
        
        return false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        return f(n - 1, m - 1, s, p);
    }
};

/******************************************************************************* MEMOIZATION ************************************************************************/

class Solution {
public:
    bool f(int i, int j, string &p, string &s, vector<vector<int>>& dp) {
        if(i < 0 && j < 0) {
            return true;
        }
        if(i < 0 && j >= 0) {
            return false;
        }
        if(j < 0 && i >= 0) {
            for(int k = 0; k <= i; k++) {
                if(p[k] != '*') {
                    return false;
                }
            }
            return true;
        }

        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        if(p[i] == s[j] || p[i] == '?') {
            return dp[i][j] = f(i - 1, j - 1, p, s, dp);
        }
        if(p[i] == '*') {
            return dp[i][j] = f(i - 1, j, p, s, dp) || f(i, j - 1, p, s, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n - 1, m - 1, p, s, dp);
    }
};

/***************************************************************************** DP ************************************************************************************/

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= n; i++) {
            int flag = true;
            for(int k = 1; k <= i; k++) {
                if(p[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[i][0] = flag;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                }
                else {
                    dp[i][j] = false;
                }
            }
        }
        return dp[n][m];
    }
};
