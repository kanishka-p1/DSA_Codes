/******************************************************************** QUESTION *****************************************************************************************/

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 

Example 1:

Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
Example 2:

Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6
 

Constraints:

1 <= prices.length <= 5 * 104
1 <= prices[i] < 5 * 104
0 <= fee < 5 * 104
*/

/************************************************************************ ANSWER ***************************************************************************************/

// fee is charged at the time of buying
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadbuy, aheadnotbuy, currbuy, currnotbuy;
        aheadbuy = 0, aheadnotbuy = 0;
        for(int ind = n - 1; ind >= 0; ind--) {
            currbuy = max(-prices[ind] - fee + aheadnotbuy, aheadbuy);
            currnotbuy = max(prices[ind] + aheadbuy, aheadnotbuy);
            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
        return aheadbuy;
    }
};

//fee is charged at the time of selling
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int aheadbuy, aheadnotbuy, currbuy, currnotbuy;
        aheadbuy = 0, aheadnotbuy = 0;
        for(int ind = n - 1; ind >= 0; ind--) {
            currbuy = max(-prices[ind]  + aheadnotbuy, aheadbuy);
            currnotbuy = max(prices[ind] - fee + aheadbuy, aheadnotbuy);
            aheadbuy = currbuy;
            aheadnotbuy = currnotbuy;
        }
        return aheadbuy;
    }
};
