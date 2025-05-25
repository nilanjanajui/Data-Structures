#include <iostream>
#include <vector>
#include <queue>

using namespace std;

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
        adj[v].push_back(u); // undirected graph
    }

    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<int> dist(nodes + 1, 1e9);
    dist[src] = 0;

    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : adj[u])
        {
            if (dist[u] + 1 < dist[v])
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    cout << "\nShortest distances from node " << src << ":\n";
    for (int i = 1; i <= nodes; i++)
    {
        if (dist[i] == 1e9)
            cout << "Node " << i << ": Unreachable\n";
        else
            cout << "Node " << i << ": " << dist[i] << "\n";
    }

    return 0;
}





















// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>

// using namespace std;

// int main()
// {
//     int nodes, edges;

//     cout << "Enter number of Nodes and Edges: ";
//     cin >> nodes >> edges;

//     vector<int> adj[nodes + 1];

//     cout << "Enter " << edges << " edges (u v):\n";
//     for (int i = 0; i < edges; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u); // undirected graph
//     }

//     int src, dest;
//     cout << "Enter source and destination node: ";
//     cin >> src >> dest;

//     vector<int> dist(nodes + 1, 1e9);
//     vector<int> parent(nodes + 1, -1);

//     dist[src] = 0;
//     queue<int> q;
//     q.push(src);

//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();

//         for (int v : adj[u])
//         {
//             if (dist[u] + 1 < dist[v])
//             {
//                 dist[v] = dist[u] + 1;
//                 parent[v] = u;
//                 q.push(v);
//             }
//         }
//     }

//     if (dist[dest] == 1e9)
//     {
//         cout << "\nNo path from " << src << " to " << dest << ".\n";
//     }
//     else
//     {
//         cout << "\nShortest distance from " << src << " to " << dest << ": " << dist[dest] << "\n";
//         cout << "Path: ";

//         // Reconstruct path using parent[]
//         vector<int> path;
//         for (int v = dest; v != -1; v = parent[v])
//         {
//             path.push_back(v);
//         }

//         // Print in reverse order (from src to dest)
//         for (int i = path.size() - 1; i >= 0; i--)
//         {
//             cout << path[i];
//             if (i != 0)
//                 cout << " -> ";
//         }
//         cout << endl;
//     }

//     return 0;
// }
