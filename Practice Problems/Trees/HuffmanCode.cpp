#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    Node(int f, Node *l, Node *r) : ch('\0'), freq(f), left(l), right(r) {}
};

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};


void generateCodes(Node *root, string code, unordered_map<char, string> &codes)
{
    if (!root)
        return;
    if (!root->left && !root->right)
    {
        codes[root->ch] = code;
    }
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

int main()
{
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    vector<char> chars(n);
    vector<int> freq(n);

    cout << "Enter characters and their frequencies: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> chars[i] >> freq[i];
    }

    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(new Node(chars[i], freq[i]));
    }

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();
        Node *right = pq.top();
        pq.pop();

        Node *merged = new Node(left->freq + right->freq, left, right);
        pq.push(merged);
    }

    Node *root = pq.top();

    unordered_map<char, string> codes;
    generateCodes(root, "", codes);

    cout << "\nHuffman Codes: " << endl;
    for (auto &c : chars)
    {
        cout << c << " : " << codes[c] << "\n";
    }

    int totalFreq = 0;
    double avgLen = 0.0;
    int totalBits = 0;

    for (int i = 0; i < n; i++)
    {
        int length = codes[chars[i]].length();
        totalFreq += freq[i];
        avgLen += freq[i] * length;
        totalBits += freq[i] * length;
    }

    avgLen /= totalFreq;

    cout << "\nAverage code length: " << avgLen << " bits" << endl;
    cout << "\nTotal length of encoded message: " << totalBits << " bits" << endl;

    return 0;
}
