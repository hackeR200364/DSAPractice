#include <iostream>
#include <chrono>
#include <climits>
using namespace std;
using namespace std::chrono;

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

Node *insertBST(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    if (val < root->data)
    {
        root->left = insertBST(root->left, val);
    }

    else
    {
        root->right = insertBST(root->right, val);
    }

    return root;
}

Node *searchInBST(Node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    if (root->data > key)
    {
        return searchInBST(root->left, key);
    }

    if (root->data < key)
    {
        return searchInBST(root->right, key);
    }
}

Node *inOrderSucc(Node *root)
{
    Node *curr = root;

    while (curr && curr->left != NULL)
    {
        curr = curr->left;
    }

    return curr;
}

Node *deleteInBST(Node *root, int key)
{
    if (key < root->data)
    {
        root->left = deleteInBST(root->left, key);
    }

    else if (key > root->data)
    {
        root->right = deleteInBST(root->right, key);
    }

    else
    {
        // CASE !
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }

        // CASE @
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }

        // CASE 3
        Node *temp = inOrderSucc(root->right);
        root->data = temp->data;
        root->right = deleteInBST(root->right, temp->data);
    }

    return root;
}

Node *constructBST(int preorder[], int *preorderIdx, int key, int min, int max, int n)
{
    if (*preorderIdx >= n)
    {
        return NULL;
    }

    Node *root = NULL;

    if (key > min && key < max)
    {
        root = new Node(key);
        *preorderIdx = *preorderIdx + 1;

        if (*preorderIdx < n)
        {
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }

        if (*preorderIdx < n)
        {
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
    }

    return root;
}

bool isBST(Node *root, Node *min = NULL, Node *max = NULL)
{
    if (root == NULL)
    {
        return true;
    }

    if (min != NULL && root->data <= min->data)
    {
        return false;
    }

    if (max != NULL && root->data >= max->data)
    {
        return false;
    }

    bool leftValid = isBST(root->left, min, root);
    bool rightValid = isBST(root->right, root, max);

    return leftValid and rightValid;
}

Node *sortedArrayToBST(int arr[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }

    int mid = (start + end) / 2;
    Node *root = new Node(arr[mid]);
    root->left = sortedArrayToBST(arr, start, mid - 1);
    root->right = sortedArrayToBST(arr, mid + 1, end);
    return root;
}

void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

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

int main()
{
    auto start = high_resolution_clock::now();

    // Node *root = NULL;
    // root = insertBST(root, 5);
    // insertBST(root, 1);
    // insertBST(root, 3);
    // insertBST(root, 4);
    // insertBST(root, 2);
    // insertBST(root, 7);

    // inOrder(root);
    // cout << endl;

    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    if (searchInBST(root, 10) == NULL)
    {
        cout << "Doesn't exist" << endl;
    }
    else
    {
        cout << "Exist" << endl;
    }

    inOrder(root);
    cout << endl;
    root = deleteInBST(root, 2);
    cout << endl;
    inOrder(root);
    cout << endl;

    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;
    Node *root2 = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    preOrder(root2);
    cout << endl;

    Node *root3 = new Node(3);
    root3->left = new Node(2);
    root3->right = new Node(4);
    if (isBST(root3, NULL, NULL))
    {
        cout << "Valid" << endl;
    }
    else
    {
        cout << "InValid" << endl;
    }

    int arr[] = {10, 20, 30, 40, 50};
    Node *root4 = sortedArrayToBST(arr, 0, 4);
    preOrder(root4);
    cout << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}