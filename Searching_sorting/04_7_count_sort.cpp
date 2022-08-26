#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void count_sort(int arr[], int n)
{
    int max = maximum(arr, n);
    vector<int> temp(max + 1);
    for (int i = 0; i < n; ++i)
    {
        temp[arr[i]]++;
    }
    int k = 0;
    for (int i = 0; i < temp.size(); ++i)
    {
        while (temp[i] > 0)
        {
            arr[k++] = i;
            temp[i]--;
        }
    }
}
void print_arr(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    vector<int> res;
    int arr[] = {3, 1, 9, 7, 1, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    count_sort(arr, n);
    print_arr(arr, n);
    return 0;
}