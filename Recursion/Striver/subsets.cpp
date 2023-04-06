/************************************************************************ QUESTION ************************************************************************************/

/*
Given an integer array nums of unique elements, return all possible subsets (the power set). 
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:
Input: nums = [0]
Output: [[],[0]]
 
Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.
*/

/***************************************************************************** ANSWER *********************************************************************************/

class Solution {
public:
    
    void subset(vector<int> &arr, int x, vector<int> list, vector<vector<int>> &ans){
    if(x == arr.size()){
        ans.push_back(list);
        return;
    }        
      subset(arr, x + 1, list, ans); // The element is not used to make the subset
      list.push_back(arr[x]);
      subset(arr, x + 1, list, ans); // The element is used to make the subset
      list.pop_back();
  }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> list;
        vector<vector<int>> ans;
        subset(nums, 0, list, ans);
        return ans;
    }
};
