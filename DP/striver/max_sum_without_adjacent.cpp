/***************************************************************** QUESTION ****************************************************************************************/

/*
Given an array Arr of size N containing positive integers. Find the maximum sum of a subsequence such that no two numbers in the sequence 
should be adjacent in the array.

Example 1:

Input:
N = 6
Arr[] = {5, 5, 10, 100, 10, 5}
Output: 110
Explanation: If you take indices 0, 3
and 5, then Arr[0]+Arr[3]+Arr[5] =
5+100+5 = 110.
Example 2:

Input:
N = 4
Arr[] = {3, 2, 7, 10}
Output: 13
Explanation: 3 and 10 forms a non
continuous  subsequence with maximum
sum.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findMaxSum() which takes the array of integers arr and n as 
parameters and returns an integer denoting the answer.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 106
1 ≤ Arri ≤ 107
*/

/************************************************************************** RECURSION ******************************************************************************/

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    if(n == 0) {
	        return 0;
	    }
	    if(n == 1) {
	        return arr[0];
	    }
	    
	    int x = INT_MAX;
	    if(n > 1) {
	        x = arr[n - 1] + findMaxSum(arr, n - 2);
	    }
	    int y = findMaxSum(arr, n - 1);
	    
	    return max(x, y);
	}
};

/********************************************************************* MEMOIZATION *********************************************************************************/

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n, vector<int>& dp) {
	    // code here
	    
	    if(n == 0) {
	        dp[n] = 0;
	        return dp[n];
	    }
	    if(n == 1) {
	        dp[n] = arr[0];
	        return arr[0];
	    }
	    
	    if(dp[n] != -1) {
	        return dp[n];
	    }
	    
	    int x = INT_MIN;
	    
	    if(n > 1) {
	        x = arr[n - 1] + findMaxSum(arr, n - 2, dp);
	    }
	    int y = findMaxSum(arr, n - 1, dp);
	    
	    dp[n] = max(x, y);
	    
	    return dp[n];
	}
	
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n + 1, -1);
	    
	    return findMaxSum(arr, n, dp);
	}
};

/*************************************************************************** DP ************************************************************************************/

class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n + 1, 0);
	    dp[1] = arr[0];
	    dp[2] = max(arr[0], arr[1]);
	    
	    for(int i = 3; i < n + 1; i++) {
	        dp[i] = max(dp[i - 1], arr[i - 1] + dp[i - 2]);
	    }
	    
	    return dp[n];
	}
};
