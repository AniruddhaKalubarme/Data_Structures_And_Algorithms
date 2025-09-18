#include<iostream>
#include<stack>
using namespace std;

void Insert(stack<int> &s, int x)
{
    if(s.empty())
    {
        s.push(x);
        return;
    }

    int num = s.top();
    s.pop();

    Insert(s,x);
    s.push(num);
}

void reverse(stack<int> &s)
{
    if(s.empty()) return;

    int num = s.top();
    s.pop();

    reverse(s);
    Insert(s, num);
}

int main()
{
    return 0;
}