#include <bits/stdc++.h>
using namespace std;

class Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }

    void push(int val)
    {
        q2.push(val);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        q1.pop();
        N--;
    }

    int top()
    {
        return q1.front();
    }

    int size()
    {
        return N;
    }

    void pop2()
    {
        if (q1.empty())
        {
            return;
        }

        while (q1.size() != 1)
        {
            q2.push(q1.front());
        }

        q1.pop();
        N--;

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void push2(int val)
    {
        q1.push(val);
        N++;
    }

    int top2()
    {
        if (q1.empty())
        {
            return -1;
        }

        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();
        q2.push(ans);

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;

        return ans;
    }

    int size2()
    {
        return N;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Top = " << st.top() << endl;
    st.pop();
    cout << "Top = " << st.top() << endl;
    st.pop();
    cout << "Top = " << st.top() << endl;
    st.pop();
    cout << "Top = " << st.top() << endl;
    st.pop();

    cout << "Size = " << st.size() << endl;

    cout << "Stack Push2 : " << endl;
    st.push2(1);
    st.push2(2);
    st.push2(3);
    st.push2(4);
    cout << "Top2 = " << st.top2() << endl;
    st.pop2();
    cout << "Top2 = " << st.top2() << endl;
    // cout << "Size2 = " << st.size2() << endl;

    return 0;
}