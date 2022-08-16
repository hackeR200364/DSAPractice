int binarySearch(int arr[], int low, int high, int a)
// {
//     int mid;
//     if (high >= low)
//     {
//         mid = (low + high) / 2;

//         if (arr[mid] == a)
//         {
//             return mid + 1;
//         }

//         else if (arr[mid] < a)
//         {
//             return binarySearch(arr, mid + 1, high, a);
//         }

//         else
//         {
//             return binarySearch(arr, low, mid - 1, a);
//         }
//     }
//     return -1;
// }
