#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node *insert(Node *root, int value)
{
    if (root == nullptr)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    return root;
}
Node *findMin(Node *root)
{
    while (root && root->left != nullptr)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *root, int value)
{
    if (root == nullptr)
        return root;

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            free(root);
            return nullptr;
        }
        else if (root->left == nullptr)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

Node *deleteRoot(Node *root)
{
    if (root == nullptr)
    {
        cout << "Tree is empty, nothing to delete.\n";
        return nullptr;
    }
    return deleteNode(root, root->data);
}

void printLevelOrder(Node *root)
{
    if (root == nullptr)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);
        if (current->right != nullptr)
            q.push(current->right);
    }
    cout << endl;
}

int main()
{
    int n, value;
    Node *root = NULL;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter nodes: " << endl;
    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        root = insert(root, value);
    }

    // cout << "Enter value to delete: ";
    // cin >> value;

    // root = deleteNode(root, value);

    root = deleteRoot(root);

    cout << "BST after deletion of root node: ";
    printLevelOrder(root);

    return 0;
}
