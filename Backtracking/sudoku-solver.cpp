#include<bits/stdc++.h>
using namespace std;

bool check(int board[][9], int row, int col, int val) {
    for(int k = 0; k < 9; k++) {
        if(board[row][k] == val) {
            return false;
        }
        if(board[k][col] == val) {
            return false;
        }
    }
    
    int ri = row - row % 3;
    int ci = col - col % 3;
    
    for(int c = ri; c < ri + 3; c++) {
        for(int d = ci; d < ci + 3; d++) {
            if(board[c][d] == val) {
                return false;
            }
        }
    }
    return true;
}

bool helper(int board[][9], int row, int col) {
    if(row == 9) {
        return true;
    }
    
    if(col == 9) {
        return helper(board, row + 1, 0);
    }
    
    if(board[row][col] != 0) {
        return helper(board, row, col + 1);
    }
    
    for(int k = 1; k <= 9; k++) {
        if(check(board, row, col, k)) {
            board[row][col] = k;
            if(helper(board, row, col + 1)) {
                return true;
            }
        }
        board[row][col] = 0;
    }
    return false;
}

bool sudokuSolver(int board[][9]) {
    return helper(board, 0, 0);
}

int main(){
    
    // write your code here
    int board[9][9];
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
    
    if(sudokuSolver(board)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    return 0;
}
