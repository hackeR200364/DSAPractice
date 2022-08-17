#include <stdio.h>
#define MAXSIZE 5

struct stack
{
    int stk[MAXSIZE];
    int top;
};
typedef struct stack STACK;
STACK s;

void push(void);
int pop(void);
void display(void);

void main()
{
    int choice;
    int option = 1;
    s.top = -1;

    while (option)
    {
        printf("1 for PUSH\n2 for POP\n3 for display\n4 for EXIT\n");

        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return;
        }
        printf("\n1 for CONTINUE & 0 for EXIT\n");
        scanf("%d", &option);
    }
}

void push()
{
    int num;
    if (s.top == (MAXSIZE - 1))
    {
        printf("\nStack Overflowed\n");
        return;
    }
    else
    {
        printf("\nEnter the element to be pushed\n");
        scanf("%d", &num);
        s.top = s.top + 1;
        s.stk[s.top] = num;
    }
    return;
}

int pop()
{
    int num;
    if (s.top == -1)
    {
        printf("\nStack is Empty\n");
        return (s.top);
    }
    else
    {
        num = s.stk[s.top];
        printf("\nPoped element is = %d\n", s.stk[s.top]);
        s.top = s.top - 1;
    }
    return (num);
}
void display()
{
    int i;
    if (s.top == -1)
    {
        printf("\nStack is empty\n");
        return;
    }
    else
    {
        printf("\nStack : \n");
        for (i = s.top; i >= 0; i--)
        {
            printf("%d\n", s.stk[i]);
        }
    }
    printf("\n");
}