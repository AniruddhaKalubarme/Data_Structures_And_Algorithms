class Solution {
    int solve(int[] sati, int index, int mul)
    {
        if(index>=sati.length)
            return 0;
        
        int include = sati[index]*mul + solve(sati, index+1, mul+1);
        int exclude = solve(sati, index+1, mul);

        return Math.max(include, exclude);
    }

    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);

        return solve(satisfaction, 0, 1);
    }
}

class Solution {
    int solve(int[] sati, int index, int mul, int dp[][])
    {
        if(index>=sati.length)
            return 0;

        if(dp[index][mul] != 0)
            return dp[index][mul];
        
        int include = sati[index]*mul + solve(sati, index+1, mul+1, dp);
        int exclude = solve(sati, index+1, mul, dp);

        dp[index][mul] = Math.max(include, exclude);
        return dp[index][mul];
    }

    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int n = satisfaction.length;
        int dp[][] = new int[n+1][n+1];
        return solve(satisfaction, 0, 1, dp);
    }
}



class Solution {
    int solveTab(int[] sati)
    {
        int n = sati.length;
        int dp[][] = new int[n+1][n+2];

        for (int index = n - 1; index >= 0; index--) {
            for (int mul = n; mul >= 1; mul--) {
                int include = sati[index] * mul + dp[index + 1][mul + 1];
                int exclude = dp[index + 1][mul];
                dp[index][mul] = Math.max(include, exclude);
            }
        }

        return dp[0][1];
    }

    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        
        return solveTab(satisfaction);
    }
}