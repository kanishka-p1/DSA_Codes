//                                                                      QUESTION

/*
The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens’ placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,

There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/

//                                                                           ANSWER


bool canPlace(vector<string>& board, int A, int row, int col, vector<vector<string>>& ans) {
    for(int i = row; i >= 0; i--) {
        if(board[i][col] == 'Q') {
            return false;
        }
    }
    
    for(int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    
    for(int i = row, j = col; i >= 0 && j < A; i--, j++) {
        if(board[i][j] == 'Q') {
            return false;
        }
    }
    
    return true;
}

void findPlaces(vector<string>& board, int row, int A, vector<vector<string>>& ans) {
    if(row == A) {
        ans.push_back(board);
        return;
    }
    
    for(int i = 0; i < A; i++) {
        if(canPlace(board, A, row, i, ans)) {
            board[row][i] = 'Q';
            findPlaces(board, row + 1, A, ans);
            board[row][i] = '.';
        }
    }
}

vector<vector<string> > Solution::solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<string> board(A, string(A, '.'));
    vector<vector<string>> ans;
    
    findPlaces(board, 0, A, ans);
    
    return ans;
}
