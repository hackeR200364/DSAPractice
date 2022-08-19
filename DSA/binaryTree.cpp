#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(struct Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main()
{
    /*    1
         / \
        2   3
    */

    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    /*
          1
         / \
        2   3
       /\
      4  5

    */

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    /*
           1
         /   \
        2     3
       /\    / \
      4  5  6   7

    */

    struct Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);
    root2->left->left = new Node(4);
    root2->left->right = new Node(5);
    root2->right->left = new Node(6);
    root2->right->right = new Node(7);

    cout << "PreOrder = ";
    preOrder(root2);
    cout << endl;

    cout << "InOrder = ";
    inOrder(root2);
    cout << endl;

    cout << "PostOrder = ";
    postOrder(root2);
    cout << endl;

    return 0;
}