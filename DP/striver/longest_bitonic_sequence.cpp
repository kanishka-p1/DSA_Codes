/********************************************************************** QUESTION ****************************************************************************************/

/*
Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.
 

Example 1:

Input: nums = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is
increasing and the sequence {3, 2} is 
decreasing so merging both we will get 
length 5.
Example 2:

Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence 
{1, 2, 10, 4, 2, 1} has length 6.
 

Your Task:
You don't need to read or print anything. Your task is to complete the function LongestBitonicSequence() which takes the array nums[] as input parameter 
and returns the maximum length of bitonic subsequence.
 

Expected Time Complexity: O(n2)
Expected Space Complexity: O(n)
 

Constraints:
1 ≤ length of array ≤ 103
1 ≤ arr[i] ≤ 106
*/

/********************************************************************************* ANSWER ****************************************************************************/

class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
        vector<int> dp1(n, 1);
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] > nums[prev] && 1 + dp1[prev] > dp1[i]) {
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }
        
        vector<int> dp2(n, 1);
        for(int i = n - 1; i >= 0; i--) {
            for(int prev = n - 1; prev > i; prev--) {
                if(nums[i] > nums[prev] && 1 + dp2[prev] > dp2[i]) {
                    dp2[i] = 1 + dp2[prev];
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dp1[i] + dp2[i] - 1);
        }
        
        return ans;
	}
};
