#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node **head, Node *new_node)
{

    new_node->next = (*head);

    (*head) = new_node;
}

void display(Node **head)
{
    Node *t = *head;

    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

void insert(Node **head, int position, int data)
{
    int i = 1;
    Node *t = (*head);
    Node *new_node = new Node;
    new_node->data = data;
    new_node->next = NULL;

    while (i < position - 1 && t->next != NULL)
    {
        i++;
        t = t->next;
    }

    if (position == 1)
    {
        new_node->next = *head;
        (*head) = new_node;
        return;
    }

    new_node->next = t->next;
    t->next = new_node;
}

void deleteNode(Node **head, int data)
{
    Node *t = (*head);
    Node *p = t;

    if (t->data == data)
    {
        *head = (*head)->next;
        return;
    }

    while (t->next != NULL)
    {
        if (t->next->data == data)
        {
            p = t->next;
            t->next = p->next;
            p->next = NULL;
            break;
        }
        t = t->next;
    }

    if (t->next == NULL)
    {
        cout << "\n"
             << "Number is not present in the list ";
    }
}

void reverse(Node **head)
{

    Node *p = *head, *q, *r;

    if ((*head)->next == NULL)
    {
        *head = p;
        return;
    }
    q = p->next;
    r = q->next;

    if (q->next == NULL)
    {
        q->next = p;
        p->next = NULL;
        *head = q;
        return;
    }

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
    (*head)->next = NULL;
    *head = r;
    r = NULL;
}

void sortedInsert(Node **head_ref, Node *new_node)
{
    Node *current;

    if (*head_ref == NULL || (*head_ref)->data >= new_node->data)
    {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else
    {

        current = *head_ref;
        while (current->next != NULL &&
               current->next->data < new_node->data)
        {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

void sort(Node **head_ref)
{

    Node *sorted = NULL;

    Node *current = *head_ref;
    while (current != NULL)
    {
        Node *next = current->next;

        sortedInsert(&sorted, current);

        current = next;
    }

    *head_ref = sorted;
}

main()
{
    Node *first = NULL;
    cout << "Enter a to create a linked list or add elements to an existing list" << endl;
    cout << "Enter b to insert an elemrnt to a linked list" << endl;
    cout << "Enter c to delete an element from a linked list" << endl;
    cout << "Enter d to reverse a linked list" << endl;
    cout << "Enter e to sort a linked list" << endl;
    cout << "Enter f to concatenate a linked list" << endl;
    cout << "Enter z to exit" << endl;

    while (1)
    {

        char command;
        cout << endl;
        cin >> command;
        switch (command)
        {
        case 'a':
        {

            int el;
            cout << "Enter number of elements you want to insert: " << endl;
            cin >> el;
            cout << "Enter elements one by one to insert: " << endl;
            int data;
            for (int i{0}; i < el; i++)
            {
                cin >> data;
                Node *node = new Node;
                node->data = data;
                node->next = NULL;

                push(&first, node);
            }
            cout << "Linked list created is: ";
            display(&first);
        }
        break;
        case 'b':
        {
            cout << endl;
            int elToInsert = 0, position = 0;
            cout << "To insert an element enter: " << endl;
            cout << "Position: ";
            cin >> position;
            cout << "Element to put at " << position << ": ";
            cin >> elToInsert;

            insert(&first, position, elToInsert);
            cout << endl
                 << "After insert: ";
            display(&first);
        }
        break;

        case 'c':
        {
            cout << endl;
            cout << "Enter a number to delete from the list: ";
            int elToDelete;
            cin >> elToDelete;

            deleteNode(&first, elToDelete);
            display(&first);
        }
        break;
        case 'd':
        {
            cout << endl;
            // cout << first->data << endl;
            reverse(&first);
            cout << "Reversed list is: ";
            display(&first);
        }
        break;

        case 'e':
        {
            cout << "\n"
                 << "Sorted list is: ";
            sort(&first);
            display(&first);
            cout << endl;
        }
        break;
        case 'f':
        {
            Node *second = NULL;
            cout << "Enter number of elements of second list to concatenate with existing list: " << endl;
            int el1;
            cin >> el1;
            cout << "Enter elements one by one: " << endl;
            for (int i{0}; i < el1; i++)
            {
                int data;
                cin >> data;
                Node *new_node = new Node;
                new_node->data = data;
                new_node->next = NULL;
                push(&second, new_node);
            }

            Node *t = second;

            while (t->next != NULL)
            {
                t = t->next;
            }

            t->next = first;

            cout << "Concatenated list is: ";
            first = second;
            display(&first);
        }
        break;
        case 'z':
        {
            exit(0);
        }
        default:
        {
            cout << "Invalid command choose from a,b,c,d,e,f and z" << endl;
            break;
        }
        }
    }
}
// Node *t, *p, *q;
// t = (*head);
// p = q = t->next;

// while (q->next != NULL)
// {
//     q = q->next;
//     p->next = t;
//     p = q;
//     // cout << t->data << " " << p->data << " " << q->data << endl;
//     t = t->next;
// }
// p->next = t;
// cout << q->next->data << " ";
// (*head)->next = NULL;
// *head = q;