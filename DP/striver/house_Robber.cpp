/************************************************************************* QUESTION ***********************************************************************************/

/*
Stickler the thief wants to loot money from a society having n houses in a single line. He is a weird person and follows a certain rule when looting the houses. 
According to the rule, he will never loot two consecutive houses. At the same time, he wants to maximize the amount he loots. The thief knows which house has what 
amount of money but is unable to come up with an optimal looting strategy. He asks for your help to find the maximum money he can get if he strictly follows the rule. 
Each house has a[i]amount of money present in it.

Example 1:

Input:
n = 6
a[] = {5,5,10,100,10,5}
Output: 110
Explanation: 5+100+5=110
Example 2:

Input:
n = 3
a[] = {1,2,3}
Output: 4
Explanation: 1+3=4
Your Task:
Complete the functionFindMaxSum()which takes an array arr[] and n as input which returns the maximum money he can get following the rules

Expected Time Complexity:O(N).
Expected Space Complexity:O(N).

Constraints:
1 ≤ n ≤ 104
1 ≤ a[i] ≤ 104
*/

/************************************************************************* RECURSION *********************************************************************************/

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        if(n == 0) {
            return 0;
        }
        
        if(n == 1) {
            return arr[0];
        }
        
        if(n == 2) {
            return max(arr[0], arr[1]);
        }
        
        return max(arr[n - 1] + FindMaxSum(arr, n - 2), FindMaxSum(arr, n - 1));
    }
};

/**************************************************************************** MEMOIZATION **************************************************************************/

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n, vector<int>& dp)
    {
        // Your code here
        if(n == 0) {
            dp[n] = 0;
            return dp[n];
        }
        
        if(n == 1) {
            dp[n] = arr[0];
            return arr[0];
        }
        
        if(n == 2) {
            dp[n] = max(arr[0], arr[1]);
            return dp[n];
        }
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        dp[n] = max(arr[n - 1] + FindMaxSum(arr, n - 2, dp), FindMaxSum(arr, n - 1, dp));
        
        return dp[n];
    }
    
    int FindMaxSum(int arr[], int n) {
        vector<int> dp(n + 1, -1);
        
        return FindMaxSum(arr, n, dp);
    }
};

/*************************************************************************** DP **********************************************************************************/

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        vector<int> dp(n + 1, 0);
        dp[1] = arr[0];
        dp[2] = max(arr[0], arr[1]);
        
        for(int i = 3; i < n + 1; i++) {
            dp[i] = max(arr[i - 1] + dp[i - 2], dp[i - 1]);
        }
        
        return dp[n];
    }
};

