#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please enter = ";
    cin >> n;
    cin.ignore();
    char arr[n + 1];

    cin.getline(arr, n);
    cin.ignore();

    int i = 0;
    int currLen = 0, maxLen = 0;
    int st = 0, maxst = 0;

    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
                maxst = st;
            }
            currLen = 0;
            st = i + 1;
        }

        else
        {
            currLen++;
            if (arr[i] == '\0')
            {
                break;
            }
        }

        i++;
    }

    for (int i = 0; i < maxLen; i++)
    {
        cout << arr[i + maxst];
    }

    cout << maxLen << endl;
    return 0;
}