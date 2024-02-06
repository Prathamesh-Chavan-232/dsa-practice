//    Circular Queue implementation -
// ---------------------------------------------------
// 1. Queue can have n maximum elements at a time.
// 2. Circular queue of n elements means that
//    it can have max n elements at a time.
// 3. It means if the size of queue is n and
//    there are n elements in the queue more can
//    be added if elements from the front leave
//    the queue
// 4. Eg of this queue - order queue in a resturant
// ---------------------------------------------------

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
        front = 0;
        rear = 0;
        size = n + 1;
        arr = new int[size];
    }
    int is_empty()
    {
        if (rear == front)
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
        if ((rear + 1) % size == front)
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
            rear = (rear + 1) % size;
            arr[rear] = x;
            return x;
        }
    }
    int dequeue()
    {
        if (is_empty())
        {
            front = 0;
            rear = 0;
            return -1;
        }
        else
        {
            front = (front + 1) % size;
            int x = arr[front];
            return x;
        }
    }
    int top()
    {
        return arr[front];
    }
    void display()
    {
        if (is_empty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            for (int i = (front + 1) % size; i != (rear + 1) % size; i = (i + 1) % size)
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
    int ch, x, res;
    char contd = 'y';
    while (true)
    {
        cout << "***** MENU *****\n"  
             << "1. Check if empty\n"
             << "2. Check if full\n"
             << "3. Enqueue\n"
             << "4. Dequeue\n"
             << "5. Display\n"
             << "6. Exit\n"
             << "****************\n"
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
            res = q.enqueue(x);
            if (res == -1)
            {
                cout << "Queue is full\n";
            }
            else
            {
                cout << res << " has enterted the queue\n";
            }
            break;
        case 4:
            res = q.dequeue();
            if (res == -1)
            {
                cout << "Queue is empty\n";
            }
            else
            {
                cout << res << " has left the queue\n";
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
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid case\n");
            break;
        }
    }
    return 0;
}