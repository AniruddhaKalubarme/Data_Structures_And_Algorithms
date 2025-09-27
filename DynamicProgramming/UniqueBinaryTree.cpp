class Solution {
public:
    int solve(int n, vector<int> &dp)
    {
        if(n <= 1)
            return 1;

        if(n == 2)
            return 2;

        if(dp[n] != -1)
            return dp[n];

        int ans = 0;
        for(int i = 1; i<=n; i++)
        {
            ans += (solve(i-1, dp)*solve(n-i, dp));
        }
        
        dp[n] = ans;
        return dp[n];
    }

    int solveTab(int n1, vector<int> &dp)
    {
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;

        for(int n = 3; n<=n1; n++)
        {
            int ans = 0;
            for(int i = 1; i<=n; i++)
            {
                ans += dp[i-1] * dp[n-i];
            }
            
            dp[n] = ans;
        }
        return dp[n1];
    }

    int numTrees(int n) {
        if(n <= 1)
            return 1;

        if(n == 2)
            return 2;
        vector<int> dp(n+1);
        return solveTab(n, dp);
    }
};