#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int nodes, edges;

    cout << "Enter number of Nodes and Edges: " << endl;
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

    vector<int> visit(nodes + 1, 0);
    queue<int> q;

    int src;

    cout << "Enter Souce: ";
    cin >> src;

    visit[src] = 1; // 1 is for true
    q.push(src);

    cout << "BFS traversal: ";
    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u])
        {
            if (!visit[v])
            {
                visit[v] = 1; // 1 is for true
                q.push(v);
            }
        }
    }

    return 0;
}
