#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> adj_list[N];
bool vis[N];

void Add_edge()
{
    int v1, v2;
    cin >> v1 >> v2;
    adj_list[v1].push_back(v2);
    adj_list[v2].push_back(v1);
}

void dfs(int vertex)
{
    if (vis[vertex]) return;

    cout << vertex << " ";
    vis[vertex] = true;
    /** Take action on the vertex after entering
     *   the vertex
     **/
    for (auto child : adj_list[vertex])
    {
        cerr << "par: " << vertex << ", child: " << child << "\n";
        /** Take action on the child after entering
         *   the child
         **/
    
        dfs(child);
        /** Take action on the child before exiting
         *   the child
         **/
    }
    /** Take action on the vertex before exiting
     *   the vertex
     **/
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        Add_edge();
    }
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        dfs(i);
    }
    return 0;
}