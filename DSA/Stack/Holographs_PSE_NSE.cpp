#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> prevSmaller(vector<int> arr)
{
    stack<int> s;
    vector<int> ans(arr.size());
    for(int i = 0; i<arr.size(); i++)
    {
        int curr = arr[i];
        while(!s.empty() && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
    return ans;
}

vector<int> nextSmaller(vector<int> arr)
{
    stack<int> s;
    vector<int> ans(arr.size());
    for(int i = arr.size()-1; i>-1; i--)
    {
        int curr = arr[i];
        while(!s.empty() && arr[s.top()]>=curr){
            s.pop();
        }
        ans[i] = s.empty() ? arr.size() : s.top();
        s.push(i);
    }
    return ans;
}

int main()
{
    system("cls"); // clering terminal
    vector<int> arr = {2,1,5,6,2,3};
    vector<int> prev = prevSmaller(arr);
    vector<int> next = nextSmaller(arr);

    int maxArea = -1;
    for(int i = 0; i<arr.size(); i++)
    {
        cout<<prev[i]<<" -> "<<next[i]<<" -> "<<arr[i]<<" -> "<<arr[i]*(next[i]-prev[i]-1)<<endl;
        maxArea = max(maxArea, arr[i]*(next[i]-prev[i]-1));
    }
    cout<<maxArea<<endl;
    return 0;
}