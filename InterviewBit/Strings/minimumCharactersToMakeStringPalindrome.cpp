//                                                                        QUESTION

/*
Given an string A. The only operation allowed is to insert  characters in the beginning of the string.

Find how many minimum characters are needed to be inserted to make the string a palindrome string.




Input Format

The only argument given is string A.
Output Format

Return the minimum characters that are needed to be inserted to make the string a palindrome string.
For Example

Input 1:
    A = "ABC"
Output 1:
    2
    Explanation 1:
        Insert 'B' at beginning, string becomes: "BABC".
        Insert 'C' at beginning, string becomes: "CBABC".

Input 2:
    A = "AACECAAAA"
Output 2:
    2
    Explanation 2:
        Insert 'A' at beginning, string becomes: "AAACECAAAA".
        Insert 'A' at beginning, string becomes: "AAAACECAAAA".
*/


//                                                                              ANSWER

// minimum insertions to make string palindrome
int lcs(string a, string b, int m, int n) {
     vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
     for(int i = 1; i <= m; i++) {
         for(int j = 1; j <= n; j++) {
             if(a[i - 1] == b[j - 1]) {
                 dp[i][j] = 1 + dp[i - 1][j - 1];
             }
             else {
                 dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
             }
         }
     }
     return dp[m][n];
 }

 int Solution::solve(string A) {
     int n = A.length();
     string str = A;
     reverse(str.begin(), str.end());
    
     int ans = n - lcs(A, str, n, n);
     return ans;
 }


//minimum insertions in front to make string palindrome
int computeLPS(string &B){
    int n = B.size(), j = 0;
    int lps[n]; 
    lps[0] = 0;
    
    int i = 1; 
    while(i < n){
        if(B[i] == B[j]){
            j++;
            lps[i] = j;
            i++;
        }
        else{
            if(j!=0){
                j = lps[j-1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return n/2 - lps[n-1];
}

int Solution::solve(string A) {
    string B = A; 
    reverse(A.begin(), A.end());
    B += "$" + A;
    return computeLPS(B);
}
