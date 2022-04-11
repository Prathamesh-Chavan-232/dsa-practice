#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void traverse(struct node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        printf("Element %d : %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    }
    printf("\n");
}
int main()
{
    int i = 0, input, n;
    node *head = malloc(sizeof(node));
    head->next = NULL;
    printf("Enter the length of LL : ");
    scanf("\n%d", &n);
    printf("Enter element %d : ", i + 1);
    scanf("\n%d", &input);
    head->data = input;
    node *ptr = head;
    for (i = 1; i < n; i++)
    {
        ptr->next = malloc(sizeof(struct node));
        ptr = ptr->next;
        printf("Enter element %d : ", i + 1);
        scanf("\n%d", &input);
        ptr->data = input;
    }
    ptr->next = NULL;
    printf("\n");
    traverse(head);
    return 0;
}