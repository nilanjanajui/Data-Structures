#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void graphColor(vector<int> adj[], int nodes)
{
    vector<int> color(nodes, -1); 
    color[0] = 1;

    vector<bool> alreadyAssigned(nodes + 1, false);

    for (int u = 1; u < nodes; u++)
    {
        fill(alreadyAssigned.begin(), alreadyAssigned.end(), false);

        for (auto av : adj[u])
        {
            if (color[av] != -1)
            {
                alreadyAssigned[color[av]] = true;
            }
        }

        int c;
        for (c = 1; c <= nodes; c++)
        {
            if (!alreadyAssigned[c])
            {
                break;
            }
        }

        color[u] = c;
    }

    int totalColors = *max_element(color.begin(), color.end());
    cout << "Number of colors required: " << totalColors << endl;

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

    graphColor(adj, nodes);

    return 0;
}


