#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int size;
    int top;
    int *arr;
} myStack;
int isEmpty(myStack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(myStack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(myStack *s, int val)
{
    if (isFull(s))
    {
        printf("stack overflow: \n");
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
// pos = 1 means element at the top of the stack
int peek(myStack *s, int pos)
{
    int res = s->top - pos + 1;
    if (res < 0)
    {
        return -1;
    }
    else
    {
        return s->arr[res];
    }
}
int stackTop(myStack *s)
{
    return s->arr[s->top];
}
int stackBottom(myStack *s)
{
    return s->arr[0];
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
    myStack *s;
    int ch, temp;
    char exp[100];
    char contd = 'y';
    printf("Enter the size of the stack : ");
    scanf("%d", &s->size);
    s->arr = (int *)malloc(s->size * sizeof(int));
    s->top = -1;
    do
    {
        printf("MENU\n1. Push\n2. Pop\n3. Peek\n4. Print stack\n5. stack Top\n6. stack Bottom7. Infix to postfix\n");
        printf("Enter your choice : ");
        scanf("\n%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value to push : ");
            scanf("\n%d", &temp);
            push(s, temp);
            break;
        case 2:
            printf("%d was popped from the stack\n", pop(s));
            break;
        case 3:
            printf("Enter the position to peek : ");
            scanf("\n%d", &temp);
            printf("The element at position %d is %d\n", temp, peek(s, temp));
            break;
        case 4:
            print_stack(s);
            break;
        case 5:
            printf("stack Top = %d\n", stackTop(s));
            break;
        case 6:
            printf("stack Bottom = %d\n", stackBottom(s));
            break;
        case 7:
            printf("Enter your expression : ");
            scanf("\n%s", &exp);
            break;
        default:
            printf("Invalid case\n");
            break;
        }
        printf("Do you want to continue (y/n) :");
        scanf("\n%c", &contd);
    } while (contd == 'y' || contd == 'Y');
    return 0;
}