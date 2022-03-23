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
    while (head != NULL)
    {
        printf("Element %d : %d\n", i + 1, head->data);
        i++;
        head = head->next;
    }
    printf("\n");
}
node *insertAtFront(node *head, int value)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = head;
    return ptr;
}
void insertAtIndex(node *head, int index, int value)
{
    // wont work for 0th index
    int i = 0;
    node *temp = head;
    while (i != (index - 1))
    {
        temp = temp->next;
        i++;
    }
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = temp->next;
    temp->next = ptr;
}
void insertAtEnd(node *head, int value)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = ptr;
    ptr->next = NULL;
}
void insertAfterNode(node *prev, int value)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = prev->next;
    prev->next = ptr;
}
int main()
{
    node *head;
    node *second;
    node *third;
    node *fourth;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node *)malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));
    head->data = 7;
    head->next = second;

    second->data = 11;
    second->next = third;

    third->data = 12;
    third->next = fourth;

    fourth->data = 52;
    fourth->next = NULL;
    printf("LL before insertion\n");
    traverse(head);
    // insertAfterNode(third, 66);
    head = insertAtFront(head, 43);
    // insertAtIndex(head, 4, 66);
    // insertAtEnd(head, 78);
    printf("LL after insertion\n");
    traverse(head);
    return 0;
}