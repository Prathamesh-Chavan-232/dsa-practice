#include <bits/stdc++.h>
using namespace std;

template <typename T>
int binSearch(vector<T> const &arr, T const target)
{
    int mid, res = -1, low = 0, high = arr.size() - 1;
    while (high - low > 1)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
template <typename T>
int binSearch(T arr[], int n, T const target)
{
    int mid, res = -1, low = 0, high = n - 1;
    while (high - low > 1)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return res;
}
/*
    This implementation is cleaner in terms of code readability

*/

template <typename T>
int bin_search(vector<T> const &arr, T const target)
{
    int l = 0, r = arr.size() - 1, res = -1, m = -1;
    while (r - l > 1)
    {
        m = (l + r) / 2;
        if (arr[m] < target)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    if (arr[l] == target)
        res = l;
    else if (arr[r] == target)
        res = r;
    return res;
}
template <typename T>
int bin_search(T arr[], int n, T const target)
{
    int l = 0, r = n - 1, res = -1, m = -1;
    while (r - l > 1)
    {
        m = l + (r - l) / 2;
        cerr << l << " " << m << " " << r << "\n";
        if (arr[m] < target)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }
    if (arr[l] == target)
    {
        res = l;
    }
    else if (arr[r] == target)
    {
        res = r;
    }
    return res;
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    int res = bin_search(arr, 5);
    cout << res << "\n";
    return 0;
}
