class Solution {
public:
    int solve(string a, string b, int i, int j, vector<vector<int>> &dp)
    {
        if(i>=a.length())
            return b.length()-j;

        if(j>=b.length())
            return a.length()-i;

        if(dp[i][j] != -1)  return dp[i][j];

        if(a[i] == b[j])
        {
            return dp[i][j] = solve(a, b, i+1, j+1, dp);
        }
        else
        {
            int Insert = 1 + solve(a, b, i, j+1, dp);
            int Delete = 1 + solve(a, b, i+1, j, dp);
            int Replace = 1 + solve(a, b, i+1, j+1, dp);

            return dp[i][j] = min(Insert, min(Delete, Replace));
        }
    }

    int solveTab(string a, string b, vector<vector<int>> &dp)
    {
        for(int j = 0; j<b.length(); j++)
        {
            dp[a.length()][j] = b.length() - j;
        }

        for(int i = 0; i<a.length(); i++)
        {
            dp[i][b.length()] = a.length()-i;
        }

        for(int i = a.length()-1; i>=0; i--)
        {
            for(int j = b.length()-1; j>=0; j--)
            {
                if(a[i] == b[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                {
                    int Insert = 1 + dp[i][j+1];
                    int Delete = 1 + dp[i+1][j];
                    int Replace = 1 + dp[i+1][j+1];

                    dp[i][j] = min(Insert, min(Delete, Replace));
                }
            }
        }

        return dp[0][0];
    }

    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
        return solveTab(word1, word2, dp);
    }
};