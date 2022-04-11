#include <stdio.h>
#include <stdlib.h>
typedef struct stack
{
    int size;
    int top;
    char undo[100][MAX];
    char redo[100][MAX];
} stack;

int isEmpty(stack *ptr)
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

int isFull(stack *ptr)
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

void push_undo(stack *s, int val)
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
void push_redo(stack *s, int val)
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
    for (int i = s->top; i >= 0; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int main()
{
    stack *s = malloc(sizeof(stack)); 
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    return 0;
}
