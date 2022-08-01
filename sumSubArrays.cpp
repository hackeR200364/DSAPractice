#include <iostream>
using namespace std;

void sum(int arr[], int n)
{
    int sumSubArr = 0;
    for (int i = 0; i < n; i++)
    {
        sumSubArr = 0;
        for (int j = i; j < n; j++)
        {
            sumSubArr += arr[j];
            cout << sumSubArr << endl;
        }
    }
}

int main()
{
    int n;
    cout << "Please enter the size of array = " << endl;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sum(arr, n);

    return 0;
}