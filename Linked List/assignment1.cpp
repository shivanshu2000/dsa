#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node *next;
};

void create(Node **head, Node *new_node)
{
    new_node->next = *head;
    *head = new_node;
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

void reverse(Node **head)
{
    Node *t;
    t = *head;

    if (t->next == NULL)
    {
        return;
    }
    Node *p, *q;
    p = q = t->next;

    while (q->next != NULL)
    {
        q = q->next;
        p->next = t;
        t = p;
        p = q;
    }
    q->next = t;

    (*head)->next = NULL;
    *head = q;
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

void insert(Node **head, int position, string data)
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

void deleteNode(Node **head, string data)
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
             << "Name is not present in the list ";
    }
}

main()
{
    Node *first = NULL;

    string s1{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string s2{"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    cout << "Press a to create a list of sstudent or push to existing list of students" << endl;
    cout << "Press b to reverse the student list" << endl;
    cout << "Press c to sort the students list" << endl;
    cout << "Press d to insert a student name to the list" << endl;
    cout << "Press e to delete a student name" << endl;
    cout << "Press z to exit" << endl;
    char option;

    while (1)
    {
        cout << endl;

        cin >> option;

        switch (option)
        {
        case 'a':
        {
            cout << "Enter the number of student names you want to store: ";
            int n;

            cin >> n;
            if (!cin)
            {
                exit(1);
            }

            string name;
            cout << "Enter names one by one:" << endl;
            for (int i{0}; i < n; i++)
            {
                fflush(stdin);
                getline(cin, name);
                int position = s1.find(name.at(0));
                name.at(0) = s2.at(position);
                Node *new_node = new Node;
                new_node->data = name;
                new_node->next = NULL;
                create(&first, new_node);
            }
            cout << "List created is: ";
            display(&first);
        }
        break;

        case 'b':
        {
            cout << endl;
            reverse(&first);
            cout << "Reverse list is: ";
            display(&first);
        }
        break;

        case 'c':
        {

            cout << endl;
            sort(&first);
            cout << "Sorted list is: ";
            display(&first);
        }
        break;

        case 'd':
        {
            string nameToInsert;
            int position;
            cout << "You have to enter a name and position at which you want to insert that name." << endl;
            cout << "Enter position: ";
            cin >> position;

            cout << "Enter name: ";
            fflush(stdin);
            getline(cin, nameToInsert);

            insert(&first, position, nameToInsert);
            cout << endl
                 << "After inserting \'" << nameToInsert << "\' list is: ";
            display(&first);
        }
        break;

        case 'e':
        {
            string nameToDelete;
            cout << "Enter a name you want to delete: ";
            fflush(stdin);
            getline(cin, nameToDelete);
            deleteNode(&first, nameToDelete);
            cout << endl;
            cout << "List after deleting \'" << nameToDelete << "\' is: ";
            display(&first);
        }
        break;
        case 'z':
        {
            exit(0);
        }

        default:
        {
            cout << "\nInvalid choice";
            break;
        }
        }
    }
}