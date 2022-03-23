// Selection Sort
#include <iostream>
using namespace std;
void SelectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        printf("min in i %d\n", min);
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
                printf("min in j %d\n", min);
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
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
    int arr[] = {2, 7, 4, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array before sorting : \n";
    print_array(arr, n);

    SelectionSort(arr, n);
    
    cout << "Array after sorting : \n";
    print_array(arr, n);
    return 0;
}