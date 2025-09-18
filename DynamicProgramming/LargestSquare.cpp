// User function Template for C++

class Solution {
  public:
    int solve(vector<vector<int>>& mat, int i, int j, int &iMax)
    {
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
        
        
        int right = solve(mat, i, j+1, iMax);
        int diag = solve(mat, i+1, j+1, iMax);
        int down = solve(mat, i+1, j, iMax);
        
        if(mat[i][j] == 1)
        {
            int ans = 1+min(right, min(diag, down));
            iMax = max(iMax, ans);
            return ans;
        }
        else
        {
            return 0;
        }
    }
    
    int solveMem(vector<vector<int>>& mat, int i, int j, int &iMax, vector<vector<int>> &dp)
    {
        if(i>=mat.size() || j>=mat[0].size())
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int right = solveMem(mat, i, j+1, iMax, dp);
        int diag = solveMem(mat, i+1, j+1, iMax, dp);
        int down = solveMem(mat, i+1, j, iMax, dp);
        
        if(mat[i][j] == 1)
        {
            int ans = 1+min(right, min(diag, down));
            iMax = max(iMax, ans);
            
            dp[i][j] = ans;
            return ans;
        }
        else
        {
            dp[i][j] = 0;
            return 0;
        }
    }

    void solveTab(vector<vector<int>>& mat, int &iMax)
    {
        vector<vector<int>> dp(mat.size()+1, vector<int> (mat[0].size()+1, 0));
        
        for(int i = mat.size()-1; i>=0; i--)
        {
            for(int j = mat[0].size()-1; j>=0; j--)
            {
                
                int right = dp[i][j+1];
                int diag = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j] == 1)
                {
                    int ans = 1+min(right, min(diag, down));
                    iMax = max(iMax, ans);
                    dp[i][j] = ans;
                }
                else
                {
                    dp[i][j] = 0;
                }
                
            }
        }
    }
    
    void solveSO(vector<vector<int>>& mat, int &iMax)
    {
        vector<vector<int>> dp(mat.size()+1, vector<int> (mat[0].size()+1, 0));
        vector<int> curr(mat[0].size()+1, 0);
        vector<int> next(mat[0].size()+1, 0);
        
        for(int i = mat.size()-1; i>=0; i--)
        {
            for(int j = mat[0].size()-1; j>=0; j--)
            {
                int right = curr[j+1];
                int diag = next[j+1];
                int down = next[j];
                
                if(mat[i][j] == 1)
                {
                    int ans = 1+min(right, min(diag, down));
                    iMax = max(iMax, ans);
                    curr[j] = ans;
                }
                else
                {
                    curr[j] = 0;
                }
                
            }
            next = curr;
        }
    }
  
    int maxSquare(vector<vector<int>>& mat) {
        // code here
        int iMax = 0;
        // vector<vector<int>> dp(mat.size(), vector<int> (mat[0].size(), -1));
        solveSO(mat, iMax);
        return iMax;
    }
};