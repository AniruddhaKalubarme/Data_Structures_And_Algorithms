#include<iostream>
using namespace std;

class Queue
{
    int n, k;
    int freespot;
    int *next;
    int *arr;
    int *front;
    int *rear;
    
    public:
    Queue(int n, int k)
    {
        this->n = n;
        this->k = k;

        next = new int[n];
        for(int i = 0; i<n; i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;
 
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i<k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }

        arr = new int[n];
        freespot = 0;
    }

    void enqueue(int data, int qn)
    {
        if(freespot == -1)
        {
            cout<<"OVERFLOW"<<endl;
            return;
        }

        int index = freespot;
        freespot = next[index];

        if(front[qn-1] == -1)
        {
            front[qn-1] = index;
        }
        else
        {
            next[rear[qn-1]] = index;
        }

        next[index] = -1;
        rear[qn-1] = index;
        arr[index] = data;
    }

    void dequeue(int qn)
    {
        if(front[qn-1] == -1)
        {
            cout<<"UNDERFLOW"<<endl;
            return;
        }
        
        int index = front[qn-1];
        cout<<"Element Deleted: "<<arr[index]<<endl;
        front[qn-1] = next[front[qn-1]];
        next[index] = freespot;
        freespot = index;
    }
};

int main()
{
    Queue obj(4,2);
    obj.enqueue(5,1);
    obj.enqueue(10,1);
    obj.enqueue(15,2);
    obj.enqueue(20,1);

    obj.dequeue(1);
    obj.dequeue(1);
    obj.dequeue(2);
    obj.dequeue(1);

    obj.enqueue(5,1);
    obj.enqueue(10,1);
    obj.enqueue(15,2);
    obj.enqueue(20,1);
    
    obj.dequeue(1);
    obj.dequeue(1);
    obj.dequeue(2);
    obj.dequeue(1);
    return 0;
}