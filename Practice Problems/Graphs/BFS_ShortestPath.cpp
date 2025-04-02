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
    map<char, char> origin;
    queue<char> q;

    char src, des;
    cout << "Enter Source and Destination: ";
    cin >> src >> des;

    visit[src] = 1;
    origin[src] = '\0'; 

    q.push(src);

    bool found = false;

    while (!q.empty() && !found)
    {
        char u = q.front();
        q.pop();

        sort(adj[u].begin(), adj[u].end());

        for (char v : adj[u])
        {
            if (!visit[v])
            {
                visit[v] = 1;
                origin[v] = u;
                q.push(v);

                if (v == des) 
                {
                    found = true;
                    break;
                }
            }
        }
    }

    if (found)
    {
        vector<char> path;
        char current = des;

        while (current != '\0')
        {
            path.push_back(current);
            current = origin[current];
        }

        reverse(path.begin(), path.end());

        cout << "Shortest Path: ";
        for (char sp : path)
        {
            cout << sp << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "No path found from " << src << " to " << des << endl;
    }

    return 0;
}


