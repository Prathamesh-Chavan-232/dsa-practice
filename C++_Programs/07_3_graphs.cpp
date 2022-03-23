// Adjacency list representation of Graphs
// Using global variables
// Space complexity - O(V + E)

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
vector<pair<int, int>> graph[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1].push_back({v2, wt});
        graph[v2].push_back({v1, wt});
    }
    for (int i = 0; i <= n; ++i)
    {
        cout << i << " -> ";
        for (auto &value : graph[i])
        {
            cout << "(" << value.first << " " << value.second << ")"
                 << " ";
        }
        cout << endl;
    }
    return 0;
}