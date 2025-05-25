#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

// Check Euler's Formula
bool Eulers(int V, int E)
{
    if (V < 3)
    {
        return false;
    }
    return E > (3 * V - 6);
}

// Check for K5
bool isK5(const vector<vector<int>> &adj, int V)
{
    if (V < 5)
    {
        return false;
    }

    for (int a = 0; a < V; ++a)
    {
        for (int b = a + 1; b < V; ++b)
        {
            for (int c = b + 1; c < V; ++c)
            {
                for (int d = c + 1; d < V; ++d)
                {
                    for (int e = d + 1; e < V; ++e)
                    {
                        vector<int> nodes = {a, b, c, d, e};
                        int edgeCount = 0;
                        for (int i = 0; i < 5; ++i)
                        {
                            for (int j = i + 1; j < 5; ++j)
                            {
                                if (find(adj[nodes[i]].begin(), adj[nodes[i]].end(), nodes[j]) != adj[nodes[i]].end())
                                {
                                    edgeCount++;
                                }
                            }
                        }
                        if (edgeCount == 10)
                        {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

// Check for K3,3 
bool isK33(const vector<vector<int>> &adj, int V)
{
    if (V < 6)
    {
        return false;
    }

    for (int a = 0; a < V; ++a)
    {
        for (int b = a + 1; b < V; ++b)
        {
            for (int c = b + 1; c < V; ++c)
            {
                for (int d = c + 1; d < V; ++d)
                {
                    for (int e = d + 1; e < V; ++e)
                    {
                        for (int f = e + 1; f < V; ++f)
                        {
                            vector<int> group1 = {a, b, c};
                            vector<int> group2 = {d, e, f};
                            int connections = 0;
                            for (int u : group1)
                            {
                                for (int v : group2)
                                {
                                    if (find(adj[u].begin(), adj[u].end(), v) != adj[u].end())
                                    {
                                        connections++;
                                    }
                                }
                            }
                            if (connections == 9)
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }
    return false;
}

// Main Planarity Check
bool isPlanar(int V, const vector<vector<int>> &adj)
{
    int E = 0;
    for (int i = 0; i < V; ++i)
        E += adj[i].size();
    E /= 2; // Each edge counted twice

    // Step 1: Euler's edge limit
    if (Eulers(V, E))
    {
        cout << "Too many edges: E > 3V - 6" << endl;
        return false;
    }

    // Step 2: Kuratowski subgraph check
    if (isK5(adj, V))
    {
        cout << "Graph contains a K5 subgraph." << endl;
        return false;
    }

    if (isK33(adj, V))
    {
        cout << "Graph contains a K3,3 subgraph." << endl;
        return false;
    }

    return true;
}

int main()
{
    int V, E;

    cout << "Number of Nodes and Edges: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);

    cout << "Enter " << E << " edges (u v):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (isPlanar(V, adj))
        cout << "Graph is Planar." << endl;
    else
        cout << "Graph is Non-Planar." << endl;

    return 0;
}
