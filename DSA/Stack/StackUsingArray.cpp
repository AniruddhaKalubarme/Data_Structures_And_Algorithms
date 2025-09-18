#include<iostream>
using namespace std;

class Stack
{
    public:
        int *arr;
        int size;
        int top;

        Stack(int size)
        {
            arr = new int[size];
            this->size = size;
            top = -1;
        }

    void push(int iNo)
    {
        if(size-top > 1)
        {
            top++;
            arr[top] = iNo;
        }
        else
        {
            cout<<"OVERFLOW"<<endl;
            return;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"UNDERFLOW"<<endl;
        }
        else
        {
            top--;
            cout<<"Successfully deleted an element"<<endl;
        }
    }

    int peak()
    {
        if(top == -1)
        {
            cout<<"Stack is EMPTY"<<endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    bool empty()
    {
        return (top==-1);
    }
};

int main()
{
    Stack s(5);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    cout<<"TOP: "<<s.peak()<<endl;
    s.pop();
    cout<<"TOP: "<<s.peak()<<endl;

    cout<<"Is stack empty: "<<s.empty()<<endl;


    return 0;
}