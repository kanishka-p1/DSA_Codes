//                                                                        QUESTION


/*
Given two binary strings, return their sum (also a binary string).
Example:

a = "100"


b = "11"
Return a + b = "111".
*/


//                                                                        ANSWER

string Solution::addBinary(string A, string B) {
    int i = A.length() - 1;
    int j = B.length() - 1;
    string ans;
    int carry = 0;
    
    while(i >= 0 || j >= 0 || carry) {
        if(i >= 0) {
            carry += A[i] - '0';
            i--;
        }
        if(j >= 0) {
            carry += B[j] - '0';
            j--;
        }
        ans += (carry % 2 + '0');
        carry = carry / 2;
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}
