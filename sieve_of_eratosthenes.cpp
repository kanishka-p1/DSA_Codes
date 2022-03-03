#include <bits/stdc++.h>
using namespace std;

void printPrimeUsingSieve(int n)
{
    vector<bool> isprime(n + 1, true);

    for (int i = 2; i * i < isprime.size(); i++)
    {
        if (isprime[i] == true)
        {
            for (int j = i + i; j < isprime.size(); j += i)
            {
                isprime[j] = false;
            }
        }
    }

    for (int i = 2; i < isprime.size(); i++)
    {
        if (isprime[i] == true)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n;
    cin >> n;
    printPrimeUsingSieve(n);

    return 0;
}