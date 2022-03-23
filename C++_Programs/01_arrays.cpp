/*
Array ADT
total size            max(),min()
used size      +      get(i),set(i,num)
base address          search(num), insert(num),append(x)
*/
#include <iostream>
using namespace std;
class myArray
{
    int totalSize, usedSize, *ptr;

public:
    myArray() {}
    myArray(int);
    myArray(int, int);
    void set();
    void display();
    int max();
    int min();
    int insert(int index, int value);
    int remove(int index);
    int append(int);
};
myArray::myArray(int tSize)
{
    totalSize = tSize;
    usedSize = tSize;
    ptr = (int *)malloc(tSize * sizeof(int));
}
myArray::myArray(int tSize, int uSize)
{
    totalSize = tSize;
    usedSize = uSize;
    ptr = (int *)malloc(tSize * sizeof(int));
}
void myArray::set()
{
    for (int i = 0; i < usedSize; i++)
    {
        cout << "Enter the value of element " << i + 1 << " : ";
        cin >> ptr[i];
    }
}
void myArray::display()
{
    for (int i = 0; i < usedSize; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
}
int myArray::insert(int index, int value)
{
    if (totalSize == usedSize)
    {
        return -1;
    }
    else if (index > totalSize)
    {
        return -2;
    }
    else
    {
        for (int i = usedSize - 1; i >= index; i--)
        {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = value;

        if (index <= usedSize)
        {
            usedSize++;
        }
        else
        {
            for (int i = usedSize; i < index; i++)
            {
                ptr[i] = 0;
            }
            usedSize = index + 1;
        }
        return 1;
    }
}
int myArray::remove(int index)
{
    if (index > totalSize)
    {
        return -1;
    }
    else
    {
        for (int i = index; i < usedSize - 1; i++)
        {
            ptr[i] = ptr[i + 1];
        }
        usedSize--;
        return 1;
    }
}
int main()
{
    int res;
    myArray marks(10, 5);
    marks.set();
    marks.display();
    res = marks.insert(3, 12);
    if (res == 1)
    {
        printf("Insertion successful\n");
        marks.display();
    }
    else if (res == -1)
    {
        printf("Array at full capacity, insertion not sucsessful");
    }
    else
    {
        printf("Index greater than array size, insertion not successful");
    }
    res = marks.remove(2);
    if (res == 1)
    {
        printf("Deletion successful\n");
        marks.display();
    }
    else
    {
        printf("Index greater than array size, deletion not successful");
    }
    return 0;
}