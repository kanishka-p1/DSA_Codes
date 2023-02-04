/**************************************************************************** QUESTION *********************************************************************************/

/*
Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing 
which (and edges through it) disconnects the graph into 2 or more components.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.

Example 1:
Input:
Output:{1,4}
Explanation: Removing the vertex 1 will
discconect the graph as-
Removing the vertex 4 will disconnect the
graph as-
Your Task:
You don't need to read or print anything. Your task is to complete the function articulationPoints() which takes V and adj as input parameters 
and returns a list containing all the vertices removing which turn the graph into two or more disconnected components in sorted order. If there are 
no such vertices then returns a list containing -1.
 
Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
 
Constraints:
1 ≤ V ≤ 105
*/

/******************************************************************************** ANSWER *******************************************************************************/

class Solution {
  public:
    int timer = 0;
    void dfs(int node, int parent, vector<int>& vis, int tin[], int low[], vector<int>& mark, vector<int> adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(auto it : adj[node]) {
            if(it == parent) {
                continue;
            }
            if(!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if(low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if(child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
  
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> vis(V, 0);
        int tin[V];
        int low[V];
        vector<int> mark(V, 0);
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for(int i = 0; i < V; i++) {
            if(mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) {
            return {-1};
        }
        return ans;
    }
};
