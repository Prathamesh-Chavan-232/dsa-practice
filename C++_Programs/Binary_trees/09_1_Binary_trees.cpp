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
    char contd = 'n';
    int data;

    cout << "Enter data for the node : ";
    cin >> data;
    root = new node(data);

    cout << "Do you want to add a child node for " << root->data << " (y/n) ? : ";
    cin >> contd;

    if (contd == 'y' || contd == 'Y')
    {
        char add_rt = 'y';

        cout << "Adding left child for " << root->data << endl;
        create_tree(root->left);

        cout << "Add right child for " << root->data << " (y/n) ? ";
        cin >> add_rt;

        if (add_rt == 'y' || add_rt == 'Y')
        {
            create_tree(root->right);
        }
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
    int ch;
    char contd = 'n';
    node *root;
    vector<int> res;
    cout
        << "MENU\n"
        << "----------------------------------\n"
        << "1. Create tree\n"
        << "2. Preorder traversal\n"
        << "3. Inorder traversal\n"
        << "4. Postorder traversal\n"
        << "5. Iterative Preorder traversal\n"
        << "6. Iterative Inorder traversal\n"
        << "7. Iterative Postorder traversal\n"
        << "-----------------------------------\n";
    do
    {

        cout << "    Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:

            create_tree(root);
            break;
        case 2:
            preorder(root);
            cout << endl;
            break;
        case 3:
            inorder(root);
            cout << endl;
            break;
        case 4:
            postorder(root);
            cout << endl;
            break;
        case 5:
            res = it_preorder(root);
            print_traversal(res);
            cout << endl;
            break;
        case 6:
            res = it_inorder(root);
            print_traversal(res);
            cout << endl;
            break;
        case 7:
            res = it_postorder1(root);
            print_traversal(res);
            cout << endl;
            break;

        default:
            cout << "Invalid case\n";
            break;
        }
        cout << "Do you want to continue (y/n) ? : ";
        cin >> contd;
    } while (contd == 'y' || contd == 'Y');

    return 0;
}