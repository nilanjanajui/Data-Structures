#include<iostream>
#include<vector>
#include<queue>

using namespace std;

bool check(int start, vector<int>adj[], int color[])
{
    queue <int> q;
    q.push(start);
    color[start] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(auto it : adj[u])
        {
            if(color[it] == -1)
            {
                color[it] = !color[u];      // !color[u] is use for opposite color
                q.push(it);
            }
            else if(color[it] == color[u])      //check already colored or not
            {
                return false;
            }
        }
    }

    return true;
}

bool isBipartite(int nodes, vector<int>adj[])
{
    int color[nodes];
    for(int i = 0; i < nodes; i++)
    {
        color[i] = -1;
    }
    for(int i = 0; i < nodes; i++)
    {
        if(color[i] == -1)
        {
            if(!check(i, adj, color))
            {
                return false;
            }
        }
    }
    return true;
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

    bool result = isBipartite(nodes, adj);

    cout << "Is the graph Bipartite? " << (result ? "Yes" : "No") << endl;

    return 0;
}


