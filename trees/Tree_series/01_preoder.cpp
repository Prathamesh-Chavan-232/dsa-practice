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
typedef vector<int> vi;
typedef vector<ll> vl;

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

// Function declarations
BinTree *createTree(vector<int> &nodes);

// classes & functions
void pre(BinTree *root, vi &res)
{
    if (root == nullptr)
        return;

    res.pb(root->val);
    pre(root->left, res);
    pre(root->right, res);
}

vector<int> preorderIt(BinTree *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    stack<BinTree *> st;
    st.push(root);

    while (!st.empty())
    {

        int n = st.size();
        for (int i = 0; i < n; ++i)
        {
            BinTree *node = st.top();
            st.pop();

            if (node->right != nullptr)
                st.push(node->right);
            if (node->left != nullptr)
                st.push(node->left);
            res.push_back(node->val);
        }
    }
    return res;
}

template <typename T>
void printTraversal(vector<T> &v)
{
    int n = v.size();
    cout << "[";
    for (int i = 0; i < n; ++i)
    {
        cout << v[i];
        i == n - 1 ? cout << "" : cout << ", ";
    }
    cout << "]\n";
}

void code()
{
    cout << "Solving...\n";
    vi nodes;
    inVec(nodes);
    BinTree *root = createTree(nodes);
    vi preorder;
    pre(root, preorder);
    vi itPre = preorderIt(root);
    cout << "Preorer traversal...\n";
    printTraversal(preorder);
    cout << "Iterative Preorer traversal...\n";
    printTraversal(itPre);
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
    freopen("/home/falcon_codes/prathamesh/programming/input.txt", "r", stdin);
    freopen("/home/falcon_codes/prathamesh/programming/output.txt", "w", stdout);
    freopen("/home/falcon_codes/prathamesh/programming/err.txt", "w", stderr);
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

BinTree *createTree(vector<int> &nodes)
{
    if (nodes.size() == 0)
        return nullptr;
    BinTree *root = new BinTree(nodes[0]);
    queue<BinTree *> q;
    q.push(root);
    int i = 1;
    while (!q.empty())
    {
        BinTree *node = q.front();
        q.pop();
        if (i >= nodes.size())
            break;
        int val = nodes[i++];
        if (val == -1)
        {
            node->left = nullptr;
        }
        else
        {
            BinTree *leftNode = new BinTree(val);
            node->left = leftNode;
            q.push(leftNode);
        }
        if (i >= nodes.size())
            break;
        val = nodes[i++];
        if (val == -1)
        {
            node->right = nullptr;
        }
        else
        {
            BinTree *rightNode = new BinTree(val);
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}