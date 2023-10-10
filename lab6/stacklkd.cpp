#ifndef __stack__cpp__
#define __stack__cpp__

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
#endif
