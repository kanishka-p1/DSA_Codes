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
