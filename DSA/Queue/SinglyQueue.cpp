#include<iostream>
using namespace std;

class Queue
{
    int *arr, size, front, rear;

    public:
    Queue(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if(rear+1 == size)
        {
            cout<<"Queue is full"<<endl;
        }
        else if(rear == -1)
        {
            arr[++rear] = x;
            front++;
        }
        else
        {
            arr[++rear] = x;
        }
    }

    void dequeue()
    {
        if(front == -1)
        {
            cout<<"Queue is empty"<<endl;
        }
        else if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }

    void ShowRear()
    {
        cout<<((rear == -1) ? -1:arr[rear]);
    }

    void ShowFront()
    {
        cout<<((front == -1) ? -1:arr[front])<<endl;;
    }
};

int main()
{
    int n = 5;
    Queue obj(n);

    obj.enqueue(5);
    obj.enqueue(4);
    obj.enqueue(3);
    obj.enqueue(2);
    obj.enqueue(1);

    obj.dequeue();

    obj.ShowFront();
    obj.ShowRear();
    return 0;
}