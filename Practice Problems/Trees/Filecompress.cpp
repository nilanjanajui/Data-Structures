#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparison for priority queue (min-heap)
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;

    // If leaf node, store the code
    if (!root->left && !root->right) {
        codes[root->ch] = code;
    }

    printCodes(root->left, code + "0", codes);
    printCodes(root->right, code + "1", codes);
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        char c;
        int freq;
        cin >> c >> freq;
        pq.push(new Node(c, freq));
    }

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    Node* root = pq.top();

    unordered_map<char, string> codes;
    printCodes(root, "", codes);

    cout << "Character Huffman Codes:\n";
    for (auto& [ch, code] : codes) {
        cout << ch << " : " << code << "\n";
    }

    return 0;
}
