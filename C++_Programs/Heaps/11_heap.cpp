#include <bits/stdc++.h>
using namespace std;

// Shortening syntax
#define fo(i, n) for (int i = 0; i < n; ++i)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? ++i : --i)
#define ll long long
#define pb push_back

// Typdefs for containers
typedef vector<int> vi;
typedef vector<ll> vl;

// Debugging tools
#ifndef ONLINE_JUDGE
#define debug(...) logger(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...)
#endif

// Function definitions
template <typename... Args>
void logger(string varname, Args &&...values) // logger for varadiac debugging print statements
{

    cerr << varname << " = ";
    string delim = "";
    (..., (cerr << delim << values, delim = ", "));
    cerr << "\n";
}

template <typename... T>
void r(T &...args)
{
    ((cin >> args), ...);
}

template <typename... T>
void w(T &&...args)
{
    ((cout << args), ...);
}

// constants
const int mod = 1'000'000'007;
const int N = 1e7, M = N;
const double PI = 3.1415926535897932384626;

/*
  * Heaps & Heapsort *
    Theory -
        Heap -
            A heap is a sequential data structure implemented using complete binary tree
             Heap is just array representation of a complete binary tree

        Complete Binary Tree -
            Binary tree whose all nodes until the level (height - 1) are completely filled
            & the nodes in the last level are strictly filled from left to right

        Heapsort -
            Heapsort is a sorting technique used on heaps, deleting the root of heap and inserting it
            at the free space at the back for every element of the heap results in a sorted array
            maxheap - sorts in ascending order
            minheap - sorts in descending order

    Time complexities -
        Heapify - O(n)
        Heap Sort - O(n*log(n))
        Create Heap - O(n*log(n))
        Insert & Delete in heap - O(log(n))
*/

// Code Begins Here
class maxHeap
{
    vi arr = {0};
    int size = 0;

public:
    maxHeap() {}
    maxHeap(int n)
    {
        Fo(i, 1, n + 1)
        {
            int temp;
            cin >> temp;
            arr.pb(temp);
            size++;
        }
    }
    void printHeap()
    {
        Fo(i, 1, size + 1) cout << arr[i] << " ";
        cout << "\n";
    }
    void insert(int val)
    {
        arr.pb(val);
        size++;
        int i = size;
        while (i > 1)
        {
            if (arr[i] > arr[i / 2])
            {
                swap(arr[i], arr[i / 2]);
                i /= 2;
            }
            else
            {
                break;
            }
        }
    }
    void createMaxHeap(int n)
    {
        Fo(i, 1, n + 1)
        {
            int temp;
            cin >> temp;
            insert(temp);
        }
    }
    void heapify(int n, int root)
    {
        int largest = root; // ideally root should be the largest
        int l = 2 * root, r = 2 * root + 1;
        if (arr[l] > arr[largest] && l < n)
        {
            largest = l; // left node is greater than root
        }
        if (arr[r] > arr[largest] && r < n)
        {
            largest = r; // right node is greater than left node
        }
        if (largest != root)
        {
            swap(arr[largest], arr[root]);
            heapify(n, largest);
        }
    }
    void makeHeap()
    {
        int startIndx = (arr.size() - 1) / 2; // starting at the first non - leaf node
        Fo(i, startIndx, 0)
        {
            heapify(arr.size(), i);
        }
    }
    void deleteRoot()
    {
        swap(arr[size--], arr[1]);
        heapify(size, 1);
    }

    void heapsort()
    {
        Fo(i, size, 0)
        {
            swap(arr[1], arr[i]);
            heapify(i, 1);
        }
    }
};

void solve()
{
    int n;
    cin >> n;
    maxHeap h(n);
    h.printHeap();
    h.insert(12);
    h.printHeap();
    h.heapsort();
    h.printHeap();
}

int main()
{
    // Start time
    auto start = chrono::steady_clock::now();

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

// Input, Output & error messages inside text files
#ifndef ONLINE_JUDGE
    freopen("C:/Prathamesh/Programming/input.txt", "r", stdin);
    freopen("C:/Prathamesh/Programming/output.txt", "w", stdout);
    freopen("C:/Prathamesh/Programming/err.txt", "w", stderr);
#endif

    // Running for multiple testcases / queries
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

// Calculating Runtime
#ifndef ONLINE_JUDGE
    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cerr << "[Finished in " << setprecision(3) << chrono::duration<double, milli>(diff).count() << " ms]\n";
#endif
    return 0;
}