#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int PrimsMST(int nodes, vector<pair<int, int>> adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> vis(nodes + 1, 0);
    pq.push({0, 1});

    int sum = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();

        int V = it.second;
        int wt = it.first;

        if (vis[V] == 1)
        {
            continue;
        }

        vis[V] = 1;

        sum += wt;

        for (auto it : adj[V])
        {
            int adjnode = it.first;
            int eW = it.second;

            if (!vis[adjnode])
            {
                pq.push({eW, adjnode});
            }
        }
    }

    return sum;
}

int main()
{
    int nodes, edges;
    cout << "Enter number of Nodes and Edges: " << endl;
    cin >> nodes >> edges;

    vector<pair<int, int>> adj[nodes + 1];

    unordered_map<char, int> charToIndex;

    int index = 1;
    for (int i = 0; i < edges; i++)
    {
        char u, v;
        int w;
        cin >> u >> v >> w;

        if (charToIndex.find(u) == charToIndex.end())
        {
            charToIndex[u] = index++;
        }
        if (charToIndex.find(v) == charToIndex.end())
        {
            charToIndex[v] = index++;
        }

        int uIdx = charToIndex[u];
        int vIdx = charToIndex[v];

        adj[uIdx].push_back({vIdx, w});
        adj[vIdx].push_back({uIdx, w});
    }

    int cost = PrimsMST(nodes, adj);

    cout << "Minimum cost in Prim's: " << cost << endl;

    return 0;
}
