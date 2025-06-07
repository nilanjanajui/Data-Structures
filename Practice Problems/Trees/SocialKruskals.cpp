#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Edge structure: (weight, u, v)
struct Edge {
    int u, v, weight;
};

// Disjoint Set Union (Union-Find) structure
struct DSU {
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return false;  // already connected
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    int n, m; 
    // n = number of nodes, m = number of edges
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<Edge> edges(m);

    cout << "Enter edges (u v weight) with 0-based node indices:\n";
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n);

    int mst_weight = 0;
    vector<Edge> mst_edges;

    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.weight;
            mst_edges.push_back(e);
        }
    }

    cout << "Total weight of MST: " << mst_weight << "\n";
    cout << "Edges included in MST:\n";
    for (auto& e : mst_edges) {
        cout << e.u << " - " << e.v << " : " << e.weight << "\n";
    }

    return 0;
}
