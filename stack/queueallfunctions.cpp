#include <iostream>
#include <conio.h>
using namespace std;

struct Queue
{
    int size;
    int rear;
    int front;
    int *p;
};

void enqueue(Queue *q, int n)
{
    if (q->rear == q->size - 1)
    {
        cout << "Queue is full " << endl;
        return;
    }

    q->rear++;
    q->p[q->rear] = n;
}

int dequeue(Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        cout << "Queue is already empty " << endl;
        return x;
    }

    q->front++;
    x = q->p[q->front];
    return x;
}

void display(Queue q)
{
    for (int i{q.front + 1}; i <= q.rear; i++)
    {
        cout << q.p[i] << " ";
    }
}

main()
{
    Queue q;
    int size;
    cout << "Enter the size of queue: ";
    cin >> q.size;

    q.p = new int[q.size];
    q.front = q.rear = -1;

    enqueue(&q, 4);
    enqueue(&q, 5);
    enqueue(&q, 8);
    cout << "Before dequeue: ";
    // cout << endl;
    display(q);
    cout << endl;
    cout << "Element deleted is: " << dequeue(&q) << endl;
    cout << "After dequeue: ";
    display(q);

    // cout << q.p[q.rear];
    getch();
}