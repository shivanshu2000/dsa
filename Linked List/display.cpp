#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int arr[], int size)
{

    struct Node *t, *last;

    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i{1}; i < size; i++)
    {
        t = new struct Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{

    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

main()
{
    int arr[] = {1, 2, 3, 4, 5};
    create(arr, 5);
    display(first);
}