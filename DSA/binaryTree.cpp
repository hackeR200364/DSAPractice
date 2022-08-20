#include <iostream>
#include <queue>
#include <chrono>
using namespace std;
using namespace std::chrono;

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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;

    if (start > end)
    {
        return NULL;
    }

    int curr = preorder[idx];
    idx++;
    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(inorder, start, end, curr);
    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}

Node *buildTree2(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }

    int val = postorder[idx];
    idx--;
    Node *curr = new Node(val);
    if (start == end)
    {
        return curr;
    }

    int pos = search(inorder, start, end, val);
    curr->right = buildTree2(postorder, inorder, pos + 1, end);
    curr->left = buildTree2(postorder, inorder, start, pos - 1);

    return curr;
}

void printLevelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}

int sumAtK(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int level = 0;
    int sum = 0;

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();

        if (node != NULL)
        {
            if (level == k)
            {
                sum += node->data;
            }
            if (node->left)
            {
                q.push(node->left);
            }
            if (node->right)
            {
                q.push(node->right);
            }
        }

        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }

    return sum;
}

int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return countNodes(root->left) + countNodes(root->right) + 1;
}

int sumNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return sumNodes(root->left) + sumNodes(root->right) + root->data;
}

int calcuHeight(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lHeight = calcuHeight(root->left);
    int rHeight = calcuHeight(root->right);

    return max(lHeight, rHeight) + 1;
}

int calcuDiameter(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lHeight = calcuHeight(root->left);
    int rHeight = calcuHeight(root->right);
    int currDiameter = lHeight + rHeight + 1;

    int lDiameter = calcuDiameter(root->left);
    int rDiameter = calcuDiameter(root->right);

    return max(currDiameter, max(lDiameter, rDiameter));
}

int calcuDiameterOpt(Node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }

    int lh = 0, rh = 0;
    int lDiameter = calcuDiameterOpt(root->left, &lh);
    int rDiameter = calcuDiameterOpt(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) + 1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

int main()
{

    auto start = high_resolution_clock::now();

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

    // int preorder[] = {1,
    //                   2,
    //                   4,
    //                   5,
    //                   3,
    //                   6,
    //                   7};
    // int inorder[] = {4,
    //                  2,
    //                  5,
    //                  1,
    //                  6,
    //                  3,
    //                  7};

    int preorder1[] = {1, 2, 4, 3, 5};
    int inorder1[] = {4, 2, 1, 5, 3};
    int postorder[] = {4, 2, 5, 3, 1};

    Node *root3 = buildTree(preorder1, inorder1, 0, 4);
    cout << "InOrder = ";
    inOrder(root3);
    cout << endl;

    Node *root4 = buildTree(postorder, inorder1, 0, 4);
    cout << "PostOrder = ";
    inOrder(root4);
    cout << endl;

    cout << "LevelOrder = ";
    printLevelOrder(root2);
    cout << endl;

    cout << "Sum at kth level = " << sumAtK(root2, 2) << endl;

    cout << "Total nodes = " << countNodes(root2) << endl;

    cout << "Total sum of nodes = " << sumNodes(root2) << endl;

    cout << "Height = " << calcuHeight(root2) << endl;

    cout << "Diameter = " << calcuDiameter(root2) << endl;

    int height = 0;
    cout << "Diameter From Optimised = " << calcuDiameterOpt(root2, &height) << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}