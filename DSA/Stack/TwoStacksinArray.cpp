#include <bits/stdc++.h> 
class TwoStack {

public:

    int *arr;
    int size;
    int top1;
    int top2;
    TwoStack(int s) {
        size = s;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }
    
    // Push in stack 1.
    void push1(int num) {
        if(top1 + 1 == top2)
        {
            return;
        }
        else
        {
            top1++;
            arr[top1] = num;
        }
    }

    // Push in stack 2.
    void push2(int num) {
        if(top1 + 1 == top2)
        {
            return;
        }
        else
        {
            top2--;
            arr[top2] = num;
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1() {
        if(top1 == -1)
        {
            return -1;
        }
        else
        {
            int temp = arr[top1];
            top1--;
            return temp;
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2() {
        if(top2 == size)
        {
            return -1;
        }
        else
        {
            int temp = arr[top2];
            top2++;
            return temp;
        }
    }
};


int main()
{
    TwoStack obj(5);
    obj.push1(1);
    obj.push2(5);
    obj.push1(2);
    obj.push1(3);
    obj.push2(4);

    obj.pop1();
    obj.pop1();
    obj.pop1();
    std::cout<<obj.pop1(); // we don't have an element in top1, only 3 elements are present
    return 0;
}