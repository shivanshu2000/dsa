#include <iostream>
#include <conio.h>

using namespace std;

struct Stack
{
    int data;
    Stack *next;
} *top = NULL;

struct Queue
{
    int data;
    Queue *next;
} * front, *rear = NULL;

void enqueue(int data)
{
    Queue *t = new Queue;
    t->data = data;
    t->next = NULL;

    if (front == NULL)
    {
        front = rear = t;
    }
    else
    {
        rear->next = t;
        rear = t;
    }
}

int dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty";
        return -1;
    }
    int x;
    Queue *t;
    t = front;
    x = t->data;
    front = front->next;
    free(t);
    return x;
}

void displayQueue()
{
    Queue *t = front;

    if (t == NULL)
    {
        cout << "Queue is empty";
        return;
    }
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

void push(int data)
{
    Stack *new_node = new Stack;
    new_node->data = data;
    new_node->next = top;

    top = new_node;
}

int pop()
{
    if (top == NULL)
    {
        cout << "Underflow";
        return -1;
    }
    top = top->next;
    return top->data;
}

void display()
{
    Stack *t = top;

    if (top == NULL)
    {
        cout << "Stack is empty";
        return;
    }

    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

int peep(int position)
{

    if (position < 1)
    {
        cout << "Position must start from 1";
        return -1;
    }
    int i = 1;
    Stack *t = new Stack;
    t = top;
    while (t != NULL && i < position)
    {
        i++;
        t = t->next;
    }

    if (t == NULL)
    {
        cout << "There is no element at " << position << " position!"
             << "Stack has " << i - 1 << " elements" << endl;
        return -1;
    }

    return t->data;
}

main()
{
    push(5);
    push(57);
    push(56);
    display();
    push(4);
    cout << endl;
    display();
    cout << endl;
    cout << "Element popped out is " << pop();
    cout << endl
         << "List after pop is: " << endl;
    display();

    int position = 0;
    cout << endl
         << "Enter the position to get an element" << endl;
    cin >> position;
    cout << "Element at position " << position << " is: " << peep(position) << endl;

    enqueue(34);
    enqueue(46);
    enqueue(64);
    enqueue(44);
    enqueue(41);
    cout << "Queue is: " << endl;
    displayQueue();
    cout << endl
         << "Queue after dequeue is: " << endl;

    dequeue();
    displayQueue();
    getch();
}
