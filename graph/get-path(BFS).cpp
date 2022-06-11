#include <iostream>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> getPath(int** edges, int n, bool* visited, int s, int e) {
    vector<int> ans;
    
    queue<int> ver;
    ver.push(s);
    
    visited[s] = true;
    unordered_map<int, int> track;
    
    int temp = 0;
    
    while(!ver.empty()) {
        int fr = ver.front();
        ver.pop();
        
        if(fr == e) {
            temp = 1;
            break;
        }
        
        for(int i = 0; i < n; i++) {
            if(!visited[i] && edges[fr][i] ==1) {
                visited[i] = true;
                track[i] = fr;
                ver.push(i);
            }
        }
    }
    
    if(temp) {
        int cur = e;
        ans.push_back(e);
        while(cur != s) {
            cur = track[cur];
            ans.push_back(cur);
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
