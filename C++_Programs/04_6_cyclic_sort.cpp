#include <iostream>
using namespace std;
void cyclicSort(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        int correct = arr[i] - 1;
        if (arr[i] != arr[correct])
        {
            swap(arr[i], arr[correct]);
        }
        else
        {
            i++;
        }
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
    int arr[] = {2, 3, 1, 5, 4, 10, 7, 6, 9, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before sorting : \n";
    print_array(arr, n);
    cyclicSort(arr, n);
    cout << "Array after sorting : \n";
    print_array(arr, n);
    return 0;
}