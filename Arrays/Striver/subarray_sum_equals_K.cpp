/*************************************************************************** QUESTION **********************************************************************************/

/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2
Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
 
Constraints:
1 <= nums.length <= 2 * 104
-1000 <= nums[i] <= 1000
-107 <= k <= 107
*/

/***************************************************************************** ANSWER **********************************************************************************/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        mp[0] = 1;
        int preSum = 0, cnt = 0;

        for(int i = 0; i < nums.size(); i++) {
            preSum += nums[i];
            int remove = preSum - k;
            cnt += mp[remove];
            mp[preSum] += 1;
        }

        return cnt;
    }
};

//         unordered_map<int, int> freq;
//         int ans = 0, sum = 0, n = nums.size();
        
//         for(auto it : nums){
//             sum += it;
//             if(sum == k){
//                 ans++;
//             }
//             if(freq.count(sum - k)){
//                 ans += freq[sum - k];
//             }
//             freq[sum]++;
//         }
//         return ans;
