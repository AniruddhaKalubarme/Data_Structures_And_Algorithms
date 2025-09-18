#include<iostream>
using namespace std;

class DoublyQueue
{
    int *arr, size, front, rear;
    public:
    DoublyQueue(int n)
    {
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    void eRear(int x)
    {
        if((rear + 1) % size == front)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(rear == -1)
        {
            rear = front = 0;
        }
        else
        {
            rear = (rear + 1)%size;
        }
        arr[rear] = x;
    }

    void eFront(int x)
    {
        if((rear + 1) % size == front)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(rear == -1)
        {
            rear = front = 0;
        }
        else if(front == 0)
        {
            front = size-1;
        }
        else
        {
            front--;
        }
        arr[front] = x;
    }

    void dFront()
    {
        if(front == -1)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        else if(front == rear)
        {
            cout<<"Deleted element is: "<<arr[front]<<endl;
            front = rear = -1;
        }
        else if(front == size-1)
        {
            cout<<"Deleted element is: "<<arr[front]<<endl;
            front = 0;
        }
        else
        {
            cout<<"Deleted element is: "<<arr[front]<<endl;
            front++;
        }
    }

    void dRear()
    {
        if(rear == -1)
        {
            cout<<"Queue is empty"<<endl;
            return;
        }
        else if(front == rear)
        {
            cout<<"Deleted element is: "<<arr[rear]<<endl;
            front = rear = -1;
        }
        else if(rear == 0)
        {
            cout<<"Deleted element is: "<<arr[rear]<<endl;
            rear = size-1;
        }
        else
        {
            cout<<"Deleted element is: "<<arr[rear]<<endl;
            rear--;
        }
    }
};

int main()
{
    return 0;
}