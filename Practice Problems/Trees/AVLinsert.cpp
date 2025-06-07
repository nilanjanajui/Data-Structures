#include <iostream>
#include <queue>

using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int height(Node *node)
{
    if (!node)
    {
        return 0;
    }
    return node->height;
}

int getBalance(Node *node)
{
    if (!node)
    {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *insert(Node *node, int key)
{
    if (!node)
    {
        return new Node(key);
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    if (balance < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// void inorder(Node *root)
// {
//     if (!root)
//         return;
//     inorder(root->left);
//     cout << root->key << " ";
//     inorder(root->right);
// }


void levelOrder(Node *root)
{
    if (!root)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        cout << curr->key << " ";

        if (curr->left)
        {
            q.push(curr->left);
        }
        if (curr->right)
        {
            q.push(curr->right);
        }
    }
}

int main()
{
    Node *root = nullptr;
    int n, key, value;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter keys:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        root = insert(root, key);
    }

    // cout << "Inorder traversal of AVL tree: ";
    // inorder(root);
    // cout << "\n";

    cout << "Level order traversal of AVL tree: ";
    levelOrder(root);
    cout << "\n";

    cout << "Enter new value to insert: ";
    cin >> value;
    root = insert(root, value);

    cout << "Level order after inserting " << value << ": ";
    levelOrder(root);

    return 0;
}
