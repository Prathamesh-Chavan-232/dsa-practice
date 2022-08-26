#include <io.h>
#include <bits/stdc++.h>
using namespace std;

// Template

// Random number generator
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

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

// constants
const int mod = 1'000'000'007;
const int N = (int)1e9, M = N;
const double PI = 3.1415926535897932384626;

template <typename T>
void _print(const T arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Program
template <typename T>
void SelectionSort(T arr[], int n);

template <typename T>
void merge(T arr[], int mid, int h);

template <typename T>
void merge_(T arr[], int l, int mid, int h);

template <typename T>
void mergeSort(T arr[], int l, int h);

// code runs for t test cases
void solve()
{
    int n;
    cin >> n; 
    int *arr = new int[n];
    
    // array input and Randomizing
    for (int i = 0; i < n; ++i)
    {
        arr[i] = i;
    }
    shuffle(arr, arr + n, rng);
    
    _print(arr, n); // unsorted array
    
    int l = 0, h = n - 1;
    mergeSort(arr, l, h);
    
    _print(arr, n); // sorted array
    free(arr);
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
    cin >> t;
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

template <typename T>
void SelectionSort(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int min_ = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_] > arr[j])
            {
                min_ = j;
            }
        }
        swap(arr[min_], arr[i]);
    }
}

template <typename T>
void merge(T arr[], int mid, int h)
{
    int temp[h + 1];
    int i = 0, j = mid + 1, k = 0;
    while (i <= mid && j <= h) // Mergeing the elements in stored order
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i++];
        }
        else
        {
            temp[k] = arr[j++];
        }
        k++;
    }
    while (i <= mid) // if elements are remaining from left subarray
    {
        temp[k++] = arr[i++];
    }
    while (j <= h) // if elements are remaining from right subarray
    {
        temp[k++] = arr[j++];
    }
    for (int i = 0; i < (h + 1); i++) // storing sorted elements in orignal array again
    {
        arr[i] = temp[i];
    }
}

template <typename T>
void merge_(T arr[], int l, int mid, int h)
{
    int l_size = mid - l + 1;
    int L[l_size + 1]; // left subarray

    int r_size = h - mid;
    int R[r_size + 1]; // right subarray

    for (int i = 0; i < l_size; ++i)
    {
        L[i] = arr[i + l];
    }
    for (int i = 0; i < r_size; ++i)
    {
        R[i] = arr[i + mid + 1];
    }

    // Instead of using while loops at the end to add the remaining elements
    // We can add INT_MAX at the end of both arr partitions
    // so the elements in the other array will always be smaller than INT_MAX,
    // we do this inside a for loop of n size, so we get all n elements and only INT_MAX will be left in the subarrays
    L[l_size] = R[r_size] = INT_MAX;

    int i = 0, j = 0;
    for (int k = l; k <= h; ++k)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i++];
        }
        else
        {
            arr[k] = R[j++];
        }
    }
}

template <typename T>
void mergeSort(T arr[], int l, int h)
{
    if (l >= h)
        return;
    int mid = (l + h) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, h);
    merge_(arr, l, mid, h);
}
