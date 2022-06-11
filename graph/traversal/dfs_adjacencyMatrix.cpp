#include <iostream>
using namespace std;

void dfs(int **edges, int n, int sv, bool *visited)
{
    cout << sv << endl;
    visited[sv] = true;

    for (int i = 0; i < n; i++)
    {
        if (i != sv && edges[sv][i] == 1 && !visited[i])
        {
            dfs(edges, n, i, visited);
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    dfs(edges, n, 0, visited);

    return 0;
}
