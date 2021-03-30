#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int arr[], int size)
{

    Node *t, *last;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (int i{1}; i < size; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *first)
{
    struct Node *t;
    t = first;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

int count(struct Node *first)
{
    struct Node *t;
    t = first;
    int n = 0;
    while (t != NULL)
    {
        n++;
        t = t->next;
    }

    return n;
}

float sum(struct Node *first)
{
    struct Node *t;
    t = first;
    float sum = 0;
    while (t != NULL)
    {
        sum += t->data;
        t = t->next;
    }

    return sum;
}

int max(struct Node *first)
{
    struct Node *t;
    t = first;
    int max = t->data;
    // cout << max << endl;

    while (t != NULL)
    {

        max = t->data > max ? t->data : max;
        // cout << max << " " << t->data << endl;
        t = t->next;
    }

    return max;
}

int middleElement(struct Node *first, int count)
{
    struct Node *t;
    t = first;
    int i = 0;
    int middleElement = 0;
    while (i % 2 == 0 ? i < count / 2 : i < count / 2 + 1)
    {
        middleElement = t->data;
        t = t->next;
        i++;
    }
    cout << middleElement << endl;
    return middleElement;
}

main()
{
    int arr[]{1, 2, 3, 8, 5, 6, 9};
    create(arr, 7);
    display(first);
    cout << endl;
    cout << count(first);
    cout << endl;
    cout << "Sum of all elements in linked list is: " << sum(first);

    cout << "\n"
         << "Maximum of the linked list is: " << max(first) << endl;

    cout << "Middle element of the list is: " << middleElement(first, count(first));
}