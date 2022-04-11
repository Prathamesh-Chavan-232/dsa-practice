#include <stdio.h>
int linear_search(stud s[MAX], int key, int n)
{
    int flag = -1;
    for (int i = 0; i < n; i++)
    {
        if (s[i].roll_no == key)
        {
            flag = i;
            break;
        }
    }
    return flag;
}

int binary_search(stud s[MAX], int key, int n)
{
    int flag = -1, low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (s[mid].roll_no == key)
        {
            flag = mid;
            break;
        }
        else if (s[mid].roll_no > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return flag;
}
int rec_binary_search(stud s[MAX], int key, int low, int high)
{
    int flag = -1;
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (s[mid].roll_no == key)
        {
            flag = mid;
        }
        else if (s[mid].roll_no > key)
        {
            rec_binary_search(s, key, low, mid - 1);
        }
        else
        {
            rec_binary_search(s, key, mid + 1, high);
        }
    }
    return flag;
}

int main()
{

    return 0;
}