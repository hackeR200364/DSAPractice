#include <iostream>
#include <chrono>
#include <vector>
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

vector<Node *> constructionOfTree(int start, int end)
{
    vector<Node *> trees;

    if (start > end)
    {
        trees.push_back(NULL);
        return trees;
    }

    for (int i = start; i <= end; i++)
    {
        vector<Node *> leftSubTrees = constructionOfTree(start, i - 1);
        vector<Node *> rightSubTrees = constructionOfTree(i + 1, end);

        for (int j = 0; j < leftSubTrees.size(); j++)
        {
            Node *left = leftSubTrees[j];

            for (int k = 0; k < rightSubTrees.size(); k++)
            {
                Node *right = rightSubTrees[k];
                Node *node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int catalan(int n)
{
    if (n <= 1)
    {
        return 1;
    }

    int res = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        res += catalan(i) * catalan(n - i - 1);
    }

    return res;
}

int main()
{
    auto start = high_resolution_clock::now();

    for (int i = 0; i < 10; i++)
    {
        cout << catalan(i) << " ";
    }
    cout << endl;

    vector<Node *> totalTrees = constructionOfTree(1, 3);
    for (int i = 0; i < totalTrees.size(); i++)
    {
        cout << (i + 1) << " : ";
        preorder(totalTrees[i]);
        cout << endl;
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    return 0;
}