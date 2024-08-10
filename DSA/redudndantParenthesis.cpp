#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string s;
    cin >> s;

    bool ans;
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
        {
            st.push(s[i]);
        }

        else if (s[i] == '(')
        {
            st.push(s[i]);
        }

        else if (s[i] == ')')
        {
            if (st.top() == '(')
            {
                ans = true;
            }

            while (s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
            {
                st.pop();
            }
            st.pop();
        }
    }
    cout << ans << endl;
}