
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int edges;

    cout << "Enter number of edges: " << endl;
    cin >> edges;

    map<char, vector<char>> adj;

    cout << "Enter " << edges << " edges (A B):\n";
    for (int i = 0; i < edges; i++)
    {
        char u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<char, bool> visit;
    queue<char> q;

    char src;
    cout << "Enter Source: ";
    cin >> src;

    visit[src] = 1;
    q.push(src);

    cout << "BFS traversal: ";
    while (!q.empty())
    {
        char u = q.front();
        q.pop();

        cout << u << " ";

        sort(adj[u].begin(), adj[u].end()); 
        for (char v : adj[u])
        {
            if (!visit[v])
            {
                visit[v] = 1;
                q.push(v);
            }
        }
    }
    cout << endl;

    return 0;
}

