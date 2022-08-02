//                                                                          QUESTION

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses of length 2*n.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
Make sure the returned list of strings are sorted.
*/


//                                                                            ANSWER

void helper(vector<string>& ans, string str, int n, int m) {
    if(n == 0 && m == 0) {
        ans.push_back(str);
        return;
    }
    if(m > 0) {
        helper(ans, str+")", n, m - 1);
    }
    if(n > 0) {
        helper(ans, str+"(", n - 1, m + 1);
    }
}

vector<string> Solution::generateParenthesis(int A) {
    vector<string> ans;
    helper(ans, "", A, 0);
    sort(ans.begin(), ans.end());
    return ans;
}
