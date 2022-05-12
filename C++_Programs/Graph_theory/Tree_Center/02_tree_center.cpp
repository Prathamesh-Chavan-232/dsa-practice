#include <iostream>
#include <vector>
using namespace std;

vector<int> treeCenter(vector<vector<int>> adj)
{
    int n = adj.size(), count = 0;
    int *degree = new int[n]{0};
    vector<int> leaves;
    for (int u = 0; u < n; u++)
    {
        degree[u] = adj[u].size(); // Counting degree of every node by taking number of elements in adj list for each node
        if (degree[u] < 2)
        { // If degree less than 2 then its a leaf node
            leaves.push_back(u);
            degree[u] = 0;
        }
    }
    count += leaves.size(); // Adding no of nodes traversed

    while (count < n)
    {
        vector<int> new_leaves;
        for (auto u : leaves)
        { // Taking each leaf node from leaves
            for (auto v : adj[u])
            {                       // Traversing all neighbours of each leaf node
                degree[v]--;        // Decrement their degree as one of its neighbour(the leaf node) is deleted
                if (degree[v] == 1) // If degree of a node is then its a leaf node
                    new_leaves.push_back(v);
            }
        }
        count += new_leaves.size(); // Adding no of nodes traversed
        leaves = new_leaves;
    }

    return leaves;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    int n, m; // n - no of vertices,  m - no of edges
    cin >> n >> m;
    vector<vector<int>> adj(n);
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> tree_center = treeCenter(adj);
    cout << "The center(s) of the tree is: ";
    for (auto node : tree_center) // Tree center can be one or two node which will be returned in a int vector
        cout << node << " ";

    return 0;
}