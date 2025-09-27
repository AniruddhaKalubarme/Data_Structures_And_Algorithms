class Solution {
  public:
    
    int solve(int m, int n, int x, vector<vector<int>> &dp)
    {
        if(x == 0 && n == 0)
            return 1;
            
        if(n == -1 || x<0)
            return 0;
            
        if(dp[n][x] != -1)
            return dp[n][x];
        
        int ans = 0;
        for(int i = 1; i<=m; i++)
        {
            ans += solve(m, n-1, x-i, dp);
        }
        
        dp[n][x] = ans;
        return dp[n][x];
    }

    
    int solveTab(int m, int n1, int x1)
    {
        
        vector<vector<int>> dp(n1+1, vector<int>(x1+1, 0));
        dp[0][0] = 1;
        
        for(int n = 1; n<=n1; n++)
        {
            for(int x = 1; x<=x1; x++)
            {
        
                int ans = 0;
                for(int i = 1; i<=m; i++)
                {
                    if(x-i > -1)
                        ans += dp[n-1][x-i];
                }
                
                dp[n][x] = ans;
            }
        }
        return dp[n1][x1];                

    }
  
    int noOfWays(int m, int n, int x) {
        // code here
        vector<vector<int>> dp(n+1, vector<int>(x+1, -1));
        return solveTab(m, n, x);
    }
};