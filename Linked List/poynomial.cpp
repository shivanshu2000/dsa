#include <iostream>
using namespace std;

struct Poly
{
    int data;
    Poly *next;
    int expo;
};

void display(Poly **head)
{
    Poly *t = *head;
    while (t != NULL)
    {
        cout << t->data << "x" << t->expo << " + ";
        t = t->next;
    }
}

void createPoly(Poly **head, Poly *new_node)
{
    new_node->next = *head;
    *head = new_node;
}

void resultPoly(Poly **head, int coefficient1, int coefficient2, int expo)
{
    Poly *last;

    Poly *new_node = new Poly;
    new_node->data = coefficient1 + coefficient2;
    new_node->expo = expo;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        last = new_node;
        return;
    }
    else
    {
        last->next = new_node;
        last = new_node;
    }

    if (coefficient2 == 0 || coefficient1 == 0)
    {
        last->next = new_node;
        last = new_node;
    }
}

void addPoly(Poly **head1, Poly **head2)
{
    Poly *finalPoly = NULL;
    Poly *t1 = *head1;
    Poly *t2 = *head2;

    Poly *last = NULL;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->expo == t2->expo)
        {
            resultPoly(&finalPoly, t1->data, t2->data, t1->expo);
            t1 = t1->next;
            t2 = t2->next;
        }
        else if (t1->expo > t2->expo)
        {
            resultPoly(&finalPoly, t1->data, 0, t1->expo);
            t1 = t1->next;
        }
        else if (t2->expo > t1->expo)
        {
            resultPoly(&finalPoly, 0, t2->data, t2->expo);
            t2 = t2->next;
        }
    }

    cout << endl
         << " Sum of two poynomials is: ";
    display(&finalPoly);
}

main()
{

    Poly *first = NULL;

    int a = 0, b = 0;
    cout << "Enter the degree of first polynomial" << endl;
    cin >> a;
    for (int i{0}; i <= a; i++)
    {
        int coefficient;
        cout << "Enter the coefficient of x" << i << ": " << endl;
        cin >> coefficient;
        Poly *new_node = new Poly;
        new_node->data = coefficient;
        new_node->expo = i;
        new_node->next = NULL;

        createPoly(&first, new_node);
    }

    display(&first);

    Poly *second = NULL;
    cout << endl;
    cout << "Enter the degree of second polynomial" << endl;
    cin >> b;
    for (int i{0}; i <= b; i++)
    {
        int coefficient;
        cout << "Enter the coefficient of x" << i << ": " << endl;
        cin >> coefficient;
        Poly *new_node = new Poly;
        new_node->data = coefficient;
        new_node->expo = i;
        new_node->next = NULL;

        createPoly(&second, new_node);
    }

    display(&second);
    addPoly(&first, &second);
}