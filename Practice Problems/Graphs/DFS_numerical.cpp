#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>

using namespace std;


int main()
{
    int nodes, edges;

    cout << "Enter number of Nodes and Edges: " << endl;
    cin >> nodes >> edges;

    vector<int> adj[nodes + 1];

    cout << "Enter " << edges << " edges (A B):\n";
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);    // for undirected graph
    }

    vector<bool>visit(nodes + 1, 0);
    stack<int>st;

    int start;
    cout << "Enter Starting node: ";
    cin >> start;

    visit[start] = 1;
    st.push(start);

    cout << "DFS Traversal: ";
    while(!st.empty())
    {
        int u = st.top();
        st.pop();

        cout << u << " ";
        for(int v: adj[u])
        {
            if(!visit[v])
            {
                visit[v] = 1;
                st.push(v);
            }
        }

    }
    cout << endl;


    return 0;
}

