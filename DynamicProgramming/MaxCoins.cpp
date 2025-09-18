#include <bits/stdc++.h> 

int solveRec(vector<int> &nums, int x)
{
    if(x==0)
        return 0;
    
    if(x<0)
        return INT_MAX;

    int mini = INT_MAX;
    for(int i = 0; i<nums.size(); i++)
    {
        int ans = solveRec(nums, x-nums[i]);

        if(ans != INT_MAX)
            mini = min(1+ans, mini);
    }   

    return mini;
}

int solveMem(vector<int> &nums, int x, vector<int> &dp)
{
    if(x==0)
        return 0;
    
    if(x<0)
        return INT_MAX;

    if(dp[x] != -1)
        return dp[x];

    int mini = INT_MAX;
    for(int i = 0; i<nums.size(); i++)
    {
        int ans = solveMem(nums, x-nums[i], dp);

        if(ans != INT_MAX)
            mini = min(1+ans, mini);
    }

    dp[x] = mini;
    return mini;
}

vector<int> dp(x+1, -1);


int minimumElements(vector<int> &num, int x)
{
    int ans = solveRec(num, x);
    if(ans == INT_MAX)
        return -1;
    else
        return ans;
}


int solveTab(vector<int> &nums, int x, vector<int> &dp)
{
    dp[0] = 0;;

    
    for(int i = 1; i<=x; i++)
    {
        for(int j = 0; j<nums.size(); j++)
        {
            if(i-nums[j] >= 0 && dp[i-nums[j]] != INT_MAX)
                dp[i] = min(dp[i], 1+dp[i-nums[j]]);
        }
    }

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1, INT_MAX);
    int ans = solveTab(num, x, dp);
    if(ans == INT_MAX)
        return -1;
    else
        return ans;
}