#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(4);
    v.push_back(1);
    v.push_back(3);

    // FOR SHOWING A VECTOR IN NORMAL WAY
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;

    // FOR SHOWING VECTOR BY A ITERATOR
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); it++)
    {
        cout << *it;
    }
    cout << endl;

    // FOR SHOWING A VECTOR THROUGH 'AUTO'
    for (auto element : v)
    {
        cout << element;
    }
    cout << endl;

    // FOR DELETING THE LAST ELEMENT OF THE VECTOR
    v.pop_back();

    // FOR MAKING A VECTOR OF A SPECIFIC SIZE
    vector<int> v2(3);

    // FOR MAKING A VECTOR OF A SPECIFIC SIZE AND ELEMENT
    vector<int> v3(3, 50);

    // FOR SWAPING TWO VECTOR'S ELEMENTS
    swap(v, v3);

    // FOR SORTING VECTORS
    sort(v3.begin(), v3.end());

    // TESTING
    cout << "v = ";
    for (auto element : v)
    {
        cout << element << " ";
    }
    cout << endl;

    cout << "v3 = ";
    for (auto element : v3)
    {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}