class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> dp;
        int ans = 1;

        for (int x : arr) {
            dp[x] = dp[x - diff] + 1;
            ans = max(ans, dp[x]);
        }

        return ans;
    }
};