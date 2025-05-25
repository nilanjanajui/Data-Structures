#include <iostream>
#include <queue>

using namespace std;

struct node
{
    int data;
    node *left, *right;

    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

node *BuildTree()
{
    int rootData;
    cout << "Enter root: " << endl;
    cin >> rootData;

    if (rootData == -1)
    {
        return NULL;
    }

    node *root = new node(rootData);
    queue<node *> q;
    q.push(root);

    while (!q.empty())
    {
        node *current = q.front();
        q.pop();

        int leftData, rightData;
        cin >> leftData >> rightData;

        if (leftData != -1)
        {
            current->left = new node(leftData);
            q.push(current->left);
        }

        if (rightData != -1)
        {
            current->right = new node(rightData);
            q.push(current->right);
        }
    }

    return root;
}

void InOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    cout << root->data << " ";
    InOrder(root->right);
}

int main()
{
    node *root = BuildTree();

    cout << "\nInOrder Traversal: ";
    InOrder(root);
    cout << endl;

    return 0;
}
