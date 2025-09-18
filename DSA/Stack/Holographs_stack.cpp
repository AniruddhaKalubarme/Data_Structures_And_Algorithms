#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int Area(vector<int> arr)
{
    stack<int> s;
    int maxArea = -1;
    for(int i = 0; i<arr.size(); i++)
    {
        while(!s.empty() && arr[s.top()]>arr[i])
        {
            int nse = i;
            int curr = s.top();
            s.pop();
            int pse = s.empty() ? -1 : s.top();

            maxArea = max(maxArea, arr[curr] * (nse - pse - 1));
        }

        s.push(i);
    }
    while(!s.empty())
    {
        int nse = arr.size();
        int curr = s.top();
        s.pop();
        int pse = s.empty() ? -1 : s.top();
        maxArea = max(maxArea, arr[curr] * (nse - pse - 1));
    }
    return maxArea;
}

int main()
{
    vector<int> arr = {3,6,5,7,4,8,1,0};
    int area = Area(arr);
    cout<<"Area: "<<area<<endl;
    return 0;
}