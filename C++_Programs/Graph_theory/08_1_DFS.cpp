#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class graph
{

private:
    vector<int> *adj_list;
    bool *vis;

public:
    graph() {}
    graph(int n);
    void Add_edge();
    void dfs(int vertex);
    void print_graph(int n);
};
graph::graph(int n)
{
    adj_list = new vector<int>[n];
    vis = new bool[n];
}
void graph::Add_edge()
{
    int v1, v2;
    cin >> v1 >> v2;
    adj_list[v1].push_back(v2);
    adj_list[v2].push_back(v1);
}



void graph::dfs(int vertex)
{
    cout << vertex << " ";
    vis[vertex] = true;
    // Take
    for (auto &child : adj_list[vertex])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    graph g(n + 1);

    for (int i = 0; i < m; ++i)
    {
        g.Add_edge();
    }
    g.dfs(1);
    return 0;
}