#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int isEmpty(node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}
node *push(node *top, int val)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    ptr->next = top;
    top = ptr;
    return top;
}
int pop(node **top)
{
    if (isEmpty(*top))
    {
        printf("Stack underflow\n");
        return -1;
    }
    node *ptr = *top;
    (*top) = (*top)->next;
    int x = ptr->data;
    free(ptr);
    return x;
}
int peek(node *top, int index)
{
    node *ptr = top;
    for (int i = 0; (i < index && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;
    }
}
int stackBottom(node *top)
{
    struct node *ptr = top;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    return ptr->data;
}
void print_stack(node *top)
{
    int i = 0;
    while (top != NULL)
    {
        printf("Element = %d\n", top->data);
        top = top->next;
        i++;
    }
    printf("\n");
}
int main()
{
    int x;
    node *top = malloc(sizeof(node));
    top->data = 34;
    top->next = NULL;
    top = push(top, 78);
    top = push(top, 74);
    top = push(top, 13);
    print_stack(top);
    printf("Element at index 1 is %d\n", peek(top, 1));
    printf("%d\n", stackBottom(top));
    return 0;
}