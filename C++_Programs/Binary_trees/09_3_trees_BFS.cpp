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
    vector<vector<int>> lvl_order();
};

vector<vector<int>> node ::lvl_order()
{
    vector<vector<int>> res; // vector of vector for storing lvls

    if (this == NULL) // if root is NULL then return empty vector
        return res;

    queue<node *> q;

    q.push(this); // push root node in queue

    while (!q.empty())
    {
        int n = q.size();
        vector<int> lvl;

        for (int i = 0; i < n; ++i) // storing a lvl
        {
            node *temp = q.front();    // take top element from the queue and store in the lvl
            lvl.push_back(temp->data); // push element in its lvl
            q.pop();

            if (temp->left != NULL) // if left isnt null, push it to queue for popping in next iteration
                q.push(temp->left);

            if (temp->right != NULL) // if right isnt null, push it to queue for popping in next iteration
                q.push(temp->right);
        }
        res.push_back(lvl); // add lvl to vector of lvls
    }
    return res;
}

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

int main()
{
    node *root;
    create_tree(root);

    vector<vector<int>> v;
    v = root->lvl_order();

    for (int i = 0; i < v.size(); ++i) // printing all lvls
    {
        for (int j = 0; j < v[i].size(); ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}