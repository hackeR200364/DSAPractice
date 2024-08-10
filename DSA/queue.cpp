#include <iostream>
#include <stack>
using namespace std;

#define n 20

class queu
{
    int *arr;
    int front;
    int back;

public:
    queu()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void push(int x)
    {
        if (back == n - 1)
        {
            cout << "Queue overflowed" << endl;
            return;
        }
        back++;
        arr[back] = x;

        if (front == -1)
        {
            front++;
        }
    }

    void pop()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue undeflowed" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "Stack Underflowed" << endl;
            return -1;
        }

        return arr[front];
    }

    bool empty()
    {
        if (front == -1 || front > back)
        {
            return true;
        }
        return false;
    }
};

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class queueLL
{
    node *front;
    node *back;

public:
    queueLL()
    {
        front = NULL;
        back = NULL;
    }

    void push(int x)
    {
        node *newNode = new node(x);

        if (front == NULL)
        {
            back = newNode;
            front = newNode;
            return;
        }

        back->next = newNode;
        back = newNode;
    }

    void pop()
    {
        if (front == NULL)
        {
            cout << "Queue Underflowed" << endl;
            return;
        }

        node *toDelete = front;
        front = front->next;

        delete toDelete;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue Underflowed" << endl;
            return -1;
        }

        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
        {
            return true;
        }

        return false;
    }
};

class queueS
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s1.empty() and s2.empty())
        {
            cout << "Queue Underflowed" << endl;
            return -1;
        }
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int topVal = s2.top();
        s2.pop();
        return topVal;
    }

    bool empty()
    {
        if (s1.empty() and s2.empty())
        {
            return true;
        }
        return false;
    }
};

class queueS2
{
    stack<int> s1;

public:
    void push(int x)
    {
        s1.push(x);
    }

    int pop()
    {
        if (s1.empty())
        {
            cout << "Queue Underflowed" << endl;
            return -1;
        }

        int x = s1.top();
        s1.pop();

        if (s1.empty())
        {
            return x;
        }

        int item = pop();
        s1.push();
        return item;
    }

    bool empty()
    {
        if (s1.empty())
        {
            return true;
        }
        return false;
    }
};

int main()
{
    cout << "Queue with Array" << endl;
    queu q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.peek() << endl;
    q.pop();
    cout << q.empty() << endl;

    cout << "Queue with Linked List" << endl;
    queueLL qll;
    qll.push(1);
    qll.push(2);
    qll.push(3);
    qll.push(4);
    cout << qll.peek() << endl;

    cout << "Queue with Stack" << endl;
    queueS qS;
    qS.push(1);
    qS.push(2);
    qS.push(3);
    qS.push(4);
    cout << qS.pop() << endl;
    qS.push(5);
    cout << qS.pop() << endl;
    cout << qS.pop() << endl;
    cout << qS.pop() << endl;
    cout << qS.pop() << endl;
    cout << qS.pop() << endl;

    cout << "Queue with Array" << endl;
    queueS2 qS2;
    qS2.push(1);
    qS2.push(2);
    qS2.push(3);
    qS2.push(4);
    cout << qS2.pop() << endl;

    return 0;
}