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

void graphColor(vector<int> adj[], vector<int> Color, int m, int v, int nodes)
{
    if (v == nodes)
    {
        for(int i = 0; i < nodes; i++)
        {
            cout << Color[i] << " ";
        }
        cout << endl;

        return;
    }

    for (int c = 1; c <= m; c++)
    {
        if (isvalid(adj, Color, c, v))
        {
            Color[v] = c;
            graphColor(adj, Color, m, v + 1, nodes);
            Color[v] = 0;
        }
    }
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

    bool found = false;

    cout << "Possible combinations for " << m << " colors: ";
    graphColor(adj, Color, m, 0, nodes);  

    if (!found) 
    {
        cout << "\nNo valid coloring possible with " << m << " colors";
    }


    return 0;
}


