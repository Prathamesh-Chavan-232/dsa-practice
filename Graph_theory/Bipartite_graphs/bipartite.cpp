#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>> adj, int src = 0)
{
    int *color = new int[adj.size()]{0}; // 0 is not colored, 1 is red, -1 is blue
    color[src] = 1;                      // color source red
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto v : adj[u])
        {
            if (!color[v])
            {
                q.push(v);
                color[v] = color[u] * (-1); // Giving the opposite color
            }
            else
            {
                if (color[v] == color[u]) // if same colored as src then return false(not bipartite)
                    return false;
            }
        }
    }
    return true;
}

int main()
{
    int n, m; // n- no of vertices,  m- no of edges
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // first field is adj matrix, second field is source vertex
    isBipartite(adj, 0) ? cout << "YES\n" : cout << "NO\n";

    return 0;
}
