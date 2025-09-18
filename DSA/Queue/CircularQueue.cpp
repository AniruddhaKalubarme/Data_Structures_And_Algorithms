#include<iostream>
using namespace std;

class CircularQueue
{
    int *arr, size, front, rear;

    public:

    CircularQueue(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    void enqueue(int x)
    {
        if((rear+1) % size == front)
        {
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(rear == -1)
        {
            rear = front = 0;
            arr[rear] = x;
        }
        else
        {
            rear = (rear+1) % size;
            arr[rear] = x;
        }
    }

    void dequeue()
    {
        if(front == -1)
        {
            cout<<"Queue is Empty"<<endl;
            return;
        }
        else if(front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front+1)%size;
        }
    }

};

int main()
{
    int size = 2;
    CircularQueue obj(size);
    obj.enqueue(5);
    obj.enqueue(3);

    obj.dequeue();
    obj.dequeue();  

    return 0;
}