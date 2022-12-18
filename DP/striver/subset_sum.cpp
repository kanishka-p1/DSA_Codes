/*********************************************************************** QUESTION ************************************************************************************/

/*
Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 


Example 1:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
Example 2:

Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 30
Output: 0 
Explanation: There is no subset with sum 30.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function isSubsetSum() which takes the array arr[], its size N and an integer sum as input parameters and returns boolean value true if there exists a subset with given sum and false otherwise.
The driver code itself prints 1, if returned value is true and prints 0 if returned value is false.
 

Expected Time Complexity: O(sum*N)
Expected Auxiliary Space: O(sum*N)
 

Constraints:
1 <= N <= 100
1<= arr[i] <= 100
1<= sum <= 105
*/

/********************************************************************** RECURSION **********************************************************************************/

class Solution{   
public:
    bool helper(vector<int>& arr, int sum, int i) {
        if(sum == 0) {
            return true;
        }
        
        if(i >= arr.size()) {
            return false;
        }
        
        if(arr[i] <= sum) {
            return helper(arr, sum, i + 1) || helper(arr, sum - arr[i], i + 1);
        }
        else {
            return helper(arr, sum, i + 1);
        }
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        return helper(arr, sum, 0);
    }
};

/************************************************************************** MEMOIZATION ****************************************************************************/

class Solution{   
public:
    bool helper(vector<int>& arr, int sum, int n, vector<vector<int>>& dp) {
        if(sum == 0 && n == 0) {
            return true;
        }
        if(n == 0) {
            return false;
        }
        if(sum == 0) {
            return true;
        }
        
        if(dp[n][sum] != -1) {
            return dp[n][sum];
        }
        
        if(arr[n - 1] <= sum) {
            dp[n][sum] = helper(arr, sum, n - 1, dp) || helper(arr, sum - arr[n - 1], n - 1, dp);
        }
        else {
            dp[n][sum] = helper(arr, sum, n - 1, dp);
        }
        
        return dp[n][sum];
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return helper(arr, sum, n, dp);
    }
};

/********************************************************************************* DP ******************************************************************************/

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        
        for(int i = 0; i < n + 1; i++) {
            dp[i][0] = true;  //sum = 0
        }
        
        for(int j = 1; j < sum + 1; j++) {
            dp[0][j] = false;  //arr = 0
        }
        
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < sum + 1; j++) {
                if(arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n][sum];
        
    }
};
