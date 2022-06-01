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
typedef vector<pii> vpii;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef map<int, int> mii;
typedef map<ll, ll> ml;
typedef set<ll> sl;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> uml;
typedef unordered_set<ll> usl;

// Debugging tools

// Varidiac Variable debugger
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

// Varadiac I/O
template <typename... T>
void r(T &...args)
{
    ((cin >> args), ...);
}
template <typename... T>
void w(T &&...args)
{
    ((cout << args << " "), ...);
    cout << "\n";
}

// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

vi arr; // Array to store heap

void printHeap()
{
    Fo(i, 1, arr.size()) cout << arr[i] << " ";
    cout << "\n";
}

void heapify(int n, int root)
{
    int largest = root; // ideally root should be the largest
    int l = 2 * root, r = 2 * root + 1;
    debug(l, r);
    if (arr[l] > arr[largest] && l < n)
    {
        largest = l; // left node is greater than root
    }
    if (arr[r] > arr[largest] && r < n)
    {
        largest = r; // right node is greater than left node
    }
    if (largest != root)
    {
        swap(arr[largest], arr[root]);
        heapify(n, largest);
    }
}
void makeHeap()
{
    int startIndx = (arr.size() - 1) / 2; // starting at the first non - leaf node
    Fo(i, startIndx, 0)
    {
        heapify(arr.size(), i);
    }
}
void heapsort()
{
    Fo(i, arr.size() - 1, 0)
    {
        swap(arr[1], arr[i]);
        heapify(i, 1);
    }
}
void solve()
{
    int n;
    cin >> n;
    Fo(i, 1, n + 1)
    {
        int temp;
        cin >> temp;
        arr.pb(temp);
    }
    makeHeap();
    printHeap();

    heapsort();
    printHeap();
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
        solve();
    }

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}