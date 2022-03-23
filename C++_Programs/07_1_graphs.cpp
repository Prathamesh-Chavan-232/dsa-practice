// Graphs using adjacency matrix and classes
// Disadvantage - Takes O(n^2) time complexity and space complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph
{
    vector<vector<int>> adj;

public:
    graph() {}
    graph(int n)
    {
        adj.resize(n);
        for (int i = 0; i < n; ++i)
        {
            adj[i].resize(n);
        }
    }
    void Add_edge()
    {
        int a, b;
        cin >> a >> b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    void Remove_edge()
    {

        int a, b;
        cin >> a >> b;
        adj[a][b] = 0;
        adj[b][a] = 0;
    }
};
int main()
{
    int n, m; // n - no of vertices, m - no of edges
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; ++i)
    {
        g.Add_edge();
    }
    return 0;
}