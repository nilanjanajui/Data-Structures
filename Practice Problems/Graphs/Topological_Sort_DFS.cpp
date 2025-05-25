#include<iostream>
#include<vector>
#include<stack>

using namespace std;

void DFS(int v, int vis[], stack<int> &st, vector<int>adj[])
{
    vis[v] = 1;
    for(auto it : adj[v])
    {
        if(!vis[it])
        {
            DFS(it, vis, st, adj);
        }
    }
    st.push(v);
}

void TopoSort(int nodes, vector<int>adj[])
{
    int vis[nodes + 1] = {0};
    stack<int> st;

    for(int i = 1; i <= nodes; i++)
    {
        if(!vis[i])
        {
            DFS(i, vis, st, adj);
        }
    }

    cout << "Topological Sort: " ;
    while(!st.empty())
    {
        int u = st.top();
        st.pop();

        cout << u << " ";
    }

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

        adj[u].push_back(v);    //directed graph
    }

    TopoSort(nodes, adj);

    return 0;
}


