class Solution {
  public:
    
    int solve(vector<int> &arr, int curr, int prev, vector<vector<int>> &dp)
    {
        if(curr == arr.size())
            return 0;
            
        if(dp[curr][prev+1] != -1)
            return dp[curr][prev+1];
            
        int take = 0;
        if(prev == -1 || arr[curr]>arr[prev])
            take = 1+solve(arr, curr+1, curr, dp);
        
        int notTake = solve(arr, curr+1, prev, dp);
        
        dp[curr][prev+1] = max(take, notTake);
        return dp[curr][prev+1];
    }

    
    int solveTab(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        for(int curr = n-1; curr>=0; curr--)
        {
            for(int prev = curr; prev>=-1; prev--)
            {
                int take = 0;
                if(prev == -1 || arr[curr]>arr[prev])
                    take = 1+solve(arr, curr+1, curr, dp);
                
                int notTake = solve(arr, curr+1, prev, dp);
                
                dp[curr][prev+1] = max(take, notTake);
            }
        }
        
        return dp[0][0];
    }

    int lis(vector<int>& arr) {
        return solveTab(arr);
    }
};