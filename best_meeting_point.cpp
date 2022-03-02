#include <bits/stdc++.h>
using namespace std;

int median(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 0)
    {
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    }
    else
    {
        return arr[n / 2];
    }
}

int bestMeetPoint(int m, int n, vector<vector<int>> house)
{
    vector<int> x;
    vector<int> y;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (house[i][j] == 1)
            {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }
    int x_med = median(x);
    int y_med = median(y);

    int distance;
    for (int i = 0; i < x.size(); i++)
    {
        distance += abs(x[i] - x_med) + abs(y[i] - y_med);
    }

    return distance;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> house(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> house[i][j];
        }
    }
    cout << bestMeetPoint(m, n, house);

    return 0;
}