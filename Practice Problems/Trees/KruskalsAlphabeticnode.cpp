#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Edge
{
    char u, v;
    int weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

unordered_map<char, char> parent;

char find(char x)
{
    if (parent.find(x) == parent.end())
    {
        parent[x] = x;
    }
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }

    return parent[x];
}

bool union_sets(char a, char b)
{
    char rootA = find(a);
    char rootB = find(b);
    if (rootA == rootB)
    {
        return false;
    }
    parent[rootB] = rootA;
    return true;
}

int main()
{
    int E;
    cout << "Enter number of edges: ";
    cin >> E;

    vector<Edge> edges;

    cout << "Enter edges in format: u v weight (e.g. A B 4)\n";
    for (int i = 0; i < E; ++i)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    sort(edges.begin(), edges.end(), compare);

    vector<Edge> mst;
    int totalWeight = 0;

    for (Edge edge : edges)
    {
        if (union_sets(edge.u, edge.v))
        {
            mst.push_back(edge);
            totalWeight += edge.weight;
        }
    }

    cout << "\nMinimum Spanning Tree edges:\n";
    for (Edge edge : mst)
    {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << "\n";
    }
    cout << "Total Weight of MST: " << totalWeight << "\n";

    return 0;
}
