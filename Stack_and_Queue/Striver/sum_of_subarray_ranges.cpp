/************************************************************************** QUESTION ************************************************************************************/

/*
You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.
Return the sum of all subarray ranges of nums.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,2,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0 
[2], range = 2 - 2 = 0
[3], range = 3 - 3 = 0
[1,2], range = 2 - 1 = 1
[2,3], range = 3 - 2 = 1
[1,2,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 1 + 1 + 2 = 4.
Example 2:
Input: nums = [1,3,3]
Output: 4
Explanation: The 6 subarrays of nums are the following:
[1], range = largest - smallest = 1 - 1 = 0
[3], range = 3 - 3 = 0
[3], range = 3 - 3 = 0
[1,3], range = 3 - 1 = 2
[3,3], range = 3 - 3 = 0
[1,3,3], range = 3 - 1 = 2
So the sum of all ranges is 0 + 0 + 0 + 2 + 0 + 2 = 4.
Example 3:
Input: nums = [4,-2,-3,4,1]
Output: 59
Explanation: The sum of all subarray ranges of nums is 59.
 
Constraints:
1 <= nums.length <= 1000
-109 <= nums[i] <= 109
*/

/************************************************************************* ANSWER ************************************************************************************/

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        stack<int> s;
        vector<int> sRight(n, n), sLeft(n, -1), gRight(n, n), gLeft(n, -1);

        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums[s.top()] >= nums[i]) {
                s.pop();
            }
            if(!s.empty()) {
                sLeft[i] = s.top();
            }
            s.push(i);
        }

        while(!s.empty()) {
            s.pop();
        }

        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && nums[s.top()] > nums[i]) {
                s.pop();
            }
            if(!s.empty()) {
                sRight[i] = s.top();
            }
            s.push(i);
        }

        while(!s.empty()) {
            s.pop();
        }

        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums[s.top()] <= nums[i]) {
                s.pop();
            }
            if(!s.empty()) {
                gLeft[i] = s.top();
            }
            s.push(i);
        }

        while(!s.empty()) {
            s.pop();
        }

        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && nums[s.top()] < nums[i]) {
                s.pop();
            }
            if(!s.empty()) {
                gRight[i] = s.top();
            }
            s.push(i);
        }

        for(int i = 0; i < n; i++) {
            long long leftMin = i - sLeft[i], rightMin = sRight[i] - i;
            long long leftMax = i - gLeft[i], rightMax = gRight[i] - i;
            sum += ((leftMax * rightMax) - (leftMin * rightMin)) * nums[i];
        }

        return sum;
    }
};
