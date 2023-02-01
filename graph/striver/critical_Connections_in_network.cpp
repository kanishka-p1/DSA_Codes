/****************************************************************** QUESTION ******************************************************************************************/

/*
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] 
represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
Return all critical connections in the network in any order.
 
Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
 
Constraints:
2 <= n <= 105
n - 1 <= connections.length <= 105
0 <= ai, bi <= n - 1
ai != bi
There are no repeated connections.
*/

/************************************************************************* ANSWER ************************************************************************************/

class Solution {
public:
    int timer = 1;
    
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges) {
        vis[node] = 1;
     // tin and low will store the timer of the node visited
        tin[node] = low[node] = timer;
     // for the next level of node timer will increment
        timer++;
        for(auto it : adj[node]) {
         // we will not consider the case where the node is equal to the parent (node == adj)
            if(it == parent) {
                continue;
            }
         // if the adjacent node is not previously visited then we will call dfs on it and update the value of node
         // with the minimum of lowest time of the node and the time of adjacent node
            if(vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
             // checking if the bridge is present or not
                if(low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
         // we will just update the time of the node if bridge is not there
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);

        return bridges;
    }
};
