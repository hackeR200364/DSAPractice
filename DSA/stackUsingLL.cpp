#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int val)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = val;
    new_node->next = top;
    top = new_node;
}

void pop()
{
    if (top == NULL)
    {
        cout << "Stack underflowed" << endl;
    }

    else
    {
        cout << "The poppoed element is" << top->data << endl;
        top = top->next;
    }
}

void display()
{
    struct Node *ptr;
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        ptr = top;
        cout << "Stack Elements" << endl;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }

    cout << endl;
}

int main()
{
    int ch, val;
    cout << "1. Push\n2. Pop\n3. Display\n4. Exit" << endl;
    do
    {
        cout << "Enter choice : " << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
        {
            cout << "Enter the val to push : " << endl;
            cin >> val;
            push(val);
            break;
        }

        case 2:
        {
            pop();
            break;
        }

        case 3:
        {
            display();
            break;
        }

        case 4:
        {
            cout << "Exiting" << endl;
            break;
        }

        default:
        {
            cout << "Invalid choice" << endl;
        }
        }

    } while (ch != 4);
}