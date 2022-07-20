//                                                                     QUESTION

/*
Given N x M character matrix A of O's and X's, where O = white, X = black.


Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not included)




Input Format:

    The First and only argument is a N x M character matrix.
Output Format:

    Return a single integer denoting number of black shapes.
Constraints:

    1 <= N,M <= 1000
    A[i][j] = 'X' or 'O'
Example:

Input 1:
    A = [ OOOXOOO
          OOXXOXO
          OXOOOXO  ]
Output 1:
    3
Explanation:
    3 shapes are  :
    (i)    X
         X X
    (ii)
          X
    (iii)
          X
          X
Note: we are looking for connected shapes here.

XXX
XXX
XXX
is just one single connected black shape.
*/


//                                                                            ANSWER


void helper(vector<string>& A, vector<vector<bool>>& vis, int i, int j) {
    if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || vis[i][j] || A[i][j] != 'X') {
        return;
    }
    
    vis[i][j] = 1;
    helper(A, vis, i + 1, j);
    helper(A, vis, i, j + 1);
    helper(A, vis, i - 1, j);
    helper(A, vis, i, j - 1);
}

int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    int ans = 0;
    
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(!vis[i][j] && A[i][j] == 'X') {
                helper(A, vis, i, j);
                ans++;
            }
        }
    }
    
    return ans;
}
