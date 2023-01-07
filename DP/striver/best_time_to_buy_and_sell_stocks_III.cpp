/*************************************************************************** QUESTION **********************************************************************************/

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
Example 2:

Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.
Example 3:

Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
 

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 105
*/

/************************************************************************* RECURSION *********************************************************************************/

class Solution {
public:
    int f(int ind, int buy, int cap, vector<int>& prices) {
        int n = prices.size();
        if(cap == 0 || n == ind) {
            return 0;
        }
        int profit = 0;
        if(buy) {
            profit = max(-prices[ind] + f(ind + 1, 0, cap, prices), 0 + f(ind + 1, 1, cap, prices));
        }
        else {
            profit = max(prices[ind] + f(ind + 1, 1, cap - 1, prices), 0 + f(ind + 1, 0, cap, prices));
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return f(0, 1, 2, prices);
    }
};

/************************************************************************* MEMOIZATION *******************************************************************************/

class Solution {
public:
    int f(int ind, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if(cap == 0 || n == ind) {
            return 0;
        }
        
        if(dp[ind][buy][cap] != -1) {
            return dp[ind][buy][cap];
        }

        int profit = 0;
        if(buy) {
            profit = max(-prices[ind] + f(ind + 1, 0, cap, prices, dp), 0 + f(ind + 1, 1, cap, prices, dp));
        }
        else {
            profit = max(prices[ind] + f(ind + 1, 1, cap - 1, prices, dp), 0 + f(ind + 1, 0, cap, prices, dp));
        }

        return dp[ind][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, prices, dp);
    }
};

/********************************************************************************* DP ********************************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= 2; cap++) {
                    int profit = 0;
                    if(buy) {
                        profit = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
                    }
                    else {
                        profit = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};

/*************************************************************************** SPACE OPTIMIZATION **********************************************************************/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> after(2, vector<int>(3, 0));
        vector<vector<int>> curr(2, vector<int>(3, 0));

        for(int ind = n - 1; ind >= 0; ind--) {
            for(int buy = 0; buy <= 1; buy++) {
                for(int cap = 1; cap <= 2; cap++) {
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
        return after[1][2];
    }
};
  
