#include<iostream>
#include<algorithm>
using namespace std;

int binarySearch(int key, int arr[], int n)
{
    int s = 0;
    int e = n;
    while (s<=e)
    {
        int mid = (s+e)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout<<"Element not found"<<endl;
    return -1;
}

int linearSearch(int key, int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            cout<<"Element found."<<endl;
            return i;
        }
                
    }
    cout<<"Element not found"<<endl;
    return -1;
}

int main(){

    int key;
    int arrSize = 10;
    int arr[arrSize] = {1,20,10,50,79,15,54,97,19,22};
	char res;

	cout<<"'L' for Linear Search\n'B' for Binary Search"<<endl;
    cin>>res;

    switch (res)
    {
    case 'L':
        cout<<"Please enter the number you want to search = ";
        cin>>key;
        cout<<linearSearch(key, arr, arrSize)<<endl;
        break;

    case 'B':
        cout<<"Please enter the number you want to search = ";
        cin>>key;
        cout<<binarySearch(key, arr, arrSize)<<endl;
        break;
    
    default:
        cout<<"Please choose correct option!"<<endl;
        break;
    }
	
	return 0;
}
