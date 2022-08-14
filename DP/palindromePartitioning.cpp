//                                                                          QUESTION


/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

 

Example 1:

Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.
Example 2:

Input: s = "a"
Output: 0
Example 3:

Input: s = "ab"
Output: 1
*/


//                                                                        ANSWER


//approach 1 (recursive)
class Solution {
public:
    bool ispalindrome(string s, int l, int r) {
        for (int i = l, j = r; i < j; i++, j--) {
            if (s[i] != s[j]) {
                return false;
            }
        }
            
        return true;
    }
    
    int helper(string s, int i, int j) {
        if(i >= j) {
            return 0;
        }
        if(ispalindrome(s, i, j) == true) {
            return 0;
        }
        
        int ans = INT_MAX;
        
        for(int k = i; k <= j -1; k++) {
            int temp = 1 + helper(s, i, k) + helper(s, k + 1, j);
            ans = min(ans, temp);
        }
        
        return ans;
    }
    
    int minCut(string s) {
        int n = s.length();
        int ans = helper(s, 0, n - 1);
        return ans;
    }
};


//approach 2 (memo)

class Solution {
public:
    bool ispalindrome(string s, int i, int j) {
        if(i == j) {
            return true;
        }
        if(i > j) {
            return true;
        }
        
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    int helper(string s, int i, int j, vector<vector<int>>& dp) {
        
        if(i >= j) {
            return 0;
        }
        if(ispalindrome(s, i, j) == true) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        
        for(int k = i; k <= j -1; k++) {
            int temp = 1 + helper(s, i, k, dp) + helper(s, k + 1, j, dp);
            ans = min(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();                
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = helper(s, 0, n - 1, dp);
        return ans;
    }
};


//approach 3 (memo optimized)

class Solution {
public:
    bool ispalindrome(string s, int i, int j) {
        if(i == j) {
            return true;
        }
        if(i > j) {
            return true;
        }
        
        while(i < j) {
            if(s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        
        return true;
    }
    
    int helper(string s, int i, int j, vector<vector<int>>& dp) {
        
        if(i >= j) {
            return 0;
        }
        if(ispalindrome(s, i, j) == true) {
            return 0;
        }
        
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = INT_MAX;
        
        for(int k = i; k <= j -1; k++) {
            int left, right;
            if(dp[i][k] != -1) {
                left = dp[i][k];
            }
            else {
                left = helper(s, i, k, dp);
                dp[i][k] = left;
            }
            if(dp[k + 1][j] != -1) {
                right = dp[k + 1][j];
            }
            else {
                right = helper(s, k + 1, j, dp);
                dp[k + 1][j] = right;
            }
            int temp = 1 + left + right;
            ans = min(ans, temp);
        }
        
        return dp[i][j] = ans;
    }
    
    int minCut(string s) {
        int n = s.length();                
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int ans = helper(s, 0, n - 1, dp);
        return ans;
    }
};
