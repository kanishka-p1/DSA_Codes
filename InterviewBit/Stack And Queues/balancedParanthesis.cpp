//                                                                         QUESTION

/*
Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.



Problem Constraints
1 <= |A| <= 105



Input Format
First argument is an string A.



Output Format
Return 1 if parantheses in string are balanced else return 0.



Example Input
Input 1:

 A = "(()())"
Input 2:

 A = "(()"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 Given string is balanced so we return 1
Explanation 2:

 Given string is not balanced so we return 0
 */

//                                                                            ANSWER


int Solution::solve(string A) {
    int len = A.length();
    if(len == 0 || len == 1) {
        return false;
    }
    
    stack<char> st;
    
    for(int i = 0; i < len; i++) {
        if(A[i] == '(') {
            st.push(A[i]);
        }
        if(A[i] == ')') {
            if(st.empty()) {
                return false;
            }
            
            char top = st.top();
            st.pop();
            
            if(top == '(' && A[i] != ')') {
                return false;
            }
        }
    }
    
    return st.empty();
}
