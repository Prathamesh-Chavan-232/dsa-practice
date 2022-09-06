#include <bits/stdc++.h>
using namespace std;

template <typename T>
int binSearch(vector<T> const &arr, T const target)
{
    int mid, res = -1, l = 0, r = arr.size() - 1;
    while (r >= l)
    {
        mid = l + (r - l) / 2;
        if (arr[mid] == target)
        {
            res = mid;
            break;
        }
        else if (arr[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return res;
}
int main()
{

    return 0;
}