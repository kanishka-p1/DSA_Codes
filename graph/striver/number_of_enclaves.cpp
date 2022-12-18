/***************************************************************************** QUESTION *******************************************************************************/

/*
You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

 

Example 1:


Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
Output: 3
Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
Example 2:


Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
Output: 0
Explanation: All 1s are either on the boundary or can reach the boundary.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 500
grid[i][j] is either 0 or 1.
*/

/******************************************************************************** DFS *********************************************************************************/

class Solution {
public:

    void dfs(vector<vector<int>>& grid, int x, int y) {
        if(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == 0) {
            return;
        }
        grid[x][y] = 0;

        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int count = 0;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1) {
                    if(grid[i][j] == 1) {
                        dfs(grid, i, j);
                    }
                }
            }
        }

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};

/******************************************************************************** BFS *******************************************************************************/

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> visited(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    if(grid[i][j] == 1) {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {
                int nr = r + dir[k][0];
                int nc = c + dir[k][1];

                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1 && visited[nr][nc] == 0) {
                    q.push({nr, nc});
                    visited[nr][nc] = 1;
                }
            }
        }

        int count = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && visited[i][j] == 0) {
                    count++;
                }
            }
        }

        return count;
    }
};
