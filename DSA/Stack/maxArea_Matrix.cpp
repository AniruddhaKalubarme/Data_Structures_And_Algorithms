#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void Solve(vector<int> arr, int &maxArea)
{
    stack<int> s;
    int n = arr.size();
    for(int i = 0; i<n; i++)
    {
        while(!s.empty() && arr[s.top()] >= arr[i])
        {
            int nse = i;
            int curr = s.top();
            s.pop();
            int pse = s.empty() ? -1 : s.top();

            maxArea = max(maxArea, arr[curr] * (nse - pse -1));
        }
        s.push(i);
    }
    while(!s.empty())
    {
        int nse = n;
        int curr = s.top();
        s.pop();
        int pse = s.empty() ? -1 : s.top();

        maxArea = max(maxArea, arr[curr] * (nse - pse -1));
    }
}

int main()
{
    vector<vector<int>> vec =  {{0,1,1,0},
                                {1,1,1,1},
                                {1,1,1,1},
                                {1,1,0,0}};
    int maxArea = -1;

    vector<int> ans(vec[0].size());
    // cout<<ans[3]<<endl;
    for(int i = 0; i<vec.size(); i++)
    {
        for(int j = 0; j<vec[0].size(); j++)
        {
            ans[j] = (vec[i][j] == 0) ? 0 : ans[j]+vec[i][j];
        }
        Solve(ans, maxArea);
    }

    cout<<maxArea<<endl;
    
    return 0;
}