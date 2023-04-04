/*************************************************************************** QUESTION ********************************************************************************/

/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

Example 1:
Input: nums = [3,2,3]
Output: 3
Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 
Constraints:
n == nums.length
1 <= n <= 5 * 104
-109 <= nums[i] <= 109
*/

/********************************************************************************** ANSWER *****************************************************************************/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> res;
        int n = nums.size();
        int m = n/2;
        for(auto it : nums){
            res[it]++;
        }
        for(int i = 0; i < n; i++){
            if(res[nums[i]] > m){
                return nums[i]; 
            } 
        }
        return 0;
    }
};
