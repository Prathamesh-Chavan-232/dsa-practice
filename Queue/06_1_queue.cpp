//    Linear Queue implementation - 
// -----------------------------------------------   
// 1. Queue has n maximum elements
// 2. Linear queue of size n
//    means insertion can only be done n times
// 3. It means if the size of queue is n then if 
//    the queue is full new members can't join 
//    even if someone leaves
// 4. Eg of this queue - Line for movie tickets
// -----------------------------------------------   


#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class my_queue
{
private:
    int front;
    int rear;
    int size;
    int *arr;

public:
    my_queue() {}
    my_queue(int n)
    {
        front = -1;
        rear = -1;
        size = n;
        arr = new int[size];
    }
    int is_empty()
    {
        if (rear == -1 || rear == front)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int is_full()
    {
        if (rear + 1 >= size)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int enqueue(int x)
    {
        if (is_full())
        {
            return -1;
        }
        else
        {
            rear++;
            arr[rear] = x;
            return rear;
        }
    }
    int dequeue()
    {
        if (is_empty())
        {
            front = -1;
            rear = -1;
            return -1;
        }
        else
        {
            front++;
            int x = arr[front];

            // O(n) operation - shifting elements to make space for new elements 
            //                  after one element leaves

            // for (int i = front + 1; i <= rear; ++i) 
            // {
            //     arr[i - 1] = arr[i];
            // }
            // front--;
            // rear--;

            return x;
        }
    }
    int top()
    {
        return arr[front + 1];
    }
    void display()
    {
        if (is_empty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            for (int i = front + 1; i <= rear; ++i)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int n;
    cout << "Enter the size of the my_queue : ";
    cin >> n;
    my_queue q(n);
    int ch, x, pos;
    char contd = 'y';
    do
    {
        cout << "***** MENU *****\n"
             << "1. Check if empty\n"
             << "2. Check if full\n"
             << "3. Enqueue\n"
             << "4. Dequeue\n"
             << "5. Display\n"
             << "*****      *****\n"
             << "Enter your choice : ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            if (q.is_empty())
            {
                cout << "Queue is empty\n";
            }
            else
            {
                cout << "Queue is not empty\n";
            }
            break;
        case 2:
            if (q.is_full())
            {
                cout << "Queue is full\n";
            }
            else
            {
                cout << "Queue is not full\n";
            }
            break;
        case 3:
            cout << "Enter value to insert : ";
            cin >> x;
            pos = q.enqueue(x);
            if (pos == -1)
            {
                cout << "Queue is full\n";
            }
            else
            {
                cout << "member " << pos + 1 << " added\n";
            }
            break;
        case 4:
            pos = q.dequeue();
            if (pos == -1)
            {
                cout << "Queue is empty\n";
            }
            else
            {
                cout << pos << " has left the queue\n";
            }
            break;
        case 5:
            q.display();

            // How queue is actually used as a data structure
            // 1. Take the top element -> perform desired operation
            // 2. Pop to excess next element -> perform desired operation

            // for (int i = 0; i < n; ++i)
            // {
            //     cout << q.top() << endl;
            //     q.dequeue();
            // }
            
            break;
        default:
            printf("Invalid case\n");
            break;
        }
        printf("Do you want to continue (y/n) : ");
        cin >> contd;
    } while (contd == 'y' || contd == 'Y');
    return 0;
}