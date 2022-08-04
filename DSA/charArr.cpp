#include <iostream>
using namespace std;

int main()
{
    char arr[100] = "rupam";
    char a[100];
    int i = 0;
    cout << "Please enter your name : ";
    cin >> a;

    cout << "Character array display by loop" << endl;
    while (arr[i] != '\0')
    {
        cout << arr[i] << endl;
        i++;
    }

    cout << "Character array display without loop" << endl;
    cout << a;

    cout << "accessing 3rd element of or displaying a perticular element of Character array" << endl;
    cout << a[3];

    return 0;
}