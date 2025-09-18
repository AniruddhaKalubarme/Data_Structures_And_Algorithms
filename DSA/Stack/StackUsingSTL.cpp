#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> s;
    s.push(11);
    s.push(21);
    s.push(51);
    s.push(101);
    
    cout<<"Top: "<<s.top()<<endl;
    s.pop();
    cout<<"Top: "<<s.top()<<endl;

    cout<<"Does stack is empty: "<<s.empty()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<"Does stack is empty: "<<s.empty()<<endl;
    
    return 0;
}