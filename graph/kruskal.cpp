#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class edge {
    public :
    int s, d, w;
};

bool compare(edge e1, edge e2) {
    return e1.w < e2.w;
}

int findParent(int v, int* parent) {
    if(parent[v] == v) {
        return v;
    }
    return findParent(parent[v], parent);
}

void kruskal(edge *input, int n, int e) {
    sort(input, input + e, compare);
    
    edge *output = new edge[n - 1];
    int *parent = new int[n];
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    int count = 0;
    int i = 0;
    
    while(count != n - 1) {
        edge curedge = input[i];
        int spar = findParent(curedge.s, parent);
        int dpar = findParent(curedge.d, parent);
        
        if(spar != dpar) {
            output[count] = curedge;
            count++;
            parent[spar] = dpar;
        }
        i++;
    }
    
    for(int i = 0; i < n - 1; i++) {
        if(output[i].s < output[i].d) {
            cout << output[i].s << " " << output[i].d << " " 
                << output[i].w << endl;    
        }
        else {
            cout << output[i].d << " " << output[i].s << " " 
                << output[i].w << endl;
        }
    }
}

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;
    edge *input = new edge[e];
    
    for(int i = 0; i < e; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].s = s;
        input[i].d = d;
        input[i].w = w;
    }
    
    kruskal(input, n, e);
}
