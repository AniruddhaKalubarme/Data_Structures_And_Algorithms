class Solution {

    boolean chk(int[][] cub, int curr, int prev)
    {
        if(cub[curr][0] >= cub[prev][0] && cub[curr][1] >= cub[prev][1] && cub[curr][2] >= cub[prev][2])
            return true;
        else
            return false;
    }
    
    int solve(int[][] cub, int curr, int prev)
    {
        if(curr == cub.length)
            return 0;
        
        int take = 0;
        if(prev == -1 || chk(cub, curr, prev))
        {
            take = cub[curr][2]+solve(cub, curr+1, curr);
        }

        int notTake = solve(cub, curr+1, prev);

        return Math.max(take, notTake);
    }

    int solveMem(int[][] cub, int curr, int prev, int dp[][])
    {
        if(curr == cub.length)
            return 0;

        if(dp[curr][prev+1] != 0)
            return dp[curr][prev+1];
        
        int take = 0;
        if(prev == -1 || chk(cub, curr, prev))
        {
            take = cub[curr][2]+solveMem(cub, curr+1, curr, dp);
        }

        int notTake = solveMem(cub, curr+1, prev, dp);

        dp[curr][prev+1] = Math.max(take, notTake);
        return dp[curr][prev+1];        
    }


    int solveTab(int[][] cub)
    {
        int n = cub.length;
        int dp[][] = new int[n+1][n+1];
        
        for(int curr = n-1; curr>=0; curr--)
        {
            for(int prev = curr; prev>=-1; prev--)
            {
                int take = 0;
                if(prev == -1 || chk(cub, curr, prev))
                {
                    take = cub[curr][2]+dp[curr+1][curr+1];
                }

                int notTake = dp[curr+1][prev+1];

                dp[curr][prev+1] = Math.max(take, notTake);
            }
        }


        return dp[0][-1+1];        
    }

    public int maxHeight(int[][] cuboids) {

        int n = cuboids.length;
        int dp[][] = new int[n][n];
        for(int []row : cuboids)
        {
            Arrays.sort(row);
        }

        Arrays.sort(cuboids, (a, b) -> {
            if (a[0] != b[0]) return a[0] - b[0];
            if (a[1] != b[1]) return a[1] - b[1];
            return a[2] - b[2];
        });

        // return solveMem(cuboids, 0, -1, dp);
        return solveTab(cuboids);
    }
}