#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    int temp, hole;
    for (int i = 1; i < n - 1; i++)
    {
        temp = arr[i];
        hole = i;
        while (hole > 0 && arr[hole - 1] > temp)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = temp;
    }
}
int main()
{
    int arr[] = {7, 2, 4, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}