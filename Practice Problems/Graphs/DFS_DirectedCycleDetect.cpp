#include<iostream>
#include<vector>

using namespace std;

bool dfsCheck(int V, vector<int>adj[], int vis[], int pathVis[])
{
    vis[V] = 1;
    pathVis[V] = 1;

    for(auto it : adj[V])
    {
        if(!vis[it])
        {
            if(dfsCheck(it, adj, vis, pathVis) == true)
            {
                return true;
            }
        }

        else if(pathVis[it])
        {
            return true;
        }
    }

    pathVis[V] = 0;
    return false;
}

bool isCycle(int nodes, vector<int> adj[])
{
    int vis[nodes + 1] = {0};
    int pathVis[nodes + 1] = {0};

    for(int i = 1; i <= nodes; i++)
    {
        if(dfsCheck(i, adj, vis, pathVis) == true)
        {
            return true;
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
        //adj[v].push_back(u); 
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
