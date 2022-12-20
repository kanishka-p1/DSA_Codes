/*********************************************************************** QUESTION ************************************************************************************/

/*
Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) 
forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and 
returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1
*/

/*************************************************************************** ANSWER *********************************************************************************/

class Solution {
  public:
    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& visited, vector<pair<int, int>>& vec, int bi, int bj) {
        visited[i][j] = 1;
        vec.push_back({i - bi, j - bj});
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        for(int k = 0; k < 4; k++) {
            int nr = i + dir[k][0];
            int nc = j + dir[k][1];
            
            if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && !visited[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, grid, visited, vec, bi, bj);
            }
        }
    }
  
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        set<vector<pair<int, int>>> st;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, visited, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        
        return st.size();
    }
};
