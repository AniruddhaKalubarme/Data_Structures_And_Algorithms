int solve(int n, vector<int> &days, vector<int> &cost, int index)
{
    if(index>=n)
        return 0;

    int op1 = cost[0] + solve(n, days, cost, index+1);

    int i;
    for(i = index; i<n && days[i]<days[index]+7; i++);
    int op2 = cost[1] + solve(n, days, cost, i);

    for(i = index; i<n && days[i]<days[index]+30; i++);
    int op3 = cost[2] + solve(n, days, cost, i);

    return min(op1, min(op2, op3));
}
int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1, -1);
    return solve(n, days, cost, 0);
}


int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    if(index>=n)
        return 0;

    if(dp[index] != -1)
        return dp[index];

    int op1 = cost[0] + solveMem(n, days, cost, index+1, dp);

    int i;
    for(i = index; i<n && days[i]<days[index]+7; i++);
    int op2 = cost[1] + solveMem(n, days, cost, i, dp);

    for(i = index; i<n && days[i]<days[index]+30; i++);
    int op3 = cost[2] + solveMem(n, days, cost, i, dp);

    dp[index] = min(op1, min(op2, op3));
    return dp[index];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1, -1);
    return solveMem(n, days, cost, 0, dp);
}



int solveTab(int n, vector<int> &days, vector<int> &cost, vector<int> &dp)
{
    dp[n] = 0;

    for(int k = n-1; k>=0; k--)
    {
        int op1 = cost[0] + dp[k+1];

        int i;
        for(i = k; i<n && days[i]<days[k]+7; i++);
        int op2 = cost[1] + dp[i];

        for(i = k; i<n && days[i]<days[k]+30; i++);
        int op3 = cost[2] + dp[i];

        dp[k] = min(op1, min(op2, op3));
    }
    return dp[0];
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1, -1);
    return solveTab(n, days, cost, dp);
}


int solveSpace(int n, vector<int> &days, vector<int> &cost)
{
    queue<pair<int,int>> week, month;

    int ans = 0;
    for(int day : days)
    {
        while(!week.empty() && day-7>=week.front().first)
        {
            week.pop();
        }

        while(!month.empty() && day-30>=month.front().first)
        {
            month.pop();
        }

        week.push(make_pair(day, ans+cost[1]));
        month.push(make_pair(day, ans+cost[2]));

        ans = min(ans+cost[0], min(week.front().second, month.front().second));
    }

    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    return solveSpace(n, days, cost);
}