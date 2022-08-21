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
    cerr << "\n";
}

// STL vector / set (of any type) debugger
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
    for (auto it = c.begin(); it != c.end(); it++)
    {
        cerr << *it;
        it == --c.end() ? cerr << "" : cerr << ", ";
    }
    cerr << "}";
}

// Data structures
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
// Function declarations
TreeNode *deserialize(vector<string> &nodes);
TreeNode *createTree();

// Function definitions
void Add_edge(int v1, int v2);
void dfs(int vertex);

// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

vi graph[N]; // For Adjacency List
bool vis[N];

/*
    Link -
    Problem -
    Difficulty -
    contest -
    Status -
    Date -
*/
/*  Approach -

*/

vector<int> inOrder(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    stack<TreeNode *> st;
    TreeNode *curr = root;
    while (true)
    {
        if (curr != nullptr)
        {
            debug(curr->val);
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            curr = curr->right;
        }
    }
    return res;
}
void code()
{
    TreeNode *root = createTree();
    vector<int> res = inOrder(root);
    debcon(res);
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
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}

TreeNode *deserialize(vector<string> &nodes)
{
    if (nodes.size() == 0)
        return nullptr;
    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> st;
    st.push(root);
    int i = 1;
    while (!st.empty())
    {
        TreeNode *node = st.front();
        st.pop();
        if (i >= nodes.size())
            break;
        string str = nodes[i++];
        if (str == "#")
        {
            node->left = nullptr;
        }
        else
        {
            TreeNode *leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            st.push(leftNode);
        }
        if (i >= nodes.size())
            break;
        str = nodes[i++];
        if (str == "#")
        {
            node->right = nullptr;
        }
        else
        {
            TreeNode *rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            st.push(rightNode);
        }
    }
    return root;
}
TreeNode *createTree()
{
    string s;
    getline(cin, s);
    vector<string> nodes;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] == ',' || s[i] == '[' || s[i] == ']' || s[i] == ' ')
            continue;
        else
        {
            string str(1, s[i]);
            nodes.push_back(str);
        }
    }
    TreeNode *root = deserialize(nodes);
    return root;
}