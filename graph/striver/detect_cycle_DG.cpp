/******************************************************************* QUESTION ****************************************************************************************/

/*
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.


Example 1:

Input:



Output: 1
Explanation: 3 -> 3 is a cycle

Example 2:

Input:


Output: 0
Explanation: no cycle in the graph

Your task:
You dont need to read input or print anything. Your task is to complete the function isCyclic() which takes the integer V denoting the number of vertices 
and adjacency list as input parameters and returns a boolean value denoting if the given directed graph contains a cycle or not.


Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)


Constraints:
1 ≤ V, E ≤ 105
*/

/****************************************************************************** DFS *********************************************************************************/

class Solution {
  public:
    bool check(int node, vector<int> adj[], vector<int>& vis, vector<int>& dfsvis) {
        vis[node] = 1;
        dfsvis[node] = 1;
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                if(check(it, adj, vis, dfsvis)) {
                    return true;
                }
            }
            else if(dfsvis[it]) {
                return true;
            }
        }
        dfsvis[node] = 0;
        return false;
    }
  
  
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int> dfsvis(V, 0);
        
        for(int i = 0; i < V; i++)  {
            if(!vis[i]) {
                if(check(i, adj, vis, dfsvis)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

/***************************************************************************** BFS **********************************************************************************/

//USING TOPOLOGICAL SORT
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> indegree(V);
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                indegree[i]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topo;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it : adj[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        if(topo.size() == V) {
            return false;
        }
        else {
            return true;
        }
    }
};
