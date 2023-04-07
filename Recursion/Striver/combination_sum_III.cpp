/**************************************************************************** QUESTION *******************************************************************************/

/*
Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
1. Only numbers 1 through 9 are used.
2. Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.
Example 2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
Example 3:
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.

Constraints:
2 <= k <= 9
1 <= n <= 60
*/

/***************************************************************************** ANSWER *********************************************************************************/

class Solution {
public:
    void combination(int x, int target, vector<int> &arr, vector<vector<int>> &res, vector<int> &ans, int k){
        if(x == arr.size()) {  
            if(target == 0 && k == 0) {    
                res.push_back(ans);
            }
            return;
        }
        if(arr[x] <= target) {
            ans.push_back(arr[x]);   
            combination(x + 1, target - arr[x], arr, res, ans, k - 1);
            ans.pop_back(); 
        }
        combination(x + 1, target, arr, res, ans, k);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> c = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<vector<int>> res;
        vector<int> ans;
        combination(0, n, c, res, ans, k);
        return res;
    }
};
