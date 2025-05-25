// Levelwise tree representation by using queue or bfs method

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
        if (!(cin >> leftData))
        {
            break;
        }
        if (!(cin >> rightData))
        {
            break;
        }

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

int main()
{
    node *root = BuildTree();

    cout << endl;

    return 0;
}
