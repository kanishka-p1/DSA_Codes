/******************************************************************FIBONACCI***********************************************************************************/


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
long long int mod = 1e9 + 7;
long long int dp[100001];
class Solution {
  public:
    long long int topDown(int n) {
        // code here
        // vector<long long int> t(n + 1, -1);
        if(n <= 1) {
            return n;
        }
        
        if(dp[n] != -1) {
            return dp[n] % mod;
        }
        dp[n] = (topDown(n - 1) + topDown(n - 2)) % mod;
        return dp[n] % mod;
    }
    long long int bottomUp(int n) {
        // code here
        vector<long long int> dp(n + 1, 0);
        
        dp[1] = 1;
        for(int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        }
        return dp[n] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 100001; i++) dp[i] = -1;
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends


/********************************************************************* CLIMBING STAIRS **********************************************************************/

/* QUESTION */

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/


/************************************************************************** RECURSION ***************************************************************************/

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) {
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};


/*********************************************************************** MEMOIZATION *****************************************************************************/
class Solution {
public:
    int climbStairs(int n) {
         vector<int> dp(n + 1, -1);
        if(n <= 2) {
            dp[n] = n;
            return n;
        }
        
        if(dp[n] != -1) {
            return dp[n];
        }
        
        dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return dp[n];
    }
};


/*************************************************************************** DP ************************************************************************************/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        if(n <= 2) {
            return n;
        }
        
        dp[1] = 1;
        dp[2] = 2;
        
        for(int i = 3; i < n + 1; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
