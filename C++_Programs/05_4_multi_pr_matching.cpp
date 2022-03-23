#include <iostream>
#include <cstring>
using namespace std;
class stack
{
    int size, top;
    char *arr;

public:
    friend void print_stack(stack &s);
    friend int paren_match(stack &s, char x);
    stack(void) {}
    stack(int n)
    {
        size = n;
        top = -1;
        arr = (char *)malloc(size * sizeof(char));
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
        res = arr[top];
        top--;
        return res;
    }
};
int paren_match(stack &s, char x)
{
    int static temp = 0;
    if (x == '(' || x == '[' || x == '{')
    {
        s.push(x);
    }
    else if (x == ')' || x == ']' || x == '}')
    {
        if (s.isEmpty())
        {
            temp++;
        }
        else if ((x == ')' && s.arr[s.top] != '(') || (x == ']' && s.arr[s.top] != '[') || (x == '}' && s.arr[s.top] != '{'))
        {
            temp++;
        }
        else
        {
            s.pop();
        }
    }
    return temp;
}
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
    string exp = "{(7*8)}-{[3]}";
    stack s(exp.size());
    for (int i = 0; i < exp.size(); ++i)
    {
        int x = exp[i];
        count = paren_match(s, x);
        if (count > 0)
        {
            break;
        }
    }
    if (!s.isEmpty() || count > 0)
    {
        printf("Parenthesis unbalanced\n");
    }
    else
    {
        printf("Parenthesis balanced\n");
    }
    print_stack(s);
    return 0;
}