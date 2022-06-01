#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, v) for (ll i = 0; i < v; ++i)
#define Fo(i, k, v) for (ll i = k; k < v ? i < v : i > v; k < v ? ++i : --i)
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
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " =";
    string delim = " ";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\v";
}

// STL vector / set (of any type) debugger
#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\v";
#else
#define debcon(x)
#endif
template <typename T>
void _print(T const &c)
{
    cerr << "{ ";
    foreach (it, c)
    {
        cerr << *it << ", ";
    }
    cerr << "}";
}

// Function definitions
void Add_edge(int v1, int v2, int w);
void dfs(int vertex);

// constants
const int mod = 1'000'000'007;
const int v = 1e7, M = v;
const double PI = 3.1415926535897932384626;

vpii graph[v]; // For Adjacency List
bool vis[v];

/*  Approach -

    Single Source shortest path algorithm -
        Start from Source node - Set distance till every node as infinity,
        Check all neighbours of current node,if their distance can be minimized, we minimize it & add it to priority_queue
        Once all the neighbours of current node are checked, we mark it as visited (we dont try to minimize its distance anymore)
        (we can do this right when we start checking its neighbours)

*/

void dijkstra(int v, int k)
{
    priority_queue<pii, vpii, greater<pii>> pq; // store -> {distance from source, node}
    vi dist(v + 1, INT_MAX);
    pq.push({0, k});
    dist[k] = 0;
    while (!pq.empty())
    {
        pii top = pq.top();
        pq.pop();
        int u = top.second;                       //  select closest node
        vis[u] = true;                            // mark node as visited;
        for (int i = 0; i < graph[u].size(); ++i) // checking every neighbour of current node
        {
            int v = graph[u][i].first;       // neighbour node
            int weight = graph[u][i].second; // distance if neighbour from source node
            if (dist[v] > dist[u] + weight && !vis[v])
            {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    for (int i = 1; i < dist.size(); ++i)
    {
        cout << i << " " << dist[i] << "\n";
    }
}
void code()
{
    int v, e, k;
    cin >> v >> e >> k;
    fo(i, e)
    {
        int v1, v2, w;
        cin >> v1 >> v2 >> w;
        Add_edge(v1, v2, w);
    }
    dijkstra(v, k);
}

int main()
{
    // Start time
    auto start = chrono::steady_clock::now();

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// Input, Output & error messages inside text files
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    // Running for multiple testcases / queries
    int t = 1;
    // cin >> t;
    while (t--)
    {
        code();
    }

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]";
#endif
    return 0;
}

void Add_edge(int v1, int v2, int w)
{
    graph[v1].push_back({v2, w});
    // graph[v2].push_back({v1, w});
}