/******************************************************************** QUESTION ****************************************************************************************/

/*
Given an integer N representing the number of pairs of parentheses, the task is to generate all combinations of well-formed(balanced) parentheses.

Example 1:
Input:
N = 3
Output:
((()))
(()())
(())()
()(())
()()()
Example 2:
Input:
N = 1
Output:
()

Your Task:  
You don't need to read input or print anything. Complete the function AllParenthesis() which takes N as input parameter and returns the list of balanced parenthesis.

Expected Time Complexity: O(2N * N).
Expected Auxiliary Space: O(2*N*X), X = Number of valid Parenthesis.

Constraints:
1 ≤ N ≤ 12
*/

/**************************************************************************** ANSWER **********************************************************************************/

class Solution
{
    public:
    void helper(vector<string>& ans, string str, int o, int c) {
        if(o == 0 && c == 0) {
            ans.push_back(str);
            return;
        }
        if(c > 0) {
            helper(ans, str+")", o, c - 1);
        }
        if(o > 0) {
            helper(ans, str+"(", o - 1, c + 1);
        }
    }
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        vector<string> ans;
        helper(ans, "", n, 0);
        return ans;
    }
};


// METHOD 2 BACKTRACKING
class Solution {
public:
    void generate(vector<string> &ans, string str, int open, int close) {
        if(open == 0 && close == 0) {
            ans.push_back(str);
            return;
        }
        if(open > 0) {
            str.push_back('(');
            generate(ans, str, open - 1, close);
            str.pop_back();
        }
        if(close > 0 && close > open) {
            str.push_back(')');
            generate(ans, str, open, close - 1);
            str.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generate(ans, "", n, n);
        return ans;
    }
};
