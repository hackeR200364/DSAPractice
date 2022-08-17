#define SIZE 100
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

char s[SIZE];
int top = -1;
void RemoveSpaces(char *source)
{
    char *i = source;
    char *j = source;
    while (*j != 0)
    {
        *i = *j++;
        if (*i != ' ')
            i++;
    }
    *i = 0;
}
void push(char elem)
{
    s[++top] = elem;
}
char pop()
{
    return (s[top--]);
}
int pr(char elem)
{
    switch (elem)
    {
    case '#':
        return 0;
    case '(':
        return 1;
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 3;
    }
}
void i_to_p(char *infix, char *postfix)
{
    char ch, elem;
    int i = 0, k = 0;
    RemoveSpaces(infix);
    push('#');
    while ((ch = infix[i++]) != '\n')
    {
        if (ch == '(')
            push(ch);
        else if (isalnum(ch))
            postfix[k++] = ch;
        else if (ch == ')')
        {
            while (s[top] != '(')
                postfix[k++] = pop();
            elem = pop();
        }
        else
        {
            while (pr(s[top]) >= pr(ch))
                postfix[k++] = pop();
            push(ch);
        }
    }
    while (s[top] != '#')
        postfix[k++] = pop();
    postfix[k] = 0;
}
int eval_postfix(char *postfix)
{
    char ch;
    int i = 0, op1, op2;
    while ((ch = postfix[i++]) != 0)
    {
        if (isdigit(ch))
            push(ch - '0');
        else
        {
            op2 = pop();
            op1 = pop();
            switch (ch)
            {
            case '+':
                push(op1 + op2);
                break;
            case '-':
                push(op1 - op2);
                break;
            case '*':
                push(op1 * op2);
                break;
            case '/':
                push(op1 / op2);
                break;
            }
        }
    }
    return s[top];
}
void main()
{
    int c = 1;
    char in[50], po[50];
    printf("\n Input the Infix expression: \n");
    fgets(in, 50, stdin);
    while (1 > 0)
    {
        printf("\n 1.For Infix to Postfix \n 2.For Evaluation \n 3. For exit \n Please enter your choice = ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
        {
            i_to_p(in, po);
            printf("\n Infix: %s Postfix: %s \n", in, po);
            top = -1;
            break;
        }
        case 2:
        {
            i_to_p(in, po);
            top = -1;
            printf("\n Evaluation: %d \n", eval_postfix(po));
            break;
        }
        case 3:
            exit(0);
            break;
        }
    }
}