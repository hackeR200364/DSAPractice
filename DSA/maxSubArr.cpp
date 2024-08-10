#include <iostream>
#include <climits>

using namespace std;

void maxSubArrsSumKadane(int arr[], int n)
{
    int currentSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currentSum += arr[i];
        if (currentSum < 0)
        {
            currentSum = 0;
        }
        maxSum = max(maxSum, currentSum);
    }
    cout << maxSum << endl;
}

void maxSubArrsSumCumulativeSum(int arr[], int n)
{
    int currSum[n + 1];
    currSum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        currSum[i] = currSum[i - 1] + arr[i - 1];
    }

    int maxSum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }
    cout << maxSum << endl;
}

void maxSubArrBruteForce(int arr[], int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }

            maxSum = max(maxSum, sum);
        }
    }
    cout << maxSum << endl;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // maxSubArrs(arr, n);
    // maxSubArrsSumCumulativeSum(arr, n);
    maxSubArrsSumKadane(arr, n);

    return 0;
}