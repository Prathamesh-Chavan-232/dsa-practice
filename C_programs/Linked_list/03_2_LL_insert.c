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
node *insertAtIndex(node *head, int index, int value)
{
    // wont work for 0th index
    int i = 0;
    node *temp = head;
    while (i != index)
    {
        temp = temp->next;
        i++;
    }
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = temp->next;
    temp->next = ptr;
    return head;
}
node *insertAtEnd(node *head, int value)
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
    return head;
}
node *insertAfterNode(node *head, node *prev, int value)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = value;
    ptr->next = prev->next;
    prev->next = ptr;
    return head;
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
    // head = insertAfterNode(head,third, 66);
    head = insertAtFront(head, 43);
    // head = insertAtIndex(head, 4, 66);
    // head = insertinsertAtEnd(head, 78);
    printf("LL after insertion\n");
    traverse(head);
    return 0;
}