#include <iostream>
using namespace std;

int setbit(int n, int pos)
{
    return (n | (1 << pos));
}

bool getBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

int unique3(int arr[], int n)
{
    int result = 0;

    for (int i = 0; i < 64; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (getBit(arr[j], i))
            {
                sum++;
            }
        }
        if (sum & 3 != 0)
        {
            result = setbit(result, i);
        }
    }
    return result;
}

int unique(int arr[], int n)
{
    int xorSum = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum = xorSum ^ arr[i];
    }
    return xorSum;
}

int setBit(int n, int pos)
{
    return ((n & (1 << pos)) != 0);
}

void unique2(int arr[], int n)
{
    int xorSum = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum = xorSum ^ arr[i];
    }
    int tempXor = xorSum;
    int setbit = 0;
    int pos = 0;
    while (setbit != 1)
    {
        setbit = xorSum & 1;
        pos++;
        xorSum = xorSum >> 1;
    }
    int newXor = 0;
    for (int i = 0; i < n; i++)
    {
        if (setBit(arr[i], (pos - 1)))
        {
            newXor = newXor ^ arr[i];
        }
    }
    cout << newXor << endl;
    cout << (tempXor ^ newXor) << endl;
}

bool isPowerOf2(int n)
{
    return (n && !(n & n - 1));
}

int numberOfOnes(int n)
{
    int count = 0;
    while (n)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

void subSets(int arr[], int n)
{
    for (int i = 0; i < (1 << n); i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                cout << arr[j] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{

    int arr[4] = {1, 2, 3, 4};
    int arr2[] = {1, 2, 3, 4, 1, 2, 3};
    int arr3[] = {1, 2, 3, 1, 2, 3, 5, 7};
    int arr4[] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 3};

    subSets(arr, 4);
    cout << isPowerOf2(14) << endl;
    cout << numberOfOnes(19) << endl;
    cout << unique(arr2, 7) << endl;
    unique2(arr3, 8);
    cout << unique3(arr4, 10) << endl;
    return 0;
}