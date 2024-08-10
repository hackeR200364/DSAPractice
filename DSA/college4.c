#include <stdio.h>
#include <stdlib.h>
struct node
{
    int in;
    struct node *next;
};
struct node *start = NULL;
void create()
{
    if (start == NULL)
    /*{
        int n;
        printf("\n Enter the number of nodes: \n");
        scanf("%d",&n);
        if(n != 0)*/
    {
        int data;
        int n;
        struct node *P;
        struct node *temp;
        P = malloc(sizeof(struct node));
        start = P;
        temp = start;
        printf("\n Enter number to be inserted: ");
        scanf("%d", &data);
        start->in = data;

        for (int i = 1; i > 0; i++)
        {
            P = malloc(sizeof(struct node));
            temp->next = P;
            printf("\n Enter number to be inserted: ");
            scanf("%d", &data);
            P->in = data;
            temp = temp->next;
            printf("\n Enter 0 to BREAK and 1 to CONTINUE\n");
            scanf("%d", &n);
            if (n == 0)
                break;
        }
        printf("\n The list is created \n");
    }
    else
        printf("\n The list is already created \n");
}
void ins_at_first()
{
    int data;
    struct node *temp;
    temp = malloc(sizeof(struct node));
    printf("\nEnter number to"
           " be inserted : ");
    scanf("%d", &data);
    temp->in = data;

    temp->next = start;
    start = temp;
}

void ins_at_any_pos()
{
    struct node *temp, *P;
    int pos, data, i = 1;
    P = malloc(sizeof(struct node));
    printf("\n Enter position and data:");
    scanf("%d %d", &pos, &data);
    temp = start;
    P->in = data;
    P->next = 0;
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
    P->next = temp->next;
    temp->next = P;
}
void del_at_first()
{
    struct node *temp;
    if (start == NULL)
        printf("\n List is empty \n");
    else
    {
        temp = start;
        start = start->next;
        free(temp);
    }
}
void display()
{
    struct node *temp;
    if (start == NULL)
        printf("\n List is empty \n");
    else
    {
        temp = start;
        printf("The created LINKED LIST is: ");
        while (temp != NULL)
        {
            printf("%d ", temp->in);
            temp = temp->next;
        }
    }
}

int main()
{
    int c;
    while (1)
    {
        printf("\n 1. Create \n");
        printf("\n 2. For insertion at starting\n");
        printf("\n 3. For insertion at any position\n");
        printf("\n 4. For deletion of first element\n");
        printf("\n 5. To see list\n");
        printf("\n 6. To exit\n");
        printf("Enter Choice :\n");
        scanf("%d", &c);

        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            ins_at_first();
            break;
        case 3:
            ins_at_any_pos();
            break;
        case 4:
            del_at_first();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
            break;
        default:
            printf("Incorrect Choice \n");
        }
    }
    return 0;
}