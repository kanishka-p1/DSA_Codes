//                                                                       QUESTION


/*
Given a string, 

find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.Given a string, 

find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.
*/


//                                                                          ANSWER


int Solution::lengthOfLongestSubstring(string A) {
    unordered_map<char, int> ans;
    int left = 0, right = 0;
    int res = 0;
    while(right < A.length()) {
        char c = A[right];
        ans[c]++;
        
        while(ans[c] > 1) {
            char d = A[left];
            left++;
            ans[d]--;
        }
        
        right++;
        
        res = max(res, right - left);
    }
    
    return res;
}
