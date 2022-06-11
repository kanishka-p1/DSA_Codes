#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void bfs(int** edges, int n, bool* visited, int sv, vector<int>& temp) {
    queue<int> ver;
    ver.push(sv);
    visited[sv];
    
    while(!ver.empty()) {
        int fr = ver.front();
        ver.pop();
        temp.push_back(fr);
        for(int i = 0; i < n; i++) {
            if(!visited[i] && edges[fr][i] == 1 && i != sv) {
                visited[i] = true;
                ver.push(i);
            }
        }
    }
}

vector<vector<int>> bfs_track(int** edges, int n, bool* visited) {
    vector<vector<int>> res;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            vector<int> temp;
            bfs(edges, n, visited, i, temp);
            res.push_back(temp);
        }
    }
    return res;
}

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;
    
    int** edges = new int*[n];
    for(int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for(int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }
    
    for(int i = 0; i < e; i++) {
        int s, f;
        cin >> s >> f;
        edges[s][f] = 1;
        edges[f][s] = 1;
    }
    
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    vector<vector<int>> ans = bfs_track(edges, n, visited);
    
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
        sort(ans[i].begin(), ans[i].end());
        for(int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    delete [] visited;
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
}
