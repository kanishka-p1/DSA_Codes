//                                                                    QUESTION

/*
Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.


 Input Format

The only argument given is string A.
Output Format

Return the string A after reversing the string word by word.
For Example

Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
Output 2:
    "ib is this"

Input 3:
 A = " hello world "
Output 3:
 "world hello"
*/


//                                                                          ANSWER

//approach1
string Solution::solve(string A) {
    reverse(A.begin(), A.end());
    int l = 0, r = 0, i = 0, n = A.size();
    
    while(i < n) {
        while(i < n && A[i] != ' ') {
            A[r++] = A[i++];
        }
        if(l < r) {
            reverse(A.begin() + l, A.begin() + r);
            if(r == n) {
                break;
            }
            A[r++] = ' ';
            l = r;
        }
        i++;
    }
    
    if(r > 0 && A[r - 1] == ' ') {
        r--;
    }
    A.resize(r);
    
    return A;    
}


//approach2
string reverseWords(string s) {
        if(s.size() == 0) {
        return s;        
    }
    
    stack<string> st;
    string ans;
    
    for(int i = 0; i < s.size(); i++) {
        string word;
        if(s[i] == ' ') {
            continue;
        }
        while(i < s.size() && s[i] != ' ' ) {
            word += s[i]; 
            i++;
        }
        st.push(word);
        
    }
        
    while(!st.empty()) {
        ans += st.top(); 
        st.pop();
        if(!st.empty()) {
          ans += " ";  
        } 
    }
    
    return ans;
    }
