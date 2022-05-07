#include <bits/stdc++.h>
using namespace std;

template <typename T>
int binSearch(vector<T> const &arr, T const target)
{
    int mid, res = -1, low = 0, high = arr.size() - 1;
    while (low <= high)
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
int main()
{
    
    return 0;
}