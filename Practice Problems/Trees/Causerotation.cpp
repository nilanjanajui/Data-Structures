#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key, bool& rotated, int& firstRotationKey) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key, rotated, firstRotationKey);
    else if (key > node->key)
        node->right = insert(node->right, key, rotated, firstRotationKey);
    else
        return node;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // Perform rotations only once
    if (!rotated) {
        // Left Left Case
        if (balance > 1 && key < node->left->key) {
            rotated = true;
            firstRotationKey = key;
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && key > node->right->key) {
            rotated = true;
            firstRotationKey = key;
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && key > node->left->key) {
            rotated = true;
            firstRotationKey = key;
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && key < node->right->key) {
            rotated = true;
            firstRotationKey = key;
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }

    return node;
}

int main() {
    int n;
    cin >> n;
    int val;
    Node* root = nullptr;
    bool rotated = false;
    int firstRotationKey = -1;

    for (int i = 0; i < n; ++i) {
        cin >> val;
        root = insert(root, val, rotated, firstRotationKey);
    }

    cout << firstRotationKey << endl;
    return 0;
}
