#include <iostream>
using namespace std;

// void showMatrix(int arr[], int n, int m)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// void searchInMatrix(int arr[], int n, int m, int k)
// {
//     bool flag = false;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (arr[i][j] == k)
//             {
//                 flag = true;
//             }
//         }
//     }

//     if (flag)
//     {
//         cout << "Element found" << endl;
//     }
//     else
//     {
//         cout << "Element not found" << endl;
//     }
// }

int main()
{
    int n, m;
    cout << "Please enter the number of rows & cols = ";
    cin >> n >> m;

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // SHOW THE 2D ARRAY
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // SEARCH A ELEMENT
    int k;
    cout << "Please enter the searching element = ";
    cin >> k;

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == k)
            {
                flag = true;
            }
        }
    }

    if (flag)
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    // SPIRAL ORDER MATRIX
    int row_start = 0, row_end = n - 1, col_start = 0, col_end = m - 1;

    while (row_start <= row_end && col_start <= col_end)
    {
        // FOR ROW_START
        for (int col = col_start; col <= col_end; col++)
        {
            cout << arr[row_start][col] << " ";
        }
        row_start++;

        // FOR COL_END
        for (int row = row_start; row <= row_end; row++)
        {
            cout << arr[row][col_end] << " ";
        }
        col_end--;

        // FOR ROW_END
        for (int col = col_end; col >= col_start; col--)
        {
            cout << arr[row_end][col] << " ";
        }
        row_end--;

        // FOR COL_START
        for (int row = row_end; row >= row_start; row--)
        {
            cout << arr[row][col_start] << " ";
        }
        col_start++;
    }

    return 0;
}