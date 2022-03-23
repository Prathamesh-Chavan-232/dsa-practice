#include <stdio.h>
#include <stdlib.h>
typedef struct myStack
{
    int size;
    int top;
    int *arr;
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
int main()
{
    // myStack s;
    // s.size = 80;
    // s.top = -1;
    // s.arr = (int *)malloc(s.size * sizeof(int));

    myStack *s = malloc(sizeof(myStack)); // Using pointer variable helps in easily passing stack to functions
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // Pushing an element manually
    // s->arr[0] = 9;
    // s->arr[1] = 2;
    // s->arr[2] = 1;
    // s->arr[3] = 5;

    push(s, 65);
    push(s, 89);
    push(s, 78);
    push(s, 53);
    push(s, 12);
    push(s, 41);
    push(s, 93);
    push(s, 16);
    push(s, 36);
    push(s, 26);

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
