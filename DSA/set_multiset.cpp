#include <iostream>
#include <set>

using namespace std;
int main()
{
    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(2);
    s.insert(3);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << s.size() << "\n";
    s.erase(2);
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;

    multiset<int> s2;
    s2.insert(1);
    s2.insert(2);
    s2.insert(3);
    s2.insert(3);
    s2.insert(3);
    s2.insert(3);
    s2.insert(3);

    for (auto i : s2)
    {
        cout << i << " ";
    }
    cout << endl;

    // s2.erase(3);
    s2.erase(s2.find(3));

    for (auto i : s2)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}