class Solution {
  public:
    bool solve(vector<int>& arr, int i, int iSum, vector<vector<int>> &dp)
    {
        if(iSum == 0)
            return true;
        
        if(i>=arr.size() || iSum<0) return false;
            
        if(dp[i][iSum] != -1)
            return dp[i][iSum];
        
        bool take = solve(arr, i+1, iSum-arr[i], dp);
        bool notTake = solve(arr, i+1, iSum, dp);
        
        dp[i][iSum] = (take | notTake);
        return dp[i][iSum];
    }
    
    bool solveTab(vector<int>& arr, int iSum1, vector<vector<bool>> dp)
    {
        int n = arr.size();
        
        for(int i = 0; i<=n; i++)
            dp[i][0] = true;
        
        for(int i = n-1; i>=0; i--)
        {
            for(int iSum = 0; iSum<=iSum1; iSum++)
            {
                bool take = false;
                if(iSum - arr[i] >= 0)
                    take = dp[i+1][iSum-arr[i]];
                bool notTake = dp[i+1][iSum];
                
                dp[i][iSum] = (take | notTake);
            }
        }
        
        return dp[0][iSum1];
    }
    
  
    bool equalPartition(vector<int>& arr) {
        int Total = 0;
        int n = arr.size();
        for(auto no : arr)
            Total += no;
            
        if(Total % 2 == 1)
            return false;
        
        vector<vector<bool>> dp(n+1, vector<bool>((Total/2)+1, false));
            
        return solveTab(arr, Total/2, dp);
    }
};