/**************************************************************************** QUESTION *********************************************************************************/

/*
Given an integer array nums, return the length of the longest strictly increasing 
subsequence
.

 

Example 1:

Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
Example 2:

Input: nums = [0,1,0,3,2,3]
Output: 4
Example 3:

Input: nums = [7,7,7,7,7,7,7]
Output: 1
 

Constraints:

1 <= nums.length <= 2500
-104 <= nums[i] <= 104
*/

/************************************************************************* RECURSION ************************************************************************************/

class Solution {
public:
    int f(int ind, int prevind, vector<int>& nums) {
        int n = nums.size();
        if(ind == n) {
            return 0;
        }
        //not take the curr element
        int len = 0 + f(ind + 1, prevind, nums);

        //take the curr element
        if(prevind == -1 || nums[ind] > nums[prevind]) {
            len = max(len, 1 + f(ind + 1, ind, nums));
        }

        return len;
    }

    int lengthOfLIS(vector<int>& nums) {
        return f(0, -1, nums);
    }
};

/*************************************************************************** MEMOIZATION *****************************************************************************/

class Solution {
public:
    int f(int ind, int prevind, vector<int>& nums, vector<vector<int>>& dp) {
        int n = nums.size();
        if(ind == n) {
            return 0;
        }

        if(dp[ind][prevind + 1] != -1) {
            return dp[ind][prevind + 1];
        }

        //not take the curr element
        int len = 0 + f(ind + 1, prevind, nums, dp);

        //take the curr element
        if(prevind == -1 || nums[ind] > nums[prevind]) {
            len = max(len, 1 + f(ind + 1, ind, nums, dp));
        }

        return dp[ind][prevind + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, nums, dp);
    }
};
