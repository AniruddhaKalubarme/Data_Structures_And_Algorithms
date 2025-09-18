#include <bits/stdc++.h> 
// Approach-1 : using top down
void solve(int n, int curr, int &iCnt)
{
    if(curr == n)
    {
        iCnt++;
        return;
    }

    if(curr>n)
    {
        return;
    }

    solve(n, curr+1, iCnt);
    solve(n, curr+2, iCnt);
}

int countDistinctWays(int nStairs) {
    int iCnt = 0;
    solve(nStairs, 0, iCnt);
    return iCnt;
}


// Approach-2: using bottom up
#include <bits/stdc++.h> 
#define mod 1000000007

int solve(int n, int curr, vector<int> &dp)
{
    if(curr == n)
    {
        return 1;
    }

    if(curr>n)
    {
        return 0;
    }

    if(dp[curr] != -1)
        return dp[curr];

    dp[curr] = (solve(n, curr+1, dp) + solve(n, curr+2, dp))%mod;
    return dp[curr];
}

int countDistinctWays(int nStairs) {
    vector<int> dp(nStairs+1, -1);
    return solve(nStairs, 0, dp);
}


// Cost with stairs
class Solution {
public:
    int solve(int n, vector<int> &cost, int curr)
    {
        if(curr == n-1 || curr == n-2)
            return cost[curr];

        return cost[curr]+min(solve(n, cost, curr+1), solve(n, cost, curr+2));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return min(solve(cost.size(), cost, 0), solve(cost.size(), cost, 1));
    }
};


// Top down
class Solution {
public:
    int solve(int n, vector<int> &cost, int curr, vector<int> &dp)
    {
        if(curr == n-1 || curr == n-2)
            return cost[curr];

        if(dp[curr] != -1)
            return dp[curr];

        dp[curr] = cost[curr]+min(solve(n, cost, curr+1, dp), solve(n, cost, curr+2, dp));
        return dp[curr];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), -1);
        return min(solve(cost.size(), cost, 0, dp), solve(cost.size(), cost, 1, dp));
    }
};


// Bottom - up
class Solution {
public:
    int solve(int n, vector<int> &cost)
    {
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i<n; i++)
        {
            dp[i] = cost[i]+min(dp[i-1],dp[i-2]);
        }

        return min(dp[n-1],dp[n-2]);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return solve(cost.size(), cost);
    }
};


// space optimised
class Solution {
public:
    int solve(int n, vector<int> &cost)
    {
        int first = cost[0];
        int second = cost[1];

        for(int i = 2; i<n; i++)
        {
            int temp = cost[i]+min(first,second);
            first = second;
            second = temp;
        }

        return min(first,second);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        return solve(cost.size(), cost);
    }
};