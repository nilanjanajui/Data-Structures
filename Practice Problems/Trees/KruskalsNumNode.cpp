#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge
{
    int u, v, weight;
};

bool compare(Edge a, Edge b)
{
    return a.weight < b.weight;
}

const int MAXN = 1000;
int parent[MAXN];

int find(int x)
{
    if (parent[x] == x)
    {
        return x;
    }
    return parent[x] = find(parent[x]);
}

bool union_sets(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
    {
        return false;
    }
    parent[b] = a;

    return true;
}

int main()
{
    int n, E;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> E;

    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }

    vector<Edge> edges(E);

    cout << "Enter edges in format: u v weight\n";
    for (int i = 0; i < E; ++i)
    {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
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
