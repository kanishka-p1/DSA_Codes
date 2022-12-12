// QUESTION
/* 
Given a directed graph. The task is to do Breadth First Traversal of this graph starting from 0.
Note: One can move from node u to node v only if there's an edge from u to v and find the BFS traversal 
of the graph starting from the 0th vertex, from left to right according to the graph. Also, you should only 
take nodes directly or indirectly connected from Node 0 in consideration.
*/

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V, false);
        queue<int> ver;
        ver.push(0);
        visited[0] = true;
        vector<int> ans;
        
        while(!ver.empty()) {
            int f = ver.front();
            ver.pop();
            ans.push_back(f);
            
            for(auto it : adj[f]) {
                if(!visited[it]) {
                    visited[it] = true;
                    ver.push(it);
                }
            }
        }
        return ans;
    }
};
