#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> solve(vector<int> arr, int n)
{
    vector<int> ans;
    stack<int> s;
    s.push(-1);
    for(int i = 0; i<n; i++)
    {
        int curr = arr[i];
        while(s.top()!=-1 && s.top()<=curr)
            s.pop();
        ans.push_back(s.top());
        s.push(curr);
    }

    return ans;
}

int main()
{
    vector <int> vec = {1,5,4,8,3,2};
    vec = solve(vec, vec.size());

    for(auto it:vec)
    {
        cout<<it<<" ";
    }
    return 0;
}