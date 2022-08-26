#include <bits/stdc++.h>
using namespace std;

#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
template <typename... Args>
void logger(string varname, Args &&...values)
{
    cerr << varname << " = ";
    string delim = "";
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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
TreeNode *createTree();
TreeNode *deserialize(vector<string> &nodes);

vector<vector<int>> lvlOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == nullptr)
        return res;

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> lvl;
        int sz = q.size();
        for (int i = 0; i < sz; ++i)
        {
            TreeNode *curr = q.front();
            q.pop();

            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);

            lvl.push_back(curr->val);
        }
        res.push_back(lvl);
    }
    return res;
}
void solve()
{
    TreeNode *root = createTree();
    vector<vector<int>> res = lvlOrder(root);
    for (vector<int> lvl : res)
    {
        debcon(lvl);
    }
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
TreeNode *deserialize(vector<string> &nodes)
{
    if (nodes.size() == 0)
        return nullptr;
    TreeNode *root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
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
            q.push(leftNode);
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
            q.push(rightNode);
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