#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> stockSpan(vector<int> prices)
{
    vector<int> ans;
    stack<pair<int, int> > s;

    for (auto price : prices)
    {
        int days = 1;
        while (!s.empty() and s.top().first <= price)
        {
            days += s.top().second;
            s.pop();
        }
        s.push(make_pair(price, days));
        ans.push_back(days);
    }
    return ans;
}

int main()
{
    vector<int> a;
    a.push_back(100);
    a.push_back(80);
    a.push_back(60);
    a.push_back(70);
    a.push_back(60);
    a.push_back(75);
    a.push_back(85);
    vector<int> res = stockSpan(a);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << "\n";
}
