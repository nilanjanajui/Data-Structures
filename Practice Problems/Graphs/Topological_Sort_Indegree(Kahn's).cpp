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
    vector<int> indegree(nodes + 1, 0);

    cout << "Enter " << edges << " edges (u v):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);

        indegree[v]++;      // tracking indegree
    }

    queue<int> q;

    for(int i = 1; i <= nodes; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    cout << "Topological Sort: " ;
    while(!q.empty())
    {
        int n = q.front();
        q.pop();

        cout << n << " ";

        for(auto it : adj[n])
        {
            indegree[it]--;
            if(indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    cout << endl;

    return 0;
}

