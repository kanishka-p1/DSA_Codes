#include<bits/stdc++.h>
using namespace std;

bool isBoardSafe(vector<vector<int>> &board, int row, int col) {
    int n = board.size();
    
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    
    for(int i = row + 1, j = col + 1; i < n && j < n; i++, j++) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    
    for(int i = row + 1, j = col - 1; i < n && j  >= 0; i++, j--) {
        if(board[i][j] == 1) {
            return false;
        }
    }
    
    for(int i = row - 1; i >= 0; i--) {
        if(board[i][col] == 1) {
            return false;
        }
    }
    
    for(int i = row + 1; i < n; i++) {
        if(board[i][col] == 1) {
            return false;
        }
    }
    
    return true;
}

void placeQueen (vector<vector<int>> &board, int row, int n) {
    if(row == n) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << board[i][j] << " ";
            }
        }
        cout << endl;
    }
    
    for(int j = 0; j < n; j++) {
        if(isBoardSafe(board, row, j)) {
            board[row][j] = 1;
            placeQueen(board, row + 1, n);
            board[row][j] = 0;
        }
    }
}

void placeNQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    placeQueen(board, 0, n);
}

int main(){
    
    // write your code here
    int n;
    cin >> n;
    placeNQueens(n);
    return 0;
}
