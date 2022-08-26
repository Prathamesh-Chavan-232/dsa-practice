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
    friend void print_traversal(vector<int> v);
    friend void create_tree(node *&root);
    friend void preorder(node *&root);
    friend void inorder(node *&root);
    friend void postorder(node *&root);
    friend vector<int> it_preorder(node *&root);
    friend vector<int> it_inorder(node *&root);
    friend vector<int> it_postorder1(node *&root);
};

void create_tree(node *&root)
{
    char left = 'n', right = 'n';
    int data;
    cin >> data >> left >> right;
    root = new node(data);
    if (left == 'y' || left == 'Y')
    {
        create_tree(root->left);
    }
    if (right == 'y' || right == 'Y')
    {
        create_tree(root->right);
    }
}

void preorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(node *&root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
vector<int> it_preorder(node *&root)
{
    vector<int> res;
    if (root == NULL)
        return res;
    stack<node *> s;
    s.push(root);
    while (!s.empty())
    {
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            node *temp = s.top();
            s.pop();

            if (temp->right != NULL)
                s.push(temp->right);

            if (temp->left != NULL)
                s.push(temp->left);

            res.push_back(temp->data);
        }
    }
    return res;
}

vector<int> it_inorder(node *&root)
{
    vector<int> res;
    if (root == NULL)
    {

        return res;
    }
    stack<node *> s;
    node *temp = root;
    while (true)
    {
        // s.push(temp); can't push here because it will also try to push null to the stack.
        if (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
        else
        {
            if (s.empty())
            {
                break; // we use this instead of while(!s.empty()) because when we pop the root stack will be empty but it will have right node(s)
            }
            temp = s.top();
            s.pop();
            res.push_back(temp->data);
            temp = temp->right;
        }
    }
    return res;
}
vector<int> it_postorder1(node *&root)
{
    vector<int> res;
    if (root == NULL)
    {
        return res;
    }
    stack<node *> s;
    node *curr, *temp;
    curr = root;
    while (!s.empty())
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            temp = s.top()->right;
            if (temp == NULL)
            {
                temp = s.top();
                s.pop();
                res.push_back(temp->data);
                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    res.push_back(temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return res;
}

void print_traversal(vector<int> v)
{
    for (auto &value : v)
    {
        cout << value << " ";
    }
}

int main()
{
    node *root;
    create_tree(root);
    preorder(root);
    inorder(root);
    postorder(root);
    return 0;
}