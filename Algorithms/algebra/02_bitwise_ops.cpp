#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define ll long long
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

// Container input tools
void inVec(vector<int> &v)
{
    string s;
    getline(cin, s);
    int num = 0, sign = 1;

    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == '[' || s[i] == ']')
            continue;
        if (s[i] == '-')
            sign = -1;
        else if (s[i] == ',' || s[i] == ' ')
            v.push_back(num), num = 0;
        else
        {
            num = num * 10 + (s[i] - '0');
            num *= sign;
            sign = 1;
        }
    }
    v.push_back(num);
}

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
    cerr << "\n";
}

// debugger for STL vector / set (of any type)
#ifndef ONLINE_JUDGE
#define debcon(x)        \
    cerr << #x << " = "; \
    _print(x);           \
    cerr << "\n";
#else
#define debcon(x)
#endif
template <typename T>
void _print(T const &c)
{
    cerr << "{ ";
    foreach (it, c)
    {
        it != --c.end() ? cerr << *it << ", " : cerr << *it;
    }
    cerr << "}";
}

// Data structures
struct BinTree
{
    int val;
    BinTree *left;
    BinTree *right;
    BinTree() {}
    BinTree(int val) : val(val), left(nullptr), right(nullptr) {}
};

// constants
const int mod = 1e9 + 7;
const int N = 1e5 + 10, M = N;
const double PI = 3.1415926535897932384626;

/**
 * @brief-
 *      Binary numbers & Bitwise Operators
 * 1. Convert Decimal to Binary
 *      (num >> i) & 1 tells us if ith bit is set or not
 *              e.g 9 & (1 >> 2)  = 1001 & 0100 = 0
 * 2. Set & Unset bit
 *
 *
 */

// Global variables
vi graph[N];
bool vis[N];

// classes & functions
vi convertToBin(ll x)
{
    ll n = ceil(log2((float)x)); // No of digits in the binary num = wt of last digit + 1
    vi bin(n);
    debug(n);
    for (int i = n - 1; i >= 0; --i) // reverse for since we print from msb to lsb
    {

        int bit = (x >> i) & 1;
        debug(i, bit);
        cout << bit;
        bin[i] = bit; // 1st element -> MSB
        // can also be done using left shift but this method is more intuitive
        // and we can store in an array & print at the same time.
    }
    cout << "\n";
    return bin;
}

void code()
{
    int x;
    cin >> x;
    // Convert Decimal to Binary
    vi res = convertToBin(x); // store return value

    // Set ith bit
    convertToBin(x | (1 << 2));

    // Unset ith bit
    convertToBin(x & ~(1 << 2));

    // toggle bit
    convertToBin(x ^ (1 << 2));

    cout << __builtin_popcountll(x) << "\n";
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
