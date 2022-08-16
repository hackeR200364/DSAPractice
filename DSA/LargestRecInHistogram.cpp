#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int get_max_area(vector<int> a)
{
    int n = a.size(), ans = 0, i = 0;
    stack<int> st;
    a.push_back(0);

    while (i < n)
    {
        while (!st.empty() and a[st.top()] > a[i])
        {
            int t = st.top();
            int h = a[t];
            st.pop();

            if (st.empty())
            {
                ans = max(ans, h * i);
            }

            else
            {
                int len = i - st.top() - 1;
                ans = max(ans, h * len);
            }
        }
        st.push(i);
        i++;
    }

    return ans;
}

int32_t main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(5);
    a.push_back(6);
    a.push_back(2);
    a.push_back(3);
    cout << get_max_area(a) << endl;
}