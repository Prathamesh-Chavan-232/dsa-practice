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

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

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

TreeNode *deserialize(vector<string> &nodes)
{
    cout << "Deserializing...\n";
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
        debug(str, i);
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
        debug(str, i);

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
            debug(str);
            nodes.push_back(str);
        }
    }
    printTraversal(nodes);
    TreeNode *root = deserialize(nodes);
    return root;
}

vector<int> pre(TreeNode *root)
{
    vector<int> res;
    if (root == nullptr)
        return res;

    stack<TreeNode *> st;
    st.push(root);

    while (!st.empty())
    {

        int n = st.size();
        for (int i = 0; i < n; ++i)
        {
            TreeNode *node = st.top();
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
void solve()
{
    cout << "Solving...\n";
    TreeNode *root = createTree();
    vector<int> preorder = pre(root);
    cout << "Preorer traversal...\n";
    printTraversal(preorder);
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