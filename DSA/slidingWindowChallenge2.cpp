#include <iostream>
using namespace std;

int smalledtSubArr(int arr[], int n, int x)
{
    int sum = 0, minLen = n + 1, start = 0, end = 0;
    while (end < n)
    {
        while (sum <= x && end < n)
        {
            sum += arr[end++];
        }

        while (sum > x && start < n)
        {
            if (end - start < minLen)
            {
                minLen = end - start;
            }

            sum -= arr[start++];
        }
    }

    return minLen;
}

int main()
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int x = 51;
    int n = 6;

    cout << "min len = " << smalledtSubArr(arr, n, x) << endl;
    return 0;
}