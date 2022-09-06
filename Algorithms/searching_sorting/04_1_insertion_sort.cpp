#include <iostream>
using namespace std;
void insertionSort(int arr[], int n)
{
    int temp, hole;
    for (int i = 1; i < n - 1; i++)
    {
        temp = arr[i];
        hole = i;
        int k = 0;
        printf("Pass %d\n", i);
        for (k = 0; k < n; k++)
        {
            printf("%d ", arr[k]);
        }
        printf("\n");
        while (hole > 0 && arr[hole - 1] > temp)
        {
            arr[hole] = arr[hole - 1];
            hole--;
        }
        arr[hole] = temp;
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
    int arr[] = {34, 8, 64, 51, 32, 21};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}