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
}
int main()
{
    node *head;
    node *second;
    node *third;
    node *tail;
    // Allocate memory for nodes in the LL in heap
    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    tail = (node *)malloc(sizeof(node));
    // Link First and second nodes
    head->data = 7;
    head->next = second;
    // Link Second and third nodes
    second->data = 11;
    second->next = third;
    // Link third and fourth nodes
    third->data = 12;
    third->next = tail;
    // Terminate the list and tail node
    tail->data = 23;
    tail->next = NULL;
    traverse(head);
    return 0;
}