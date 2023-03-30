/************************************************************************** QUESTION *********************************************************************************/

/*
Given an array arr[] of size N and an integer K, the task is to left rotate the array K indexes

Example 1:
Input: N = 7, K = 2
arr[] = {1, 2, 3, 4, 5, 6, 7}
Output: 3 4 5 6 7 1 2
Explanation: Rotation of the above 
array by 2 will make the output array .

Example 2:
Input: N = 6, K = 12
arr[] = {1, 2, 3, 4, 5, 6}
Output: 1 2 3 4 5 6

Your Task:
This is a function problem. You don't need to take any input, as it is already accomplished by the driver code. You just need to complete the 
function leftRotate() that takes array arr, integer K and integer N as parameters and rotate the given array by d value.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 105
*/

/****************************************************************************** ANSWER ******************************************************************************/

class Solution{
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   k = k % n;
	   vector<int> temp;
	   for(int i = 0; i < k; i++) {
	       temp.push_back(arr[i]);
	   }
	   
	   for(int i = k; i < n; i++) {
	       arr[i - k] = arr[i];
	   }
	   
	   int j = 0;
	   for(int i = n - k; i < n; i++) {
	       arr[i] = temp[j];
	       j++;
	   }
	} 
};
