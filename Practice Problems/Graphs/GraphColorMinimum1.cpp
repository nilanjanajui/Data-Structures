// If the color number not match with theory

#include <iostream>
#include <vector>

using namespace std;

bool isValid(int node, int c, vector<int> &color, vector<int> adj[])
{
    for (int neighbor : adj[node])
    {
        if (color[neighbor] == c)
            return false;
    }
    return true;
}

bool solve(int node, int nodes, int maxColors, vector<int> &color, vector<int> adj[])
{
    if (node == nodes)
        return true;

    for (int c = 1; c <= maxColors; c++)
    {
        if (isValid(node, c, color, adj))
        {
            color[node] = c;
            if (solve(node + 1, nodes, maxColors, color, adj))
                return true;
            color[node] = 0; // backtrack
        }
    }
    return false;
}

int findChromaticNumber(vector<int> adj[], int nodes)
{
    vector<int> color(nodes, 0);

    for (int k = 1; k <= nodes; k++)
    {
        fill(color.begin(), color.end(), 0);
        if (solve(0, nodes, k, color, adj))
        {
            cout << "Minimum colors required: " << k << endl;
            cout << "Coloring:\n";
            for (int i = 0; i < nodes; i++)
            {
                cout << "Node " << i << " → Color " << color[i] << endl;
            }
            return k;
        }
    }
    return nodes; // worst case: each node needs its own color
}

int main()
{
    int nodes, edges;
    cout << "Enter number of Nodes and Edges: ";
    cin >> nodes >> edges;

    vector<int> adj[nodes + 1];
    cout << "Enter " << edges << " edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    findChromaticNumber(adj, nodes);

    return 0;
}
