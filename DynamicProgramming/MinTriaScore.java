class Solution {
    int solve(int[] v, int i, int j, int dp[][])
    {
        if(i+1 == j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = Integer.MAX_VALUE;

        for(int k = i+1; k<j; k++)
        {
            ans = Math.min(ans, v[i]*v[k]*v[j] + solve(v, i, k, dp) + solve(v, k, j, dp));
        }

        dp[i][j] = ans;
        return ans;
    }

    public int minScoreTriangulation(int[] values) {
        int n = values.length+1;
        int dp[][] = new int[n][n];

        for(int[] row : dp)
        {
            Arrays.fill(row, -1);
        }
        return solve(values, 0, values.length-1, dp);
    }
}