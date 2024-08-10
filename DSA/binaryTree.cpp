#include <iostream>
#include <queue>
#include <vector>
#include <chrono>
#include <climits>

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

void sumReplace(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    sumReplace(root->left);
    sumReplace(root->right);

    if (root->left != NULL)
    {
        root->data += root->left->data;
    }

    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    if (isBalanced(root->left) == false)
    {
        return false;
    }

    if (isBalanced(root->right) == false)
    {
        return false;
    }

    int lh = calcuHeight(root->left);
    int rh = calcuHeight(root->right);

    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isBalanced2(Node *root, int *height)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = 0, rh = 0;
    if (isBalanced2(root->left, &lh) == false)
    {
        return false;
    }

    if (isBalanced2(root->right, &rh) == false)
    {
        return false;
    }

    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void rightView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == (n - 1))
            {
                cout << curr->data << " ";
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }
        }
    }
}

void leftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            Node *curr = q.front();
            q.pop();

            if (i == (n - 1))
            {
                cout << curr->data << " ";
            }

            if (curr->right != NULL)
            {
                q.push(curr->right);
            }

            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
        }
    }
}

Node *LCA(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *left = LCA(root->left, n1, n2);
    Node *right = LCA(root->right, n1, n2);

    if (left != NULL && right != NULL)
    {
        return root;
    }

    if (left == NULL && right == NULL)
    {
        return NULL;
    }

    if (left != NULL)
    {
        return LCA(root->left, n1, n2);
    }
    return LCA(root->right, n1, n2);
}

int findDist(Node *root, int k, int dist)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root->data == k)
    {
        return dist;
    }

    int left = findDist(root->left, k, (dist + 1));
    if (left != -1)
    {
        return left;
    }
    return findDist(root->right, k, (dist + 1));
}

int distBtwNodes(Node *root, int n1, int n2)
{
    Node *lca = LCA(root, n1, n2);

    int d1 = findDist(lca, n1, 0);
    int d2 = findDist(lca, n2, 0);

    return (d1 + d2);
}

void flatten(Node *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }

    if (root->left != NULL)
    {
        flatten(root->left);

        Node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node *t = root->right;
        while (t->right != NULL)
        {
            t = t->right;
        }
        t->right = temp;
    }
    flatten(root->right);
}

void printSubTreeNodesCaseI(Node *root, int k)
{
    if (root == NULL or k < 0)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    printSubTreeNodesCaseI(root->left, k - 1);
    printSubTreeNodesCaseI(root->right, k - 1);
}

int printNodesAtk(Node *root, Node *target, int k)
{
    if (root == NULL)
    {
        return -1;
    }

    if (root == target)
    {
        printSubTreeNodesCaseI(root, k);
        return 0;
    }

    int dl = printNodesAtk(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubTreeNodesCaseI(root->right, k - dl - 2);
        }
        return (1 + dl);
    }

    int dr = printNodesAtk(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
        {
            cout << root->data << " ";
        }
        else
        {
            printSubTreeNodesCaseI(root->left, k - dr - 2);
        }
        return (1 + dr);
    }

    return -1;
}

bool getPath(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }

    path.push_back(root->data);
    if (root->data == key)
    {
        return true;
    }

    if (getPath(root->left, key, path) or getPath(root->right, key, path))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int lowestCommonA(Node *root, int n1, int n2)
{
    vector<int> path1, path2;

    if (!getPath(root, n1, path1) or !getPath(root, n2, path2))
    {
        return -1;
    }

    int pc;
    for (pc = 0; pc < path1.size() && path2.size(); pc++)
    {
        if (path1[pc] != path2[pc])
        {
            break;
        }
    }

    return path1[pc - 1];
}

Node *lowestCommonA2(Node *root, int n2, int n1)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 or root->data == n2)
    {
        return root;
    }

    Node *leftLCA = lowestCommonA2(root->left, n2, n1);
    Node *rightLCA = lowestCommonA2(root->right, n2, n1);

    if (leftLCA && rightLCA)
    {
        return root;
    }

    if (leftLCA != NULL)
    {
        return leftLCA;
    }

    return rightLCA;
}

int maxPathSumUtil(Node *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max(max(root->data, root->data + left + right), max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    return singlePathSum;
}

int maxPathSum(Node *root)
{
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    return ans;
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

    cout << "Root2 = ";
    preOrder(root2);
    cout << endl;
    // sumReplace(root2);
    // cout << "Root2 after Sum Replace = ";
    // preOrder(root2);
    // cout << endl;

    cout << "Root2 is : ";
    cout << (isBalanced(root2) ? "Balanced" : "UnBalanced") << endl;
    Node *root5 = new Node(1);
    root5->left = new Node(2);
    root5->left->left = new Node(3);
    cout << "Root5 is : ";
    cout << (isBalanced(root5) ? "Balanced" : "UnBalanced") << endl;

    int height2 = 0;
    cout << "Opt Root2 is : ";
    cout << (isBalanced2(root2, &height2) ? "Balanced" : "UnBalanced") << endl;
    cout << "Opt Root5 is : ";
    cout << (isBalanced2(root5, &height2) ? "Balanced" : "UnBalanced") << endl;

    cout << "Right View = ";
    rightView(root2);
    cout << endl;

    Node *root6 = new Node(5);
    root6->left = new Node(3);
    root6->right = new Node(6);
    root6->left->left = new Node(2);
    root6->left->right = new Node(4);
    cout << "Left View = ";
    leftView(root6);
    cout << endl;

    Node *root7 = new Node(1);
    root7->left = new Node(2);
    root7->right = new Node(3);
    root7->left->left = new Node(4);
    root7->right->right = new Node(5);
    cout << "Distance Btw Nodes = " << distBtwNodes(root7, 4, 5) << endl;

    Node *root8 = new Node(4);
    root8->left = new Node(9);
    root8->right = new Node(5);
    root8->left->left = new Node(1);
    root8->left->right = new Node(3);
    root8->right->right = new Node(6);
    flatten(root8);
    cout << "Flatten root2 = ";
    inOrder(root8);
    cout << endl;

    Node *root9 = new Node(1);
    root9->left = new Node(2);
    root9->right = new Node(3);
    root9->left->left = new Node(4);
    cout << "Dist at K " << printNodesAtk(root9, root9->left, 1) << endl;

    Node *root10 = new Node(1);
    root10->left = new Node(2);
    root10->right = new Node(3);
    root10->left->left = new Node(4);
    root10->right->left = new Node(5);
    root10->right->right = new Node(6);
    root10->right->left->left = new Node(7);
    int n1 = 7, n2 = 6;
    int lca = lowestCommonA(root10, n1, n2);
    if (lca == -1)
    {
        cout << "Doesn't exist" << endl;
    }
    else
    {
        cout << "Exist : " << lca << endl;
    }

    Node *lca2 = lowestCommonA2(root10, n1, n2);
    if (lca2 == NULL)
    {
        cout << "Doesn't exist" << endl;
    }
    else
    {
        cout << "Exist : " << lca2->data << endl;
    }

    Node *root11 = new Node(1);
    root11->left == new Node(2);
    root11->right == new Node(3);
    root11->left->left == new Node(4);
    root11->right->right == new Node(5);
    cout << "Max Path Sum = " << maxPathSum(root11) << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}