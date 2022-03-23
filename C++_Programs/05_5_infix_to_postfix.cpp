// Stack infix to postfix written by me 
// works for ( ) parenthesis other parenthesis can be added easily
// Commented code was used for debugging purposes
// Other comments written to explain how parenthesis are handled 
#include <iostream>
using namespace std;
int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '(' || x == ')')
    {
        return 1;
    }
    return 0;
}
int precedence(char x)
{
    if (x == '*' || x == '/')
    {
        return 2;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
class stack
{
    int size, top;
    char *arr;

public:
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
    void push(char val)
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
    char pop()
    {
        char res;
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
    void print_stack()
    {
        if (isEmpty())
        {
            printf("The stack is empty.\n");
        }
        else
        {
            printf("\n");
            printf("The stack is : ");
            for (int i = top; i >= 0; i--)
            {
                printf("%c ", arr[i]);
            }
            printf("\n");
        }
    }
    void postfix(string exp, string &res)
    {
        char x;
        int i = 0;
        while (i < exp.size())
        {
            x = exp[i];
            // printf("x = %c\n", x);
            // printf("i = %d\n", i);
            if (isOperator(x))
            {

                if (isEmpty() || (precedence(x) > precedence(arr[top])) || x == '(') // we will push ( into stack regardless of the precedence of stack top
                {                                                                   //  However this will also push ) into the stack so we will have to make sure it doesnt append in our ans
                    push(x);
                    // print_stack();
                    i++;
                }
                else if (x == ')')
                {
                    while (arr[top] != '(')
                    {
                        res.append(1, pop());
                    }
                    pop();
                }
                else
                {
                    res.append(1, pop());
                }
            }
            else
            {
                res.append(1, x);
                i++;
            }
            // cout << "postfix str = " << res << endl;
            // print_stack();
        }
        while (!(isEmpty()))
        {
            if (arr[top] == ')') // we dont want parenthesis in our postfix
            {
                pop();
            }
            else
            {
                res.append(1, pop());
            }
        }
    }
};

int main()
{
    string exp = "(a*x-y)*z";
    stack s(exp.size());
    string res;
    s.postfix(exp, res);
    // s.print_stack();
    cout << res << endl;
    return 0;
}