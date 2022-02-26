#include <iostream>
using namespace std;

void printMazePaths(int sr, int sc, int dr, int dc, string psf)
{
    if (sr == dr && sc == dc)
    {
        cout << psf << endl;
        return;
    }

    for (int i = 1; i <= dc - sc; i++)
    {
        printMazePaths(sr, sc + i, dr, dc, psf + "h" + to_string(i));
    }
    for (int j = 1; j <= dr - sr; j++)
    {
        printMazePaths(sr + j, sc, dr, dc, psf + "v" + to_string(j));
    }
    for (int k = 1; k <= dc - sc && k <= dr - sr; k++)
    {
        printMazePaths(sr + k, sc + k, dr, dc, psf + "d" + to_string(k));
    }
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    printMazePaths(0, 0, n - 1, m - 1, "");
    return 0;
}