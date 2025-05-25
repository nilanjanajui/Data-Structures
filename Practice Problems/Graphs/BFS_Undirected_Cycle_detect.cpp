#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool detectCycle(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});      // because source has no parents

    while (!q.empty())
    {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            else if (adjacentNode != parent)        // if already visited and not the parent:
            {                                       // → Cycle Detected.
                return true; 
            }
        }
    }
    return false;
}

bool isCycle(int nodes, vector<int> adj[])
{
    int vis[nodes + 1] = {0};

    for (int i = 1; i <= nodes; i++)
    {
        if (!vis[i])
        {
            if (detectCycle(i, adj, vis))
            {
                return true;
            }
        }
    }
    return false;
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

    if (isCycle(nodes, adj))
    {
        cout << "Cycle Detected\n";
    }
    else
    {
        cout << "No Cycle Found\n";
    }

    return 0;
}
