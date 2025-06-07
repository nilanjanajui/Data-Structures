#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

int getHeight(Node* node) {
    return node ? node->height : 0;
}

int getBalance(Node* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

Node* rightRotate(Node* y, int depth, int inserted, int& maxDepth, int& result) {
    if (depth > maxDepth) {
        maxDepth = depth;
        result = inserted;
    }
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node* leftRotate(Node* x, int depth, int inserted, int& maxDepth, int& result) {
    if (depth > maxDepth) {
        maxDepth = depth;
        result = inserted;
    }
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key, int depth, int& maxDepth, int& result) {
    if (!node) return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key, depth + 1, maxDepth, result);
    else if (key > node->key)
        node->right = insert(node->right, key, depth + 1, maxDepth, result);
    else
        return node;  // Ignore duplicates

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balance = getBalance(node);

    // LL
    if (balance > 1 && key < node->left->key)
        return rightRotate(node, depth, key, maxDepth, result);

    // RR
    if (balance < -1 && key > node->right->key)
        return leftRotate(node, depth, key, maxDepth, result);

    // LR
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left, depth + 1, key, maxDepth, result);
        return rightRotate(node, depth, key, maxDepth, result);
    }

    // RL
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right, depth + 1, key, maxDepth, result);
        return leftRotate(node, depth, key, maxDepth, result);
    }

    return node;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    Node* root = nullptr;
    int maxDepth = -1;
    int result = -1;

    for (int i = 0; i < n; ++i) {
        root = insert(root, arr[i], 0, maxDepth, result);
    }

    cout << result << endl;
    return 0;
}
