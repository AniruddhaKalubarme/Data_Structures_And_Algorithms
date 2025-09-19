class Solution {
    int solve(int []obs, int curr, int lane)
    {
        if(curr == obs.length-1)
            return 0;

        
        if(obs[curr+1] != lane)
            return solve(obs, curr+1, lane);
        else
        {
            int iMin = Integer.MAX_VALUE;
            for(int i = 1; i<=3; i++)
            {
                if(lane != i && obs[curr] != i)
                {
                    iMin = Math.min(iMin, 1 + solve(obs, curr, i));
                }
            }

            return iMin;
        }
    }
    public int minSideJumps(int[] obstacles) {
        return solve(obstacles, 0, 2);
    }
}



class Solution {
    int solve(int []obs, int curr, int lane, int [][]dp)
    {
        if(curr == obs.length-1)
            return 0;

        if(dp[curr][lane] != 0)
            return dp[curr][lane];
        
        if(obs[curr+1] != lane)
            return solve(obs, curr+1, lane, dp);
        else
        {
            int iMin = Integer.MAX_VALUE;
            for(int i = 1; i<=3; i++)
            {
                if(lane != i && obs[curr] != i)
                {
                    iMin = Math.min(iMin, 1 + solve(obs, curr, i, dp));
                }
            }
            
            dp[curr][lane] = iMin;
            return iMin;
        }
    }
    public int minSideJumps(int[] obstacles) {
        int n = obstacles.length;
        int [][]dp = new int[n+1][4];
        return solve(obstacles, 0, 2, dp);
    }
}