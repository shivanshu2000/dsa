#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *first = NULL;

void create(int arr[], size_t size)
{

    Node *t, *last;
    first = new Node;
    first->data = arr[0];
    first->next = NULL;
    last = first;

    for (size_t i{1}; i < size; i++)
    {
        t = new Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{

    struct Node *t;
    t = p;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

int count()
{
    Node *t;
    t = first;
    int count = 0;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}

void deleteNode(int number)
{

    Node *t;
    t = first;

    if (first->data == number)
    {
        Node *t;
        t = first;
        first = first->next;
        t->next = NULL;
        // first->next = NULL;
    }

    else
    {
        while (t->next->data != number)
        {
            if (t != NULL)
            {
                t = t->next;
            }
        }

        if (t->next->data == number)
        {
            Node *successive = t->next->next;
            t->next->next = NULL;
            t->next = successive;
        }
        else
        {
            cout << "Number not found. Select from: ";
            display(first);
            cout << endl;
        }
    }
}

void insertNode(int position, int value)
{

    Node *t;
    t = first;
    Node *newNode;
    newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (first == NULL && position > 1)
    {
        cout << "List is empty. Please insert some elements first" << endl;
    }

    else if (position > count() + 1 || position < 1)
    {
        cout << "Invalid position. List has only " << count() << " elements." << endl;
    }
    else if (position == 1)
    {

        Node *temp;
        temp = newNode;
        newNode->next = first;
        first = temp;
        cout << first->data;
    }
    // else if (position == count() + 1)
    // {
    //     for (int i{1}; i < position; i++)
    //     {
    //         t->next = t->next == NULL ? newNode : t->next;
    //         t = t->next;
    //     }
    // }
    else
    {
        Node *successiveNode;
        for (int i{1}; i < position - 1; i++)
        {

            t = t->next;
            successiveNode = t->next;
        }
        t->next = newNode;
        newNode->next = successiveNode;
    }
}

main()
{
    int arr[]{1, 2, 3, 4, 5, 6};

    // create(arr, 6);
    // cout << first << endl;
    // display(first);
    cout << endl;

    insertNode(1, 25);
    insertNode(2, 26);
    insertNode(3, 10);
    cout << endl;
    display(first);
    cout << endl;
    deleteNode(6);
    display(first);
}