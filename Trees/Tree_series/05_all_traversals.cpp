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

// Function declarations
BinTree *createTree(vector<int> &nodes);

/**
 * @brief -
 *      Calculates all 3 traversals in one flow
 ** @approach -
 * push nodes in the stack along with a corresponding number
 *   1 -> pre, 2 -> in, 3 -> post
 * push {root,1}
 * if num == 1
 *   pre.pb(root), num++ & push root->left
 * if num == 2
 *   in.pb(root), num++ push root->right
 * if num == 3
 *   post.pb(root)
 * @param root
 * @return vvi - vectors containing pre, in & post order traversals
 */

// classes & functions
vvi allTraversals(BinTree *root)
{

    vvi all;
    if (root == nullptr)
        return all;
    vi pre, in, post;
    stack<pair<BinTree *, int>> st;
    st.push({root, 1});
    while (!st.empty())
    {
        auto &[curr, order] = st.top();
        st.pop();
        if (order == 1)
        {
            st.push({curr, ++order});
            pre.pb(curr->val);

            if (curr->left)
                st.push({curr->left, 1});
        }
        else if (order == 2)
        {
            st.push({curr, ++order});
            in.pb(curr->val);

            if (curr->right)
                st.push({curr->right, 1});
        }
        else
            post.pb(curr->val);
    }
    all.pb(pre);
    all.pb(in);
    all.pb(post);
    return all;
}

void code()
{
    vi nodes;
    inVec(nodes);
    debvec(nodes);
    BinTree *root = createTree(nodes);
    vvi all = allTraversals(root);
    for (vi travs : all)
    {
        debvec(travs);
    }
    for (int i = 0; i < 3; ++i)
    {

        if (i == 0)
        {
            cout << "Preorder: ";
        }
        else if (i == 1)
        {
            cout << "Inorder: ";
        }
        else
        {
            cout << "Postorder: ";
        }

        for (auto &value : all[i])
        {
            cout << value << " ";
        }
        cout << endl;
    }
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