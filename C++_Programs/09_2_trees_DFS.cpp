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
    friend void preorder(node *&root);
    friend void inorder(Node *&root);
    friend void postorder(Node *&root);
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


int main()
{
    node *root;
    create_tree(root);
    preorder(root);
    inorder(root);
    postorder(root);
    return 0;
}