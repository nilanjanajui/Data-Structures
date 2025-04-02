#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int nodes, edges;

    cout << "Number of Nodes and Edges: ";
    cin >> nodes >> edges;

    vector<int>adj[nodes + 1];

    cout << "Enter " << edges << " edges (u v):\n";
    for (int i = 0; i < edges; i++) 
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i = 1; i <= nodes; i++)
    {
        cout << "Node " << i << ": ";
        for(int v : adj[i])
        {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;

}

