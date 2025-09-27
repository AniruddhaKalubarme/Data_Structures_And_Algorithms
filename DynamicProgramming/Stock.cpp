class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int iMin = prices[0];
        int profit = 0;

        for(int i = 1; i<n; i++)
        {
            int diff = prices[i]-iMin;
            profit = max(diff, profit);
            iMin = min(iMin, prices[i]);
        }

        return profit;
    }
};