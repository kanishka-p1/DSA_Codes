/********************************************************************** QUESTION ***************************************************************************************/

/*
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.

Return the size of the largest island in grid after applying this operation.

An island is a 4-directionally connected group of 1s.

 

Example 1:

Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Constraints:

n == grid.length
n == grid[i].length
1 <= n <= 500
grid[i][j] is either 0 or 1.
*/

/**************************************************************************** ANSWER ********************************************************************************/

class DisjointSet {
    
    public:

    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findPar(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void unionSize(int u, int v) {
        int parent_u = findPar(u);
        int parent_v = findPar(v);

        if(parent_u == parent_v) return;

        if(size[parent_u] < size[parent_v]) {
            size[parent_v] += size[parent_u];
            parent[parent_u] = parent_v;
        }

        else {
            size[parent_u] += size[parent_v];
            parent[parent_v] = parent_u;
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();

        DisjointSet ds(n*n);

        // make disjoint set data structure out of pre-existing graph
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int arr[4][2] = {{-1, 0}, {1, 0}, {0, 1},{0, -1}};
                    for(int k = 0; k < 4; k++) {
                        int x = i + arr[k][0];
                        int y = j + arr[k][1];
                        if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1) {
                            int value_i = i*n + j;
                            int value_x = x*n + y;
                            ds.unionSize(value_i, value_x);
                        }
                    }
                }
            }
        }

        int area = 0;

        // travel to every 0 cell and make it one to check if its size is max
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] == 0) {
                    
                    int arr[4][2] = {{-1, 0}, {1, 0}, {0, 1},{0, -1}};
                    
                    // we make a set so that we can store unique neighbouring area
                    // it can be possible that two neighbours are part of the same component
                    set<int> components;
                    
                    for(int k = 0; k < 4; k++) {
                        int x = i + arr[k][0];
                        int y = j + arr[k][1];
                        
                        if(x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == 1) {
                            components.insert(ds.findPar(x*n + y));
                        }
                    }
                    
                    int neigh_size = 0;
                    for(auto it: components) {
                        neigh_size += ds.size[it];
                    }

                    area = max(area, neigh_size + 1);
                }
            }
        }

        // this we are doing for cases where already existing components might be larger
        // than the ones being made by making a cell 1
        for(int i = 0; i < n*n; i++) {
            area = max(area, ds.size[ds.findPar(i)]);
        }

        return area;
    }
};
