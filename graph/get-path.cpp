#include <iostream>
#include<vector>
using namespace std;

vector<int> getPath(int** edges, int n, bool* visited, int s, int e) {
    vector<int> ans;
    if(s == e) {
        ans.push_back(s);
        return ans;
    }
    
    visited[s] = true;
    
    for(int i = 0; i < n; i++) {
        if(!visited[i] && edges[i][s] == 1) {
            vector<int> temp = getPath(edges, n, visited, i, e);
            if(temp.size() != 0) {
                ans = temp;
                ans.push_back(s);
                return ans;
            }
        }
    }
    return ans;
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
    
    int ver1, ver2;
    cin >> ver1 >> ver2;
    
    bool* visited = new bool[n];
    for(int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    vector<int> res = getPath(edges, n, visited, ver1, ver2);
    
    if(res.size() != 0) {
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
    }
    
    delete [] visited;
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
}
