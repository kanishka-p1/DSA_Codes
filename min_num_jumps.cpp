#include <iostream>
using namespace std;

int minjumps(int n)
{
    int count = 1;
    int sum = 0;
    while (sum < n)
    {
        sum += count;
        count++;
    }

    if ((sum - n) % 2 == 0)
    {
        return count - 1;
    }
    else if ((sum + count - n) % 2 == 0)
    {
        return count;
    }
    else
    {
        return count + 1;
    }
}

int main()
{
    int n;
    cin >> n;
    cout << minjumps(n);
    return 0;
}