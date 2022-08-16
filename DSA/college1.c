#include <stdio.h>
#include <stdlib.h>

void displayArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insert(int arr[], int n, int pos, int x)
{
    n++;

    for (int i = n - 1; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = x;

    displayArray(arr, n);
}

void deletion(int arr[], int pos, int n)
{
    if (pos >= n + 1)
        printf("\nDeletion not possible.\n");

    else
    {
        for (int i = pos - 1; i < n - 1; i++)
            arr[i] = arr[i + 1];

        printf("\nResultant array is\n");

        displayArray(arr, n - 1);
    }
}

void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    displayArray(arr, n);
}

void check(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("\nNot sorted\n");
            return;
        }
        else
        {
            printf("\nSorted\n");
            return;
        }
    }
}

void binarySearch(int key, int arr[], int n)
{
    int s = 0;
    int e = n;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (arr[mid] == key)
        {
            printf("Element found at %d", mid);
            return;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    printf("Element not found");
    return;
}

int main()
{
    while (1)
    {
        int res;

        printf("\n0 for exit & 1 for continue : ");
        scanf("%d", &res);

        int arr[100], pos, n, x;

        printf("\nEnter number of elements in array\n");
        scanf("%d", &n);

        printf("\nEnter %d elements\n", n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }

        if (res == 1)
        {

            printf("\n1 for Insertion\n2 for deletion\n3 for bubble sort\n4 for binary search\n5 for check\n6 for exit : ");
            scanf("%d", &res);
            switch (res)
            {
            case 1:
            {
                printf("\nEnter the position for inserting = ");
                scanf("%d", &pos);
                printf("\nEnter the element for inserting = ");
                scanf("%d", &x);
                insert(arr, n, pos, x);
                break;
            }

            case 2:
            {
                printf("\nEnter the position of the element = ");
                scanf("%d", &pos);
                deletion(arr, pos, n);
                break;
            }

            case 3:
            {
                bubblesort(arr, n);
                break;
            }

            case 4:
            {
                printf("Please enter the number you want to search = ");
                scanf("%d", &x);
                binarySearch(x, arr, n);
                break;
            }

            case 5:
            {
                check(arr, n);
                break;
            }

            case 6:
            {
                exit(1);
                break;
            }

            default:
                printf("\nPLease select correct option\n");
                break;
            }
        }

        else if (res == 0)
        {
            exit(0);
        }
    }
    return 0;
}