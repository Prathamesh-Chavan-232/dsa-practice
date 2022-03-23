// Time complexity -> O(n)

// Program that reads entire expression to check parenthesis matching
// then tells the number of opening and closing parentheses
// I wrote to play around with static variables in CPP
// Logically its dumb to read the entire expression
// even if we already know it is unbalanced
// One use case for this - to suggest balanced expression after checking

#include <iostream>
#include <string.h>
using namespace std;
class stack
{
    int size, top, i, j;
    char *arr;

public:
    friend void print_stack(stack &s);
    stack(void) {}
    stack(int n)
    {
        size = n;
        top = -1;
        arr = (char *)malloc(size * sizeof(char));
        i = 0;
        j = 0;
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
    int paren_match(char x)
    {
        int static temp = 0;
        if (x == '(')
        {
            push('(');
            i++;
        }
        else if (x == ')')
        {
            if (isEmpty())
            {
                printf("Stack underflow\n");
                temp++;
            }
            else
            {
                pop();
            }
            j++;
        }
        return temp;
    }
    void print_brackets()
    {
        printf("No. of opening brackets : %d\n", i);
        printf("No. of closing brackets : %d\n", j);
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
            printf("%c ", s.arr[i]);
        }
        printf("\n");
    }
}

int main()
{
    int count = 0;
    char exp[] = "7*8)))-3(7";
    stack s(strlen(exp));
    for (int i = 0; i < strlen(exp); ++i)
    {
        int x = exp[i];
        count = s.paren_match(x);
    }
    printf("%d\n", count);
    if (!s.isEmpty() || count > 0)
    {
        if (count > 0)
        {
            printf("Parenthesis unbalanced due to stack underflow\n");
        }
        else
        {
            printf("Parenthesis unbalanced due to stack not empty at EOE\n");
        }
    }
    else
    {
        printf("Parenthesis balanced\n");
    }
    s.print_brackets();
    print_stack(s);
    return 0;
}