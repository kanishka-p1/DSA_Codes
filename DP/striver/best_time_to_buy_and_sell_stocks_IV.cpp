/*********************************************************************** QUESTION **************************************************************************************/

/*
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.

Find the maximum profit you can achieve. You may complete at most k transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
Example 2:

Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
 

Constraints:

1 <= k <= 100
1 <= prices.length <= 1000
0 <= prices[i] <= 1000
*/

/***************************************************************************** ANSWER **********************************************************************************/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> after(2, vector<int>(k + 1, 0));
        vector<vector<int>> curr(2, vector<int>(k + 1, 0));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= k; cap++) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[ind] + after[0][cap], after[1][cap]);
                    }
                    else {
                        profit = max(prices[ind] + after[1][cap - 1], after[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            after = curr;
        }
        return after[1][k];
    }
};

/****************************************************************** METHOD 2 RECURSION ******************************************************************************/

class Solution {
public:
    int f(int ind, int trans, vector<int>& prices, int n, int k) {
        if(ind == n || trans == 2*k) {
            return 0;
        }
        
        //buy
        if(trans % 2 == 0) {
            return max(-prices[ind] + f(ind + 1, trans + 1, prices, n, k), f(ind + 1, trans, prices, n, k));
        }
        //sell
        else {
            return max(prices[ind] + f(ind + 1, trans + 1, prices, n, k), f(ind + 1, trans, prices, n, k));
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return f(0, 0, prices, n, k);
    }
};

/****************************************************************** METHOD 2 MEMOIZATION *****************************************************************************/

class Solution {
public:
    int f(int ind, int trans, vector<int>& prices, int n, int k, vector<vector<int>>& dp) {
        if(ind == n || trans == 2*k) {
            return 0;
        }

        if(dp[ind][trans] != -1) {
            return dp[ind][trans];
        }
        
        //buy
        if(trans % 2 == 0) {
            dp[ind][trans] = max(-prices[ind] + f(ind + 1, trans + 1, prices, n, k, dp), f(ind + 1, trans, prices, n, k, dp));
        }
        //sell
        else {
            dp[ind][trans] = max(prices[ind] + f(ind + 1, trans + 1, prices, n, k, dp), f(ind + 1, trans, prices, n, k, dp));
        }

        return dp[ind][trans];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return f(0, 0, prices, n, k, dp);
    }
};

/******************************************************************* METHOD 2 DP *************************************************************************************/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 1, vector<int>(2*k + 1, 0));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int trans = 2*k - 1; trans >= 0; trans--) {
                //buy
                if(trans % 2 == 0) {
                    dp[ind][trans] = max(-prices[ind] + dp[ind + 1][trans + 1], dp[ind + 1][trans]);
                }
                //sell
                else {
                    dp[ind][trans] = max(prices[ind] + dp[ind + 1][trans + 1], dp[ind + 1][trans]);
                }
            }
        }
        return dp[0][0];
    }
};

/********************************************************************* SPACE OPTIMIZATION ****************************************************************************/

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<int> after(2*k + 1, 0);
        vector<int> curr(2*k + 1, 0);

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int trans = 2*k - 1; trans >= 0; trans--) {
                //buy
                if(trans % 2 == 0) {
                    curr[trans] = max(-prices[ind] + after[trans + 1], after[trans]);
                }
                //sell
                else {
                    curr[trans] = max(prices[ind] + after[trans + 1], after[trans]);
                }
            }
            after = curr;
        }
        return after[0];
    }
};
