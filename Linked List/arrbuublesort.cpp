#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int n)
{
    int i, j;
    int flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                flag = 1;
            }
        }

        if (flag == 0)
            break;
    }
}

void displayArray(int *arr, size_t size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << *(arr + i) << " ";
}

main()
{
    int size;
    cout << "Enter size of an array: " << endl;
    cin >> size;
    int *arr = new int[size];
    cout << "Enter elements of an array" << endl;

    for (int i{0}; i < size; i++)
    {
        int a;
        cin >> a;
        arr[i] = a;
    }

    sort(arr, size);
    cout << "Sorted array:"
         << "\n";
    displayArray(arr, size);
}