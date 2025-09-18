
class Solution {
  public:
    int solve(int n)
    {
        if(n == 2)
            return 1;
        
        if(n == 1)
            return 0;
        
        int ans = (n-1)*(solve(n-1) + solve(n-2));
        return ans;
    }
    
    int countDer(int n) {
        return solve(n);
    }
};

class Solution {
  public:
    int solveMemo(int n, vector<int> &dp)
    {
        if(n == 2)
            return 1;
        
        if(n == 1)
            return 0;
        
        if(dp[n] != -1)
            return dp[n];
        
        dp[n] = (n-1)*(solveMemo(n-1, dp) + solveMemo(n-2, dp));
        return dp[n];
    }
    
    int countDer(int n) {
        vector<int> dp(n+1, -1);
        return solveMemo(n, dp);
    }
};

class Solution {
  public:
    int solveTab(int n, vector<int> &dp)
    {
        dp[1] = 0;
        dp[2] = 1;
        
        for(int i = 3; i<=n; i++)
        {
            dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
        }
        
        return dp[n];
    }
    
    int countDer(int n) {
        vector<int> dp(n+1, -1);
        return solveTab(n, dp);
    }
};


class Solution {
  public:
    int solve(int n)
    {
        if(n == 1)
            return 0;
        if(n == 2)
            return 1;
            
        int first = 0;
        int sec = 1;
        
        for(int i = 3; i<=n; i++)
        {
            int curr = (i-1)*(sec+first);
            first = sec;
            sec = curr;
        }
        
        return sec;
    }
    
    int countDer(int n) {
        return solve(n);
    }
};