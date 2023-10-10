#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000

template <class T>
class Stack
{
    int n, cap; // n la so phan tu hien chua,cap suc chua cua mang
    T *buff;    // con tro luu du dulieu cua stack
public:
    Stack()
    {
        n = cap = 0;
        buff = 0;
    }
    ~Stack()
    {
        if (buff)
            delete[] buff;
    }
    void push(T x)
    {
        if (n == cap)
        {
            cap = cap * 2 + 1;
            T *tem = new T[cap];
            for (int i = 0; i < n; i++)
                tem[i] = buff[i];
            if (buff)
                delete[] buff;
            buff = tem;
        }
        buff[n++] = x;
    }
    int size()
    {
        return n;
    }
    void pop()
    {
        n--;
    }
    bool empty()
    {
        return n == 0;
    }
    T &top()
    {
        return buff[n - 1];
    }
};
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
