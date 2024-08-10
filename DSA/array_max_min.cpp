#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Please enter the length of array = ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    int maxNum = INT16_MIN;
    int MinNum = INT16_MAX;

    for (int i = 0; i < n; i++)
    {
        maxNum = max(maxNum, arr[i]);
        MinNum = min(MinNum, arr[i]);
        
    }

    cout << "Maximum number = "<<maxNum<<endl<<"Minimum = "<<MinNum<<endl;

    return 0;    

}