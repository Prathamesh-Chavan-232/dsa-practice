#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class node
{
    int data;
    node *left;
    node *right;

public:
    node() {}
    node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    friend void create_tree(node *&root);
    friend vector<vector<int>> all_traversals(node *&root);
};

void create_tree(node *&root)
{
    char isleft = 'n', isright = 'n';
    int data;
    cin >> data >> isleft >> isright;
    root = new node(data);
    if (isleft == 'y' || isleft == 'Y')
    {
        create_tree(root->left);
    }
    if (isright == 'y' || isright == 'Y')
    {
        create_tree(root->right);
    }
}

vector<vector<int>> all_traversals(node *&root)
{
    vector<vector<int>> res;
    if (root == NULL)
    {
        return res;
    }
    vector<int> pre, in, post;
    stack<pair<node *, int>> s;
    s.push({root, 1});

    while (!s.empty())
    {
        auto it = s.top();
        s.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->left != NULL)
            {
                s.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            s.push(it);
            if (it.first->right != NULL)
            {
                s.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    res.push_back(pre);
    res.push_back(in);
    res.push_back(post);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);   // input
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout); // output
#endif

    node *root;
    create_tree(root);
    vector<vector<int>> v = all_traversals(root);
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

        for (auto &value : v[i])
        {
            cout << value << " ";
        }
        cout << endl;
    }
    return 0;
}