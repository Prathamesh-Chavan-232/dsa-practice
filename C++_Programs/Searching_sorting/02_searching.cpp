// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

class MyArray
{
	int totalSize, usedSize, *ptr;

public:
	MyArray() {}
	MyArray(int);
	MyArray(int, int);
	int lin(int n, int x);
};
MyArray::MyArray(int tSize)
{
	totalSize = tSize;
	usedSize = tSize;
	ptr = (int *)malloc(tSize * sizeof(int));
}
MyArray::MyArray(int tSize, int uSize)
{
	totalSize = tSize;
	usedSize = uSize;
	ptr = (int *)malloc(tSize * sizeof(int));
}
int MyArray::lin(int n, int x)
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

int main()
{
	int arr[] = {1, 10, 30, 15};
	int x = 30;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << x << " is present at index "
		 << search(arr, n, x);

	getchar();
	return 0;
}
