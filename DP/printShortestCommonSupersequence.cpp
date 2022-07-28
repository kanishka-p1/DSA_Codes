//                                                                      QUESTION

/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

 

Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
Example 2:

Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
 

Constraints:

1 <= str1.length, str2.length <= 1000
str1 and str2 consist of lowercase English letters.
*/

//                                                                          ANSWER

class Solution {
public:
    string lcs(string s1, string s2, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        string res = "";
        int i = m, j = n;
        while(i > 0 && j > 0) {
            if(s1[i - 1] == s2[j - 1]) {
                res.push_back(s1[i - 1]);
                i--;
                j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]) {
                res.push_back(s1[i - 1]);
                i--;
            }
            else {
                res.push_back(s2[j - 1]);
                j--;
            }
        }
        
        while(i > 0) {
            res.push_back(s1[i - 1]);
            i--;
        }
        while(j > 0) {
            res.push_back(s2[j - 1]);
            j--;
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        string ans = lcs(str1, str2, m, n);
        
        return ans;
    }
};
