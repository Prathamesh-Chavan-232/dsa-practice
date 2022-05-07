#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define ll long long
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)

// Typdefs for containers
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

// Function declarations
template <typename... Args>
void logger(string varname, Args &&...values);

template <typename T>
void _print(T const &c);

template <typename... T>
void r(T &...args);

template <typename... T>
void w(T &&...args);

// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

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
void _print(T const &c) // print any STL container
{
    cerr << "{";
    tr(it, c) cerr << *it << ", ";
    cerr << "}";
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

class maxHeap
{
    vi arr = {0};
    int size = 1;

public:
    maxHeap() {}
    void createMaxHeap(int n);
    void insert(int val);
    void deleteRoot();
    void heapify();
    void printHeap();
    void heapsort();
};
void maxHeap::printHeap()
{
    Fo(i, 1, size) cout << arr[i] << " ";
    cout << "\n";
}
void maxHeap::insert(int val)
{
    arr.pb(val);
    size++;
    int i = size - 1;
    while (i > 1)
    {
        if (arr[i] > arr[i / 2])
        {
            swap(arr[i], arr[i / 2]);
            i /= 2;
        }
        else
        {
            break;
        }
    }
}
void maxHeap::createMaxHeap(int n)
{
    Fo(i, 1, n + 1)
    {
        int temp;
        cin >> temp;
        insert(temp);
    }
}
void maxHeap::deleteRoot()
{

}

void maxHeap::heapsort()
{
    
}

void solve()
{
    int n;
    cin >> n;
    maxHeap h;
    h.createMaxHeap(n);
    h.printHeap();
    h.insert(12);
    h.printHeap();
    // h.deleteRoot();
    // h.printHeap();
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