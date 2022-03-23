#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
void traverse(struct node *head)
{
    int i = 0;
    // while (head != NULL)
    for (int i = 0; i < 2; i++)
    {
        printf("Element : %d\n", head->data);
        head = head->next;
    }
}
int main()
{
    node *head;
    node *second;
    node *third;
    node *fourth;
    // Allocate memory for nodes in the LL in heap
    head = malloc(sizeof(node));
    second = malloc(sizeof(node));
    third = malloc(sizeof(node));
    fourth = malloc(sizeof(node));
    // Link First and second nodes
    head->data = 4;
    head->next = second;
    // Link Second and third nodes
    second->data = 3;
    second->next = third;
    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;
    // Terminate the list and tail node
    fourth->data = 1;
    fourth->next = NULL;

    traverse(head);
    printf("%d\n", head->data);
    return 0;
}