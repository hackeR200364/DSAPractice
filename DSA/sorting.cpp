#include <iostream>
using namespace std;

void showArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    showArray(arr, n);
}

void bubbleSort(int arr[], int n)
{
    int counter = 1;
    while (counter < n)
    {
        for (int i = 0; i < n - counter; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        counter++;
    }
    showArray(arr, n);
}

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int current = arr[i];
        int j = i - 1;
        while (arr[j] > current && j >= 0)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = current;
    }
    showArray(arr, n);
}

int main()
{
    int n;
    char res;
    cout << "For Selection Sort enter 'S'\nFor Bubble Sort enter 'B'\nFor Insertion Sort enter 'I'\n"
         << endl;
    cin >> res;
    cout << "Please enter the size of array = ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    switch (res)
    {
    case 'S':
        selectionSort(arr, n);
        break;

    case 'B':
        bubbleSort(arr, n);
        break;

    case 'I':
        insertionSort(arr, n);
        break;

    default:
        cout << "Please choose correct option" << endl;
        break;
    }

    return 0;
}