// Bubble sort
#include <iostream>
using namespace std;
void BubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - i - 2; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
        printf("pass %d\n", i + 1);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n\n";
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
    int arr[] = {12, 34, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Array before sorting : \n";
    print_array(arr, n);

    BubbleSort(arr, n);

    cout << "Array after sorting : \n";
    print_array(arr, n);
    return 0;
}