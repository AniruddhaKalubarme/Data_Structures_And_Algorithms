class Solution {
public:
    int solve(vector<int>& prices, int k, int i, int Oparation, vector<vector<int>> &dp)
    {
        if(i == prices.size())  return 0;
        if(Oparation == k)  return 0;

        if(dp[i][Oparation] != -1)  return dp[i][Oparation];

        int profit = 0;
        if(Oparation%2 == 0)
        {
            profit = max(-prices[i] + solve(prices, k, i+1, Oparation+1, dp), solve(prices, k, i+1, Oparation, dp));
        }
        else
        {
            profit = max(prices[i] + solve(prices, k, i+1, Oparation+1, dp), solve(prices, k, i+1, Oparation, dp));
        }

        return dp[i][Oparation] = profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(k*2+1, -1));
        return solve(prices, k*2, 0, 0, dp);
    }
};