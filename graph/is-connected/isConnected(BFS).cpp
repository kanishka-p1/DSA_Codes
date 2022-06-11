#include <iostream>
#include<queue>
using namespace std;

void bfs(int** edges, int n, bool* visited, int s) {
    queue<int> ver;
    visited[s] = true;
    ver.push(s);
    
    while(!ver.empty()) {
        int fr = ver.front();
        ver.pop();
        
        for(int i = 0; i < n; i++) {
            if(!visited[i] && edges[fr][i] == 1 && s != i) {
                visited[i] = true;
                ver.push(i);
            }
        }
    } 
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
    
    bfs(edges, n, visited, 0);
    
    bool isConnected = true;
    
    for(int i = 0; i < n; i++) {
        if(visited[i] == false) {
            isConnected = false;
            cout << "false";
            break;
        }
    }
    
    if(isConnected) {
        cout << "true";
    }
    
    delete [] visited;
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
}
