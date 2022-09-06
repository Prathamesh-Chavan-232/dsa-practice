#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int l, int mid, int h)
{
    int i = 0, j = mid + 1, k = 0;
    int *temp = new int[h + 1];
    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid || j <= h)
    {
        if (i <= mid)
        {
            temp[k] = arr[i];
            i++;
        }
        else
        {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    for (int i = 0; i < (h + 1); i++) // Storing sorted elements in orignal array again
    {
        arr[i] = temp[i];
    }
}
void mergeSort(int arr[], int l, int h)
{
    if (l < h) // base condition
    {
        int mid = (l + h) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
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
    int arr[] = {9, 4, 7, 6, 3, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array before sorting : \n";
    print_array(arr, n);

    mergeSort(arr, 0, n - 1);
    cout << "Array after sorting : \n";
    print_array(arr, n);
    return 0;
}