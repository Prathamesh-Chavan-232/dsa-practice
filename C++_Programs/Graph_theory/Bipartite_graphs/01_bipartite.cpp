#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define pb push_back
#define mp make_pair
#define pqb priority_queue<int>
#define pqs priority_queue<int, vector<int>, greater<int>>
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define formap(m) for (auto [key, value] : m)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// Typdefs for containers
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;

// Debugging tools
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif

#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif

// Function definitions
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

template <typename T>
void _print(T const &c) // print any type of vector / set
{
    cerr << "{ ";
    foreach (it, c)
        cerr << *it << ", ";
    cerr << "}";
}

// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

/*  Bipartite Graphs

    Standard Definition -

    Simple Definition - A graph that can be colored with 2 colors, such that
                 no adjacent nodes have the same color

    Notes -
        * A graph with an odd length cycle can't be a bipartite graph
        * Every graph without an odd length cycle is a bipartite graph

*/

class graph
{

private:
    vi *adj_list;
    bool *vis;

public:
    graph() {}
    graph(int n);
    void Add_edge();
    void dfs(int vertex);
    void bfs(int vertex);
    void print_graph(int n);
};
graph::graph(int n)
{
    adj_list = new vi[n];
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

    for (auto &child : adj_list[vertex])
    {
        if (!vis[child])
        {
            dfs(child);
        }
    }
}
void solve()
{
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
    cin >> t;
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