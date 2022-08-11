#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// void waveSort(int arr[], int n)
// {
//     for (int i = 1; i < n; i += 2)
//     {
//         if (arr[i] > arr[i - 1])
//         {
//             swap(arr, i, i - 1);
//         }
//         if (arr[i] > arr[i + 1] && i <= n - 2)
//         {
//             swap(arr, i, i + 1);
//         }
//     }
// }

void dnfSort(int arr[], int n)
{
    int low = 0;
    int mid = 0;
    int high = n - 1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr, low, mid);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr, mid, high);
            high--;
        }
    }
}

void countSort(int arr[], int n)
{
    int k = arr[0];
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }

    int count[10] = {0};
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for (int i = 1; i <= k; i++)
    {
        count[i] += count[i - 1];
    }

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[] = {1, 3, 2, 3, 4, 1, 6, 4, 3};
    countSort(arr, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int arr2[] = {1, 0, 2, 1, 0, 1, 2, 1, 2};
    dnfSort(arr2, 9);
    for (int i = 0; i < 9; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // int arr3[] = {1, 3, 4, 7, 5, 6, 2};
    // waveSort(arr3, 7);
    // for (int i = 0; i < 7; i++)
    // {
    //     cout << arr3[i] << " ";
    // }
    // cout << endl;

    return 0;
}