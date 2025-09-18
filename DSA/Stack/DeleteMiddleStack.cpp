#include<iostream>
#include<stack>
using namespace std;

void Solve(stack<int> &inputStack, int N, int iCnt = 0)
{
   if(iCnt == N/2)
   {
      inputStack.pop();
      return;
   }

   int num = inputStack.top();
   inputStack.pop();
   Solve(inputStack, N, ++iCnt); // iCnt++ produce error
   inputStack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N)
{	
   Solve(inputStack, N);
}

void Display(stack<int> s, int N, int top = 0)
{
    if(top == N)
        return;
    
    int num = s.top();
    s.pop();
    cout<<num<<endl;
    Display(s,N,++top);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    // deleteMiddle(s,5);
    Display(s,5);
    return 0;
}