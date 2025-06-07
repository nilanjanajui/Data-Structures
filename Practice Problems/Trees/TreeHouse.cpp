#include <iostream>
using namespace std;

struct Node {
    char key;
    Node* left;
    Node* right;
    int height;

    Node(char k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

// Height helper
int getHeight(Node* node) {
    return node ? node->height : 0;
}

// Balance factor
int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Right rotation
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

// Left rotation
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

// AVL insert
Node* insert(Node* node, char key) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // ignore duplicates

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // Balancing
    if (balance > 1 && key < node->left->key)      // LL
        return rightRotate(node);
    if (balance < -1 && key > node->right->key)    // RR
        return leftRotate(node);
    if (balance > 1 && key > node->left->key) {    // LR
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {  // RL
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Inorder traversal (sorted order)
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key;
    inorder(root->right);
}

int main() {
    int n;
    cin >> n;

    string forts;
    cin >> forts;

    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        root = insert(root, forts[i]);
    }

    inorder(root);
    cout << endl;
    return 0;
}
