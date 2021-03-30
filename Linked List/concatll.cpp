#include <iostream>
#include <iomanip>
using namespace std;

struct node
{
    int DATA;
    node *NEXT;
};

node *HEAD = NULL;
void Create(int data);
void Display();
void Sort();

int main()
{
    int num, numOfEl;
    cout << "Enter number of elements: ";
    cin >> numOfEl;
    cout << "Enter " << numOfEl << " numbers: ";
    for (int i = 0; i < numOfEl; i++)
    {
        cin >> num;
        Create(num);
    }
    cout << "\nDisplay before sorting.\n";
    Display();
    Sort();
    cout << "\nDisplay after sorting.\n";
    Display();
}

void Sort()
{
    node *h = HEAD, *i, *j;
    for (i = h; i != NULL && i->NEXT != NULL; i = i->NEXT)
    {
        node *min;
        min = i;
        for (j = i->NEXT; j != NULL; j = j->NEXT)
        {
            if (j->DATA < min->DATA)
                min = j;
        }
        if (min != i)
        {
            int temp;
            temp = min->DATA;
            min->DATA = i->DATA;
            i->DATA = temp;
        }
    }
    // HEAD = h;
}

void Display()
{
    node *current;
    current = HEAD;
    cout << setw(20) << "LAST" << setw(20) << "NUMBER" << setw(20) << "NEXT" << endl;
    while (current != NULL)
    {
        cout << setw(20) << current << setw(20) << current->DATA << setw(20) << current->NEXT << endl;
        current = current->NEXT;
    }
    system("pause>0");
}

void Create(int data)
{
    node *front, *tail;
    tail = new node;
    tail->DATA = data;
    tail->NEXT = NULL;
    if (HEAD == NULL)
        HEAD = tail;
    else
    {
        front = HEAD;
        while (front->NEXT != NULL)
            front = front->NEXT;
        front->NEXT = tail;
    }
}