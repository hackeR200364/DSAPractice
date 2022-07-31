#include<iostream>
using namespace std;

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
    
    default:
        cout<<"Please choose correct option!"<<endl;
        break;
    }
	
	return 0;
}
