//                                                                        QUESTION

/*
Given a string A denoting an expression. It contains the following operators '+', '-', '*', '/'.

Chech whether A has redundant braces or not.

NOTE: A will be always a valid expression.



Problem Constraints
1 <= |A| <= 105



Input Format
The only argument given is string A.



Output Format
Return 1 if A has redundant braces, else return 0.



Example Input
Input 1:

 A = "((a+b))"
Input 2:

 A = "(a+(a+b))"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 ((a+b)) has redundant braces so answer will be 1.
Explanation 2:

 (a+(a+b)) doesn't have have any redundant braces so answer will be 0.
 */


//                                                                            ANSWER


bool check(string& s) {
    stack<char> st;
    for(auto& it : s) {
        if(it == ')') {
            char top = st.top();
            st.pop();
            
            bool flag = true;
            while(!st.empty() && top != '(') {
                if(top == '+' || top == '-' || top == '*' || top == '/') {
                    flag = false;
                }
                top =  st.top();
                st.pop();
            }
            
            if(flag == true) {
                return true;
            }
        }
        else {
            st.push(it);
        }
    }
    return false;
}

int Solution::braces(string A) {
    bool ans = check(A);
    return ans;
}
