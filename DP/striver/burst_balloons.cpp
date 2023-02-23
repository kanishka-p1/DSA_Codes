/************************************************************************* QUESTION ***********************************************************************************/

/*
You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there 
is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

 

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
Example 2:

Input: nums = [1,5]
Output: 10
 

Constraints:

n == nums.length
1 <= n <= 300
0 <= nums[i] <= 100
*/

/**************************************************************************** RECURSION ******************************************************************************/

class Solution {
public:
    int f(int i, int j, vector<int>& nums) {
        if(i > j) {
            return 0;
        }
        int ans = INT_MIN;
        for(int ind = i; ind <= j; ind++) {
            int cost = nums[i - 1] * nums[ind] * nums[j + 1] + f(i, ind-1, nums) + f(ind+1, j, nums);
            ans = max(ans, cost);
        }
        return ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return f(1, n, nums);
    }
};

/************************************************************************ MEMOIZATION *****************************************************************************/

class Solution {
public:
    int f(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if(i > j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = INT_MIN;
        for(int ind = i; ind <= j; ind++) {
            int cost = nums[i - 1] * nums[ind] * nums[j + 1] + f(i, ind-1, nums, dp) + f(ind+1, j, nums, dp);
            ans = max(ans, cost);
        }
        return dp[i][j] = ans;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return f(1, n, nums, dp);
    }
};

/***************************************************************************** DP ***********************************************************************************/

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for(int i = n; i >= 1; i--) {
            for(int j = 1; j <= n; j++) {
                if(i > j) {
                    continue;
                }
                int ans = INT_MIN;
                for(int ind = i; ind <= j; ind++) {
                    int cost = nums[i - 1] * nums[ind] * nums[j + 1] + dp[i][ind-1] + dp[ind+1][j];
                    ans = max(ans, cost);
                }
                dp[i][j] = ans;
            }
        }
        return dp[1][n];
    }
};
