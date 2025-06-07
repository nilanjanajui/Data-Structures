#include <iostream>
using namespace std;

struct Node {
    int score;
    Node* left;
    Node* right;
    Node(int val) : score(val), left(nullptr), right(nullptr) {}
};

// Insert a score into BST
Node* insert(Node* root, int score) {
    if (!root) return new Node(score);
    if (score < root->score)
        root->left = insert(root->left, score);
    else if (score > root->score)
        root->right = insert(root->right, score);
    // if score == root->score, no duplicates inserted (optional)
    return root;
}

// Search a score in BST
bool search(Node* root, int score) {
    if (!root) return false;
    if (root->score == score) return true;
    if (score < root->score)
        return search(root->left, score);
    else
        return search(root->right, score);
}

int main() {
    int n;
    cout << "Enter number of scores: ";
    cin >> n;

    Node* root = nullptr;
    cout << "Enter the scores:\n";
    for (int i = 0; i < n; i++) {
        int val; cin >> val;
        root = insert(root, val);
    }

    int query;
    cout << "Enter score to search: ";
    cin >> query;

    if (search(root, query))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}
