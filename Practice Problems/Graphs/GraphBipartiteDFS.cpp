#include<iostream>
#include<vector>

using namespace std;

bool DFS(int start, int col, int Color[], vector<int> adj[])
{
    Color[start] = col;

    for(auto it : adj[start])
    {
        if(Color[it] == -1)
        {
            if(!DFS(it, !col, Color, adj))  // Recursion uses the call stack(automatically managed by function calls)
            {
                return false;
            }
            
        }
        else if(Color[it] == col)
        {
            return false;
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
            if(!DFS(i, 0, color, adj))
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




// If want to use stack
/* bool iterativeDFS(int start, int Color[], vector<int> adj[]) {
    stack<int> s;
    s.push(start);
    Color[start] = 0;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        for (auto neighbor : adj[node]) {
            if (Color[neighbor] == -1) {
                Color[neighbor] = !Color[node];
                s.push(neighbor);
            } else if (Color[neighbor] == Color[node]) {
                return false;
            }
        }
    }
    return true;
}
*/