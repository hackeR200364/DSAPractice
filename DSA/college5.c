#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *create(int);

int search(int);
int list_size();
int get_data();
int get_position();

struct node *create(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    if (new_node == NULL)
    {
        printf("\nMemory can't be allocated\n");
        return NULL;
    }

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;

    return new_node;
}

void insert_begin(int data)
{
    struct node *new_node = create(data);

    if (new_node)
    {
        if (head == NULL)
        {
            new_node->next = new_node;
            new_node->prev = new_node;
            head = new_node;
            return;
        }
        head->prev->next = new_node;
        new_node->prev = head->prev;
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void delete_end()
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *last_node = head->prev;

    last_node->prev->next = head;
    head->prev = last_node->prev;

    free(last_node);
    last_node = NULL;
}

void delete_begin()
{
    if (head == NULL)
    {
        printf("\nList is Empty\n");
        return;
    }
    else if (head->next == head)
    {
        free(head);
        head = NULL;
        return;
    }

    struct node *temp = head;
    head->prev->next = head->next;
    head->next->prev = head->prev;
    head = head->next;

    free(temp);
    temp = NULL;
}

void delete_mid(int position)
{
    if (position <= 0)
    {
        printf("\n Invalid Position \n");
    }
    else if (position > list_size())
    {
        printf("\n Invalid position \n");
    }
    else if (position == 1)
    {
        delete_begin();
    }
    else if (position == list_size())
    {
        delete_end();
    }
    else
    {
        struct node *temp = head;
        struct node *prev = NULL;
        int i = 1;

        while (i < position)
        {
            prev = temp;
            temp = temp->next;
            i += 1;
        }
        prev->next = temp->next;
        temp->next->prev = prev;
        free(temp);
        temp = NULL;
    }
}

int search(int key)
{
    if (head == NULL)
    {
        printf("\n Not Found \n");
        return 0;
    }

    struct node *temp = head;
    do
    {
        if (temp->data == key)
        {
            return 1;
        }
        temp = temp->next;
    } while (temp != head);

    return 0;
}

void display()
{
    if (head == NULL)
    {
        printf("\nList is empty!\n");
        return;
    }

    struct node *temp = head;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}

int list_size()
{
    if (head == NULL)
    {
        return 0;
    }

    struct node *temp = head;
    int count = 0;

    do
    {
        count += 1;
        temp = temp->next;
    } while (temp != head);

    return count;
}

int get_data()
{
    int data;
    printf("\n\nEnter Data: ");
    scanf("%d", &data);

    return data;
}

int get_position()
{
    int position;
    printf("\n\nEnter Position: ");
    scanf("%d", &position);

    return position;
}

int main()
{
    int user_choice;
    int data, position;

    while (1)
    {
        printf("\n1. Create");
        printf("\n2. Insert a node at first");
        printf("\n3. Delete from last");
        printf("\n4. Delete any node ");
        printf("\n5. Search a node data");
        printf("\n6. Show List");
        printf("\n7. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &user_choice);

        switch (user_choice)
        {
        case 1:
            printf("List is created");
            break;
        case 2:
            printf("\nInserting a node at beginning");
            data = get_data();
            insert_begin(data);
            break;

        case 3:
            printf("\nDeleting node from last\n");
            delete_end();
            break;

        case 4:
            printf("\nDelete any node\n");
            position = get_position();
            delete_mid(position);
            break;

        case 5:
            printf("\nEnter Searching element: ");
            data = get_data();
            if (search(data) == 1)
            {
                printf("\n\tNode Found\n");
            }
            else
            {
                printf("\n\tNode Not Found\n");
            }
            break;

        case 6:
            printf("\nThe List is: \n\n");
            display();
            break;

        case 7:
            exit(1);
            return 0;

        default:
            printf("\n\tInvalid Choice\n");
        }
    }

    return 0;
}