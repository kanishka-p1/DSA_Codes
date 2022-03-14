#include <bits/stdc++.h>
using namespace std;

vector<string> crossword(10);
vector<string> words;
bool flag;

void puzzle(int ind)
{
    if (!flag)
    {
        return;
    }
    if (ind == words.size())
    {
        if (flag)
        {
            for (auto word : crossword)
            {
                cout << word << endl;
            }
            flag = false;
        }
        return;
    }
    int i, j, p, q, k;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            p = i, q = j;
            for (k = 0; k < words[ind].size() && p + k < 10; k++)
            {
                if (crossword[p + k][q] != '-' && crossword[p + k][q] != words[ind][k])
                {
                    break;
                }
            }
            if (k == words[ind].size())
            {
                vector<string> temp = crossword;
                for (k = 0; k < words[ind].size(); k++)
                {
                    crossword[p + k][q] = words[ind][k];
                }
                puzzle(ind + 1);
                crossword = temp;
            }
            for (k = 0; k < words[ind].size() && q + k < 10; k++)
            {
                if (crossword[p][q + k] != '-' && crossword[p][q + k] != words[ind][k])
                {
                    break;
                }
            }
            if (k == words[ind].size())
            {
                vector<string> temp = crossword;
                for (k = 0; k < words[ind].size(); k++)
                {
                    crossword[p][q + k] = words[ind][k];
                }
                puzzle(ind + 1);
                crossword = temp;
            }
        }
    }
}

int main()
{
    flag = true;
    int i, j;
    for (i = 0; i < 10; i++)
    {
        cin >> crossword[i];
    }
    string s, w;
    cin >> w;
    for (auto it : w)
    {
        if (it == ';')
        {
            words.push_back(s);
            s = "";
        }
        else
        {
            s += it;
        }
    }
    words.push_back(s);
    puzzle(0);

    return 0;
}