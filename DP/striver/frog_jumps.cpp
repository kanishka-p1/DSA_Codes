//QUESTION
/*
 Geek wants to climb from the 0th stair to the (n-1)th stair. At a time the Geek can climb either one or two steps. A height[N] array is also given. Whenever the frog jumps from stair i to stair j, the energy consumed in the jump is abs(height[i]- height[j]), where abs() means the absolute difference. return the minimum energy that can be used by the Geek to jump from stair 0 to stair N-1.

Example:
Input:
n = 4
height = {10 20 30 10}
Output:
20
Explanation:
Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost).
Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost).
so, total energy lost is 20 which is the minimum.
Your Task:
You don't need to read input or print anything. Your task is to complete the function MinimumEnergy() which takes the array height, and integer n, and returns the minimum energy that is lost.

Expected Time Complexity: O(n)
Expected Space Complexity: O(n)

Constraint:
1<=n<=100000
1<=height[i]<=1000
*/

/**************************************************************** RECURSION *****************************************************************************************/

//approach 1

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if(n == 1) {
            return 0;
        }
        
        if(n == 2) {
            return abs(height[1] - height[0]);
        }
        
        int x = abs(height[n - 1] - height[n - 2]) + minimumEnergy(height, n - 1);
        int y = abs(height[n - 1] - height[n - 3]) + minimumEnergy(height, n - 2);
        
        return min(x, y);
    }
};

//approach 2

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        if(n == 1) {
            return 0;
        }
        
        int x = abs(height[n - 1] - height[n - 2]) + minimumEnergy(height, n - 1);
        int y = INT_MAX;
        
        if(n > 2) {
            y = abs(height[n - 1] - height[n - 3]) + minimumEnergy(height, n - 2);
        }
        
        return min(x, y);
    }
};

/***************************************************************** MEMOIZATION *********************************************************************************/

class Solution {
  public:
    int solve(vector<int>& height, int n, /*vector<int>& dp*/ int*dp) {
        if(n == 1) {
            dp[n] = 0;
            return 0;
        }
        if(n == 2) {
            dp[n] = abs(height[1] - height[0]);
            return dp[n];
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        
        int x = abs(height[n - 1] - height[n - 2]) + solve(height, n - 1, dp);
        int y = abs(height[n - 1] - height[n - 3]) + solve(height, n - 2, dp);
        
        dp[n] = min(x, y);
        return dp[n];
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        // vector<int> dp(n, -1);
        int *dp = new int[n + 1];
        for(int i = 0; i < n + 1; i++) {
            dp[i] = -1;
        }
        solve(height, n, dp);
    }
};

/************************************************************************* DP **************************************************************************************/

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n, 0);
        // dp[0] = 0;
        for(int i = 1; i < n; i++) {
            int y = INT_MAX;
            int x = dp[i - 1] + abs(height[i] - height[i - 1]);
            if(i > 1) {
                y = dp[i - 2] + abs(height[i] - height[i - 2]);
            }
            dp[i] = min(x, y);
        }
        return dp[n - 1];
    }
};

/******************************************************************** SPACE OPTIMIZATION ****************************************************************************/

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        int curr, prev, prev2;
        prev = abs(height[1] - height[0]);
        prev2 = 0;
        
        for(int i = 2; i < n; i++) {
            int x = prev + abs(height[i] - height[i - 1]);
            int y = prev2 + abs(height[i] - height[i - 2]);
            
            curr = min(x, y);
            prev2 = prev;
            prev = curr;
            
        }
        return prev;
    }
};
