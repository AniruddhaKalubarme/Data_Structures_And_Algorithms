class Solution {
    int solve(int[] slices, int curr, int n, int pick, int dp[][])
    {
        if (pick == slices.length/3) return 0; 
        if (curr >= n) return Integer.MIN_VALUE;

        if(dp[curr][pick] != 0)
            return dp[curr][pick];
        
        int take = slices[curr] + solve(slices, curr+2, n, pick+1, dp);
        int notTake = solve(slices, curr+1, n, pick, dp);

        dp[curr][pick] = Math.max(take, notTake);
        return dp[curr][pick];
    }

    int solveTab(int[] slices)
    {
        int n = slices.length;
        int dp1[][] = new int[n+2][n+2];
        int dp2[][] = new int[n+2][n+2];

        for(int curr = n-2; curr>=0; curr--)
        {
            for(int pick = slices.length/3 - 1; pick >=0; pick--)
            {
                int take = slices[curr] + dp1[curr+2][pick+1];
                int notTake = dp1[curr+1][pick];

                dp1[curr][pick] = Math.max(take, notTake);
            }
        }

        int case1 = dp1[0][0];

        for(int curr = n-1; curr>=1; curr--)
        {
            for(int pick = slices.length/3 - 1; pick >=0; pick--)
            {
                int take = slices[curr] + dp2[curr+2][pick+1];
                int notTake = dp2[curr+1][pick];

                dp2[curr][pick] = Math.max(take, notTake);
            }
        }

        int case2 = dp2[1][0];

        return Math.max(case1, case2);
    }

    public int maxSizeSlices(int[] slices) {
        // int n = slices.length;
        // int dp[][] = new int[n][n];
        // int dp1[][] = new int[n][n];

        // return Math.max(solve(slices, 0, n-1, 0, dp1), solve(slices, 1, n, 0, dp));
        return solveTab(slices);
    }
}