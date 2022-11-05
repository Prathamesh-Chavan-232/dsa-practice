#include <bits/stdc++.h>
using namespace std;

// constants
const int N = 1e5 + 10;
const int mod = 1e9 + 7;

// global variables
vector<int> curr_cc;
vector<vector<int>> cc;
vector<int> graph[N];
bool vis[N];
// classes & functions
void Add_edge()
{
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}

void dfs(int vertex)
{
    if (vis[vertex])
        return;

    curr_cc.push_back(vertex);
    vis[vertex] = true;
    for (auto child : graph[vertex])
    {
        cerr << "par: " << vertex << ", child: " << child << "\n";
        dfs(child);
    }
}
void code()
{
    int ct = 0;
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; ++i)
    {
        Add_edge();
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!vis[i])
        {

            curr_cc.clear();
            dfs(i);
            cc.push_back(curr_cc);
        }
    }
    cout << cc.size() << "\n";
    for (auto &v : cc)
    {
        for (auto &i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
}

int main()
{
    auto start = chrono::steady_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("/home/falconcodes/prathamesh/programming/input.txt", "r", stdin);
    freopen("/home/falconcodes/prathamesh/programming/output.txt", "w", stdout);
    freopen("/home/falconcodes/prathamesh/programming/err.txt", "w", stderr);
#endif
    int t = 1;
    // cin >> t;
    while (t--)
    {
        code();
    }
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}
