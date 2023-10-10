#include<bits/stdc++.h>
#include"stack.cpp"
using namespace std;
int main()
{
    Stack<int> a;
    int n, x, type;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            a.push(x);
        }
        else if (type == 2)
        {
            if (a.size() != 0)
            {
                a.pop();
            }
        }
        else
        {
            if (a.size() != 0)
                cout << a.top() << endl;
            else
                cout << "Empty!" << endl;
        }}
}
