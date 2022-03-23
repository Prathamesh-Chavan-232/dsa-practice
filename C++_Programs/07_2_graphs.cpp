// Adjacency matrix representation of Graphs
// using global variables.
// Disadvantage - Space complexity O(n^2)
// vertices maximum - 10e3
#include <iostream>
#include <bits/stdc++.h>
const int N = 1e3;
int graph[N][N];
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int v1, v2, wt;
        cin >> v1 >> v2 >> wt;
        graph[v1][v2] = wt;
        graph[v2][v1] = wt;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}