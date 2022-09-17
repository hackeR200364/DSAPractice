#include <iostream>
#include <climits>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

struct Info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTInBT(Node *root)
{
    if (root = NULL)
    {
        return {0, INT_MIN, INT_MAX, true};
    }

    if (root->left == NULL && root->right == NULL)
    {
        return {1, root->data, root->data};
    }

    Info leftInfo = largestBSTInBT(root->left);
    Info rightInfo = largestBSTInBT(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if (leftInfo.isBST && rightInfo.size && leftInfo.max < root->data && rightInfo.min > root->data)
    {
        curr.min = min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max, max(leftInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;
    }

    curr.ans = curr.size;
    curr.isBST = false;
    return curr;
}

int main()
{
    Node *root = new Node(15);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(5);

    cout << " Largest BST to BT !" << largestBSTInBT(root).ans << endl;

    return 0;
}