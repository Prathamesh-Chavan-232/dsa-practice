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

/**
 * @brief
 *  Inorder traversal - left root right
 * Iterative approach -
     *      start by thinking how the recursive fn will make use of the auxillary stack.

     *      since we need to clear the left-most side first, if node has a left, we move to the left
            we push these each of these left children to a stack. so we can pop them in the correct order

     *      when a node's left is null or the curr node is null. our left is cleared. means its time for the root
            which would be stack's top, we retrieve it and root is cleared.

    *       Now we need to check for the right. After this,
            Same process shall repeat.
 */

// classes & functions
void in(BinTree *root, vi &res)
{
    if (root == nullptr)
        return;

    // left -> root -> right
    in(root->left, res);
    res.pb(root->val);
    in(root->right, res);
}

vi inorderIt(BinTree *root)
{
    vi res;
    if (root == nullptr)
        return res;

    BinTree *curr = root;
    stack<BinTree *> st;
    // we don't directly push the root node since we can't impose !st.empty() as the condition.
    while (true)
    {
        if (curr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            // if no more roots are present then the tree is traversed
            if (st.empty())
                break;
            curr = st.top();
            st.pop();
            res.pb(curr->val);
            curr = curr->right;
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
    vi inorder;
    in(root, inorder);
    vi itIn = inorderIt(root);
    cout << "Inorder traversal...\n";
    printTraversal(inorder);
    cout << "Iterative inorder traversal...\n";
    printTraversal(itIn);
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