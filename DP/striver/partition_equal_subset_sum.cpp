/********************************************************************* QUESTION ****************************************************************************************/

/*
Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the 
sum of elements in both subsets is equal.

 

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

/************************************************************************ ANSWER ***************************************************************************************/

class Solution {
public:
    bool helper(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));

        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for(int j = 1; j <= sum; j++) {
            dp[0][j] = false;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= sum; j++) {
                if(nums[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][sum];
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        if(sum % 2 != 0) {
            return false;
        }

        return helper(nums, sum / 2);
    }
};
