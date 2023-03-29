/************************************************************************** QUESTION **********************************************************************************/

/*
Given a number N, find the first N Fibonacci numbers. The first two number of the series are 1 and 1.

Example 1:
Input:
N = 5
Output: 1 1 2 3 5
Example 2:
Input:
N = 7
Output: 1 1 2 3 5 8 13
Your Task:
Your task is to complete printFibb() which takes single argument N and returns a list of first N Fibonacci numbers.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).
Note: This space is used to store and return the answer for printing purpose.

Constraints:
1<= N <=84
*/

/*************************************************************************** ANSWER ***********************************************************************************/

class Solution
{
    public:
    //Function to return list containing first n fibonacci numbers.
    vector<long long> rec(vector<long long>& ans, int n, long long first, long long second) {
        if(n < 1) {
            return ans;
        }
        ans.push_back(second);
        long long temp = second;
        second = first + second;
        first = temp;
        rec(ans, n - 1, first, second);
        return ans;
    }
    
    vector<long long> printFibb(int n) 
    {
        //code here
        // vector<long long> ans(n);
        // ans[0] = 1;
        // ans[1] = 1;
        // for(int i = 2; i < n; i++) {
        //     ans[i] = ans[i-1] + ans[i-2];
        // }
        // return ans;
        
        long long first = 0;
        long long second = 1;
        vector<long long> ans;
        return rec(ans, n, first, second);
    }
};
