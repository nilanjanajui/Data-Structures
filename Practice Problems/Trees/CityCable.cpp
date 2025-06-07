#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <set>
using namespace std;

typedef pair<int, char> Edge;  // (weight, destination)
typedef pair<int, pair<char, char>> MSTEdge; // (weight, (from, to))

struct Compare {
    bool operator()(const MSTEdge& a, const MSTEdge& b) {
        return a.first > b.first; // min-heap
    }
};

void primMST(unordered_map<char, vector<Edge>>& graph, char start) {
    unordered_map<char, bool> inMST;
    priority_queue<MSTEdge, vector<MSTEdge>, Compare> minHeap;
    vector<MSTEdge> selectedEdges;
    int totalCost = 0;

    // Start with 'start' node
    inMST[start] = true;
    for (auto& neighbor : graph[start]) {
        minHeap.push({neighbor.first, {start, neighbor.second}});
    }

    while (!minHeap.empty()) {
        MSTEdge current = minHeap.top();
        minHeap.pop();

        int weight = current.first;
        char u = current.second.first;
        char v = current.second.second;

        if (inMST[v]) continue;

        // Select edge
        inMST[v] = true;
        totalCost += weight;
        selectedEdges.push_back({weight, {u, v}});

        // Add new neighbors
        for (auto& neighbor : graph[v]) {
            if (!inMST[neighbor.second]) {
                minHeap.push({neighbor.first, {v, neighbor.second}});
            }
        }
    }

    // Output results
    cout << "Minimum Cost: " << totalCost << endl;
    cout << "Selected Edges in MST:" << endl;
    for (auto& edge : selectedEdges) {
        cout << edge.second.first << " - " << edge.second.second << " : " << edge.first << endl;
    }
}

int main() {
    unordered_map<char, vector<Edge>> graph;
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    cout << "Enter edges in format: from to weight (e.g. A B 4):\n";
    for (int i = 0; i < E; i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        graph[u].push_back({w, v});
        graph[v].push_back({w, u});  // undirected
    }

    char start;
    cout << "Enter starting node: ";
    cin >> start;

    primMST(graph, start);

    return 0;
}
