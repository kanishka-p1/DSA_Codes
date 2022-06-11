#include <iostream>
#include<queue>
using namespace std;

void bfs(int** graph, int v, bool* visited, int sv) {
    queue<int> ver;
    visited[sv] = true;
    ver.push(sv);
    
    while(!ver.empty()) {
        int n = ver.front();
        ver.pop();
        cout << n << " ";
        
        for(int i = 0; i < v; i++) {
            if(!visited[i] && graph[n][i] == 1 && i != sv) {
                visited[i] = true;
                ver.push(i);
            }
        }
    }
}

int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
    
    int** graph = new int*[v];
    
    for(int i = 0; i < v; i++) {
        graph[i] = new int[v];
        for(int j = 0; j < v; j++) {
            graph[i][j] = 0;
        }
    }
    
    for(int i = 0; i < e; i++) {
        int s, f;
        cin >> s >> f;
        graph[s][f] = 1;
        graph[f][s] = 1;
    }
    
    bool* visited = new bool[v];
    for(int i = 0; i < v; i++) {
        visited[i] = false;
    }
    
    for(int i = 0; i < v; i++) {
        if(!visited[i]) {
            bfs(graph, v, visited, i);
        }
    }
    
}
