#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isvalid(vector<int> adj[], vector<string> &Color, string c, int v)
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

void graphColor(vector<int> adj[], vector<string> &Color, int m, int v, int nodes, vector<string> &colors, bool &found)
{
    if (v == nodes)
    {
        for (int i = 0; i < nodes; i++)
        {
            cout << Color[i] << " ";
        }
        cout << endl;
        found = true;
        return;
    }

    for (int i = 0; i < m; i++)
    {
        if (isvalid(adj, Color, colors[i], v))
        {
            Color[v] = colors[i];
            graphColor(adj, Color, m, v + 1, nodes, colors, found);
            Color[v] = "";
        }
    }
}

int main()
{
    int nodes, edges;

    cout << "Enter number of Nodes and Edges: " << endl;
    cin >> nodes >> edges;

    vector<int> adj[nodes + 1];
    vector<string> Color(nodes, "");

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

    vector<string> colors(m);
    cout << "Enter " << m << " color names: ";
    for (int i = 0; i < m; i++)
    {
        cin >> colors[i];
    }

    bool found = false;

    cout << "Possible combinations for " << m << " colors:\n";
    graphColor(adj, Color, m, 0, nodes, colors, found);

    if (!found)
    {
        cout << "\nNo valid coloring possible with " << m << " colors";
    }

    return 0;
}


