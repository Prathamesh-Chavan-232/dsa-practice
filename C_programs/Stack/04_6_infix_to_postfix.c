// CWH tutorial code only works for expressions without parentheses.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct myStack
{
    int size;
    int top;
    char *arr;
} myStack;

int isEmpty(myStack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isOperator(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 1;
    }
    return 0;
}
int precedence(char x)
{
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else if (x == '*' || x == '/')
    {
        return 2;
    }
}
int isFull(myStack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(myStack *s, int val)
{
    if (isFull(s))
    {
        printf("stack overflow, cannot push %d to the stack\n", val);
    }
    else
    {
        s->top++;
        s->arr[s->top] = val;
    }
}
int pop(myStack *s)
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
void print_stack(myStack *s)
{
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int stackTop(myStack *s)
{
    return s->arr[s->top];
}
char *postfix(myStack *s, char *infix)
{
    char *postfix = (char *)malloc((strlen(infix) + 1) * sizeof(char));
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            j++;
            i++;
        }
        else
        {
            if (precedence(infix[i]) > precedence(s->arr[s->top]))
            {
                push(s, infix[i]);
                i++;
            }
        }
    }
}
int main()
{

    myStack *s = malloc(sizeof(myStack));
    s->size = 10;
    s->top = -1;
    s->arr = (char *)malloc(s->size * sizeof(char));

    print_stack(s);
    printf("popped %d from the stack\n", pop(s));
    printf("Aftering popping the stack is\n");
    print_stack(s);

    printf("The element at position %d is %d\n", 3, peek(s, 3));

    for (int i = 1; i <= s->top + 1; i++)
    {
        printf("The element at position %d is %d\n", i, peek(s, i));
    }

    return 0;
}
