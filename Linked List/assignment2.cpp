#include <iostream>
using namespace std;

struct Poly
{
    int data;
    int expo;
    Poly *next;
};

void display(Poly *head)
{
    Poly *t = head;
    while (t != NULL)
    {
        cout << t->data << "x^" << t->expo << " + ";
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
    new_node->data = coefficient1 - coefficient2;
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

void subPoly(Poly **head1, Poly **head2)
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
         << "Subtraction of two poynomials is: ";
    display(finalPoly);
}

void mResultpoly(Poly **second, Poly **head, Poly *current)
{
    Poly *t1 = *second;

    while (t1 != NULL)
    {
        Poly *new_node = new Poly;
        new_node->data = (t1->data) * (current->data);
        new_node->expo = t1->expo + current->expo;
        createPoly(&*head, new_node);
        t1 = t1->next;
    }
}

void addDuplicates(Poly **start)
{

    Poly *t3 = *start;
    Poly *t4, *dup;

    while (t3 != NULL && t3->next != NULL)
    {

        t4 = t3;

        while (t4->next != NULL)
        {
            if (t3->expo == t4->next->expo)
            {

                t3->data = t3->data + t4->next->data;
                // dup = t4->next;
                t4->next = t4->next->next;
                // delete (dup);
            }
            else
            {

                t4 = t4->next;
            }
        }

        t3 = t3->next;
    }
    cout << "Multiplication result of two polynomials is: ";
    display(*start);
}

void multiply(Poly **head1, Poly **head2)
{
    Poly *second = NULL;

    Poly *t1, *t2;
    t1 = *head1;
    t2 = *head2;

    while (t1 != NULL)
    {
        mResultpoly(&t2, &second, t1);
        t1 = t1->next;
    }

    addDuplicates(&second);
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
    cout << "First polynomial: ";
    display(first);
    cout << endl;
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

    cout << "Second polynomial: ";
    display(second);
    cout << endl;
    // display(&second);

    cout << "Enter s to subtract above polynomials" << endl;
    cout << "Enter m to multiply above polynomials" << endl;
    cout << "Enter z to exit" << endl;
    char option;

    while (1)
    {
        cout << endl;
        cin >> option;
        switch (option)
        {
        case 's':
        {
            subPoly(&first, &second);
        }
        break;
        case 'm':
        {

            multiply(&first, &second);
        }
        break;
        case 'z':
            exit(0);
        default:
        {
            cout << "Invalid choice" << endl;
        }
        break;
        }
    }
}