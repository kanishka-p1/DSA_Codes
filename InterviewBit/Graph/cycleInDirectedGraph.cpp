bool checkCycle(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& dfsvis) {
    vis[node] = 1;
    dfsvis[node] = 1;
    
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(checkCycle(it, adj, vis, dfsvis)) {
                return true;
            }
        } else if(dfsvis[it]) {
            return true;
        }
    }
    
    dfsvis[node] = 0;
    return false;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> vis(A + 1, 0);
    vector<int> dfsvis(A + 1, 0);
    
    vector<vector<int>> adj(A + 1);
    for(auto it : B) {
        adj[it[0]].push_back(it[1]);
        it.clear();
    }
        
    for(int i = 1; i <= A; i++) {
        if(!vis[i]) {
            if(checkCycle(i, adj, vis, dfsvis)) {
                return true;
            }
        }
    }
    
    return false;
}
