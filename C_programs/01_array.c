#include <stdio.h>
#include <stdlib.h>
typedef struct MyArray
{
    int totalSize;
    int usedSize;
    int *ptr;
} MyArray;

void createArray(MyArray *arr, int tSize, int uSize)
{
    // (*a).totalSize = tSize;
    // (*a).usedSize = uSize;
    // (*a).ptr = (int *)malloc(tSize * sizeof(int));
    arr->totalSize = tSize;
    arr->usedSize = uSize;
    arr->ptr = (int *)malloc(tSize * sizeof(int));
}
void set(MyArray *arr)
{
    printf("Enter the Elements of the array : \n");
    for (int i = 0; i < (*arr).usedSize; i++)
    {
        printf("\tEnter element %d : ", i + 1);
        scanf("\n%d", &arr->ptr[i]);
    }
}
void display(MyArray *arr)
{
    printf("The Elements of the array are : \n");
    for (int i = 0; i < (*arr).usedSize; i++)
    {
        printf("%d ", arr->ptr[i]);
    }
    printf("\n");
}
int insert(MyArray *arr, int index, int value)
{
    if (arr->totalSize == arr->usedSize)
    {
        return -1;
    }
    else if (index > arr->totalSize)
    {
        return -2;
    }
    else
    {
        for (int i = arr->usedSize - 1; i >= index; i--)
        {
            arr->ptr[i + 1] = arr->ptr[i];
        }
        arr->ptr[index] = value;
        if (index <= arr->usedSize)
        {
            arr->usedSize++;
        }
        else
        {
            for (int i = usedSize; i < index; i++)
            {
                ptr[i] = 0;
            }
            arr->usedSize = index + 1;
        }
        return 1;
    }
}
int remove(int index)
{
    if (index > arr->totalSize)
    {
        return -1;
    }
    else
    {
        for (int i = index; i < arr->usedSize - 1; i++)
        {
            arr->ptr[i] = ptr[i + 1];
        }
        arr->usedSize--;
        return 1;
    }
}
int main()
{
    MyArray marks;
    int res;
    createArray(&marks, 100, 5);
    set(&marks);
    display(&marks);
    res = insert(&marks, 3, 12);
    if (res == 1)
    {
        printf("Insertion succesful\n");
        display(&marks);
    }
    else if (res == -1)
    {
        printf("Array at full capacity, insertion not sucsessful");
    }
    else
    {
        printf("Index greater than array size, insertion not successful");
    }
    return 0;
}
