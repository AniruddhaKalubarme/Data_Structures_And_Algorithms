class Solution {
public:
    int solve(vector<int>& prices, int i, int buy, vector<vector<vector<int>>> &dp, int limit)
    {
        if(i == prices.size()) return 0;
        if(limit == 0) return 0;

        if(dp[i][buy][limit]!=-1)
            return dp[i][buy][limit];

        int profit = 0;
        if(buy == 0)
        {
            profit = max(-prices[i] + solve(prices, i+1, 1, dp, limit), solve(prices, i+1, 0, dp, limit));
        }
        else
        {
            profit = max(prices[i] + solve(prices, i+1, 0, dp, limit-1), solve(prices, i+1, 1, dp, limit));
        }

        return dp[i][buy][limit] = profit;
    }

    int solveTab(vector<int>& prices)
    {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(2, vector<int>(3, 0)));

        for(int i = prices.size()-1; i>=0; i--)
        {
            for(int buy = 1; buy>=0; buy--)
            {
                for(int limit = 0; limit<=2; limit++)
                {
                    int profit = 0;
                    if(buy == 0)
                    {
                        profit = max(-prices[i] + dp[i+1][1][limit] , dp[i+1][0][limit]);
                    }
                    else
                    {
                        if(limit>0)
                            profit = max(prices[i] + dp[i+1][0][limit-1], dp[i+1][1][limit]);
                    }

                    dp[i][buy][limit] = profit;
                }
            }
        }

        return dp[0][0][2];
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return solveTab(prices);
    }
};/9 