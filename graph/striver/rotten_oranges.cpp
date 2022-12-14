/**************************************************************** QUESTION ***************************************************************************************/

/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

 

Example 1:


Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

/******************************************************************** ANSWER ************************************************************************************/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int countfresh = 0;
        int ans = -1;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.emplace(i, j);
                }
                else if(grid[i][j] == 1) {
                    countfresh++;
                }
            }
        }

        if(countfresh == 0) {
            return 0;
        }

        int dir[4][2] = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

        while(!q.empty()) {
            int s = q.size();
            ans++;
            while(s-- > 0) {
                auto [r, c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nr = r + dir[i][0];
                    int nc = c + dir[i][1];
                    if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1) {
                        q.emplace(nr, nc);
                        grid[nr][nc] = 0;
                        countfresh--;
                    }
                }
            }
        }

        if(countfresh == 0) {
            return ans;
        }
        else {
            return -1;
        }
    }
};

