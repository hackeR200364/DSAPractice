#include <stdio.h>
#define MAX 10
int stack[MAX], top = -1;
void push(int x);
int pop();

void main()
{
    int val, prompt;
    do
    {
        printf("\nPress <1> to PUSH & <2> to POP & <0> to EXIT");
        scanf("%d", &prompt);

        switch (prompt)
        {
        case 1:
            printf("\nEnter element to push = ");
            scanf("%d", &val);
            push(val);
            break;

        case 2:
            printf("\nPopped element = %d", pop());
            break;

        case 0:
            break;

        default:
            break;
        }
    } while (prompt != 0);
    {
        /* code */
    }
}

void push(int x)
{
    if ((top == MAX - 1))
    {
        printf("\n Stack Overflowed");
    }
    else
    {
        stack[++top] = x;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("\n Stack Underflowed");
        return 0;
    }
    else
    {
        return stack[top--];
    }
}