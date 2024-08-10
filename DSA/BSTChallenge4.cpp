#include <iostream>
using namespace std;

int searchInRotatesArr(int arr[], int key, int left, int right)
{
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }

    if (arr[left] < arr[right])
    {
        if (key >= arr[left] && key <= arr[mid])
        {
            return searchInRotatesArr(arr, key, left, mid - 1);
        }
        return searchInRotatesArr(arr, key, mid + 1, right);
    }

    if (key >= arr[mid] && key <= arr[right])
    {
        return searchInRotatesArr(arr, key, mid + 1, right);
    }
    return searchInRotatesArr(arr, key, left, mid - 1);
}

int main()
{
    int arr[] = {6, 7, 8, 9, 10, 1, 2, 5};
    int n = 8;
    int key = 11;

    int i = searchInRotatesArr(arr, key, 0, n - 1);

    if (i == -1)
    {
        cout << "Key doesn't exist" << endl;
    }
    else
    {
        cout << "Key exists " << i << endl;
    }
    return 0;
}