#include <iostream>
#include <vector>

using namespace std;

bool isvalid(vector<int> adj[], vector<int> &Color, int c, int v)
{
    for (auto u : adj[v])
    {
        if (Color[u] == c)
        {
            return false;
        }
    }

    return true;
}

bool graphColor(vector<int> adj[], vector<int> Color, int m, int v, int nodes)
{
    if (v == nodes)
    {
        return true;
    }

    for (int c = 1; c <= m; c++)
    {
        if (isvalid(adj, Color, c, v))
        {
            Color[v] = c;
            if (graphColor(adj, Color, m, v + 1, nodes))
            {
                return true;
            }
            Color[v] = 0;
        }
    }

    return false;
}

int main()
{
    int nodes, edges;

    cout << "Enter number of Nodes and Edges: " << endl;
    cin >> nodes >> edges;

    vector<int> adj[nodes + 1];
    vector<int> Color(nodes, 0);

    cout << "Enter " << edges << " edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int m;

    cout << "Number of Colors: ";
    cin >> m;

    bool result = graphColor(adj, Color, m, 0, nodes);

    cout << "Is graph coloring possible with " << m << " colors: "
        << (result ? "Yes" : "No") << endl;     // ternary operator



    return 0;
}


