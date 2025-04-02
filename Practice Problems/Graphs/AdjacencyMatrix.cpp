#include <iostream>
using namespace std;

void Addedge(int adj[][100], int u, int v)
{
    adj[u][v] = 1;
    adj[v][u] = 1; // For undirected graph
}

void createGraph(int adj[][100], int nodes)
{
    cout << "Adjacency Matrix: " << endl;
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int nodes, edges;
    int adj[100][100] = {0}; 
    cout << "Number of nodes: ";
    cin >> nodes;

    cout << "Number of edges: ";
    cin >> edges;

    cout << "Enter " << edges << " edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        Addedge(adj, u, v);
    }

    createGraph(adj, nodes);

    return 0;
}


