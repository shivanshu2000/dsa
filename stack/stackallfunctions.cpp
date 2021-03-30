#include <iostream>
#include <conio.h>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *p;
};

void push(Stack *st, int value)
{
    if (st->top == st->size - 1)
    {
        cout << "Overflow" << endl;
    }
    else
    {

        st->top++;
        st->p[st->top] = value;
    }
}

int pop(Stack *st)
{

    int x = -1;

    if (st->top == -1)
    {
        cout << "Underflow" << endl;
        return x;
    }

    x = st->p[st->top];
    st->top--;
    return x;
}

int peek(Stack st, int position)
{
    if (st.top - position + 1 < 0)
    {
        cout << "Invalid position: ";
        return -1;
    }
    return st.p[st.top - position + 1];
}

int stackTop(Stack st)
{
    if (st.top == -1)
    {
        return -1;
    }

    return st.p[st.top];
}

int isEmpty(Stack st)
{
    if (st.top == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack st)
{
    if (st.top == st.size - 1)
    {
        return 1;
    }

    return 0;
}

void display(Stack st)
{
    for (int i{st.top}; i >= 0; i--)
    {
        cout << st.p[i] << " ";
    }
}

main()
{

    Stack st;
    cout << "Enter the size of stack" << endl;
    cin >> st.size;

    st.p = new int[st.size];

    st.top = -1;
    push(&st, 2);
    push(&st, 3);
    push(&st, 4);
    push(&st, 5);
    cout << "Stack elements are: ";
    display(st);
    cout << endl;
    pop(&st);
    cout << "After popping: ";
    display(st);
    cout << endl;
    cout << (isEmpty(st) == 0 ? "Stack is not empty" : "Stack is empty") << endl;
    cout << "Element found at position 2 is: " << peek(st, 2) << endl;

    cout << "Stack elements are: ";
    display(st);
    getch();
}