/***************************************************************************** QUESTION ********************************************************************************/

/*
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).The solution set must not contain duplicate subsets. 
Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:
Input: nums = [0]
Output: [[],[0]]
 
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/

/****************************************************************************** ANSWER ********************************************************************************/

class Solution {
public:
    void generate(vector<vector<int>>& ans, vector<int>& res, int x, vector<int>& nums) {
        ans.push_back(res);

        for(int i = x; i < nums.size(); i++) {
            if(i != x && nums[i] == nums[i-1]) {
                continue;
            }
            res.push_back(nums[i]);
            generate(ans, res, i+1, nums);
            res.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        sort(nums.begin(), nums.end());
        generate(ans, res, 0, nums);
        return ans;
    }
};
