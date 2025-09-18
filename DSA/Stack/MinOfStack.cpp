#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

void Display(stack<int>);
// Approach - 1
void FindMin(stack<int> s, stack<int> &ans, int &iMin)
{
    if(s.empty())
    {
        return;
    }

    int num = s.top();
    s.pop();

    FindMin(s, ans,  iMin);

    iMin = min(num, iMin);
    ans.push(iMin);
}

void Display(stack<int> s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" -> ";
        s.pop();
    }
}

// Approach - 2
class SpecialStack {
    public:
    
    stack <int> s;
    int iMin;
    SpecialStack()
    {
        iMin = INT_MAX;
    }

    void push(int data) {
        if(s.empty())
        {
            s.push(data);
            iMin = data;
        }
        else if(data < iMin)
        {
            int val = 2*data - iMin;
            s.push(val);
            iMin = data;
        }
        else
        {
            s.push(data);
        }
    }

    void pop() {
        if(s.empty())
            return;
        else if(s.top()<=iMin)
        {
            int val = 2*iMin - s.top();
            iMin = val;
        }
        s.pop();
    }

    int top() {
        if(s.top() < iMin)
            return iMin;
        else
            return s.top();
    }

    int getMin() {
        return iMin;
    }  
};


int main()
{
    vector<int> arr = {5,6,2,3,8};
    stack<int> ans, s;
    // stack<int> s;
    for(auto it:arr)
        s.push(it);

    int val = INT_MAX;
    FindMin(s, ans, val);
    Display(ans);
    return 0;
}