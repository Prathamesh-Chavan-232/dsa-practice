#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
#define fo(i, n) for (ll i = 0; i < n; ++i)
#define Fo(i, k, n) for (ll i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define foreach(it, a) for (auto it = a.begin(); it != a.end(); it++)

// Shortenting stl function calls
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()

// Typdefs for containers
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef priority_queue<int> pqb;
typedef priority_queue<int, vector<int>, greater<int>> pqs;

// constants
const int mod = 1e9 + 7;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

vvi graph(N, vi(N)); // For Adjacency matrix
bool vis[N];

/**
 *   @brief-
 *           Perform a flood fill, a flood fill is an operation where we change the color
 *           (given value at image[i][j])
 *           of all the nodes {i,j} that've an edge b/w them.
 *
 *           Here Nodes of the graph are represented by a M by N grid & each cell of the matrix is a vertex.
 *           If 2 vertices (nodes) have the same color then they're connected.
 *           Given a source to start from we need to change the color of all the nodes connected to it.
 */
// classes & functions
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int iclr = image[sr][sc];
        dfs(image, sr, sc, iclr, color);
    }

    void dfs(vvi image, int i, int j, int iclr, int fclr)
    {
        int n = image.size();
        int m = image[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m) // return if out of bounds
            return;
        if (image[i][j] != iclr) // return if arent same color
            return;

        image[i][j] = fclr; // Chanage the color of connected node.

        dfs(image, i - 1, j, iclr, fclr);
        dfs(image, i + 1, j, iclr, fclr);
        dfs(image, i, j - 1, iclr, fclr);
        dfs(image, i, j + 1, iclr, fclr);
    }
};

void code()
{
    int fClr, n, m;
    cin >> n >> m;
    vvi image(n, vi(m));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> image[i][j];
        }
    }
    Solution s;
    int sr, sc, fclr;
    cin >> sr >> sc >> fclr;
    s.floodFill(image, sr, sc, fclr);
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

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}