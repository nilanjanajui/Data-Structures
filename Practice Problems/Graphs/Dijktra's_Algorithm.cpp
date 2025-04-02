#include<iostream>
#include<vector>
#include<queue>

#define INF 1e9

using namespace std;

int main()
{
    int nodes, edges;

    cout << "Enter number of Nodes and Edges: " << endl;
    cin >> nodes >> edges;

    vector<pair<int, int>> adj[nodes + 1];

    cout << "Enter " << edges << " edges and weight (u v w):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});   // for undirected graph
    }

    vector<int>dis(nodes + 1, INF);
    vector<int>visit(nodes + 1, 0);

    priority_queue<pair<int, int>>pq;

    cout << "Enter Source: ";
    int src;
    cin >> src;

    dis[src] = 0;
    pq.push({0, src});

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        if(!visit[u])
        {
            visit[u] = 1;
        }

        for(auto path : adj[u])
        {
            int v = path.first;
            int w = path.second;

            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    cout << "Shortest path: ";
    for(int i = 1; i <= nodes; i++)
    {
        if (dis[i] == INF)
        {
            cout << "INF ";
        }
        else
        {
            cout << dis[i] << " ";
        }
    }
    cout << endl;


    return 0;
}

