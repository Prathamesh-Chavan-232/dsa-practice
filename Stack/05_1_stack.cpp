#include <iostream>
using namespace std;
class stack
{
    int size, top, *arr;

public:
    friend void print_stack(stack &s);
    friend void free_arr(stack &s);
    stack(void) {}
    stack(int n)
    {
        size = n;
        top = -1;
        arr = (int *)malloc(size * sizeof(int));
    }
    int isEmpty()
    {
        if (top == -1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int isFull()
    {
        if (top == size - 1)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void push(int val)
    {
        if (isFull())
        {
            printf("Stack overflow\n");
        }
        else
        {
            top++;
            arr[top] = val;
        }
    }
    int pop()
    {
        int res;
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            res = arr[top];
            top--;
            return res;
        }
    }
    int peek(int i, int traverse = -1, int incre = 1)
    {
        int res = top - i + 1;
        if (traverse == -1)
        {
            if (res < 0)
            {
                return -1;
            }
            else
            {
                return arr[res];
            }
        }
        else
        {
            int j = i;
            while (j < traverse)
            {
                cout << "The element at index " << j << " is " << arr[top - j] << "\n";
                j += incre;
            }
            return 0;
        }
    }
    int top()
    {
        return arr[top];
    }
};
void print_stack(stack &s)
{
    if (s.isEmpty())
    {
        printf("The stack is empty.\n");
    }
    else
    {
        for (int i = s.top; i >= 0; i--)
        {
            printf("%d ", s.arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int x;
    stack s(10);
    s.push(65);
    s.push(89);
    s.push(78);
    s.push(53);
    s.push(12);
    s.push(41);
    s.push(93);
    s.push(16);
    s.push(36);
    s.push(26);
    printf("popped %d from the stack\nAftering popping the stack is\n", s.pop());`
    // print_stack(s);
    for (int i = 0; i < ; ++i)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    printf("Element at index 1 is %d\n", s.peek(1));
    x = s.peek(2, 5);    // peek(Staring index,ending index-1);
    x = s.peek(1, 7, 2); // peek(Staring index,ending index-1,step arg);
    return 0;
}

// we dont need stack s to be a pointer here because stack
// is a stack and all the functions are in the class so they
// can change its members directly