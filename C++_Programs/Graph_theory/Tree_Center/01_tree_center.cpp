#include <bits/stdc++.h>
using namespace std;

void solve()
{
    const int N = 1e3;       // Number of nodes in graph
    const int INF = INT_MAX; // Infinity
    int d[N][N];             // Distances between nodes
    int e[N];                // Eccentricity of nodes
    set<int> c;              // Center of graph
    int rad = INF;           // Radius of graph
    int diam;                // Diamater of graph

    // Floyd-Warshall's algorithm
    for (int k = 0; k < N; k++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int i = 0; i < N; i++)
            {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }

    // Counting values of eccentricity
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            e[i] = max(e[i], d[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        rad = min(rad, e[i]);
        diam = max(diam, e[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (e[i] == rad)
        {
            c.insert(i);
        }
    }
}
int main()
{
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}