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

void intersect(node2 *&head1, node2 *&head2, int pos)
{
    node2 *temp1 = head1;
    pos--;

    while (pos--)
    {
        temp1 = temp1->next;
    }

    node2 *temp2 = head2;

    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp1;
}

int intersection(node2 *&head1, node2 *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    node2 *ptr1;
    node2 *ptr2;

    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

node2 *merge(node2 *&head1, node2 *&head2)
{
    node2 *p1 = head1;
    node2 *p2 = head2;
    node2 *dummy = new node2(-1);
    node2 *p3 = dummy;

    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }

        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }

    return dummy->next;
}

node2 *mergeRecursive(node2 *&head1, node2 *&head2)
{
    if (head1 == NULL)
    {
        return head2;
    }

    if (head2 == NULL)
    {
        return head1;
    }

    node2 *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }

    return result;
}

void inserAtHeadCircular(node *&head, int val)
{
    node *n = new node(val);

    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }

    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
    head = n;
}

void insertAtTailCircular(node *&head, int val)
{
    if (head == NULL)
    {
        inserAtHeadCircular(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = n;
    n->next = head;
}

void displayCircular(node *&head)
{
    node *temp = head;

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    cout << "NULL" << endl;
}

void deleteAtHeadCircular(node *&head)
{
    node *temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    node *toDelete = head;
    temp->next = head->next;
    head = head->next;

    delete toDelete;
}

void deletionCircular(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHeadCircular(head);
        return;
    }

    node *temp = head;
    int count = 1;

    while (count != pos - 1)
    {
        temp = temp->next;
        count++;
    }

    node *toDelete = temp->next;
    temp->next = temp->next->next;

    delete toDelete;
}

void evenAfterOdd(node *&head)
{
    node *odd = head;
    node *even = head->next;
    node *evenStart = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart;

    if (odd->next != NULL)
    {
        even->next = NULL;
    }
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

    node2 *head4 = NULL;
    node2 *head5 = NULL;
    insertAtTail2(head4, 1);
    insertAtTail2(head4, 2);
    insertAtTail2(head4, 3);
    insertAtTail2(head4, 4);
    insertAtTail2(head4, 5);
    insertAtTail2(head4, 6);
    insertAtTail2(head5, 9);
    insertAtTail2(head5, 10);
    cout << "Before intersecting Head 4" << endl;
    display2(head4);
    cout << "Before intersecting Head 5" << endl;
    display2(head5);
    intersect(head4, head5, 3);
    cout << "After intersecting Head 4" << endl;
    display2(head4);
    cout << "After intersecting Head 5" << endl;
    display2(head5);
    cout << intersection(head4, head5) << endl;

    node2 *head6 = NULL;
    node2 *head7 = NULL;
    int arr1[] = {1, 4, 5, 7};
    int arr2[] = {2, 3, 6};
    for (int i = 0; i < 4; i++)
    {
        insertAtTail2(head6, arr1[i]);
    }
    for (int i = 0; i < 3; i++)
    {
        insertAtTail2(head7, arr2[i]);
    }
    cout << "Head 6 = ";
    display2(head6);
    cout << "Head 7 = ";
    display2(head7);
    // cout << "Head 6 & Head 7 Merged through Loop" << endl;
    // node2 *newHeadMerged = merge(head6, head7);
    // display2(newHeadMerged);

    cout << "Head 6 & Head 7 Merged through Recursion" << endl;
    node2 *newHeadMerged2 = mergeRecursive(head6, head7);
    display2(newHeadMerged2);

    node *head8 = NULL;
    insertAtTailCircular(head8, 1);
    insertAtTailCircular(head8, 2);
    insertAtTailCircular(head8, 3);
    insertAtTailCircular(head8, 4);
    cout << "Circular Linked List before adding head" << endl;
    displayCircular(head8);
    inserAtHeadCircular(head8, 5);
    cout << "Circular Linked List after adding head" << endl;
    displayCircular(head8);

    cout << "After deletion in Circular Linked List" << endl;
    deletionCircular(head8, 5);
    displayCircular(head8);

    cout << "After deletion of head in Circular Linked List" << endl;
    deleteAtHeadCircular(head8);
    displayCircular(head8);

    node *head9 = NULL;
    int arr[] = {1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++)
    {
        insertAtTail(head9, arr[i]);
    }
    cout << "Head9 = ";
    diaplay(head9);
    evenAfterOdd(head9);
    cout << "Even nodes after odd nodes" << endl;
    diaplay(head9);

    return 0;
}