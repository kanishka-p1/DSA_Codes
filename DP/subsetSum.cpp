//                                                                        QUESTION

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
*/

//                                                                        ANSWER

// BRUTE FORECE
class Solution{   
public:

    bool helper(vector<int>arr, int sum, int n) {
        if(n == 0 && sum == 0) {
            return true;
        }
        
        if(n == 0) {
            return false;
        }
        
        if(sum == 0) {
            return true;
        }
        
        if(arr[n - 1] <= sum) {
            return helper(arr, sum, n - 1) ||helper(arr, sum - arr[n - 1], n - 1);
        }
        else {
            return helper(arr, sum, n - 1);
        }
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        return helper(arr, sum, n);
    }
};

// MEMOIZATION

class Solution{   
public:

    bool helper(vector<int> arr, int sum, int n, vector<vector<int>>& dp) {
        if(n == 0 && sum == 0) {
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
            dp[n][sum] = helper(arr, sum, n - 1, dp) ||helper(arr, sum - arr[n - 1], n - 1, dp);
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

//DP

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size() + 1;
        int m = sum + 1;
        
        vector<vector<bool>> dp(n, vector<bool>(m));
        
        //if array consist of any number of elements but the sum is 0
        for(int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        
        //if array is 0 and sum is > 0
        for(int j = 1; j < m; j++) {
            dp[0][j] = false;
        }
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(arr[i - 1] <= j) {
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[n - 1][m - 1];
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
