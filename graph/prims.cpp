#include <iostream>
#include <climits>
using namespace std;

int findMinVer(int* weights, bool* visited, int n) {
    int minver = -1;
    for(int i = 0; i < n; i++) {
        if(!visited[i] && (minver == -1 || weights[i] < weights[minver])) {
            minver = i;
        }
    }
    return minver;
}

void prims(int** edges, int n) {
    int* parent = new int[n];
    int* weights = new int[n];
    bool* visited = new bool[n];
    
    for(int i = 0; i < n; i++) {
        visited[i] = false;
        weights[i] = INT_MAX;
    }
    
    parent[0] = -1;
    weights[0] = 0;
    
    for(int i = 0; i < n - 1; i++) {
        int minver = findMinVer(weights, visited, n);
        visited[minver] = true;
        for(int j = 0; j < n; j++) {
            if(!visited[j] && edges[minver][j] != 0) {
                if(edges[minver][j] < weights[j]) {
                    weights[j] = edges[minver][j];
                    parent[j] = minver;
                }
            }
        }
    }
    
    for(int i = 1; i < n; i++) {
        if(parent[i] < i) {
            cout << parent[i] << " " << i << " " << weights[i] << endl;
        }
        else {
            cout << i << " " << parent[i] << " " << weights[i] << endl;
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
        int s, f, w;
        cin >> s >> f >> w;
        edges[s][f] = w;
        edges[f][s] = w;
    }
    
    prims(edges, n);
    
    for(int i = 0; i < n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
}
