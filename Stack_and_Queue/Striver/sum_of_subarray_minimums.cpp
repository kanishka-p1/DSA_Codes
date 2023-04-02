/************************************************************************ QUESTION ************************************************************************************/

/*
Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, 
return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation: 
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.
Example 2:
Input: arr = [11,81,94,43,3]
Output: 444
 
Constraints:
1 <= arr.length <= 3 * 104
1 <= arr[i] <= 3 * 104
*/

/********************************************************************************* ANSWER *****************************************************************************/

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> s;
        int n = arr.size();
        vector<int> right(n), left(n);

        for(int i = 0; i < n; i++) {
            right[i] = n - i - 1;
            left[i] = i;
        }

        for(int i = 0; i < n; i++) {
            while(!s.empty() && arr[s.top()] > arr[i]) {
                right[s.top()] = i - s.top() - 1;
                s.pop();
            }
            s.push(i);
        }

        while(!s.empty()) {
            s.pop();
        }

        for(int i = n - 1; i >= 0; i--) {
            while(!s.empty() && arr[s.top()] >= arr[i]) {
                left[s.top()] = s.top() - i - 1;
                s.pop();
            }
            s.push(i);
        }

        int ans = 0;
        int mod = 1e9+7;

        for(int i = 0; i < n; i++) {
            long long prod = ((right[i] + 1) * (left[i] + 1)) % mod;
            prod = (prod * arr[i]) % mod;
            ans = (ans + prod) % mod;
        }

        return ans;
    }
};
