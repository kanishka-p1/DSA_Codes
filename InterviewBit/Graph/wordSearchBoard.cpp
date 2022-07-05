//                                                                    QUESTION

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The cell itself does not count as an adjacent cell. 

The same letter cell may be used more than once.

Example :

Given board =

[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns 1,
word = "SEE", -> returns 1,
word = "ABCB", -> returns 1,
word = "ABFSAB" -> returns 1
word = "ABCD" -> returns 0
Note that 1 corresponds to true, and 0 corresponds to false.
*/

//                                                                 ANSWER


bool helper(vector<string> &A, string B, int i, int j, int s) {
    if(i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || A[i][j] != B[s]){
        return false;
    }
    
    if(s == B.size() - 1) {
        return true;
    }
    
    if(helper(A, B, i + 1, j, s + 1)){
        return true;
    }
    if(helper(A, B, i, j + 1, s + 1)){
        return true;
    }
    if(helper(A, B, i - 1, j, s + 1)){
        return true;
    }
    if(helper(A, B, i, j - 1, s + 1)){
        return true;
    }
    
    return false;
}

int Solution::exist(vector<string> &A, string B) {
    int n = A.size();
    int m = A[0].size();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bool ans = helper(A, B, i, j, 0);
            if(ans) {
                return true;
            }
        }
    }
    return 0;
}
