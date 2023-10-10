#include <bits/stdc++.h>
#include"stack.cpp"
using namespace std;
int main()
{
    Stack<int> s;
    string cur;
    cin >> cur;
    for (int i = 0; i < cur.size(); i++)
    {
        if (cur[i] == '(')
        {	
            s.push(i + 1);
        }
        else
        {
            int tmp = s.top();
            s.pop();
            cout << tmp << " " << i + 1 << endl;
        }
    }
}

