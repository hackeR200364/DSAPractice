#include <iostream>
using namespace std;

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

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        head = n;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}

bool search(node *head, int key)
{
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

void diaplay(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteAtHead(node *&head)
{
    node *toDelete = head;
    head = head->next;

    delete toDelete;
}

void deletion(node *&head, int val)
{
    if (search(head, val) == 0)
    {
        cout << "There is no element of entered value" << endl;
        return;
    }

    if (head->next == NULL)
    {
        deleteAtHead(head);
        return;
    }

    node *temp = head;
    while (temp->next->data != val)
    {
        temp = temp->next;
    }
    node *toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}

node *reverse(node *&head)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nxtptr;

    while (currptr != NULL)
    {
        nxtptr = currptr->next;
        currptr->next = prevptr;

        prevptr = currptr;
        currptr = nxtptr;
    }

    return prevptr;
}

node *reverseRecursive(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *newHead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}

node *reversek(node *&head, int k)
{
    node *prevptr = NULL;
    node *currptr = head;
    node *nxtptr;

    int count = 0;
    while (currptr != NULL && count < k)
    {
        nxtptr = currptr->next;
        currptr->next = prevptr;
        prevptr = currptr;
        currptr = nxtptr;
        count++;
    }

    if (nxtptr != NULL)
    {
        head->next = reversek(nxtptr, k);
    }

    return prevptr;
}

void makeCycle(node *&head, int pos)
{
    node *temp = head;
    node *startNode;

    int count = 1;
    while (temp->next != NULL)
    {
        if (count == pos)
        {
            startNode = temp;
        }
        temp = temp->next;
        count++;
    }
    temp->next = startNode;
}

bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow)
        {
            return true;
        }
    }
    return false;
}

bool removeCycle(node *&head)
{
    node *slow = head;
    node *fast = head;

    if (detectCycle(head) == 0)
    {
        return false;
    }

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);

    fast = head;

    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
    return true;
}

class node2
{
public:
    int data;
    node2 *next;
    node2 *prev;

    node2(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

void insertAtHead2(node2 *&head, int val)
{
    node2 *n = new node2(val);
    n->next = head;

    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

void insertAtTail2(node2 *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead2(head, val);
        return;
    }

    node2 *n = new node2(val);
    node2 *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display2(node2 *head)
{
    node2 *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleAtHead2(node2 *&head)
{
    node2 *todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletion2(node2 *&head, int pos)
{
    if (pos == 1)
    {
        deleAtHead2(head);
        return;
    }

    node2 *temp = head;
    int count = 1;

    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;

    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    delete temp;
}

int length(node2 *head)
{
    int l = 0;
    node2 *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}

node2 *kappend(node2 *&head, int k)
{
    node2 *newHead;
    node2 *newTail;
    node2 *tail = head;

    int l = length(head);
    int count = 1;

    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }

        if (count == l - k + 1)
        {
            newHead = tail;
        }

        tail = tail->next;
        count++;
    }

    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

int main()
{
    node *head = NULL;
    cout << "Initial NULL Linked List" << endl;
    diaplay(head);

    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    cout << "After adding elements in Linked List" << endl;
    diaplay(head);

    insertAtHead(head, 4);
    cout << "After adding element in front of the Linked List" << endl;
    diaplay(head);

    cout << search(head, 3) << endl;
    cout << "Searching in the Linked List" << endl;
    diaplay(head);

    deletion(head, 5);
    cout << "After deleting specific element of the Linked List" << endl;
    diaplay(head);

    deleteAtHead(head);
    cout << "After deleting first element of the Linked List" << endl;
    diaplay(head);

    node *newHead = reverse(head);
    cout << "After reversing the elements of the Linked List in loop way" << endl;
    diaplay(newHead);

    node *newHeadRecurr = reverseRecursive(newHead);
    cout << "After reversing the elements of the Linked List in recursive way" << endl;
    diaplay(newHeadRecurr);

    int k = 2;
    node *head2 = NULL;
    cout << "Initial NULL Linked List" << endl;
    diaplay(head2);
    insertAtTail(head2, 1);
    insertAtTail(head2, 2);
    insertAtTail(head2, 3);
    insertAtTail(head2, 4);
    insertAtTail(head2, 5);
    insertAtTail(head2, 6);
    cout << "After adding elements in Linked List" << endl;
    diaplay(head2);
    cout << "After reversing the k elements of the Linked List in recursive way" << endl;
    node *newheadk = reversek(head2, k);
    diaplay(newheadk);

    cout << "Make a cycle in Linked List" << endl;
    makeCycle(head2, 3);

    cout << "Check if there is any cycle or not" << endl;
    cout << detectCycle(head) << endl;

    cout << "After removing the cycle" << endl;
    cout << removeCycle(head2) << endl;
    cout << detectCycle(head2) << endl;
    diaplay(head2);

    cout << "Doubly Linked List" << endl;
    node2 *head3 = NULL;
    insertAtTail2(head3, 1);
    insertAtTail2(head3, 2);
    insertAtTail2(head3, 3);
    insertAtTail2(head3, 4);
    display2(head3);

    // cout << "After adding head element in Linked List" << endl;
    // insertAtHead2(head3, 5);
    // display2(head3);

    // cout << "After deleting a specific element in Linked List" << endl;
    // deletion2(head3, 5);
    // display2(head3);

    node2 *newHead2 = kappend(head3, 3);
    cout << "After appending" << endl;
    display2(newHead2);

    return 0;
}