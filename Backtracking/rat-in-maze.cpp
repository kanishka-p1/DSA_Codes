#include<bits/stdc++.h>
using namespace std;

void print(int ans[20][20], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
    }
}

void solveMaze(int maze[20][20], int ans[20][20], int x, int y, int n) {
    if(x == n - 1 && y == n - 1) {
        ans[x][y] = 1;
        print(ans, n);
        cout << endl;
        return;
    }
    
    if(x > n - 1 || x < 0 || y > n - 1 || y < 0) {
        return;
    }
    
    if(x > n - 1 || x < 0 || y > n - 1 || y < 0 || maze[x][y] == 0 || ans[x][y]  == 1) {
        return;
    }
    
    ans[x][y] = 1;
    solveMaze(maze, ans, x - 1, y, n);
    solveMaze(maze, ans, x + 1, y, n);
    solveMaze(maze, ans, x , y - 1, n);
    solveMaze(maze, ans, x, y + 1, n);
    ans[x][y] = 0;
}

void ratInMaze(int maze[20][20], int n) {
    int ans[20][20];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ans[i][j] = 0;
        }
    }
    solveMaze(maze, ans, 0, 0, n);
}

int main() {

	// Write your code here
    int n; 
    cin >> n;
    int maze[20][20];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }
    ratInMaze(maze, n);
}
