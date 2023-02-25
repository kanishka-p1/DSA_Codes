/********************************************************************* QUESTION ***************************************************************************************/

/*
Given a boolean expression S of length N with following symbols.
Symbols
    'T' ---> true
    'F' ---> false
and following operators filled between symbols
Operators
    &   ---> boolean AND
    |   ---> boolean OR
    ^   ---> boolean XOR
Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

Example 1:
Input: N = 7
S = T|T&F^T
Output: 4
Explaination: The expression evaluates 
to true in 4 ways ((T|T)&(F^T)), 
(T|(T&(F^T))), (((T|T)&F)^T) and (T|((T&F)^T)).
Example 2:
Input: N = 5
S = T^F|F
Output: 2
Explaination: ((T^F)|F) and (T^(F|F)) are the 
only ways.

Your Task:
You do not need to read input or print anything. Your task is to complete the function countWays() which takes N and S as input parameters and 
returns number of possible ways modulo 1003.

Expected Time Complexity: O(N3)
Expected Auxiliary Space: O(N2) 

Constraints:
1 ≤ N ≤ 200 
*/

/**************************************************************************** RECURSION *****************************************************************************/

class Solution{
public:
    int mod = 1003;

    long long f(int i, int j, int isTrue, string &S) {
        if(i > j) {
            return 0;
        }
        if(i == j) {
            if(isTrue) {
                return S[i] == 'T';
            }
            else {
                return S[i] == 'F';
            }
        }
        long long ways = 0;
        for(int ind = i + 1; ind <= j - 1; ind += 2) {
            long long lt = f(i, ind - 1, 1, S);
            long long lf = f(i, ind - 1, 0, S);
            long long rt = f(ind + 1, j, 1, S);
            long long rf = f(ind + 1, j, 0, S);
            
            if(S[ind] == '&') {
                if(isTrue) {
                    ways += (lt * rt) % mod;
                }
                else {
                    ways += ((lt * rf) % mod + (lf * rt) % mod + (lf *rf) % mod) % mod;
                }
            }
            else if(S[ind] == '|') {
                if(isTrue) {
                    ways += ((lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
                }
                else {
                    ways += (lf * rf) % mod;
                }
            }
            else {
                if(isTrue) {
                    ways += ((lt * rf) % mod + (lf * rt) % mod) % mod;
                }
                else {
                    ways += ((lt * rt) % mod + (lf * rf) % mod);
                }
            }
        }
        return ways;
    }

    int countWays(int N, string S){
        // code here
        return f(0, N - 1, 1, S);
    }
};

/***************************************************************************** MEMOIZATION *************************************************************************/

class Solution{
public:
    int mod = 1003;

    long long f(int i, int j, int isTrue, string &S, vector<vector<vector<int>>>& dp) {
        if(i > j) {
            return 0;
        }
        
        if(i == j) {
            if(isTrue) {
                return S[i] == 'T';
            }
            else {
                return S[i] == 'F';
            }
        }
        
        if(dp[i][j][isTrue] != -1) {
            return dp[i][j][isTrue];
        }
        
        long long ways = 0;
        for(int ind = i + 1; ind <= j - 1; ind += 2) {
            long long lt = f(i, ind - 1, 1, S, dp);
            long long lf = f(i, ind - 1, 0, S, dp);
            long long rt = f(ind + 1, j, 1, S, dp);
            long long rf = f(ind + 1, j, 0, S, dp);
            
            if(S[ind] == '&') {
                if(isTrue) {
                    ways += (lt * rt) % mod;
                }
                else {
                    ways += ((lt * rf) % mod + (lf * rt) % mod + (lf *rf) % mod) % mod;
                }
            }
            else if(S[ind] == '|') {
                if(isTrue) {
                    ways += ((lt * rt) % mod + (lt * rf) % mod + (lf * rt) % mod) % mod;
                }
                else {
                    ways += (lf * rf) % mod;
                }
            }
            else {
                if(isTrue) {
                    ways += ((lt * rf) % mod + (lf * rt) % mod) % mod;
                }
                else {
                    ways += ((lt * rt) % mod + (lf * rf) % mod);
                }
            }
        }
        return dp[i][j][isTrue] = ways % mod;
    }

    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N, vector<vector<int>>(N, vector<int>(2, -1)));
        return f(0, N - 1, 1, S, dp);
    }
};
