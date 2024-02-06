#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
    int data;
    node *next;

public:
    void enqueue(node *&front, node *&rear)
    {
        int x;
        node *temp = new node();
        if (temp == NULL)
        {
            cout << "Queue is full!" << endl;
        }
        else
        {
            if ((rear == NULL) && (front == NULL))
            {
                rear = temp;
                front = temp;
            }
            cout << "Enter the number to insert : ";
            cin >> x;
            temp->data = x;
            temp->next = NULL;
            rear->next = temp;
            rear = temp;
        }
    }
    void dequeue(node *&front)
    {
        if (front == NULL)
        {
            cout << "Queue is empty!" << endl;
        }
        else if (front->next == NULL)
        {
            front = NULL;
        }
        else
        {
            node *d;
            d = front;
            front = front->next;
            free(d);
        }
    }
    int top(node *&front)
    {
        if (front == NULL)
        {
            return -1;
        }
        else
        {
            node *temp = new node();
            temp = front;
            return temp->data;
        }
    }
};
using namespace std;
int main()
{
    node q;
    node *front = NULL;
    node *rear = NULL;
    q.enqueue(front, rear);
    q.enqueue(front, rear);
    q.enqueue(front, rear);
    q.enqueue(front, rear);
    q.enqueue(front, rear);
    q.enqueue(front, rear);
    for (int i = 0; i < 5; ++i)
    {
        cout << q.top(front) << " ";
        q.dequeue(front);
    }
    cout << endl;
    cout << q.top(front) << endl;
    q.dequeue(front);
    return 0;
}