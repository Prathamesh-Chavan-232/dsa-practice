#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;

void traverse(node *head)
{
    int i = 0;
    node *ptr = head;
    do
    {
        printf("Element %d : %d\n", i + 1, ptr->data);
        ptr = ptr->next;
        i++;
    } while (ptr != head);
}
node *insertAtFirst(node *head, int value)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    // At this point p points to the last node of this circular linked list
    p->next = ptr;
    ptr->next = head;
    head = ptr;
    return head;
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
    head->next = second;
    // Link Second and third nodes
    second->data = 3;
    second->next = third;
    // Link third and fourth nodes
    third->data = 6;
    third->next = fourth;
    // Terminate the list and tail node
    fourth->data = 1;
    fourth->next = head;
    printf("LL before insertion\n");
    traverse(head);
    head = insertAtFirst(head, 80);
    printf("LL after insertion\n");
    traverse(head);
    return 0;
}