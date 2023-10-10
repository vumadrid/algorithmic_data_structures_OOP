#include <bits/stdc++.h>
using namespace std;

// khai bao node
struct Node
{
    int data;
    struct Node *link;
};
struct Node *top; // khai bao node root
void push(int data)
{
    struct Node *temp;
    temp = new Node();
    // kiem tra ngan xep full
    // them phan tu neu co the
    if (!temp)
    {
        return;
    }
    temp->data = data;
    temp->link = top;
    top = temp;
}
// kiem tra ngan xep rong
int isEmpty()
{
    return top == NULL;
}

// tra ve phan tu dau cua stack
int peek()
{
    if (!isEmpty())
        return top->data;
    else
        return INT_MIN;
}

// Utility function to pop top
// element from the stack
void pop()
{
    struct Node *temp;

    // Check for stack underflow
    if (top == NULL)
    {
        return;
    }
    else
    {
        temp = top;
        top = top->link;
        temp->link = NULL;
        free(temp);
    }
}
int main()
{
    int n, x, type;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> x;
            push(x);
        }
        else if (type == 2)
        {
            if (!isEmpty())
            {
                pop();
            }
        }
        else
        {
            if (!isEmpty())
                cout << peek() << endl;
            else
                cout << "Empty!" << endl;
        }
    }
}

