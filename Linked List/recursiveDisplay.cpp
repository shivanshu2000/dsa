#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int arr[], size_t size)
{
    struct Node *t, *last;

    first = new Node;
    first->data = arr[0];
    last = first;
    first->next = NULL;

    for (int i{1}; i < size; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;

        last->next = t;
        last = t;
    }
}

void count(struct Node *p)
{
    int count = 0;

    while (p != 0)
    {
        count++;
        p = p->next;
    }

    cout << count << endl;
}

void display(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << " ";
        display(p->next);
    }
}

main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
    cout << endl;
    count(first);
}