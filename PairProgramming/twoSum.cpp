#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void twoSum(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                cout << "i = " << i << "j = " << j << endl;
            }
        }
    }
}

vector<int> twoSumOpt(int arr[], int n, int k)
{
    
}

int main()
{
    auto start = high_resolution_clock::now();

    int s, k;
    cout << "Size = ";
    cin >> s;
    cout << "Key = ";
    cin >> k;

    int arr[s];
    for (int i = 0; i < s; i++)
    {
        cin >> arr[i];
    }

    display(arr, s);

    twoSumOpt(arr, s, k);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;
}