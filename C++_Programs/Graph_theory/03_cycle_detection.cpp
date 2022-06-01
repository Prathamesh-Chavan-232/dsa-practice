#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> graph[N];
bool vis[N];

void Add_edge()
{
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}

bool dfs(int vertex, int par)
{
    vis[vertex] = true;
    bool isLoopExists = false;
    for (auto &child : graph[vertex])
    {
        if (vis[child] && child == par)
            continue;

        else if (vis[child])
            return true;

        isLoopExists |= dfs(child, vertex);
    }
    return isLoopExists;
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

    int ct = 0;
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        Add_edge();
    }
    bool isLoopExists = false;
    for (int i = 1; i <= n; ++i)
    {
        if (vis[i])
            continue;
        if (dfs(i, 0))
        {
            isLoopExists = true;
        }
        cout << isLoopExists << "\n";
        isLoopExists = false;
    }
    return 0;
}