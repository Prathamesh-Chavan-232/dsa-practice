// Time complexity -> O(n)
#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    char *arr;
    int top;
    int size;
} stack;
int isEmpty(stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void push(stack *s, char val)
{

    s->top++;
    s->arr[s->top] = val;
}
int pop(stack *s)
{
    int res;
    if (isEmpty(s))
    {
        return -1;
    }
    else
    {
        res = s->arr[s->top];
        s->top--;
        return res;
    }
}
void print_stack(stack *s)
{
    if (isEmpty(s))
    {
        printf("The stack is empty\n");
    }
    else
    {
        for (int i = s->top; i >= 0; i--)
        {
            printf("%c ", s->arr[i]);
        }
        printf("\n");
    }
}
int paren_match(stack *s, char x, int *count)
{
    int temp;
    temp = *count;
    if (x == '(')
    {
        push(s, '(');
    }
    else if (x == ')')
    {
        if (isEmpty(s))
        {
            printf("Stack underflow\n");
            temp++;
        }
        else
        {
            pop(s);
        }
    }
    return temp;
}
int main()
{
    int count = 0;
    stack *s = (stack *)malloc(sizeof(stack));
    char exp[] = "(7*8)-3((()))7";
    s->top = -1;
    s->size = sizeof(exp) / sizeof(exp[0]);
    s->arr = (char *)malloc(s->size * sizeof(char *));
    for (int i = 0; i < s->size; i++)
    {
        int x = exp[i];
        count = paren_match(s, x, &count);
        if (count > 0)
        {
            break;
        }
    }
    if (!isEmpty(s) || count > 0)
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
    print_stack(s);
    return 0;
}