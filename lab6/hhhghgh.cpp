#include <bits/stdc++.h>
using namespace std;
int main()
{
    stack<pair<int, char>> s;
    string cur;
    cin >> cur;
    for (int i = 0; i < cur.size(); i++)
    {
        if (cur[i] == '(')
        {
            s.push({i + 1, cur[i]});
        }
        else
        {
            pair<int, char> tmp = s.top();
            s.pop();
            cout << tmp.first << " " << i + 1 << endl;
        }
    }
}

