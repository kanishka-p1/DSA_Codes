/********************************************************************** QUESTION **************************************************************************************/

/*
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

/*************************************************************************** RECURSION ******************************************************************************/

class Solution {
public:
    int helper(int i, int j, string s1, string s2) {
        if(i < 0) {
            return j + 1;
        }
        if(j < 0) {
            return i + 1;
        }
        if(s1[i] == s2[j]) {
            return helper(i - 1, j - 1, s1, s2);
        }
        else {
            return 1 + min(helper(i, j - 1, s1, s2), min(helper(i - 1, j, s1, s2), helper(i - 1, j - 1, s1, s2)));
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        return helper(m - 1, n - 1, word1, word2);
    }
};

/************************************************************************* MEMOIZATION *****************************************************************************/

class Solution {
public:
    int helper(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
        if(i < 0) {
            return j + 1;
        }
        if(j < 0) {
            return i + 1;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(s1[i] == s2[j]) {
            return dp[i][j] = helper(i - 1, j - 1, s1, s2, dp);
        }
        else {
            return dp[i][j] = 1 + min(helper(i, j - 1, s1, s2, dp), min(helper(i - 1, j, s1, s2, dp), helper(i - 1, j - 1, s1, s2, dp)));
        }
    }

    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(m - 1, n - 1, word1, word2, dp);
    }
};

/***************************************************************************** DP **********************************************************************************/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for(int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
            }
        }

        return dp[m][n];
    }
};

/************************************************************************* SPACE OPTIMIZATION ***********************************************************************/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for(int j = 0; j <= n; j++) {
            prev[j] = j;
        }

        for(int i = 1; i <= m; i++) {
            curr[0] = i;
            for(int j = 1; j <= n; j++) {
                if(word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                }
                else {
                    curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};
