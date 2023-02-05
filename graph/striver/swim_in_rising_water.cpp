/************************************************************************** QUESTION ************************************************************************************/

/*
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally 
adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. 
Of course, you must stay within the boundaries of the grid during your swim.

Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

Example 1:
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
 
Constraints:
n == grid.length
n == grid[i].length
1 <= n <= 50
0 <= grid[i][j] < n2
Each value grid[i][j] is unique.
*/

/********************************************************************************* ANSWER ******************************************************************************/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> time(n, vector<int>(n, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        time[0][0] = grid[0][0];
        pq.push({time[0][0], {0, 0}});
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

            for(int k = 0; k < 4; k++) {
                int nr = row + dir[k][0];
                int nc = col + dir[k][1];

                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] < time[nr][nc]) {
                    if(diff < grid[nr][nc]) {
                        time[nr][nc] = grid[nr][nc];
                        pq.push({time[nr][nc], {nr, nc}});
                    }
                    else if(diff < time[nr][nc]) {
                        time[nr][nc] = diff;
                        pq.push({time[nr][nc], {nr, nc}});
                    }
                }
            }
        }

        return time[n - 1][n - 1];
    }
};
