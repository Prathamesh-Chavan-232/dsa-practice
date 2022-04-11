#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} node;
node *traverse(struct node *head)
{
    int i = 0;
    while (head != NULL)
    {
        printf("Element %d : %d\n", i + 1, head->data);
        i++;
        head = head->next;
    }
    printf("\n");
}
int main()
{
    node *head;
    node *second;
    node *third;
    node *fourth;
    // Allocate memory for nodes in the LL in heap
    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    // Link First and second nodes
    head->data = 4;
    head->prev = NULL;
    head->next = second;
    // Link Second and third nodes
    second->data = 3;
    second->prev = head;
    second->next = third;
    // Link third and fourth nodes
    third->data = 6;
    third->prev = second;
    third->next = fourth;
    // Terminate the list and tail node
    fourth->data = 1;
    fourth->prev = third;
    fourth->next = NULL;
    traverse(head);
    return 0;
}