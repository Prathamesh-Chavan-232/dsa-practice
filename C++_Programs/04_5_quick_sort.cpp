#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int partition(int a[], int l, int h)
{
    int pivot = a[l], start = l, end = h;
    while (start < end)
    {
        while (a[start] <= pivot)
        {
            start++;
        }
        while (a[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(a[start], a[end]);
        }
    }
    swap(a[l], a[end]);
    return end;
}
void quicksort(int arr[], int l, int h)
{
    if (l < h)
    {
        int loc;
        loc = partition(arr, l, h);
        quicksort(arr, l, loc - 1);
        quicksort(arr, loc + 1, h);
    }
}
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main()
{
    int arr[] = {7, 6, 10, 5, 9, 2, 1, 15, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before sorting : \n";
    print_array(arr, n);
    quicksort(arr, 0, n - 1);
    cout << "Array after sorting : \n";
    print_array(arr, n);
    return 0;
}