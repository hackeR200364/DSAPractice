#include <iostream>
#include <climits>

using namespace std;

bool isPossible(int arr[], int n, int m, int min)
{
    int stdsReq = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > min)
        {
            return false;
        }
        if (sum + arr[i] > min)
        {
            stdsReq++;
            sum = arr[i];
            if (stdsReq > m)
            {
                return false;
            }
        }
        else
        {
            sum += arr[i];
        }
    }
}

int allocateMinimum(int arr[], int n, int m)
{
    int sum = 0;
    if (n < m)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i];
    }

    int start = 0, end = sum, ans = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}

int main()
{
    int arr[] = {12, 34, 67, 90};
    int n = 4, m = 2;

    cout << "The minimum no of pages : " << allocateMinimum(arr, n, m) << endl;
    return 0;
}