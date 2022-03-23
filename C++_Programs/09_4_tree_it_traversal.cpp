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
    friend vector<int> it_preorder(node *&root);
    friend vector<int> it_inorder(node *&root);
    friend vector<int> it_postorder1(node *&root); // using 1 stack
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
                break; // we use this instead of while(!s.empty()) because when we pop 1 the stack will be empty but it will have right node(s)
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
    do
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
    } while (!s.empty());
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
    vector<int> v = it_postorder1(root);
    for (auto &value : v)
    {
        cout << value << " ";
    }
    return 0;
}