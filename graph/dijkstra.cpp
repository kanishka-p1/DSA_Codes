#include <iostream>
#include <climits>
using namespace std;

int findminver(int* distance, bool* visited, int n) {
    int minver = -1;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && (minver == -1 || distance[i] < distance[minver])) {
            minver = i;
        }
    }
    return minver;
}

void dijkstra(int** edges, int n) {
    bool* visited = new bool[n];
    int* distance = new int[n];
    
    for(int i = 0; i < n; i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    
    distance[0] = 0;
    
    for(int i = 0; i < n - 1; i++) {
        int minver = findminver(distance, visited, n);
        visited[minver] = true;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && edges[minver][j] != 0) {
                int dis = distance[minver] + edges[minver][j];
                if(dis < distance[j]) {
                    distance[j] = dis;
                }
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << i << " " << distance[i] << endl;
    }
    
    delete [] visited;
    delete [] distance;
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
        int s, f, w;
        cin >> s >> f >> w;
        edges[s][f] = w;
        edges[f][s] = w;
    }
    
    dijkstra(edges, n);
    
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
}
