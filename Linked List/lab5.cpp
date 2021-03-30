#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void display(Node *t)
{
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}

int count(Node *head)
{
    Node *t = head;
    int count = 0;
    while (t != NULL)
    {
        count++;
    }

    return count;
}

void insert(Node **head, int positionToInsert, int elToInsert, int position = 0)
{

    Node *t = *head;
    Node *new_node = new Node;
    new_node->data = elToInsert;
    new_node->next = NULL;

    if (positionToInsert == 1)
    {
        new_node->next = *head;
        *head = new_node;

        return;
    }

    if (positionToInsert == 2)
    {
        if (*head == NULL || position == 1)
        {
            new_node->next = *head;
            *head = new_node;
        }
        else
        {
            int i = 1;
            while (i < position - 1 && t->next != NULL)
            {

                i++;
                t = t->next;
            }

            new_node->next = t->next;
            t->next = new_node;
        }

        return;
    }

    if (positionToInsert == 3)
    {
        if (*head == NULL)
        {
            *head = new_node;
            new_node->next = NULL;
        }
        else
        {

            while (t->next != NULL)
            {
                t = t->next;
            }

            t->next = new_node;
            new_node->next = NULL;
        }

        return;
    }
}

void deleteNode(Node **head, string positionToDelete, int position = 0)
{

    Node *t = *head;

    if (*head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (position == 1)
    {
        *head = t->next;
        return;
    }

    if (positionToDelete == "start")
    {
        *head = t->next;
        return;
    }

    if (positionToDelete == "between")
    {
        int i = 1;
        while (i < position - 1 && t->next != NULL)
        {
            i++;
            t = t->next;
        }

        if (t->next == NULL)
        {
            cout << "Invalid position " << endl;
            return;
        }
        else if (t->next->next == NULL)
        {
            t->next = NULL;
            return;
        }
        else
        {
            t->next = t->next->next;
            return;
        }
    }
    if (positionToDelete == "end")
    {
        while (t->next->next != NULL)
        {
            t = t->next;
        }

        t->next = NULL;
        return;
    }
}

main()
{
    Node *first = NULL;

    cout << "Enter a to insert the node at beginning" << endl;
    cout << "Enter b to insert the node by position" << endl;
    cout << "Enter c to insert the node at end" << endl;
    cout << "Enter d to delete the first node" << endl;
    cout << "Enter e to delete the node by position" << endl;
    cout << "Enter f to delete the last node" << endl;
    cout << "Enter g to display the linked list" << endl;
    cout << "Enter z to exit" << endl;

    char option;

    while (1)
    {

        cin >> option;
        switch (option)
        {
        case 'a':
        {
            int elToInsert;
            cout << "Enter an element you want to insert at the start of the list: ";
            cin >> elToInsert;
            insert(&first, 1, elToInsert);
        }
        break;
        case 'b':
        {
            int elToInsert, position;
            cout << "Enter position in the list you want to insert an element: ";
            cin >> position;
            cout << "\nEnter element you want to insert at " << position << " position: ";
            cin >> elToInsert;
            insert(&first, 2, elToInsert, position);
        }

        break;

        case 'c':
        {
            int elToInsert;
            cout << "Enter an element you want to insert at the end of the list: ";
            cin >> elToInsert;

            insert(&first, 3, elToInsert);
        }
        break;

        case 'd':
        {
            deleteNode(&first, "start");
        }
        break;

        case 'e':
        {
            int position;
            cout << "Enter the position of node you want to delete: ";
            cin >> position;
            deleteNode(&first, "between", position);
        }
        break;

        case 'f':
        {
            deleteNode(&first, "end");
        }

        break;

        case 'g':
        {
            cout << "Linked list is: ";
            display(first);
            cout << endl;
            break;
        }
        case 'z':
        {
            exit(0);
        }

        default:
        {
            cout << "Invalid choice " << endl;
        }
        break;
        }
    }
}
