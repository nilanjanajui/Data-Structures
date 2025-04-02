#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<algorithm>

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

    map<char, bool>visit;
    stack<char>st;

    char start;
    cout << "Enter Starting node: ";
    cin >> start;

    visit[start] = 1;
    st.push(start);

    cout << "DFS Traversal: ";
    while(!st.empty())
    {
        char u = st.top();
        st.pop();

        cout << u << " ";
        for(char v: adj[u])
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

