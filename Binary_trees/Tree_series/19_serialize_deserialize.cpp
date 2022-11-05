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
    void createTree(TreeNode *root);
    vector<int> pre(TreeNode *root);
    TreeNode *deserialize(vector<string> serial);
};

void createTree(TreeNode *&root)
{
    char left = 'n', right = 'n';
    int val;
    cin >> val >> left >> right;
    root = new TreeNode(val);
    if (left == 'y' || left == 'Y')
    {
        createTree(root->left);
    }
    if (right == 'y' || right == 'Y')
    {
        createTree(root->right);
    }
}

vector<string> serialize(TreeNode *root)
{
    cout << "Serializing...\n";
    vector<string> serial;
    if (root == nullptr)
        return serial;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();
        if (node == nullptr)
            serial.push_back("#");
        else
            serial.push_back(to_string(node->val));

        if (node != nullptr)
        {
            q.push(node->left);
            q.push(node->right);
        }
    }
    return serial;
}

TreeNode *deserialize(vector<string> &serial)
{
    cout << "Deserializing...\n";
    if (serial.size() == 0)
        return nullptr;
    TreeNode *root = new TreeNode(stoi(serial[0]));
    queue<TreeNode *> q;
    q.push(root);
    int i = 1;
    while (!q.empty())
    {
        TreeNode *node = q.front();
        q.pop();

        string str = serial[i++];
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
        str = serial[i++];
        debug(str, i);
        debug("lol");

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
template <typename T>
void printRes(vector<T> &v)
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
void solve()
{
    cout << "Solving...\n";
    TreeNode *root;
    createTree(root);
    vector<string> serial = serialize(root);
    printRes(serial);
    TreeNode *node = deserialize(serial);
    vector<int> preorder = pre(node);
    printRes(preorder);
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
