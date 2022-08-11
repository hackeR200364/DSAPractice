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

int main()
{
    int n;
    int max1 = 0;
    int mx = -199999999;
    cout << "Please enter the size of array = ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        max1 = max1 + arr[i];
        mx = max(mx, arr[i]);
        cout << mx << endl;
    }

    showArray(arr, n);
    cout << "Sum of the array = " << max1 << endl;

    return 0;
}