#include <iostream>
#include <bits/stdc++.h>
// adjacent list representation of graphs
// Using classes
using namespace std;
class graph
{

private:
    vector<pair<int, int>> *adj_list;

public:
    graph() {}
    graph(int n);
    void Add_edge();
    // void Remove_edge();
    void print_graph(int n);
};
graph::graph(int n)
{
    adj_list = new vector<pair<int, int>>[n];
}
void graph::Add_edge()
{
    int v1, v2, wt;
    cin >> v1 >> v2 >> wt;
    adj_list[v1].push_back({v2, wt});
    adj_list[v2].push_back({v1, wt});
}
void graph::print_graph(int n)
{
    for (int i = 1; i <= n; ++i)
    {
        cout << i << " -> ";
        for (auto &value : adj_list[i])
        {
            cout << "(" << value.first << " " << value.second << ")"
                 << " ";
        }
        cout << endl;
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
    g.print_graph(n);
    return 0;
}