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

void reverse()
{
    Node *p, *q, *r;

    p = first;
    q = p->next;
    r = q->next;

    while (r->next != NULL)
    {
        // cout << p->data << " " << q->data << r->data << endl;
        q->next = p;
        p = q;
        q = r;
        r = r->next;
    }

    r->next = q;
    q->next = p;
    first->next = NULL;
    first = r;
    r = NULL;
    // cout << r << " " << r->data << " " << r->next->data << endl;
}

main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    create(arr, 10);
    display(first);
    reverse();
    cout << endl
         << "Reverse linked list: ";
    display(first);
}