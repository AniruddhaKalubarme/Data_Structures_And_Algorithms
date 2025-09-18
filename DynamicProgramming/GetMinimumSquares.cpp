
class Solution {
  public:
    int solve(int n)
    {
        if(n<0) return INT_MAX;
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        
        int ans = INT_MAX;
        for(int i = 1; i<n; i++)
        {
            int temp = solve(n-(i*i));
            if(temp == INT_MAX) break;
            ans = min(ans, temp);
        }
        
        return ans+1;
    }
    
    int MinSquares(int n) {
        return solve(n);
    }
};

// User function Template for C++

class Solution {
  public:
    int solveMem(int n,vector<int> &dp)
    {
        if(n<0) return INT_MAX;
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        if(dp[n] != -1)
            return dp[n];
            
        int ans = INT_MAX;
        for(int i = 1; i<n; i++)
        {
            int temp = solveMem(n-(i*i), dp);
            if(temp == INT_MAX) break;
            ans = min(ans, temp);
        }
        
        dp[n] = ans+1;
        return dp[n];
    }
    
    int MinSquares(int n) {
        vector<int> dp(n+1, -1);
        return solveMem(n, dp);
    }
};


int solveTab(int n,vector<int> &dp)
{
    dp[0] = 0;
    
    
    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j*j<=n; j++)
        {
            if(i-(j*j) > -1)
                dp[i] = min(dp[i], 1+ dp[i-(j*j)]);
        }
    }
    
    return dp[n];
}

int MinSquares(int n) {
    vector<int> dp(n+1, INT_MAX);
    return solveTab(n, dp);
}