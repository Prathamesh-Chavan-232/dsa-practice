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
    friend bool isBST(node *&root);
    friend void inorder(node *&root);
    friend void insert_BST(node *&root, node *&prev, int key);
    friend node *search_BST(node *&root, int key);
    friend node *insert(node *root, int key);
    friend node *delete_BST(node *root, int key);
    friend node *inorderPre(node *root);
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

void inorder(node *&root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool isBST(node *&root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return false;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return false;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return true;
    }
}

node *search_BST(node *&root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search_BST(root->left, key);
    }
    else
    {
        return search_BST(root->right, key);
    }
}

void insert_BST(node *&root, node *&prev, int key)
{

    if (root == NULL)
    {
        node *temp = new node(key);
        if (prev == NULL)
        {
            root = temp;
        }
        if (key < prev->data)
        {

            prev->left = temp;
        }
        else
        {
            prev->right = temp;
        }
        cout << "node inserted\n";
        return;
    }
    if (key == root->data)
    {
        cout << "Already exists\n";
        return;
    }
    else if (key < root->data)
    {
        insert_BST(root->left, root, key);
    }
    else
    {
        insert_BST(root->right, root, key);
    }
}

node *insert(node *root, int key)
{
    if (root == NULL)
    {
        return new node(key);
    }
    if (key < root->data)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert(root->right, key);
    }
    return root;
}

node *inorderPre(node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}
node *delete_BST(node *root, int key)
{
    node *prev;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right)
    {
        free(root);
        return NULL;
    }

    // Search for the node to be deleted
    if (key < root->data)
    {
        root->left = delete_BST(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = delete_BST(root->right, key);
    }

    // Deletion stratergy
    else
    {
        prev = inorderPre(root);
        root->data = prev->data;
        root->left = delete_BST(root->left, prev->data);
    }
    return root;
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
    cout << isBST(root) << endl;

    inorder(root);
    cout << endl;

    int key = 13;
    root = delete_BST(root, 13);

    inorder(root);
    cout << endl;

    return 0;
}