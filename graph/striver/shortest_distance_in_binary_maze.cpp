/********************************************************************** GFG ******************************************************************************************/

/*
Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. 
The path can only be created out of a cell if its value is 1. 

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, 
you can move in one of the four directions, Up, Down, Left and Right.

Example 1:

Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the 
shortest path from source to destination cell.
Example 2:

Input:
grid[][] = {{1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 0},
            {1, 0, 1, 0, 1}}
source = {0, 0}
destination = {3, 4}
Output:
-1
Explanation:
The path is not possible between source and 
destination, hence return -1.
Your Task:

You don't need to read or print anything. Your task is to complete the function shortestPath() which takes the a 2D integer array grid, 
source cell and destination cell as an input parameters and returns the shortest distance between source and destination cell.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:

1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
The source and destination cells are always inside the given matrix.
The source and destination cells always contain 1.
*/

/************************************************************************ ANSWER ***********************************************************************************/

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue<pair<int, pair<int, int>>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        if(source.first == destination.first && source.second == destination.second) {
            return 0;
        }
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int k = 0; k < 4; k++) {
                int nr = r + dir[k][0];
                int nc = c + dir[k][1];
                if(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] == 1 && dist[nr][nc] > dis + 1) {
                    dist[nr][nc] = dis + 1;
                    if(nr == destination.first && nc == destination.second) {
                        return dist[nr][nc];
                    }
                    q.push({dis + 1, {nr, nc}});
                }
            }
        }
        
        return -1;
    }
};

/*************************************************************************** LEETCODE *******************************************************************************/

/*
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

 

Example 1:


Input: grid = [[0,1],[1,0]]
Output: 2
Example 2:


Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
Example 3:

Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 100
grid[i][j] is 0 or 1
*/

/*************************************************************************** ANSWER *********************************************************************************/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, 1e9));
        dist[0][0] = 1;
        q.push({1, {0, 0}});
        int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

        if(grid[0][0] == 1) {
            return -1;
        }
        if(m == 1 || n == 1) {
            return 1;
        }

        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;

            for(int k = 0; k < 8; k++) {
                int nr = r + dir[k][0];
                int nc = c + dir[k][1];

                if(nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 0 && dist[nr][nc] > 1 + dis) {
                    dist[nr][nc] = 1 + dis;
                    if(nr == m - 1 && nc == n - 1) {
                        return dist[nr][nc];
                    }
                    q.push({1 + dis, {nr, nc}});
                }
            }
        }

        return -1;
    }
};
