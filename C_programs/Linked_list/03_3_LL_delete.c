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
node *deleteAtFront(node *head)
{
    node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
node *deleteAtIndex(node *head, int index)
{
    node *p = head;
    node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
node *deleteAtEnd(node *head)
{
    node *p = head;
    node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}
node *deleteAtKey(node *head, int key)
{
    node *p = head;
    node *q = head->next;
    if (p->data == key)
    {
        deleteAtFront(head);
        return head;
    }
    else
    {
        while (q->data != key && q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        if (q->data == key)
        {
            p->next = q->next;
        }
        free(q);
        return head;
    }
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
    printf("LL before deletion\n");
    traverse(head);
    head = deleteAtFront(head);
    printf("LL after deletion\n");
    traverse(head);
    printf("%d",head->data);
    return 0;
}