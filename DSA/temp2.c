#include <stdio.h>
#include <stdlib.h>

// NODE CREATION
struct Node
{

    int data;
    struct Node *next;
};

// INSETION AT BEGINING
void insertAtBeginning(struct Node **head_ref, int new_data)
{

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// INSERTION A NODE AFTER A NODE
void insertAfter(struct Node *prev_node, int new_data)
{

    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

// INSERT AT END
void insertAtEnd(struct Node **head_ref, int new_data)
{

    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref; /* used in step 5 */

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

// DELETION OF A NODE
void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

// SHOW THE LINKED LIST
void printList(struct Node *node)
{

    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

int main()
{
    struct Node *head = NULL;

    while (1)
    {
        int ch = 0;
        int val = 0;
        int pos = 0;
        printf("\n1. Insertion at begining\n2. Insertion at end\n3. Insert after a node\n4. Delete a node\n5. Display\n6. Delete first\n7. Exit\n");
        printf("\nPlease enter a choice = ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
        {

            printf("\nPlease enter a value\n");
            scanf("%d", &val);
            printf("\nBefore insertion at begining\n");
            printList(head);
            insertAtBeginning(&head, val);
            printf("\nAfter insertion\n");
            printList(head);
            break;
        }

        case 2:
        {
            printf("\nPlease enter a value\n");
            scanf("%d", &val);
            printf("\nBefore insertion at end\n");
            printList(head);
            insertAtEnd(&head, val);
            printf("\nAfter insertion at end\n");
            printList(head);
            break;
        }

        case 3:
        {
            printf("\nPlease enter a position\n");
            scanf("%d", &pos);
            printf("\nPlease enter a value\n");
            scanf("%d", &val);
            printf("\nBefore insertion\n");
            printList(head);
            insertAfter(head->next, val);
            printf("\nAfter insertion\n");
            printList(head);
            break;
        }

        case 4:
        {
            printf("\nPlease enter a position\n");
            scanf("%d", &pos);
            printf("\nBefore Deletion\n");
            printList(head);
            deleteNode(&head, pos);
            printf("\nAfter Deletion\n");
            printList(head);
            break;
        }

        case 5:
        {
            printf("\nList\n");
            printList(head);
            break;
        }

        case 6:
        {
            pos = 1;
            printf("\nBefore Deletion\n");
            printList(head);
            deleteNode(&head, pos);
            printf("\nAfter Deletion\n");
            printList(head);
            break;
        }

        case 7:
            exit(1);
        }
    }
}