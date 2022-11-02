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
 * @brief- Handy tricks for performing useful arithimetic & logical operations using bits
 *         Using bitwise operators is usually faster than using other operators (e.g using << or >> instead of * or /)
 *
 */

// Global variables
vi graph[N];
bool vis[N];

// classes & functions
void printBin(int x)
{
    int n = log2(float(x)) + 1;
    for (int i = n - 1; i >= 0; --i)
    {
        cout << ((x >> i) & 1);
    }
    cout << "\n";
}

void code()
{
    int n;
    cin >> n;
    if (n & 1)
        cout << "odd\n";
    else
        cout << "even\n";

    // Mulitply by 2
    cout << (n << 1) << "\n";
    printBin(n << 1);

    // Divide by 2
    cout << (n >> 1) << "\n";
    printBin(n >> 1);

    // (hi + lo) >> 1; Can use this in binary search

    for (char i = 'A'; i <= 'E'; ++i)
    {
        cout << i << "\n";
        printBin(int(i));
    }
    for (char i = 'a'; i <= 'e'; ++i)
    {
        cout << i << "\n";
        printBin(int(i));
    }
    // printBin('A' | (1 << 5));
    // char a = 'A' | (1 << 5);

    // lowercase to uppercase
    char a = 'A' | ' ';

    // uppercasse lowercase
    char A = 'a' & '_';

    cout << a << "\n";
    cout << A << "\n";

    printBin(59);

    // clear, unset, set or toggle i LSBs from a number
    int num = 59, i = 1;
    int b = num & (~((1 << (i + 1)) - 1));
    printBin(b);

    // clear, unset, set or toggle i MSBs from a number
    i = 3;
    int c = num & ((1 << (i + 1)) - 1);
    printBin(c);
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
